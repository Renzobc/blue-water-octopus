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
 * bynary_gap.hpp
 */

#include "iteractions/binary_gap.hpp"

#include <gtest/gtest.h>

namespace test_binary_gap
{
TEST(binary_gap, example_A_1041) { EXPECT_EQ(binary_gap::solution_A(1041), 5); }

TEST(binary_gap, example_A_32) { EXPECT_EQ(binary_gap::solution_A(32), 0); }

TEST(binary_gap, example_B_1041) { EXPECT_EQ(binary_gap::solution_B(1041), 5); }

TEST(binary_gap, example_B_1162) { EXPECT_EQ(binary_gap::solution_B(1162), 3); }
}  // namespace test_binary_gap