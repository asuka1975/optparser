#ifndef ASUKA1975_OPTPARSER_OPTPARSER_CONFIG_HPP
#define ASUKA1975_OPTPARSER_OPTPARSER_CONFIG_HPP

#include <string>

#include "types/optvalue/wrappers.hpp"
#include "option_entity_config.hpp"

namespace asuka1975 {
    class OptParserConfig {
    public:
        template <optvalue::Wrapper TWrapper>
        OptParserConfig& option(const std::string& optionName, const std::string& description) {
            return *this;
        }

        template <optvalue::Wrapper TWrapper>
        OptParserConfig& option(const std::string& optionName, const std::string& alias, const std::string& description) {
            return *this;
        }

    private:

    };
}

#endif