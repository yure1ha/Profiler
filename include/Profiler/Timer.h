#pragma once

#include <chrono>

namespace Profiler
{

class Timer
{

public:
  Timer() { reset(); }

  using Clock = std::chrono::steady_clock;
  using Duration = Clock::duration;

  void reset() { m_start = Clock::now(); }

  [[nodiscard]] Duration elapsed() const
  {
    return Clock::now() - m_start;
  }

private:
  Clock::time_point m_start {};
};

} // namespace Profiler
