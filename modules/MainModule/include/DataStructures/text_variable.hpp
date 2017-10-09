//
// Created by stanislav on 10/9/17.
//


#pragma once

#include "variable.hpp"


namespace data_works{
    class TextVariable : Variable
    {
    public:
        TextVariable(const std::string &name, int max_length );

        TextVariable(const TextVariable &obj);

        ~TextVariable();

        bool isValueAllowed(const std::string &str)const;

        int getMaxLength();

    private:
        int max_length_;
    };
}