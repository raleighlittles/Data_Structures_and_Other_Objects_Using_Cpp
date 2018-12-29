//
// Created by raleigh on 12/28/18.
//

//The <math> facility provides a standard
//        function log(x) , which returns the natural
//        logarithm of x (with a base that is ap-
//proximately 2.71828). This base is written e, and the
//        logarithms with this base are called natural
//logarithms, or Napierian logarithms, after the
//        Scottish mathematician John Napier (1550–1617)
//who invented these logarithms. The number e may
//seem like a strange choice for the base of a
//logarithm, but the choice is motivated by the fact
//that natural logarithms are easy to approximate as
//the sum of a series, and they also occur as the limits
//of series such as the computation of compound
//interest. In your math class, you probably used the
//notation ln x for the natural logarithm of x.
//Anyway, in this project, you are to write a
//        function:
//
//double logb(double base, double x);
//The function returns the logarithm of x to the given
//base . Make use of the log function and the formulas
//in Section 11.4.

#include <cmath>

namespace TreeProjects {

    double logb(double base, double x) {
        // Using the well-known change of base formula for logarithms, and the formula on page 576
        return std::log(x) / std::log(base);
    }

};