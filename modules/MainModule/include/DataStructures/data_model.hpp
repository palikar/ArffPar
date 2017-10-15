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

    void setName(const std::string &name);

    const std::string &getName() const;

    const std::vector<std::shared_ptr<data_works::Variable>> &getVariables()const;
  private:
    std::string name_;
    std::vector<std::shared_ptr<data_works::Variable>> variables_vec_;
    boost::unordered_map<std::string, std::shared_ptr<data_works::Variable>> variables_;

  };
}
