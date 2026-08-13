#pragma once

#include <chrono>

namespace Profiler
{

class Timer
{

public:
  // steady_clock is used because it is guaranteed to be monotonic
  using Clock = std::chrono::steady_clock;
  using Duration = Clock::duration;

  Timer();

  void reset();

  [[nodiscard]] Duration elapsed() const;

  template <typename ToDuration> [[nodiscard]] ToDuration elapsedAs() const
  {
    return std::chrono::duration_cast<ToDuration>(elapsed());
  }

private:
  Clock::time_point start_ {};
};

} // namespace Profiler
