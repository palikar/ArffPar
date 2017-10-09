//
// Created by stanislav on 10/9/17.
//


#include "DataStructures/text_variable.hpp"


namespace data_works
{

    TextVariable::TextVariable(const std::string &name, int max_length)
            : Variable(name),
              max_length_(max_length)
    {


    }

    TextVariable::~TextVariable()
    {

    }


    bool TextVariable::isValueAllowed(const std::string &val) const
    {
        return true;
    }

    int TextVariable::getMaxLength()
    {
        return this->max_length_;
    }
}