#include "lib.hpp"

#include <iostream>
#include <gtest/gtest.h>
#include <utility>

using namespace simplelib;

TEST(Libsimple, Sum_one)
{
	double const sum_res = sum(1.0, 234.0);
	ASSERT_EQ(sum_res, 235.0);
}

TEST(Libsimple, Sum_two)
{
	double const sum_res = sum(-3234.0, -223.0);
	ASSERT_EQ(sum_res, -3457.0);
}


TEST(Libsimple, Quadratic_equation_one)
{
	auto Pair_res = std::make_pair(0.0, 0.0);
	auto Pair_exp_res = std::make_pair(0.0512708, -234.051);
	int const quadratic_equation_res = quadratic_equation(1.0, 234.0, -12.0, Pair_res);
	ASSERT_TRUE(Pair_res == Pair_exp_res);
}

TEST(Libsimple, Quadratic_equation_two)
{
	auto Pair_res = std::make_pair(0.0, 0.0);
	int const quadratic_equation_res = quadratic_equation(1.0, 1.0, 1.0, Pair_res);
	ASSERT_EQ(quadratic_equation_res, -1);
}