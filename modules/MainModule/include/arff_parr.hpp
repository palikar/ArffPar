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
    Settings settings;


    void loadFromFile(std::string file, data_works::DataModel *model,
                      std::vector<std::shared_ptr<data_works::Example> > examples);

    void sabeToFile(std::string file, void *obj);


}
