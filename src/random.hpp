#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

inline namespace RANDOM
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

    // return: [0, ResultType::max]
    ResultType operator()()
        {return mEngine();}
    // return: [0, max)
    ResultType operator()(ResultType max)
        {return mEngine() % max;}
    // return: [min, max)
    ResultType operator()(ResultType min, ResultType max)
        {return mEngine() % (max - min) + min;}

    // return: [0, T::max]
    template<class T = ResultType>
    T random()
        {return static_cast<T>(mEngine());}
    // return: [0, max)
    template<class T = ResultType>
    T random(T max)
        {return random<T>() % max;}
    // return: [min, max)
    template<class T = ResultType>
    T random(T min, T max)
        {return random<T>() % (max - min) + min;}

    // return: [0.0, 1.0]
    template<class FloatingType = double>
    FloatingType floating()
        {return static_cast<FloatingType>(random()) / static_cast<FloatingType>(Engine::max());}

private:
    Engine mEngine;
};

// global object
inline extern Random<> RANDOM;

}

#endif