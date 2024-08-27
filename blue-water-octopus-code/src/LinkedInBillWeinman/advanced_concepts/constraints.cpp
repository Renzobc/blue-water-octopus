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
 * contraints.cpp
 */

// #include <format>
#include <concepts>
#include "advanced_concepts/constraints.hpp"

// format-style print()
// constexpr void print(const std::string_view str_fmt, auto&&... args) {
//     fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
// }

// Definition of the concept 
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// Constraint syntax;
// Contraints are logical expressions. They evaluate to true or false.
// template<typename T>
// requires true
// The above is a an open concept but a valid expression.
template<typename T>
concept Myconcept = std::integral<T> || std::floating_point<T>;

//Usage of the concept
// template<typename T>
// requires Numeric<T> // Constraint to avoid unwanted types to be passed to the function.

// Usage of concept inside the typename template
// template<Numeric T>


// Defining Concepts that dont rely on the concepts library
template<typename T>
concept NonStandardConcept = requires (T a){
    a+1; a*1; // if both expressions compile then the requires evaluates to true. 
    // Any expression thats compiles, evaluates to true, while if it does not compile it evaluates to false.
};


// Usage of concept inside the function signature
auto arg42(const NonStandardConcept auto & arg) {
    return arg + 42;
}



int main_constraint() {
    auto n = 7.9; // If it were to be a string it passes the ' const char * ' to the arg42 function making a MEMORY LEAK.
    print("The answer is [{}]\n", arg42(n)); 
}
