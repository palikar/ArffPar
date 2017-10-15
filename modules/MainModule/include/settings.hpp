//
// Created by stanislav on 10/7/17.
//


#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>



namespace arff_par

{


  struct Settings
  {
  private:
    typedef boost::property_tree::ptree tree;
  public:
    void loadFromFile(tree ptree);

    Settings(){
      relation_tag_ = "@relation";
      atribute_tag_ = "@attribute";
      data_tag_ = "@data";
      numeric_tag_ = "numeric";
      real_tag_ = "real";

    }

    const inline std::string &getRelationTag() const
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

    std::string relation_tag_;
    std::string atribute_tag_;
    std::string data_tag_;
    std::string numeric_tag_;
    std::string real_tag_ ;
  };
}
