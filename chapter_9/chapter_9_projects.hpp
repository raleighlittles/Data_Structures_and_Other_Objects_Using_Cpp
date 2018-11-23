//
// Created by raleigh on 11/11/18.
//

#include <sstream>
#include <cassert>

namespace RecursiveThinking {

    /* Problem description, problem 6
     *
     * The formula for computing the number of
ways of choosing r different things from a
set of n things is the following:
n !
C ( n , r ) = ----------------------
r ! ( n – r ) !
In this formula, the factorial function is represented
by an exclamation point (!), and defined as the product:
n ! = n × ( n – 1 ) × ( n – 2 ) × ... × 1
Discover a recursive version of the C(n, r) formula
and write a recursive C++ function that computes
the value of the formula. Embed the function in a
program and test it.
     */
    float recursive_combination_formula(int n, int r) {

        /* Remember that the C(n, r) formula is the same as the binomial coefficient. Then, we can use Pascal's Rule:
    C(n, r) = C(n-1, r) + C(n-1, r-1) to create a recursive implementation. */

        // this is by definition of the binomial coefficient.
        // there are 0 ways to choose a sample of r items from a collection of n unless r is a non-negative number
        // similarly, it is impossible to choose a set of r elements from n if r is larger than n
        if ((r < 0) or (r > n)) {
            return 0;
        }

        // there is only 1 way to choose r items out of n if you wish to choose no items, and that is not choosing any items at all
        // similarly, if there are no elements to even choose from, there is obviously only way to choose (not choosing)
        if ((r == 0) or (n <= 1)) {
            return 1;
        }

        return (recursive_combination_formula(n - 1, r) + recursive_combination_formula(n - 1, r - 1));

    }

    // std::string does have a way to create repeated characters, but it does NOT work with strings. E.g.:
    // std::string("a", 4) works, and will return "aaaa", but you cannot replace "a" with an std::string-like type
    std::string operator*(const std::string &str, std::size_t times) {
        std::stringstream stream;
        for (size_t i = 0; i < times; i++) {
            stream << str;
        }
        return stream.str();
    }


    std::string recursive_function(uint8_t left_margin, uint8_t length) {
        if (length == 0) {
            return "";
        } else {
            return (recursive_function(left_margin, length / 2) + std::string("  ") * left_margin +
                    std::string("* ") * length + "\n" +
                    recursive_function(left_margin + length / 2, length / 2));
        }

    }

    /* Problem description, Problem 9 */
    /*
     * Examine this pattern of asterisks and blanks,
and write a recursive function that can gen-
erate exactly this pattern:
     */
    std::string generate_asterisk_pattern() {
        // Hint: If you're having trouble understanding the pattern, write out how many asterisks appear on each (horizontal)
        // line.

        return recursive_function(0, 8);

    }

    // Note: The Ackermann function is unique since its one of the earliest examples of a total computable function that isn't
    // primitive recursive, i.e. a function that can't be implemented using only do-loops
    int ackermann_function(int x, int y)
    {
        assert((x >= 0) and (y >= 0)); // ackermann function is only defined for non-negative integers

        if (x == 0)
        {
            return 2 * y;
        }

        else if (x >= 1)
        {
            if (y == 0)
            {
                return 0;
            }

            if (y == 1)
            {
                return 1;
            }

            if (y >= 2)
            {
                return ackermann_function(x-1, ackermann_function(x, y-1));
            }
        }

    }


}



