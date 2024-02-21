#ifndef ASUKA1975_OPTPARSER_ERRORS_INVALID_TYPE_ERROR_HPP
#define ASUKA1975_OPTPARSER_ERRORS_INVALID_TYPE_ERROR_HPP

#include <typeinfo>
namespace asuka1975 {
    struct InvalidTypeError {
        const std::type_info& expected;
        const std::type_info& actual;
    };
}

#endif