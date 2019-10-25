#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <string>
#include <cstdlib>
#include <chrono>
#include <unordered_set>


class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
	, prefix_("")
    {
    }

    Timer(const std::string & s)
       : Timer()
   {
	   prefix_ = s;
   }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << prefix_ << "   " << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
    std::string prefix_;
};



inline void	onSet(int n) noexcept
{
	static std::unordered_set<int> mySet;
	
	if (!mySet.count(n))
	{
//		std::cout << n << std::endl;
		mySet.insert(n);
	}
}

inline void	onMass(int n) noexcept
{
	static bool mass[999'000'000];
	if (!mass[n])
	{
//		std::cerr << n << std::endl;
		mass[n] = true;
	}
}

inline void	onMassStl(int n) noexcept
{
	static std::array<bool, 999'000'000> massStl;
	if (!massStl[n])
	{
//		std::cerr << n << std::endl;
		massStl[n] = true;
	}
}


int main()
{
	const int numberCount = 999'999'999;
	std::vector<int> vec(numberCount);
	
	for (auto & num: vec)
	{
		num = std::rand() % 199'100'000;
	}

	{
		Timer t1 ("on Set");

		for (const auto & num: vec)
		{
			onSet(num);
		}
	}

	{
		Timer t1 ("on Mass");
		for (const auto & num: vec)
		{
			onMass(num);
		}

	}

	{
		Timer t1 ("on Mass stl");
		for (const auto & num: vec)
		{
			onMassStl(num);
		}

	}

	return 0;
}

