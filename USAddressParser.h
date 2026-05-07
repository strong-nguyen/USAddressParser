#pragma once

#include "Address.h"

#include <string>
#include <vector>


class USAddressParser
{
public:
  Address parseAdddress();

  void setRawAddressStr(const std::vector<std::string>& rawAddress);

  void clear();

private:
  // Street address is the first line
  void parseStreetAddress();

  // Location address is the second line
  void parseLocationAddress();

  // Contain raw string of US address (not include Recipient)
  std::vector<std::string> _rawAddress;

  // Address info after parsing
  Address _address;
};
  