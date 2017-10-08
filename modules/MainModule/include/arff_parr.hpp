//
// Created by stanislav on 10/7/17.
//

#pragma once


#include <string>
#include <settings.hpp>

namespace ArffPar
{
    Settings settings;


    void loadFromFile(std::string file, void *obj);

    void sabeToFile(std::string file, void *obj);


}
