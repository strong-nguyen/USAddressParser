#pragma once

#include "Address.h"

#include <string>
#include <vector>


class USAddressParser
{
public:
  void parseAdddress(const std::string& addressFile);

private:
  void readAddressFromFile(const std::string& addressFile);

  // Street address is the first line
  void parseStreetAddress();

  // Location address is the second line
  void parseLocationAddress();

  // Contain raw string of US address (not include Recipient)
  std::vector<std::string> _rawAddress;

  // Address info after parsing
  Address _address;
};
  