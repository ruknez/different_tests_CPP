#include "timer.h"
#include <iostream>

Timer::Timer()
    :start_(clock_t::now())
{
}

Timer::Timer(const std::string &st)
    : start_(clock_t::now()), prefix_(st)
{
}

Timer::~Timer()
{
    const auto finish = clock_t::now();
    const auto us =
        std::chrono::duration_cast<microseconds>(finish - start_).count();
    std::cout << prefix_ << us << " us" << std::endl;
}