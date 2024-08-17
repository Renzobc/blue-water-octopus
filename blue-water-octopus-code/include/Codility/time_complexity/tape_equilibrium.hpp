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
 * tape_equilibrium.hpp
 */
/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

#include <algorithm>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
namespace time_complexity
{
int solution(std::vector<int> & A)
{
  std::vector<int> B(A.size());

  //   for (auto itr = A.begin(); itr != A.end(); itr++) {
  //     B[std::abs(std::distance(itr, A.begin()))] =
  //       std::accumulate(A.begin(), itr + 1, 0, std::plus<int>());
  //   }

  std::partial_sum(A.begin(), A.end(), B.begin());

  int total_sum = B.back();
  int minimum_diffrence = std::numeric_limits<int>::max();

  std::for_each(B.begin(), B.end(), [total_sum, &minimum_diffrence](int partial_sum) -> void {
    if (std::abs(2 * partial_sum - total_sum) < minimum_diffrence) {
      minimum_diffrence = std::abs(2 * partial_sum - total_sum);
    }
  });
  return minimum_diffrence;
}
}  // namespace time_complexity