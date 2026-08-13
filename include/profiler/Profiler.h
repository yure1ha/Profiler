#pragma once

#include "profiler/ProfileEvents.h"
#include "profiler/ProfilerSink.h"

#include <memory>
#include <vector>

namespace Profiler
{

class Profiler
{
public:
  void addSink(SinkPtr sink);
  void record(const TimeSample& sample);
  void flush();

private:
  std::vector<SinkPtr> sinks_ {};
};

} // namespace Profiler
