#include "Profiler/ConsoleSink.h"
#include "Profiler/Profiler.h"
#include "Profiler/ScopedTimer.h"

#include <chrono>
#include <memory>
#include <thread>

int main() {
    Profiler::Profiler profiler;
    profiler.addSink(std::make_unique<Profiler::ConsoleSink>());

    {
        Profiler::ScopedTimer timer {1, profiler};
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    profiler.flushSinks();

    return 0;
}
