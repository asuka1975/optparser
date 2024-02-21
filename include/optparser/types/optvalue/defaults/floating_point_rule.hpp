#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_DEFAULTS_FLOATING_POINT_RULE_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_DEFAULTS_FLOATING_POINT_RULE_HPP

#include <charconv>
#include <concepts>

#include <result/result.hpp>

#include "../rule.hpp"
#include "../invalid_value.hpp"

namespace asuka1975::optvalue {
    template <std::floating_point TFloat>
    class floating_point_rule : public virtual Rule {
    public:
        bool read(const std::string&) override {
            TFloat converted;
            auto [ptr, ec] = std::from_chars(value.c_str(), value.c_str() + value.length(), converted);

            bool canReaded = ptr == (value.c_str() + value.length());
            if(canReaded) {
                this->value = Result<InvalidValue, TFloat> { converted };
            }
    
            return canReaded;
        }

        std::any get() override {
            return value;
        }
    private:
        Result<InvalidValue, TFloat> value = Result<InvalidValue, TFloat> { InvalidValue {} };
    };
}

#endif