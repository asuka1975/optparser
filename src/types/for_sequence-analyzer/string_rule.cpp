#include "optparser/types/for_sequence-analyzer/string_rule.hpp"
#include "optparser/errors/unparsable_option_error.hpp"
#include "optparser/types/optkey.hpp"
#include "optparser/types/optvalue.hpp"
#include "sequence-analyzer/rule/read_status.hpp"
#include <optional>
#include <sstream>

using namespace std::string_literals;

asuka1975::StringRule::StringRule(const std::string& key, std::optional<char> alias) : key(key), alias(alias) {

}


asuka1975::Result<asuka1975::UnparsableOptionError, std::list<std::pair<asuka1975::OptKey, asuka1975::OptValue>>> asuka1975::StringRule::create() const {
    if(value.has_value()) {
        return asuka1975::Result<asuka1975::UnparsableOptionError, std::list<std::pair<asuka1975::OptKey, asuka1975::OptValue>>> {
            std::list<std::pair<asuka1975::OptKey, asuka1975::OptValue>> {
                std::pair<asuka1975::OptKey, asuka1975::OptValue> {
                    key, 
                    OptValue {
                        value.value(),
                        value.value()
                    }
                }
            }
        };
    } else {
        return asuka1975::Result<asuka1975::UnparsableOptionError, std::list<std::pair<asuka1975::OptKey, asuka1975::OptValue>>> {
            getError()
        };
    }
}


asuka1975::UnparsableOptionError asuka1975::StringRule::getError() const noexcept {
    std::ostringstream sout;
    sout << "Unknown option";
    return UnparsableOptionError { sout.str() };
}


asuka1975::ReadStatus asuka1975::StringRule::readInternal(const std::string& item) {
    if(!keyRead) {
        if("--" + key == item) {
            keyRead = true;
            return ReadStatus::Continue;
        } else if(alias.has_value() && "-"s + alias.value() == item) {
            keyRead = true;
            return ReadStatus::Continue;
        }
    } else {
        if(item.size() > 0 && item[0] == '-') {
            return ReadStatus::Reject;
        }
        value = item;
        return ReadStatus::Complete;
    }

    return ReadStatus::Reject;
}

std::size_t asuka1975::StringRule::getSeekBackCountInternal() const noexcept {
    return 0;
}

void asuka1975::StringRule::resetInternal() {

}
