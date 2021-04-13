#include "csv_writer.hpp"

hashes_speed::CSVResultsWriter::CSVResultsWriter(const std::string &fileName)
{
  outputFile.exceptions(std::ostream::badbit | std::ostream::failbit);

  outputFile.open(fileName);
  outputFile << "bytes,murmur,fnv,xxhash\n";
}

void hashes_speed::CSVResultsWriter::addRaw(std::size_t bytes, double mmh3Time,
        double customHashTime, double xxhashTime)
{
  outputFile << bytes << "," << mmh3Time << "," << customHashTime << "," << xxhashTime << "\n";
}
