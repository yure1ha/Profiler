#include "profiler/Timer.h"

namespace Profiler
{

Timer::Timer() { reset(); }

void Timer::reset() { start_ = Clock::now(); }

Timer::Duration Timer::elapsed() const { return Clock::now() - start_; }

} // namespace Profiler
