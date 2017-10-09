//
// Created by stanislav on 10/10/17.
//
#include "DataStructures/example.hpp"

namespace data_works
{

    Example::Example(const std::shared_ptr<DataModel> &model)
            : model_(model)
    {}


    void Example::setValue(const std::string &variable, const std::string &value)
    {
        this->values_[variable] = value;
    }


}