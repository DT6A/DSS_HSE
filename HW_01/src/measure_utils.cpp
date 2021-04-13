#include "vector"

#include "measure_utils.hpp"

#include "xxhash.h"
#include "SpeedTest.h"
#include "Hashes.h"

namespace hashes_speed
{
  void xxHashWrapper(const void *key, const int len, uint32_t seed, void *out)
  {
    *reinterpret_cast<XXH64_hash_t *>(out) = XXH64(key, len, seed);
  }

  void runTestsWithParams(std::size_t lowerBound, std::size_t upperBound,
                          std::size_t step, CSVResultsWriter &writer,
                          std::size_t seed, std::size_t trialsPerTest)
  {
    std::vector<pfHash> hashMethods = {MurmurHash3_x64_128, FNV, xxHashWrapper};
    double hashingTimes[3] = {0};

    for (std::size_t keySize = lowerBound; keySize <= upperBound; keySize += step) {
      for (std::size_t i = 0; i < hashMethods.size(); ++i)
        hashingTimes[i] = SpeedTest(hashMethods[i], seed, trialsPerTest, keySize, 0);
      writer.addRaw(keySize, hashingTimes[0], hashingTimes[1], hashingTimes[2]);
    }
  }
}