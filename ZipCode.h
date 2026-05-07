#pragma once

#include <string>
#include <iostream>
#include <format>

// Normally, ZIP (Zone Immprovement Plan) code contains 5 digits
// ZIP+4: extend more 4 digits -> 9 digits


struct ZIPCode
{
  std::string baseCode;  // 5 ditgits
  std::string plusCode;  // plus 4 digits

  friend std::ostream& operator<<(std::ostream& out, const ZIPCode& zipCode)
  {
    out << std::format("ZIP: {} - Plus: {}", zipCode.baseCode, zipCode.plusCode);
    return out;
  }
};