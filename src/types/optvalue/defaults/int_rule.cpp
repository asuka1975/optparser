#include "optparser/types/optvalue/defaults/int_rule.hpp"
#include <string>


bool asuka1975::optvalue::int_rule::read(const std::string&) {
    return false;
}

std::any asuka1975::optvalue::int_rule::get() {
    return std::stoi(value);
}