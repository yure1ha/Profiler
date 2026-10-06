#pragma once

#include "Profiler/ProfileEvents.h"

namespace Profiler {

class ISink {
  public:
    ISink() = default;
    virtual ~ISink() = default;

    ISink(const ISink&) = delete;
    ISink& operator=(const ISink&) = delete;

    ISink(ISink&&) noexcept = delete;
    ISink& operator=(ISink&&) noexcept = delete;

    virtual void write(const TimeSample& timeSample) = 0;
    virtual void flush() = 0;
};

} // namespace Profiler
