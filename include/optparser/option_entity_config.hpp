#ifndef ASUKA1975_OPTPARSER_OPTION_ENTITY_CONFIG_HPP
#define ASUKA1975_OPTPARSER_OPTION_ENTITY_CONFIG_HPP

#include <memory>
#include <string>
#include <optional>

#include <sequence-analyzer/rule/rule.hpp>

#include "optparser/errors/unparsable_option_error.hpp"
#include "optparser/types/optvalue.hpp"
#include "sequence-analyzer/rule/rule_declare.hpp"
#include "types/optvalue/wrappers.hpp"


namespace asuka1975 {
    template <optvalue::Wrapper TWrapper>
    class OptionEntityConfig {
    public:
        OptionEntityConfig(const std::string& optionName, const std::string& description) : optionName(optionName), description(description) {
            
        }
        OptionEntityConfig(const std::string& optionName, const std::string& alias, const std::string& description) : optionName(optionName), description(description), alias(alias) {

        }
        OptionEntityConfig<TWrapper>& defaultValue(typename TWrapper::value_t value);
    private:
        std::string optionName;
        std::string description;
        std::optional<std::string> alias;
        std::optional<typename TWrapper::value_t> _defaultValue;
        std::unique_ptr<Rule<std::string, OptValue, UnparsableOptionError>> rule;
    };
}

#endif