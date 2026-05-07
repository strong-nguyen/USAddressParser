#pragma once


#include <string>
#include <vector>


namespace uap
{
  void trimLeft(std::string& str);

  void trimRight(std::string& str);

  void trim(std::string& str);

  std::vector<std::string> splitStr(const std::string& str, const std::string& token);
}