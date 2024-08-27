/**
 * Copyright 2024 Capra Robotics ApS
 * __________________
 * All Rights Reserved.
 * NOTICE: All information contained herein is, and remains the property
 * of Capra Robotics ApS. The intellectual and technical concepts contained
 * herein are proprietary to Capra Robotics ApS and may be covered by U.S.
 * and Foreign Patents, patents in process, and are protected by trade secret
 * or copyright law. Dissemination of this information or reproduction of this
 * material is strictly forbidden unless prior written permission is obtained
 * from Capra Robotics ApS.
 * 
 * iterator.cpp
 */

#include "advanced_concepts/iterator.hpp"

#include <forward_list>
#include <set>
#include <vector>

int main_iterator()
{
  // Input stream iterator
  double double_1, double_2 = 0;
  std::istream_iterator<double> eos;
  std::istream_iterator<double> iit(std::cin);

  if (iit == eos) {
    return 0;
  } else {
    double_1 = *iit++;  // incrementing the input iterator transforms it from eos to std::cin
  }

  if (iit == eos) {
    return 0;
  } else {
    double_2 = *iit;  // stop istreamiterator so that it stays in "eos"
  }

  std::cin.clear();

  std::cout << double_1 << "---" << double_2 << std::endl;

  // output stream iterator

  std::ostringstream oss;
  std::ostream_iterator<int> oit(oss, " - ");

  for (int index : {1, 5, 6, 9}) {
    // *oit++ = index;
    ++*oit = index;
  }

  std::cout << oss.str() << std::endl;
  oss.clear();

  // forward iterator
  std::forward_list<int> forward_list{8, 9, 5, 6};
  std::forward_list<int>::iterator
    it_forward_list;  // uses a forward iterator. it can only increment
  for (it_forward_list = forward_list.begin(); it_forward_list != forward_list.end();
       ++it_forward_list) {
    ++*oit = *it_forward_list;
    // --it_forward_list;
  }

  std::cout << oss.str() << std::endl;

  // bidirectional iterator

  std::set<int> set_one{80, 90, 100, 500, 100};

  std::set<int>::iterator it_set_one;  // Bidirectional iterator

  for (it_set_one = set_one.end(); it_set_one != set_one.begin();) {
    ++*oit = *--it_set_one;
  }

  std::cout << oss.str() << std::endl;

  // Random access iterator
  // Access any element at any position in the container. Offers all the functionality of a c pointer
  std::vector<int> vector_one{8, 9, 50, 60, 75, 25, 63};
  std::vector<int>::iterator it_vector_one = vector_one.begin();

  *++oit = *(it_vector_one + 5);  // evaluates to 25
  std::cout << oss.str() << std::endl;

  it_vector_one = vector_one.end();
  *++oit = *(it_vector_one - 2);  // evaluates to 25
  std::cout << oss.str() << std::endl;
}