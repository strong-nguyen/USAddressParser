#include "USAddressParser.h"
#include "HelpMethod.h"
#include "USDatabase.h"

#include <fstream>
#include <iostream>
#include <format>
#include <sstream>

Address USAddressParser::parseAdddress()
{
  parseStreetAddress();
  parseLocationAddress();

  return _address;
}

void USAddressParser::setRawAddressStr(const std::vector<std::string>& rawAddress)
{
  _rawAddress = rawAddress;
}

void USAddressParser::clear()
{
  _rawAddress.clear();
  _address = Address();
}

void USAddressParser::parseStreetAddress()
{
  std::string streetStr = _rawAddress[0];
  uap::trim(streetStr);

  std::size_t pos = streetStr.find(' ');
  std::string streetNumber = streetStr.substr(0, pos);
  std::string streetName = streetStr.substr(pos + 1);

  _address.streetNumber = streetNumber;

  for (const auto& suffix : uap::StreetSuffixes)
  {
    auto found = streetName.find(suffix);
    if (found != std::string::npos)
    {
      _address.streetName = streetName.substr(0, found - 1);
      break;
    }
  }

  // Parse secondary unit, for example: 132 Maple St # B
  char arr[] = { '#', ',' };
  for (int i = 0; i < 2; ++i)
  {
    if (std::size_t pos = streetName.find(arr[i]); pos != std::string::npos)
    {
      _address.secondaryUnit.secondaryUnit = streetName.substr(pos + 1);
      _address.secondaryUnit.secondaryDesignator = arr[i];
      break;
    }
  }
}

void USAddressParser::parseLocationAddress()
{
  auto tokens = uap::splitStr(_rawAddress[1], ", ");
  if (tokens.size() != 2)
  {
    return;
  }

  _address.city = tokens[0];
  std::size_t pos = tokens[1].rfind(' ');
  if (pos != std::string::npos)
  {
    _address.state = tokens[1].substr(0, pos);
    std::string zipStr = tokens[1].substr(pos + 1);

    auto zipTokens = uap::splitStr(zipStr, "-");
    if (zipTokens.size() == 1)
    {
      _address.zipCode.baseCode = zipTokens[0];
    }
    else if (zipTokens.size() == 2)
    {
      _address.zipCode.baseCode = zipTokens[0];
      _address.zipCode.plusCode = zipTokens[1];
    }
  }
}
