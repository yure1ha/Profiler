#pragma once

#include "profiler/Profiler.h"
#include "profiler/Timer.h"

#include <string>

namespace Profiler
{

class ScopedTimer
{
public:
  explicit ScopedTimer(std::string_view name, Profiler& profiler);
  ~ScopedTimer();

  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer& operator=(const ScopedTimer&) = delete;

private:
  std::string name_ {};
  Profiler& profiler_;
  Timer timer_ {};
};

} // namespace Profiler
