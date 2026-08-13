#pragma once

#include "profiler/ProfileEvents.h"

#include <memory>

namespace Profiler
{

class ProfilerSink
{
public:
  virtual ~ProfilerSink() = default;

  virtual void write(const TimeSample& timeSample) = 0;
  virtual void flush() = 0;
};

using SinkPtr = std::unique_ptr<ProfilerSink>;

} // namespace Profiler
