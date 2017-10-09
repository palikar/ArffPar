//
// Created by stanislav on 10/8/17.
//

#pragma once

#include "variable.hpp"

namespace data_works{
    class RealVariable : Variable
    {

    public:
        RealVariable(const std::string &name,
                     double min = std::numeric_limits<double>::min(),
                     double max = std::numeric_limits<double>::max());

        ~RealVariable();

        bool isValueAllowed(const std::string &val) const;

        double getMin() const;

        double getMax() const;

    private:
        double min_;
        double max_;
    };

}

