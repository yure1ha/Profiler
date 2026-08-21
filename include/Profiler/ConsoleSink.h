#pragma once

#include "Profiler/ISink.h"
#include "Profiler/ProfileEvents.h"

#include <chrono>
#include <iostream>

namespace Profiler
{

class ConsoleSink : public ISink
{
public:
  void write(const TimeSample& timeSample) override
  {
    const auto ms {std::chrono::duration_cast<std::chrono::milliseconds>(timeSample.duration).count()};

    std::cout << "[" << timeSample.name << "]" << "[ID " << timeSample.id << "] " << ms << " ms" << '\n';
  }

  void flush() override
  {
    std::cout << "Flushing..." << std::flush;
  }

};

} // namespace Profiler
