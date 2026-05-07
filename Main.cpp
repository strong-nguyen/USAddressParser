#include "USDatabase.h"
#include "USAddressParser.h"
#include "HelpMethod.h"


#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <vector>


int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "USAddressParser.exe address-file\n";
    return 1;
  }

  std::ifstream f(argv[1]);
  if (!f)
  {
    std::cerr << std::format("File {} not found\n", argv[1]);
    return 1;
  }


  USAddressParser parser;
  std::string line;
  std::vector<std::string> rawAddressStr;
  while (std::getline(f, line))
  {
    if (!line.empty())
    {
      rawAddressStr.push_back(line);
    }
    else
    {
      parser.clear();
      parser.setRawAddressStr(rawAddressStr);
      auto address = parser.parseAdddress();
      std::cout << address << std::endl;
      std::cout << "####\n\n";
      rawAddressStr.clear();
    }
  }

  if (!rawAddressStr.empty())
  {
    parser.clear();
    parser.setRawAddressStr(rawAddressStr);
    auto address = parser.parseAdddress();
    std::cout << address << std::endl;
    std::cout << "####\n\n";
  }

  return 0;
}