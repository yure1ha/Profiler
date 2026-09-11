#pragma once

#include "Profiler/ISink.h"
#include "Profiler/ProfileEvents.h"

#include <memory>
#include <vector>

namespace Profiler {

class Profiler {
  public:
    void addSink(std::unique_ptr<ISink> sink);
    void flushSinks() const;
    void record(const TimeSample& timeSample) const;

  private:
    std::vector<std::unique_ptr<ISink>> m_sinks {};
};

} // namespace Profiler
