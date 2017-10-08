//
// Created by stanislav on 10/8/17.
//

#pragma once

#include "variable.hpp"

class RealVariable : Variable
{

public:
    RealVariable(std::string &name,
                 double min = std::numeric_limits<double>::min(),
                 double max = std::numeric_limits<double>::max());

    ~IntegerVariable();

    bool isValueAllowed(boost::any val) const;

    double getMin() const;

    double getMax() const;

private:
};


