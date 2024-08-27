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
 * initialization_spaceship_chrono_span_filesystem.hpp
 */

#pragma once

#include <chrono>
#include <iostream>
#include <iterator>
#include <ratio>

#include "common.hpp"

constexpr uint64_t MAX_PRIME{0x1FFFF};

class fraction
{
  long numerator_;
  long denominator_;

public:
  fraction() = delete;
  constexpr fraction(long numerator, long denominator)
  : numerator_(numerator), denominator_(denominator) {};

  constexpr double fraction_value() const
  {
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
  }

  constexpr auto operator<=>(const fraction & rhs) const
  {
    return fraction_value() <=> rhs.fraction_value();
  }
  constexpr auto operator==(const fraction & rhs) const
  {
    return fraction_value() == rhs.fraction_value();
  }
};

// Concept of callable
template <typename T>
concept Callble = requires(T f) { f(); };

void timer(const Callble auto & callable)
{
  auto time_a = std::chrono::steady_clock::now();
  auto count = callable();
  auto time_b = std::chrono::steady_clock::now();
  std::chrono::duration<double> seconds = time_b - time_a;
  std::ostream_iterator<std::string> output_string_iterator(std::cout, "n");
  *++output_string_iterator =
    std::to_string(std::chrono::duration<double, std::milli>(seconds).count());
}

uint64_t count_primes();

int main_initialization_spaceship_chrono_span_filesystem();