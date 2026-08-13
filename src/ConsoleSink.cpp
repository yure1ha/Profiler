#include "profiler/ConsoleSink.h"

#include "profiler/ProfileEvents.h"

#include <chrono>
#include <iostream>

namespace Profiler
{

void ConsoleSink::write(const TimeSample& sample)
{
  const auto ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(sample.duration)
          .count();
  std::cout << "[TIME]" << "[" << sample.metadata.name << "]: " << ms << "ms\n";
}

void ConsoleSink::flush() { std::cout << std::flush; }

} // namespace Profiler
