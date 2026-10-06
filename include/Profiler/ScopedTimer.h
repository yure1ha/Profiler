#pragma once

#include "Profiler/ProfileEvents.h"
#include "Profiler/Profiler.h"
#include "Profiler/Timer.h"

#include <cstdint>

namespace Profiler {

class ScopedTimer {
  public:
    ScopedTimer(std::int32_t id, Profiler& profiler) : m_id {id}, m_profiler {profiler} {}

    ~ScopedTimer() {
        TimeSample timeSample;
        timeSample.id = m_id;
        timeSample.duration = m_timer.elapsed();

        m_profiler.record(timeSample);
    }

    ScopedTimer(const ScopedTimer&) = delete;
    ScopedTimer& operator=(const ScopedTimer&) = delete;

    ScopedTimer(ScopedTimer&&) noexcept = delete;
    ScopedTimer& operator=(ScopedTimer&&) noexcept = delete;

    [[nodiscard]] std::int32_t id() const {
        return m_id;
    }

  private:
    std::int32_t m_id {};

    Timer m_timer;
    Profiler& m_profiler;
};

} // namespace Profiler
