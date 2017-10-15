#include <iostream>


#include <vector>

#include <DataStructures/variable.hpp>
#include <DataStructures/integer_variable.hpp>
#include <DataStructures/example.hpp>
#include "arff_parr.hpp"
#include "tools.hpp"

int main(int argc, char *argv[])
{
  

  
  arff_par::ArffParser parser;
  parser.init();
  std::shared_ptr<data_works::DataModel> new_model = std::make_shared<data_works::DataModel>("");
  std::vector<std::shared_ptr<data_works::Example>> example_vector;

  parser.loadFromFile(argv[1], new_model, example_vector);

  parser.saveToFile(argv[2], new_model, example_vector);







  return 0;
}
