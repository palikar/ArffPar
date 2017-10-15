//
// Created by stanislav on 10/8/17.
//

#pragma  once

#include "variable.hpp"


namespace data_works
{
    class IntegerVariable : public Variable
    {


    public:
        IntegerVariable(const std::string &name,
                        int min = std::numeric_limits<int>::min(),
                        int max = std::numeric_limits<int>::max());



        ~IntegerVariable();

        bool isValueAllowed(const std::string &val) const;

        int getMin() const;

        int getMax() const;

    private:
        int max_;
        int min_;
    };
}

