//
// Created by raleigh on 11/11/18.
//

/* Problem statement, Problem #6 page 471
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

namespace RecursiveThinking
{
    /* Remember that the C(n, r) formula is the same as the binomial coefficient. Then, we can use Pascal's Rule:
     C(n, r) = C(n-1, r) + C(n-1, r-1) to create a recursive implementation. */
    float recursive_combination_formula(int n, int r)
    {
        // this is by definition of the binomial coefficient.
        // there are 0 ways to choose a sample of r items from a collection of n unless r is a non-negative number
        // similarly, it is impossible to choose a set of r elements from n if r is larger than n
        if ((r < 0) or (r > n))
        {
            return 0;
        }

        // there is only 1 way to choose r items out of n if you wish to choose no items, and that is not choosing any items at all
        // similarly, if there are no elements to even choose from, there is obviously only way to choose (not choosing)
        if ((r == 0) or (n <=1 ))
        {
            return 1;
        }

        return (recursive_combination_formula(n-1, r) + recursive_combination_formula(n-1, r-1));

    }
}
