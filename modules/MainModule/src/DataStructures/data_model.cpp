//data_modeol
// Created by stanislav on 10/10/17.
//


#include "DataStructures/data_model.hpp"


namespace data_works
{


    DataModel::DataModel(const std::string &name)
            : name_(name)
    {

    }


    DataModel::~DataModel()
    {}


    void DataModel::addVariable(const std::shared_ptr<Variable> &var)
    {
        this->variables_[var->getName()] = var;

    }

}