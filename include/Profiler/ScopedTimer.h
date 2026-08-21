#pragma once

#include "Profiler/Timer.h"
#include "Profiler/ProfileEvents.h"
#include "Profiler/Profiler.h"

#include <cstdint>

namespace Profiler
{

class ScopedTimer
{
public:
  ScopedTimer(std::int32_t id, const Profiler& profiler)
      : m_id {id},
        m_profiler {profiler}
  {
  }

  ~ScopedTimer()
  {
    TimeSample timeSample;
    timeSample.id = m_id;
    timeSample.duration = m_timer.elapsed();

    m_profiler.record(timeSample);
  }

  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer& operator=(const ScopedTimer&) = delete;

  ScopedTimer(ScopedTimer&&) = delete;
  ScopedTimer& operator=(ScopedTimer&&) = delete;

  [[nodiscard]] std::int32_t id() const { return m_id; }

private:
  std::int32_t m_id {};

  Timer m_timer;
  const Profiler& m_profiler;
};

} // namespace Profiler
