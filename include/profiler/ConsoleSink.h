#pragma once

#include "profiler/ProfileEvents.h"
#include "profiler/ProfilerSink.h"

namespace Profiler
{

class ConsoleSink : public ProfilerSink
{
public:
  void write(const TimeSample& timeSample) override;
  void flush() override;
};

} // namespace Profiler
