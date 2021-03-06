/**
 * @file beale_function.hpp
 * @author Suryoday Basak
 *
 * Definition of the Beale function.
 *
 * ensmallen is free software; you may redistribute it and/or modify it under
 * the terms of the 3-clause BSD license.  You should have received a copy of
 * the 3-clause BSD license along with ensmallen.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef ENSMALLEN_PROBLEMS_BEALE_FUNCTION_HPP
#define ENSMALLEN_PROBLEMS_BEALE_FUNCTION_HPP

namespace ens {
namespace test {

/**
 * The Beale function, defined by
 *
 * \f[
 * f(x_1,x_2) = (1.5 - x_1 + x_1 * x_2)^2 +
 *              (2.25 - x_1 + x_1 * x_2^2)^2 +
 *              (2.625 - x_1 + x_1 * x_2^3)^2
 * \f]
 *
 * This should optimize to f(x) = 0, at x = [3, 0.5].
 *
 * For more information, please refer to:
 *
 * @code
 * @misc{1307.5838,
 *   Author = {Masoumeh Vali},
 *   Title  = {Rotational Mutation Genetic Algorithm on optimizationProblems},
 *   Year   = {2013},
 *   Eprint = {arXiv:1307.5838},
 * }
 * @endcode
 */
class BealeFunction
{
 public:
  //! Initialize the BealeFunction.
  BealeFunction();

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
#include "beale_function_impl.hpp"

#endif // ENSMALLEN_PROBLEMS_BEALE_FUNCTION_HPP
