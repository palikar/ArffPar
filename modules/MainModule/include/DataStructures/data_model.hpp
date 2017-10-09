//
// Created by stanislav on 10/9/17.
//

#pragma once

#include <boost/unordered/unordered_map.hpp>
#include <vector>


#include "DataStructures/variable.hpp"


namespace data_works
{
    class DataModel
    {
    public:
        DataModel(const std::string &name);

        DataModel(const DataModel &obj) = default;

        ~DataModel();

        void addVariable(const std::shared_ptr<Variable> &var);

    private:
        std::string name_;
        boost::unordered_map<std::string, std::shared_ptr<data_works::Variable>> variables_;

    };
}