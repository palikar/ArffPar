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
    this->variables_vec_.emplace_back(var);
    this->variables_[var->getName()] = var;

  }

  void DataModel::setName(const std::string &name)
  {
    this->name_ = name;
  }

  const std::vector<std::shared_ptr<data_works::Variable>> &DataModel::getVariables() const
  {
    return this->variables_vec_;
  };

  const std::string &DataModel::getName() const
  {
    return this->name_;

  }

}
