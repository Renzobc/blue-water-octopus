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
#include "arrays/cyclic_rotation.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace test_cyclic_rotation
{
TEST(cyclic_rotation, vector_a)
{
  std::vector<int> A{3, 8, 9, 7, 6};
  cyclic_rotation::solution(A, 3);
  std::vector<int> result{9, 7, 6, 3, 8};
  int i = 0;
  std::for_each(A.begin(), A.end(), [&result, &i](auto element) -> void {
    EXPECT_EQ(element, result[i]);
    i++;
  });
};

TEST(cyclic_rotation, vector_b)
{
  std::vector<int> A{3, 8, 9, 7, 6};
  auto B = cyclic_rotation::solution_B(A, 3);
  std::vector<int> result{9, 7, 6, 3, 8};
  int i = 0;
  std::for_each(B.begin(), B.end(), [&result, &i](auto element) -> void {
    EXPECT_EQ(element, result[i]);
    i++;
  });
};
}  // namespace test_cyclic_rotation