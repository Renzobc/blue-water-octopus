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
 * move_semantics.cpp
 */

// container-02.cpp by Bill Weinman [bw.org]
// updated 2022-10-26
// #include <format>
#include <string>
#include <vector>
#include <initializer_list>
#include "advanced_concepts/move_semantics.hpp"

using std::string;

// // format-style print()
// constexpr void print(const std::string_view str_fmt, auto&&... args) {
//     fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
// }

// initializer-list ctor
template<typename T>
container<T>::container(std::initializer_list<T> il) : things {il.begin(), il.end()} {
    print("initializer-list ctor\n");
}

// copy ctor
template<typename T>
container<T>::container(const container& rhs) : things {rhs.things} {
    print("copy ctor\n");
}

// move ctor
template<typename T>
container<T>::container(container&& rhs) noexcept
: things {std::move(rhs.things)} {
    print("move ctor\n");
}

// copy assignment operator
template<typename T>
container<T>& container<T>::operator = (const container& rhs) {
    print("copy assignment operator\n");
    if(this != &rhs) things = rhs.things;
    return *this;
}

// dtor
template<typename T>
container<T>::~container() {
    print("dtor\n");
}

template<typename T>
void container<T>::reset() {
    things.clear();
}

template<typename T>
string container<T>::str() const {
    string out {};
    if(things.empty()) return "[empty]";
    for(auto i : things) {
        if(out.size()) out += ':';
        // out += format("{}", i);
        out += i;
    }
    return out;
}

template <typename T>
container<T> f(container<T> o) {
    return o;
}

int main_move_semantics() {
    container<string> a {"one", "two", "three", "four", "five"};
    container<string> b {"five", "six", "seven"};

    print("a: {}\n", a.str());
    print("b: {}\n", b.str());

    container c {std::move(a)};
    print("a: {}\n", a.str());
    print("c: {}\n", c.str());
}
