#pragma once

#include "Profiler/ProfileEvents.h"
#include "Profiler/ISink.h"

#include <memory>
#include <vector>

namespace Profiler
{

class Profiler
{
public:
  void addSink(std::unique_ptr<ISink> sink);
  void flushSinks();
  void record(const TimeSample& timeSample);

private:
  std::vector<std::unique_ptr<ISink>> m_sinks {};
};

} // namespace Profiler
