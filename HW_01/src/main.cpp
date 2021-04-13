#include <iostream>

#include "csv_writer.hpp"
#include "measure_utils.hpp"

int main(int argc, char *argv[])
{
  hashes_speed::CSVResultsWriter writer;
  hashes_speed::runTestsWithParams(std::stol(argv[1]), std::stol(argv[2]), std::stol(argv[3]), writer);

  return 0;
}
