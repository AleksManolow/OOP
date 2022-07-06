/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "String.h"

TEST_SUITE("String Tests")
{
	TEST_CASE("Pushback method")
	{
		// Arrange
        String str("aleks", 20);

		// Act
		void result1 = l1.isParallelWith(l2);
		bool result2 = l1.isParallelWith(l3);

		// Check
		CHECK(result1 == false);
		CHECK(result2 == true);
	}
}*/
#include<iostream>
#include"String.h"
int main()
{
    String one("abcd");

	char* a = "Abcd";
	String two = one.append(a);

	two.print();
    return 0;
}