#ifndef ASUKA1975_OPTPARSER_ERRORS_UNPARSABLE_OPTION_ERROR_HPP
#define ASUKA1975_OPTPARSER_ERRORS_UNPARSABLE_OPTION_ERROR_HPP

#include <string>

namespace asuka1975 {
    struct UnparsableOptionError {
        const std::string message;
    };
}

#endif