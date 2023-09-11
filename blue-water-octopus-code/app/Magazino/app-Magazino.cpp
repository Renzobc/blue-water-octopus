#include "Magazino/Magazino.hpp"

int main()
{
  // Create an example tree
  Node n(
    "root", {{"MagaZino", {{"I"}, {"Love"}, {"magazino"}}},
             {"Hello", {{"Hello", {{"Hello", {{"World"}}}}}}}});
  // Cout the solution
  std::cout << n.count_nodes_containing_string("test") << std::endl;
}

;