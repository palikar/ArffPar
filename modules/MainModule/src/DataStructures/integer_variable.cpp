//
// Created by stanislav on 10/9/17.
//

#include "DataStructures/integer_variable.hpp"
#include <boost/lexical_cast.hpp>


namespace data_works{
    IntegerVariable::IntegerVariable(const std::string &name, int min, int max) :
            Variable(name),
            min_(min),
            max_(max)
    {


    }

    IntegerVariable::~IntegerVariable()
    {

    }


    bool IntegerVariable::isValueAllowed(const std::string &val) const
    {
        try
        {
            int value = boost::lexical_cast<int>(val);
            return this->min_ <=value && value<= this->max_;
        } catch(boost::bad_lexical_cast &ex)
        {
            return false;
        };


    }

    int IntegerVariable::getMax() const
    {
        return this->max_;
    }

    int IntegerVariable::getMin() const
    {
        return this->min_;
    }
}
