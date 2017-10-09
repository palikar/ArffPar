//
// Created by stanislav on 10/10/17.
//

#pragma once

#include <iostream>
#include <boost/unordered/unordered_map.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>
#include <fstream>

#include <arff_parr.hpp>
#include <DataStructures/data_model.hpp>

namespace arff_par
{


    void loadFromFile(const std::string &file,
                      std::vector<std::shared_ptr<data_works::Example> > examples)
    {
        std::shared_ptr<data_works::DataModel> model = std::make_shared<data_works::DataModel>();
        std::ifstream infile(file);
        if(!infile)
        {
            std::cout << "Error! COuld not open file at the given directory" << '\n';
        }
        std::vector<std::string> example_parts;
        bool data = false;
        std::string line;
        while(std::getline(infile, line))
        {

            if(line[0] == '%')
            {
                continue;
            } else if(data)
            {
                example_parts.clear();
                boost::split(example_parts, line, boost::is_any_of(","));
                std::shared_ptr<data_works::Example> newEx = std::make_shared<data_works::Example>(model);
                newEx->setValues(example_parts);
                examples.push_back(newEx);
            } else if(line[0] == '@')
            {
                if(boost::starts_with(line, arff_par::settings.getRelationTag()))
                {
                    std::string model_name = line.substr(relation_tag.size());
                    boost::algorithm::trim(model_name);
                    //model->setName(model_name);
                    continue;

                }
                if(boost::starts_with(line, atribute_tag))
                {
                    std::string name = line.substr(atribute_tag.size());
                    int num = name.find(numeric_tag);
                    if(num != -1)
                    {
                        std::string attr_name = name.substr(0, num);
                        boost::algorithm::erase_all(attr_name, " ");
                        boost::algorithm::erase_all(attr_name, "\t");
                        std::cout << attr_name << '\n';
                        std::cout << "-----------------" << '\n';
                        continue;
                    }
                    num = name.find(real_tag);
                    if(num != -1)
                    {
                        std::string attr_name = name.substr(0, num);
                        boost::algorithm::erase_all(attr_name, " ");
                        boost::algorithm::erase_all(attr_name, "\t");
                        std::cout << attr_name << '\n';
                        std::cout << "-----------------" << '\n';
                        continue;
                    }
                    boost::algorithm::erase_all(name, " ");
                    boost::algorithm::erase_all(name, "\t");
                    boost::algorithm::erase_all(name, "}");
                    std::string atr_name = name.substr(0, name.find("{"));
                    std::cout << atr_name << '\n';
                    std::string rest = name.substr(name.find("{") + 1);
                    std::vector<std::string> parts;
                    boost::split(parts, rest, boost::is_any_of(","));
                    for(auto it : parts)
                    {
                        std::cout << it << '\n';
                    }
                    std::cout << "-----------------" << '\n';
                }
                if(boost::starts_with(line, data_tag))
                {
                    std::cout << "-----------------" << '\n';
                    data = true;
                    continue;
                }
            }
            std::istringstream iss(line);
            int a, b;
            //std::cout << line << '\n';
        }
        infile.close();


    }


}