#include <map>
#include <unordered_map>
#include <string>
#include <limits>
#include <vector>
#include "timer/timer.h"

// compil g++ mapVSunorderedMap.cpp timer/timer.cpp

int main()
{

    const int MyConst = 900'000;
    std::vector<int> mainVec;
    for (int i = -MyConst; i <= MyConst; i++)
    {
        mainVec.push_back(i);
    }
    mainVec.shrink_to_fit();

    {
        std::map<int, std::string> treeMap;

        Timer t("main map ");
        for (const auto n : mainVec)
        {
            treeMap[n] = std::to_string(n);
        }

        for (const auto &n : mainVec)
        {
            std::string &val = treeMap[n];
            val += "1";
        }
    }

    {
        std::unordered_map<int, std::string> hashMap;

        Timer t("hash map ");
        for (const auto n : mainVec)
        {
            hashMap[n] = std::to_string(n);
        }

        for (const auto &n : mainVec)
        {
            std::string &val = hashMap[n];
            val += "1";
        }
    }

    return 0;
};