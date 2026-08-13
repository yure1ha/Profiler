#include "profiler/Profiler.h"

#include "profiler/ProfilerSink.h"

#include <memory>
#include <utility>

namespace Profiler
{

void Profiler::addSink(SinkPtr sink) { sinks_.push_back(std::move(sink)); }

void Profiler::record(const TimeSample& sample)
{
  for (const auto& sink : sinks_)
  {
    sink->write(sample);
  }
}

void Profiler::flush()
{
  for (const auto& sink : sinks_)
  {
    sink->flush();
  }
}

} // namespace Profiler
