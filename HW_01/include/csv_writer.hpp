#pragma once

#include <string>
#include <fstream>
#include <vector>

namespace hashes_speed
{
  class CSVResultsWriter
  {
  private:
    std::ofstream outputFile;

  public:
    explicit CSVResultsWriter(const std::string &fileName="out.csv");
    void addRaw(std::size_t bytes, double mmh3Time, double customHashTime, double xxhashTime);
  };
}
