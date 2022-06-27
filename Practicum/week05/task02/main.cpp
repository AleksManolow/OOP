/*#include<iostream>
#include"Line.h"
int main()
{
    Point a(2, 8);
    Point b(1, 3);
    Point c(3, 13);

    Line one (a, b);

    std::cout << one.contains(c) << std::endl;

    return 0;
}*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Line.h"

TEST_SUITE("Line Tests")
{
	TEST_CASE("IsParallelWith method")
	{
		// Arrange
		Line l1({1, 0}, {0, 1}),
		     l2({2 ,0}, {0, -2}),
			 l3({3, 0}, {0, 3});

		// Act
		bool result1 = l1.isParallelWith(l2);
		bool result2 = l1.isParallelWith(l3);

		// Check
		CHECK(result1 == false);
		CHECK(result2 == true);
	}

	TEST_CASE("Contains method")
	{
		// Arrange
		Line l1({1, 0}, {0, 1});

		// Act
		bool result1 = l1.contains({1, 1});
		bool result2 = l1.contains({-1, 2});

		// Check
		CHECK(result1 == false);
		CHECK(result2 == true);
	}
}
