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
 * frog_river_one.hpp
 */
/*
A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank 

(position X+1). Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves.

A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river. 

The frog can cross only when leaves appear at every position across the river from 1 to X 

(that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). 

You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return −1.

For example, given X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].

*/
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <vector>

namespace counting_elements
{

int solution(int X, std::vector<int> & A)
{
  std::set<int> bridge;

  int total_sum = X * (X + 1) * 0.5;

  for (auto itr = A.begin(); itr != A.end(); itr++) {
    if (*itr <= X) {
      bridge.insert(*itr);
    }

    // if (std::accumulate(bridge.begin(), bridge.end(), 0) == total_sum) {
    //   return std::distance(A.begin(), itr);
    // }

    if (bridge.size() == X) {
      return std::distance(A.begin(), itr);
    }
  };
  return -1;
}
}  // namespace counting_elements