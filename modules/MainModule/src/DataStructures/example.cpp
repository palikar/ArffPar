//
// Created by stanislav on 10/10/17.
//
#include "DataStructures/example.hpp"

#include <iostream>

namespace data_works
{

  Example::Example(const std::shared_ptr<DataModel> &model)
    : model_(model)
  {}


  void Example::setValue(const std::string &variable, const std::string &value)
  {
    this->values_[variable] = value;
  }

  void Example::setValues(const std::vector<std::string> &vals)
  {
      
    int index = 0;
    for(auto it: this->model_->getVariables())
    {
      this->setValue(it->getName(), vals[index++]);
    }
  }


  const std::string &Example::getValue(const std::string &name)const
   {
     return this->values_.at(name);

   }


}
