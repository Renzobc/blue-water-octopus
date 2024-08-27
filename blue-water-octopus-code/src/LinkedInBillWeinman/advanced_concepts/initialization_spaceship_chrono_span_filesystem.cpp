/**
 * Copyright 2024 Capra Robotics ApS
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
 * initialization_spaceship_chrono_span_filesystem.cpp
 */

#include "advanced_concepts/initialization_spaceship_chrono_span_filesystem.hpp"

uint64_t count_primes()
{
  constexpr auto isprime = [](const uint64_t n) {
    for (uint64_t i{2}; i < n / 2; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  };

  uint64_t count{0};
  uint64_t start{2};
  uint64_t end{MAX_PRIME};
  for (uint64_t i{start}; i <= end; ++i) {
    if (isprime(i)) ++count;
  }
  return count;
}

int main_initialization_spaceship_chrono_span_filesystem()
{
  constexpr fraction a(10, 15);
  constexpr fraction b(2, 3);
  constexpr fraction c(5, 3);

  static_assert(a < c);
  static_assert(c > a);
  static_assert(a == b);
  static_assert(a <= b);
  static_assert(a <= c);
  static_assert(c >= a);
  static_assert(a != c);

  // chrono library

  timer(count_primes);
}