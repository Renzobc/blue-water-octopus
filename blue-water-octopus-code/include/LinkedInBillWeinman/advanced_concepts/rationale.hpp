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
 * rationale.hpp
 */

// rational.cpp by Bill Weinman [bw.org]
// updated 2022-07-21
// #include <format>
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "common.hpp"

using std::string;



const string nanstr {"[NAN]"};

class Fraction{
    int d {1};

    public:

    int n {0};


    Fraction() = default;
    // Fraction(int numerator): n(numerator){};
    std::string str() const;


    // Define a copy constructor
    Fraction(const Fraction& fraction):n(fraction.n)
    {
        std::cout << "Copy constructor of fraction" << std::endl; 
    }

    Fraction& operator = (const Fraction & rhs)
    {
        std::cout << "Assignment operator" << std::endl;
        if(this != & rhs)
        {
            this->n = rhs.n;
        }
        return *this;
    } 
};

class Rational {
    int n {0};
    int d {1};
public:

    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {
        print("Call the constructor for numerator and default denominator as per ", numerator, denominator);
    } // Implicitly can convert an int to a Rational
    Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {
        std::cout << "Copy constructor of Rational" << std::endl; 
    }    // copy constructor, takes by reference A rational object
    ~Rational();

    // Utilities functions
    int numerator() const { return n; };
    int denominator() const { return d; };
    Rational reduce() const;    // reduce fraction
    string str() const;         // return a formatted STL string
    string raw_str() const;     // return a non-reduced STL string

    // Operator overloads
    Rational& operator = (const Rational&);  // assignment
    // Rational operator + (const Rational& rhs) const;
    Rational operator - (const Rational&) const;
    Rational operator * (const Rational&) const;
    Rational operator / (const Rational&) const;

    // Conversion operators
    // Syntax is "operator <oother_class_name>()". 
    // It takes no arguments since it will by default take as lhs argument the class type it is define. i.e Rational.string()
    operator auto(){ // It is infering the return type!!!!!!!!!
        return str();
    }

    operator Fraction()
    {
        std::cout << "Faction operator" << std::endl;
        return Fraction();
    }

    friend std::stringstream& operator << (std::stringstream & string_stream,const Rational & rhs)
    {
        string_stream << std::to_string(int(rhs.n/rhs.d));
        return string_stream;
    }
};


int rationale_main();