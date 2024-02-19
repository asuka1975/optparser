#ifndef ASUKA1975_OPTPARSER_TYPES_OPTVALUE_HPP
#define ASUKA1975_OPTPARSER_TYPES_OPTVALUE_HPP

#include <string>

namespace asuka1975 { 
    class OptValue {
    public:
        OptValue(std::string value);
        
    private:
        std::string value;
    };
}

#endif