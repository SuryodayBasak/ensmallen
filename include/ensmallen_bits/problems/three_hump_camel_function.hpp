/**
 * @file three_hump_camel_function.hpp
 * @author Suryoday Basak
 *
 * Definition of the Three-hump camel function.
 *
 * ensmallen is free software; you may redistribute it and/or modify it under
 * the terms of the 3-clause BSD license.  You should have received a copy of
 * the 3-clause BSD license along with ensmallen.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef ENSMALLEN_PROBLEMS_THREE_HUMP_CAMEL_FUNCTION_HPP
#define ENSMALLEN_PROBLEMS_THREE_HUMP_CAMEL_FUNCTION_HPP

namespace ens {
namespace test {

/**
 * The Three-hump camel function, defined by
 *
 * \f[
 * f(x_1,x_2) = 2 * x_1^2 - 1.05 * x_1^4 + (x_1^6)/6 + x_1 * x_2 + x_2^2
 * \f]
 *
 * This should optimize to f(x) = 0, at x = [0, 0].
 *
 * For more information, please refer to:
 *
 * @code
 * @article{Ali2005,
 *   doi       = {10.1007/s10898-004-9972-2},
 *   year      = {2005},
 *   month     = apr,
 *   publisher = {Springer Nature},
 *   volume    = {31},
 *   number    = {4},
 *   pages     = {635--672},
 *   author    = {M. Montaz Ali and Charoenchai Khompatraporn and
 *                Zelda B. Zabinsky},
 *   title     = {A Numerical Evaluation of Several Stochastic Algorithms
 *                on Selected Continuous Global Optimization Test Problems},
 *   journal   = {Journal of Global Optimization}
 * }
 * @endcode
 */
class ThreeHumpCamelFunction
{
 public:
  //! Initialize the ThreeHumpCamelFunction.
  ThreeHumpCamelFunction();

  /**
   * Shuffle the order of function visitation. This may be called by the
   * optimizer.
   */
  void Shuffle();

  //! Return 1 (the number of functions).
  size_t NumFunctions() const { return 1; }

  //! Get the starting point.
  arma::mat GetInitialPoint() const { return arma::mat("-4.5; 4.5"); }

  /**
   * Evaluate a function for a particular batch-size.
   *
   * @param coordinates The function coordinates.
   * @param begin The first function.
   * @param batchSize Number of points to process.
   */
  double Evaluate(const arma::mat& coordinates,
                  const size_t begin,
                  const size_t batchSize) const;

  /**
   * Evaluate a function with the given coordinates.
   *
   * @param coordinates The function coordinates.
   */
  double Evaluate(const arma::mat& coordinates) const;

  /**
   * Evaluate the gradient of a function for a particular batch-size.
   *
   * @param coordinates The function coordinates.
   * @param begin The first function.
   * @param gradient The function gradient.
   * @param batchSize Number of points to process.
   */
  void Gradient(const arma::mat& coordinates,
                const size_t begin,
                arma::mat& gradient,
                const size_t batchSize) const;

  /**
   * Evaluate the gradient of a function with the given coordinates.
   *
   * @param coordinates The function coordinates.
   * @param gradient The function gradient.
   */
  void Gradient(const arma::mat& coordinates, arma::mat& gradient);
};

} // namespace test
} // namespace ens

// Include implementation.
#include "three_hump_camel_function_impl.hpp"

#endif // ENSMALLEN_PROBLEMS_THREE_HUMP_CAMEL_FUNCTION_HPP
