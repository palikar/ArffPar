//
// Created by stanislav on 10/9/17.
//

#pragma once

#include <boost/unordered/unordered_map.hpp>
#include <vector>

#include "integer_variable.hpp"
#include "data_model.hpp"

namespace data_works
{
  class Example
  {
  public:
    Example(const std::shared_ptr<DataModel> &model);

    Example(Example &obj) = default;
    
    const std::string &getValue(const std::string &name)const;

    template<typename Type>
    const std::string &getValue(const std::string &name)const;
    
    void setValue(const std::string &variable, const std::string &value);

    void setValues(const std::vector<std::string> &vals);

  private:
    std::shared_ptr<data_works::DataModel> model_;
    boost::unordered_map<std::string, std::string> values_;
  };



   template<typename Type>
   const std::string &Example::getValue(const std::string &name)const
   {
     //do lexical cast with boost



   }
}



