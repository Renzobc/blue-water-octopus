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

#include "counting_elements/max_counters.hpp"

#include <vector>

#include "gtest/gtest.h"
namespace test_max_counters
{
TEST(max_counters, example_test)
{
  //   For example,
  //     given :

  //     A[0] = 3 A[1] = 4 A[2] = 4 A[3] = 6 A[4] = 1 A[5] = 4 A[6] = 4

  //     the function should return [ 3, 2, 2, 4, 2 ],
  //     as explained above.

  std::vector<int> input{3, 4, 4, 6, 1, 4, 4};

  auto result = max_counters::solution(5, input);
  std::vector<int> output{3, 2, 2, 4, 2};
  int counter = 0;
  std::for_each(result.begin(), result.end(), [output, &counter](int element_result) {
    EXPECT_EQ(element_result, output[counter++]);
  });
}
}  // namespace test_max_counters
