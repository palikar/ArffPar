#include <iostream>
#include <boost/unordered/unordered_map.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <sstream>

int main()
{

   std::cout << "Application running!" <<'\n';


   std::ifstream infile("file.txt");
   if(!infile){
      std::cout << "Eroor!" << '\n';
   }


   std::string relation_tag = "@relation";
   std::string atribute_tag = "@attribute";
   std::string data_tag = "@data";
   std::string numeric_tag = "numeric";
   std::string real_tag = "real";
   bool data = false;
   std::string line;


   while(std::getline(infile, line))
   {
      if(line[0] == '%') {
         continue;
      }
      else if(data){
         std::vector<std::string> parts;
         boost::split(parts, line,  boost::is_any_of(","));
         for(auto it: parts){
            std::cout << it << '\n';
         }
         std::cout << "---------------" << '\n';

      }
      else if(line[0] == '@')
      {

         if(boost::starts_with(line, relation_tag)){
            std::string name = line.substr(relation_tag.size());
            boost::algorithm::trim(name);
            std::cout << name << '\n';
         }

         if(boost::starts_with(line, atribute_tag)){
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
            for(auto it: parts)
            {
               std::cout << it << '\n';
            }
            std::cout << "-----------------" << '\n';
         }
         if(boost::starts_with(line, data_tag)){
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



	return 0;
}

