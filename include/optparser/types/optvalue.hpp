#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_HPP

#include "optparser/errors/invalid_type_error.hpp"
#include "result/result.hpp"
#include <any>
#include <concepts>
#include <string>

namespace asuka1975 { 
    template <class T, class U>
    concept differ_from = !std::is_same_v<T, U>;

    class OptValue {
    public:
        OptValue(std::string value, std::any convertedValue);
        template <class T>
            requires differ_from<T, std::string>
        T get() {
            return value;
        }

        template <class T>
            requires std::same_as<T, std::string>
        Result<InvalidTypeError, T> get() {
            try {
                return Result<InvalidTypeError, T> { std::any_cast<T>(convertedValue) };
            } catch(std::bad_any_cast) {
                return Result<InvalidTypeError, T> { InvalidTypeError { convertedValue.type(), typeid(T) } };
            }
        }
        
    private:
        std::string value;
        std::any convertedValue;
    };
}

#endif