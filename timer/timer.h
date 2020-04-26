#include <stdlib.h> /* srand, rand */
#include <chrono>   /* for timer */
#include <string>

class Timer final
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;

public:
    Timer();
    Timer(const std::string &st);

    ~Timer();

private:
    const clock_t::time_point start_;
    const std::string prefix_;
};