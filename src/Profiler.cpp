#include "Profiler/Profiler.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

namespace Profiler {

void Profiler::addSink(std::unique_ptr<ISink> sink) {
    m_sinks.push_back(std::move(sink));
}

void Profiler::flushSinks() const {
    for (const auto& sink : m_sinks) {
        sink->flush();
    }
}

void Profiler::record(const TimeSample& timeSample) const {
    for (const auto& sink : m_sinks) {
        sink->write(timeSample);
    }
}

} // namespace Profiler
