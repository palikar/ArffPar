//
// Created by stanislav on 10/9/17.
//
#pragma once

#include <string>


namespace toole_works
{


    template<typename T>
    bool isOfType(const std::string &str);

    bool isInteger(const std::string &str);

    bool isDouble(const std::string &str);

    bool isFloat(const std::string &str);


}