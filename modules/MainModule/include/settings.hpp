//
// Created by stanislav on 10/7/17.
//


#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>


namespace ArffPar

{
    typedef boost::property_tree::ptree tree;

    struct Settings
    {
    public:
        void loadFromFile(tree ptree);

        const inline std::string &getRelation_tag_() const
        {
            return relation_tag_;
        }

        const inline std::string &getAtribute_tag_() const
        {
            return atribute_tag_;
        }

        const inline std::string &getData_tag_() const
        {
            return data_tag_;
        }

        const inline std::string &getNumeric_tag_() const
        {
            return numeric_tag_;
        }

        const inline std::string &getReal_tag_() const
        {
            return real_tag_;
        }

    private:
        std::string relation_tag_ = "@relation";
        std::string atribute_tag_ = "@attribute";
        std::string data_tag_ = "@data";
        std::string numeric_tag_ = "numeric";
        std::string real_tag_ = "real";
    };
}