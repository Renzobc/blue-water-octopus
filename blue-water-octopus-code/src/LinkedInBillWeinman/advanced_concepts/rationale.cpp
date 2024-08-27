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
 * rational.cpp
 */

#include "advanced_concepts/rationale.hpp"

std::string Fraction::str() const{
    return "Fraction " + std::to_string(this->n);
}

Rational Rational::reduce() const {
    if(n == 0 || d <= 3) return *this;
    for(auto div = d - 1; div; --div) {
        if(n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div );
        }
    }
    return *this;
}

string Rational::str() const {
    if(d == 0) return nanstr;
    if(d == 1 || n == 0) return std::to_string(n);

    auto abs_n = abs(n);     // absolute value
    if(abs_n > d) {
        auto whole = n / d;
        auto remainder = abs_n % d;
        if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
        else return std::to_string(whole);
    } else {
        return reduce().raw_str();
    }
}

string Rational::raw_str() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

// Copy operator
Rational& Rational::operator = (const Rational& rhs) {
    if (this != &rhs) { // Gets the right hand side address and compares it with the pointer address
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this; // Dereference the point to get the object itself
}

// Rational Rational::operator + (const Rational& rhs) const {
//     return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d);
// }

Rational operator + (const Rational& lhs,const Rational& rhs)
{
    return Rational(lhs.numerator() * rhs.denominator()+ rhs.numerator() * lhs.denominator(), lhs.denominator() * rhs.denominator());
};

// std::string operator +(std::string  rationale_string , const Rational& rationale)
// {
//     return rationale_string + rationale.raw_str();
// }

Rational Rational::operator - (const Rational& rhs) const {
    return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator * (const Rational& rhs) const {
    return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / (const Rational& rhs) const {
    return Rational(n * rhs.d, d * rhs.n);
}

// std::string Rational::operator<<(const Rational & rhs) const{
//     return std::to_string(int(n/d));    
// }

Rational::~Rational() {
    n = 0; d = 1;
}

// formatter specialization
// template<>
// struct std::formatter<Rational>: std::formatter<unsigned> {
//     template<typename FormatContext>
//     auto format(const Rational& o, FormatContext& ctx) {
//         return format_to(ctx.out(), "{}", o.str());
//     }
// };

int rationale_main() {
    Rational a {7};         // 7/1
    print("a is: {} = {}", a.raw_str(), a);

    Rational b(25, 15);     // 5/3
    print("b is: {} = {}", b.raw_str(), b);

    auto c = b;     // copy constructor
    print("c is: {} = {}", c.raw_str(), c);

    Rational d;     // default constructor
    print("d is: {} = {}", d.raw_str(), d);

    d = c;          // assignment operator
    print("d is: {} = {}", d.raw_str(), d);

    auto& e = d;    // reference
    d = e;          // assignment to self!
    print("e is: {} = {}", e.raw_str(), e);
    print("d is: {} = {}", d.raw_str(), d);

    print("\n");
    print("a + b = {}", a + b);
    print("a - b = {}", a - b);
    print("a * b = {}", a * b);
    print("a / b = {}", a / b);
    print("b = {}", b);
    print("b + 14 = {}", b + 14);
    print("14 + b = {}", 14 + b);

    std::string rational_string{"Rational is: "};

    // Concatenating a string.
    print(rational_string += a);

    // Conversion operator to fraction
    print(typeid(Fraction(a)).name());
    print(Fraction(a).str()); 


    Fraction fraction = Fraction(a); // Copy constructor
    Fraction fraction_a;
    fraction_a = fraction; // Assignment operator =
    Fraction fraction_copy_constructor(fraction);
    std::cout << a.numerator() << std::endl;
    std::cout << fraction_copy_constructor.n << fraction_copy_constructor.str() << std::endl;


}
