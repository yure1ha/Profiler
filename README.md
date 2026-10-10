# Profiler

A simple C++ profiling tool, currently consisting of an RAII (Resource Acquisition Is Initialization) scoped timer
using std::chrono::steady_clock to guarantee monotonic timing.

## Architecture

The program collects profiling data as different sample types and dispatches them to an interface to handle the final
formatting:

`[ScopedTimer] --> [TimeSample] --> [Profiler] --> [ConsoleSink]`
