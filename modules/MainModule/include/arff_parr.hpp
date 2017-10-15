//
// Created by stanislav on 10/7/17.
//

#pragma once


#include <string>
#include <settings.hpp>
#include <vector>
#include <DataStructures/example.hpp>

namespace arff_par
{
  class ArffParser
  {
  public:
    ArffParser();

    void init();

    void loadFromFile(const std::string &file,
                      std::shared_ptr<data_works::DataModel> &model,
                      std::vector<std::shared_ptr<data_works::Example> > &examples);

    void saveToFile(const std::string &file,  std::shared_ptr<data_works::DataModel> &model,
                    std::vector<std::shared_ptr<data_works::Example> > &examples);
  private:

    std::shared_ptr<Settings> settings;

  };



}
