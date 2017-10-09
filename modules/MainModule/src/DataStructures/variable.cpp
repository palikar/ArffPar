//
// Created by stanislav on 10/7/17.
//

#include "DataStructures/variable.hpp"


namespace data_works
{
    Variable::Variable(const std::string &name) : name_(name)
    {}

    Variable::Variable(const Variable &obj)
            : name_(obj.getName())
    {
    }

    Variable::~Variable()
    {}

    const std::string &Variable::getName() const
    {

        return this->name_;
    }
}