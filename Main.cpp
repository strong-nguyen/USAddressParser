#include "USDatabase.h"
#include "USAddressParser.h"
#include "HelpMethod.h"


#include <iostream>
#include <format>


int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "USAddressParser.exe address-file\n";
    return 1;
  }

  std::string addressFile(argv[1]);
  USAddressParser parser;
  parser.parseAdddress(addressFile);

  return 0;
}