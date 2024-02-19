#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_DEFAULTS_INT_RULE_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_DEFAULTS_INT_RULE_HPP

#include "../rule.hpp"

namespace asuka1975::optvalue {
    class int_rule : public virtual Rule {
    public:
        bool read(const std::string&) override;
        std::any get() override;
    private:
        std::string value;
    };
}

#endif