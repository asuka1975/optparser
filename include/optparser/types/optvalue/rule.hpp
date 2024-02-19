#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_RULE_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_RULE_HPP

#include <any>
#include <string>

namespace asuka1975::optvalue {
    struct Rule {
        virtual ~Rule() = default;
        virtual bool read(const std::string&) = 0;
        virtual std::any get() = 0;
    };
}

#endif