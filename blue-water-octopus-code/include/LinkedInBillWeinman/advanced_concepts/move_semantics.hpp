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
 * move_semantics.hpp
 */
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>



#include "common.hpp"

using namespace std;

template<typename T>
class container {
    std::vector<T> things {};
public:
    container() { print("default ctor\n"); }    // default ctor
    container(std::initializer_list<T> il);     // il ctor
    container(const container& rhs);            // copy ctor
    container(container&& rhs) noexcept;        // move ctor
    ~container();
    container<T>& operator = (const container& rhs);
    void reset();
    string str() const;
};

int main_move_semantics();