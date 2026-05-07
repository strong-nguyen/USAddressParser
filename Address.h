#pragma once

#include "ZipCode.h"

#include <string>
#include <iostream>
#include <format>


struct SecondaryUnit
{
  std::string secondaryUnit;  // For example # B
  std::string secondaryDesignator;  // For example: # or ,

  friend std::ostream& operator<<(std::ostream& out, const SecondaryUnit& unit)
  {
    out << std::format("SecondaryUnitName: {}, SecondaryDesignator: {}\n", unit.secondaryUnit, unit.secondaryDesignator);
    return out;
  }
};

struct Address
{
  std::string streetNumber;
  std::string streetName;
  std::string streetSuffix;  // Rd, St...
  SecondaryUnit secondaryUnit;
  std::string city;
  std::string state;
  ZIPCode zipCode;

  friend std::ostream& operator<<(std::ostream& out, const Address& address)
  {
    out << std::format("StreetNumber: {}, StreetName: {}, StreetSuffix: {}\n", address.streetNumber, address.streetName, address.streetSuffix);
    out << address.secondaryUnit;
    out << std::format("City: {}, State: {}\n", address.city, address.state);
    out << address.zipCode;

    return out;
  }
};
