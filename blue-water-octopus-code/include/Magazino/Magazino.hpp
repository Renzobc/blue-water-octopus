/**
 * Copyright 2023 Renzo Bruzzone
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// 1. (Mandatory) Write a function that takes an unsigned 32 bits integer as input and
// returns true if all the digits in the base 10 representation of that number are unique.
// bool all_digits_unique(uint32_t value)
// Example:
// all_digits_unique (48778584) returns false
// all_digits_unique (17308459) returns true

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <locale>  // std::locale, std::tolower
#include <memory>
#include <set>
#include <string>
#include <vector>

class Node
{
public:
  Node(std::string name, std::list<Node> children = {})
  {
    name_ = name;
    children_ = children;
  };

  static int cToLower(int c) { return tolower(c); }

  static std::string sToLower(std::string name)
  {
    std::string lower_case_name;
    std::for_each(name.begin(), name.end(), [&lower_case_name](char c) mutable -> void {
      lower_case_name.push_back(static_cast<char>(Node::cToLower(c)));
    });
    return lower_case_name;
  }

  int counter_children_node(Node & node, std::string needle)
  {
    int counter = 0;
    if (Node::sToLower(node.name_).find(Node::sToLower(needle)) != std::string::npos) {
      counter += 1;
    }
    std::for_each(
      node.children_.begin(), node.children_.end(),
      [this, &counter, needle](Node & node) mutable -> void {
        counter += counter_children_node(node, needle);
      });
    return counter;
  }

  int count_nodes_containing_string(std::string needle)
  {
    int counter = 0;

    counter = counter_children_node(*this, needle);

    return counter;
  }

private:
  std::string name_;
  std::list<Node> children_;
};
