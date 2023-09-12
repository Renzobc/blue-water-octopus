/**
 * Copyright 2023 Capra Robotics ApS
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
 * cyclic_rotation.hpp
 */
/*
An array A consisting of N integers is given. 

Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. 

For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);
 
that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
namespace cyclic_rotation
{
std::vector<int> solution(std::vector<int> & A, int K)
{
  if (K >= A.size()) {
    K = K % A.size();
  }
  if (A.size() != 0 && K != 0) {
    std::rotate(A.rbegin(), A.rbegin() + K, A.rend());
  }
  return A;
}

std::vector<int> solution_B(std::vector<int> & A, int K)
{
  if (K >= A.size()) {
    K = K % A.size();
  }
  std::vector<int> B(A.size());
  if (A.size() != 0 && K != 0) {
    auto b_itr = B.begin() + K;
    for (auto a_itr = A.begin(); a_itr != A.end(); a_itr++) {
      *b_itr = *a_itr;
      b_itr++;
      if (b_itr == B.end()) {
        b_itr = B.begin();
      }
    }
    return B;
  }
  return A;
}
}  // namespace cyclic_rotation