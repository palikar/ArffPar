//
// Created by stanislav on 10/10/17.
//

#include <iostream>
#include <boost/unordered/unordered_map.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>
#include <fstream>
#include <sstream>


#include <arff_parr.hpp>
#include <DataStructures/data_model.hpp>
#include <DataStructures/integer_variable.hpp>
#include <DataStructures/real_variable.hpp>
#include <DataStructures/text_variable.hpp>
#include <DataStructures/enum_variable.hpp>


namespace arff_par
{

  void ArffParser::init()
  {
    settings = std::make_shared<Settings>();

  }

  ArffParser::ArffParser()
  {
  }


  void ArffParser::loadFromFile(const std::string &file,
                                std::shared_ptr<data_works::DataModel> &model,
                                std::vector<std::shared_ptr<data_works::Example> > &examples)
  {



    std::ifstream infile(file);
    if(!infile)
    {
      std::cout << "Error! Could not open file at the given directory" << '\n';\
      exit(1);
    }
    std::vector<std::string> example_parts;
    bool data = false;
    std::string line;
    while(std::getline(infile, line))
    {

      if(line[0] == '%' || boost::algorithm::trim_all_copy(line).compare("") == 0)
      {
        continue;
      }
      else if(data)
      {
        example_parts.clear();
        boost::split(example_parts, line, boost::is_any_of(","));
        std::cout << "Generating new exmaple of the model "<< '\n';
        std::shared_ptr<data_works::Example> new_example = std::make_shared<data_works::Example>(model);

        new_example->setValues(example_parts);
        examples.push_back(new_example);

      }
      else if(line[0] == '@')
      {
        if(boost::starts_with(line, settings->getRelationTag()))
        {

          std::string model_name = line.substr(settings->getRelationTag().size());
          boost::algorithm::trim(model_name);
          model->setName(model_name);
          std::cout << "The new model is named " << model_name<< '\n';
          continue;
        }
        else if(boost::starts_with(line, settings->getAtribute_tag_()))
        {
          std::string name = line.substr(settings->getAtribute_tag_().size());
          int num = name.find(settings->getNumeric_tag_());
          if(num != -1)
          {
            std::string attr_name = name.substr(0, num);
            boost::algorithm::erase_all(attr_name, " ");
            boost::algorithm::erase_all(attr_name, "\t");
            auto new_var = std::make_shared<data_works::IntegerVariable>(attr_name);
            new_var->setType(data_works::INTEGER);
            model->addVariable(new_var);
            std::cout << "Adding a new integer variable to the model: " << attr_name << '\n';
            continue;
          }
          num = name.find(settings->getReal_tag_());
          if(num != -1)
          {
            std::string attr_name = name.substr(0, num);
            boost::algorithm::erase_all(attr_name, " ");
            boost::algorithm::erase_all(attr_name, "\t");
            auto new_var = std::make_shared<data_works::IntegerVariable>(attr_name);
            new_var->setType(data_works::REAL);
            model->addVariable(new_var);
            std::cout << "Adding a new real variable to the model: " << attr_name << '\n';
            continue;
          }


          boost::algorithm::erase_all(name, " ");
          boost::algorithm::erase_all(name, "\t");
          boost::algorithm::erase_all(name, "}");
          std::string attr_name = name.substr(0, name.find("{"));


          std::shared_ptr<data_works::EnumVariable<std::string >> new_variable
            = std::make_shared<data_works::EnumVariable<std::string >>(attr_name);


          const std::string rest = name.substr(name.find("{") + 1);
          std::vector<std::string> attr_parts;
          boost::split(attr_parts, rest, boost::is_any_of(","));
          for(auto it : attr_parts)
          {
            new_variable->addPossibleValue(it);
          }
          new_variable->setType(data_works::ENUM);
          model->addVariable(new_variable);
          std::cout << "Adding a new enum variable to the model: " << attr_name << '\n';
        }
        if(boost::starts_with(line, settings->getData_tag_()))
        {
          data = true;
        }
      }

    }
    infile.close();


  }


  void ArffParser::saveToFile(const std::string &file,
                              std::shared_ptr<data_works::DataModel> &model,
                              std::vector<std::shared_ptr<data_works::Example> > &examples)
  {


    std::stringstream string_stream;

    string_stream << settings->getRelationTag() << " " << model->getName() << '\n';
    for(auto it: model->getVariables())
    {

      switch(it->getType())
      {
      case data_works::INTEGER:
        string_stream << settings->getAtribute_tag_() << ' ' << it->getName() << ' ' << "Numeric" << '\n';
        break;
      case data_works::REAL:
        string_stream << settings->getAtribute_tag_() << ' ' << it->getName() << ' ' << "Real" << '\n';
        break;
      case data_works::ENUM:

        data_works::EnumVariable<std::string>* var
          = (data_works::EnumVariable<std::string>*)(it.get());
        if(var != nullptr)
        {
          string_stream << settings->getAtribute_tag_() << ' ' << it->getName() << ' ' << '{';

          for (auto val = var->getPossibleValues().begin(); val != var->getPossibleValues().end(); ++val) {
            string_stream << *val;
            if(val != var->getPossibleValues().end() -1)
            {
              string_stream << ',';
            }
          }
          string_stream << "}\n";

          break;
        }

      }

    }

    string_stream << settings->getData_tag_();
    for(auto it: examples)
    {
      for (auto var = model->getVariables().begin(); var != model->getVariables().end(); ++var) {
        string_stream << it->getValue((*var)->getName());
        if(var != model->getVariables().end() - 1)
        {
          string_stream << ',';
        }
      }
      string_stream << '\n';

    }


    std::ofstream stream;
    stream.open (file);
    if(!stream)
    {
      std::cout << "Erro laoding file" << '\n';
      exit(1);
    }
    stream << string_stream.str();
    stream.close();



  }


}
