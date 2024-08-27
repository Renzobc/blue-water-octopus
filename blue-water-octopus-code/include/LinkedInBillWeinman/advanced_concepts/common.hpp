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
 * common.hpp
 */
#pragma once

#include <string_view>
#include <sstream>
#include <iostream>
// #include <format>


// format-style print()
// constexpr void print(const std::string_view str_fmt, auto&&... args) {
//     fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
// }


template<typename... Args>
inline void print(std::string_view text, Args ...args)
{
    std::stringstream string_stream;
    string_stream << text << ". ";
    ((string_stream << args << " "), ...); // Append all arguments to the string stream in sequence
    std::cout << string_stream.str() << std::endl;
}