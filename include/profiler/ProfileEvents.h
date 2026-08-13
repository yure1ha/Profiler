#pragma once

#include "profiler/Timer.h"

#include <string_view>

namespace Profiler
{

struct ProfileEvent
{
  std::string_view name {};
};

struct TimeSample
{
  ProfileEvent metadata {};
  Timer::Duration duration {};
};

} // namespace Profiler
