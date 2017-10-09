//
// Created by stanislav on 10/9/17.
//

#include "DataStructures/real_variable.hpp"

#include <boost/lexical_cast.hpp>


namespace data_works{
    RealVariable::RealVariable(const std::string &name, double min, double max)
            : Variable(name),
              min_(min),
              max_(max)
    {}

    RealVariable::~RealVariable()
    {}


    bool RealVariable::isValueAllowed(const std::string &val) const
    {

        try
        {
            int value = boost::lexical_cast<double>(val);
        } catch(const boost::bad_lexical_cast &ex)
        {
            return false;
        }
    }

    double RealVariable::getMax() const
    {
        return this->max_;
    }

    double RealVariable::getMin() const
    {
        return this->min_;
    }
}