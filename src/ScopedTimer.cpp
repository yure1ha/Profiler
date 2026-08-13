#include "profiler/ScopedTimer.h"
#include "profiler/Profiler.h"

#include <string_view>

namespace Profiler
{

ScopedTimer::ScopedTimer(std::string_view name, Profiler& profiler)
    : name_ {name}, profiler_ {profiler}
{
}

ScopedTimer::~ScopedTimer()
{
  TimeSample sample {};
  sample.metadata.name = name_;
  sample.duration = timer_.elapsed();

  profiler_.record(sample);
}

} // namespace Profiler
