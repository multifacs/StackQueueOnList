#include <gtest.h>
#include "LSQ.h"

TEST(lstack, can_create_stack)
{
	ASSERT_NO_THROW(LStack<int> a);
}

TEST(lstack, can_copy)
{
	LStack<int> a;
	a.push(123);

	LStack<int> b(a);

	EXPECT_EQ(123, b.pop());
}

TEST(lstack, can_push)
{
	LStack<int> a;

	a.push(5);
	a.push(100);

	EXPECT_EQ(100, a.pop());
}

TEST(lstack, can_pop)
{
	LStack<int> a;

	a.push(5);
	a.push(100);

	a.pop();

	a.push(17);

	EXPECT_EQ(17, a.pop());
}

TEST(lstack, cant_pop_in_empty_stack)
{
	LStack<int> a;
	ASSERT_ANY_THROW(a.pop());
}


TEST(lqueue, can_create_queue)
{
	ASSERT_NO_THROW(LQueue<int> a);
}

TEST(lqueue, can_copy)
{
	LQueue<int> a;
	a.push(123);

	LQueue<int> b(a);

	EXPECT_EQ(123, b.pop());
}

TEST(lqueue, can_push)
{
	LQueue<int> a;

	a.push(5);
	a.push(100);

	EXPECT_EQ(5, a.pop());
}

TEST(lqueue, can_pop)
{
	LQueue<int> a;

	a.push(5);
	a.push(100);

	a.pop();

	a.push(17);

	EXPECT_EQ(100, a.pop());
}

TEST(lqueue, cant_pop_in_empty_queue)
{
	LQueue<int> a;
	ASSERT_ANY_THROW(a.pop());
}


TEST(pqueue, can_create_queue)
{
	ASSERT_NO_THROW(PQueue<int> a);
}

TEST(pqueue, can_copy)
{
	PQueue<int> a;
	a.push(10, 0);

	PQueue<int> b(a);

	EXPECT_EQ(10, b.pop());
}

TEST(pqueue, can_push)
{
	PQueue<int> a;

	a.push(5, 0);
	a.push(10, 1);

	EXPECT_EQ(10, a.pop());
}

TEST(pqueue, can_pop)
{
	PQueue<int> a;

	a.push(5, 0);
	a.push(10, 1);

	a.pop();

	a.push(15, 2);

	EXPECT_EQ(15, a.pop());
}

TEST(pqueue, cant_pop_in_empty_queue)
{
	LQueue<int> a;
	ASSERT_ANY_THROW(a.pop());
}