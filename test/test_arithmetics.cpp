#include "TArithmetics.h"
#include <gtest.h>

TEST(TArithmetics, check_calculator)
{
	char temp[] = "13*12+14";
	ASSERT_EQ(0, Calculat(temp));
}

TEST(TArithmetics, check_eq)
{
	char temp[] = "(7+3)/-8";
	ASSERT_EQ("12/4000+*-", Stroka(a));
}

TEST(TArithmetics, no_throw)
{
	char temp[] = "(4*4+1)/(11+2)";
	ASSERT_NO_THROW(Stroka(temp));
}

TEST(TArithmetics, check_calculator_2)
{
	char temp[] = "13*12++++";
	ASSERT_EQ(0, Calculat(temp));
}

TEST(TArithmetics, check_calculator_3)
{
	char temp[] = "13*12/4+1-9/5*13-1";
	ASSERT_EQ(0, Calculat(temp));
}

TEST(TStack, can_pull)
{
    TStack<int> temp(4);
    int num = 2;
    temp.push(num);
    temp.pull();
    EXPECT_EQ(1, q.isEmpty());
}

TEST(Stack, can_get_count)
{
    TStack<int> q(3);
    EXPECT_EQ(0, q.GetCount());
}
