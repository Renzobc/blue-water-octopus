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

#include "counting_elements/frog_river_one.hpp"

#include <vector>

#include "gtest/gtest.h"
namespace test_frog_river_one
{
//     For example, given X = 5 and array A such that:

//   A[0] = 1
//   A[1] = 3
//   A[2] = 1
//   A[3] = 4
//   A[4] = 2
//   A[5] = 3
//   A[6] = 5
//   A[7] = 4
// the function should return 6, as explained above.
TEST(counting_elements, example)
{
  std::vector<int> A{1, 3, 1, 4, 2, 3, 5, 4};
  EXPECT_EQ(counting_elements::solution(5, A), 6);
}

}  // namespace test_frog_river_one