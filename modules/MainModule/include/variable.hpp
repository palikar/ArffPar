//
// Created by stanislav on 10/7/17.
//

#pragma once

#include <string>
#include <limits>
#include <boost/unordered/unordered_map.hpp>
#include <boost/any.hpp>

class Variable
{
public:
    Variable(std::string &name);

    ~Variable();


    virtual bool isValueAllowed(boost::any val) const = 0;

    const std::string &getName() const;

private:
    std::string name_;
    boost::unordered_map<std::string, boost::any> params_;

};

