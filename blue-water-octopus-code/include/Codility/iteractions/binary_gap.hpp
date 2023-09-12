// Copyright 2023 Renzo Bruzzone
// __________________
// All Rights Reserved.
// NOTICE: All information contained herein is, and remains the property
// of Capra Robotics ApS. The intellectual and technical concepts contained
// herein are proprietary to Renzo Bruzzone ApS and may be covered by U.S.
// and Foreign Patents, patents in process, and are protected by trade secret
// or copyright law. Dissemination of this information or reproduction of this
// material is strictly forbidden unless prior written permission is obtained
// from Renzo Bruzzone.
//
// binary_gap.hpp

/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 

The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 

The number 20 has binary representation 10100 and contains one binary gap of length 1. 

The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.

Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>

namespace binary_gap
{
int solution_A(int N)
{
  std::bitset<32> binaryRepresentation(N);  // Assuming 32-bit integer

  auto binary_string = binaryRepresentation.to_string();

  std::cout << binary_string << std::endl;

  int counter, max_counter = 0;
  bool flag = false;
  std::for_each(
    binary_string.begin(), binary_string.end(),
    [&counter, &max_counter, &flag](char c) mutable -> void {
      if (c == '0' && flag) {
        counter++;
      }
      if (c == '1') {
        if (max_counter < counter & flag) {
          flag = false;
          max_counter = counter;
        };
        if (!flag) {
          flag = true;
          counter = 0;
        }
      }
    });
  return max_counter;
}

int solution_B(int N)
{
  std::bitset<32> binary_representation(N);

  std::string binary = binary_representation.to_string();

  int counter = 0;

  for (auto itr = binary.begin(); itr != binary.end(); itr++) {
    if (*itr == '1') {
      for (auto itr_0 = itr + 1; itr_0 != binary.end(); itr_0++) {
        if (*itr_0 == '1') {
          if ((std::abs(std::distance(itr, itr_0)) - 1) > counter) {
            counter = std::abs(std::distance(itr, itr_0)) - 1;
          }
          itr = itr_0;
        }
      }
    }
  }
  return counter;
}

}  // namespace binary_gap