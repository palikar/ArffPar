#pragma once

#include <vector>

#include "variable.hpp"

namespace data_works
{


  template<typename Type>
  class EnumVariable : public Variable
  {
  public:
    EnumVariable(const std::string &name):Variable(name)
      {




      };
   
    void addPossibleValue(const Type &value)
      {
        values_.push_back(value);
      };

    
    std::vector<Type>& getPossibleValues()
      {
        return this->values_;
      }


     virtual bool isValueAllowed(const std::string &val) const 
      {
        return true;
      };

  private:
    std::vector<Type> values_;

  };




}
