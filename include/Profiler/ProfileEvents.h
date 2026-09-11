#pragma once

#include "Timer.h"

#include <cstdint>
#include <string_view>

namespace Profiler {

struct TimeSample {
    std::int32_t id {};
    Timer::Duration duration {};
    std::string_view name {"TIME"};
};

} // namespace Profiler
