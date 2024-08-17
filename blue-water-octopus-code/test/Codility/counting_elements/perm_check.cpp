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
 * perm_check.hpp
 */
#include "counting_elements/perm_check.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace test_counting_elements
{

TEST(perm_check, example_1)
{
  // Given array A such that:

  //     A[0] = 4
  //     A[1] = 1
  //     A[2] = 3
  // the function should return 0.

  std::vector<int> A{4, 1, 3, 2};
  EXPECT_EQ(perm_check::solution(A), 1);
}

TEST(perm_check, example_2)
{
  std::vector<int> A{4, 1, 3};
  EXPECT_EQ(perm_check::solution(A), 0);
}
}  // namespace test_counting_elements