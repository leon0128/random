#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

namespace RANDOM
{

template<class E = std::mt19937_64
    , class S = std::random_device>
class Random
{
public:
    using Engine = E;
    using Seed = S;
    using ResultType = typename Engine::result_type;

    Random()
        : mEngine(S()()){}

    ResultType operator()()
        {return mEngine();}
    ResultType operator()(ResultType max)
        {return mEngine() % max;}
    ResultType operator()(ResultType min, ResultType max)
        {return mEngine() % (max - min) + min;}

    template<class T = ResultType>
    T random()
        {return static_cast<T>(mEngine());}
    template<class T = ResultType>
    T random(T max)
        {return random<T>() % max;}
    template<class T = ResultType>
    T random(T min, T max)
        {return random<T>() % (max - min) + min;}

    template<class FloatingType = double>
    FloatingType floating()
        {return static_cast<FloatingType>(random()) / static_cast<FloatingType>(Engine::max());}

private:
    Engine mEngine;
};

}

#endif