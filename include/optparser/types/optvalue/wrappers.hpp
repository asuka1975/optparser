#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_WRAPPERS_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_WRAPPERS_HPP

#include "defaults/integral_rule.hpp"
#include "defaults/floating_point_rule.hpp"

namespace asuka1975::optvalue {
    template <class T>
    concept Wrapper = requires {
        typename T::value_t;
        typename T::rule_t;
    };
    
    struct Char {
        using value_t = char;
        using rule_t = integral_rule<char>;
    };

    struct Short {
        using value_t = short;
        using rule_t = integral_rule<short>;
    };

    struct Int {
        using value_t = int;
        using rule_t = integral_rule<int>;
    };

    struct LongLong {
        using value_t = long long;
        using rule_t = integral_rule<long long>;
    };

    struct Float {
        using value_t = float;
        using rule_t = floating_point_rule<float>;
    };

    struct Double {
        using value_t = double;
        using rule_t = floating_point_rule<double>;
    };

    struct LongDouble {
        using value_t = long double;
        using rule_t = floating_point_rule<long double>;
    };
}

#endif