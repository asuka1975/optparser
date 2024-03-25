#ifndef ASUKA1975_OPTPARSER_TYPES_FOR_SEQUENCE_ANALYZER_STRING_RULE_HPP
#define ASUKA1975_OPTPARSER_TYPES_FOR_SEQUENCE_ANALYZER_STRING_RULE_HPP

#include <list>
#include <optional>

#include "optparser/errors/unparsable_option_error.hpp"
#include "optparser/types/optkey.hpp"
#include "optparser/types/optvalue.hpp"

#include "sequence-analyzer/rule/rule.hpp"

namespace asuka1975 {
    class StringRule : public virtual Rule<std::string, std::list<std::pair<OptKey, OptValue>>, UnparsableOptionError> {
    public:
        StringRule(const std::string& key, const std::optional<char> alias = std::nullopt);
        asuka1975::Result<UnparsableOptionError, std::list<std::pair<OptKey, OptValue>>> create() const override;
        UnparsableOptionError getError() const noexcept override;
    protected:
        asuka1975::ReadStatus readInternal(const std::string& item) override;
        std::size_t getSeekBackCountInternal() const noexcept override;
        void resetInternal() override;
    private:
        std::string key;
        std::optional<std::string> value = std::nullopt;
        std::optional<char> alias;
        bool keyRead = false;
    };
}

#endif