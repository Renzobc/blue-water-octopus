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
#include "time_complexity/tape_equilibrium.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace test_time_complexity
{
TEST(test_time_complexity, example)
{
  std::vector<int> A{3, 1, 2, 4, 3};
  EXPECT_EQ(1, time_complexity::solution(A));
}

TEST(test_time_complexity, two_elements)
{
  std::vector<int> A{0, 2000};
  EXPECT_EQ(2000, time_complexity::solution(A));
}
}  // namespace test_time_complexity
