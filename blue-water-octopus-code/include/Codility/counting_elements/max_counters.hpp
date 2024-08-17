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
 * max_counters.hpp
 */
/*
You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:

    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, 

returns a sequence of integers representing the values of the counters.

Result array should be returned as an array of integers.

For example, given:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
*/

#include <algorithm>
#include <vector>

namespace max_counters
{

std::vector<int> solution(int N, std::vector<int> & A)
{
  auto splited = A;
  std::vector<int> result(N, 0);

  while (splited.size() > 0) {
    // Signal how to split apart the vector
    auto first_max_counter = std::find_if(
      splited.begin(), splited.end(), [N](auto element) -> bool { return element > N; });

    std::vector<int> count_ocurrences(N, 0);

    for (auto i = 0; i < std::distance(splited.begin(), first_max_counter); i++) {
      count_ocurrences[splited[i]] += 1;
    }

    if (first_max_counter != splited.end()) {
      auto maximum_occurence_in_range =
        *std::max_element(count_ocurrences.begin(), count_ocurrences.end());
      auto maximum_value_in_result = *std::max_element(result.begin(), result.end());

      for (auto itr = result.begin(); itr != result.end(); itr++) {
        *itr = maximum_occurence_in_range + maximum_value_in_result;
      }
      splited = std::vector<int>{first_max_counter + 1, splited.end()};

    } else {
      for (auto itr = splited.begin(); itr != splited.end(); itr++) {
        result[*itr - 1] += 1;
      }
      splited.clear();
    }
  }
  return result;
}

}  // namespace max_counters