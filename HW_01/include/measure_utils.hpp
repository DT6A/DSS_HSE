#pragma once

#include "Types.h"
#include "smhasher_helper_header.hpp"
#include "csv_writer.hpp"

namespace hashes_speed
{
  constexpr std::size_t TRIALS = 100000;
  constexpr std::size_t RANDOM_SEED = 0;

  void runTestsWithParams(std::size_t lowerBound, std::size_t upperBound,
          std::size_t step, CSVResultsWriter &writer,
          std::size_t seed = RANDOM_SEED, std::size_t trialsPerTest = TRIALS);
}
