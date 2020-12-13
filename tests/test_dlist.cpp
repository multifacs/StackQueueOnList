#include <../gtest/gtest.h>
#include "DList.h"

TEST(dlist, can_create_list)
{
	ASSERT_NO_THROW(DList<int> a);
}

TEST(dlist, can_copy)
{
	DList<int> a;
	a.push_back(123);

	DList<int> b(a);

	EXPECT_EQ(123, b[0]);
}

TEST(dlist, can_push_back)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	EXPECT_EQ(100, lst[1]);
}

TEST(dlist, can_pop_back)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_back();

	lst.push_back(17);

	EXPECT_EQ(17, lst[1]);
}

TEST(dlist, cant_pop_in_empty_list)
{
	DList<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(dlist, can_push_front)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.push_front(17);

	EXPECT_EQ(17, lst[0]);
}

TEST(dlist, can_pop_front)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_front();

	EXPECT_EQ(100, lst[0]);
}

TEST(dlist, can_insert)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);

	EXPECT_EQ(99, lst[3]);
}

TEST(dlist, can_remove)
{
	DList<int> lst;

	lst.push_back(5);
	lst.push_back(100);
	lst.push_back(21);

	lst.remove(1);

	EXPECT_EQ(21, lst[1]);
}

TEST(dlist, can_insert_at_end)
{
	DList<int> a;
	a.push_back(1);
	a.push_back(2);

	a.insert(3, a.GetSize());

	EXPECT_EQ(3, a[a.GetSize() - 1]);
}

TEST(dlist, can_remove_at_end)
{
	DList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	a.remove(a.GetSize() - 1);

	EXPECT_EQ(2, a[a.GetSize() - 1]);
}

TEST(dlist, cant_insert_out_of_bounds)
{
	DList<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(dlist, cant_remove_out_of_bounds)
{
	DList<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}
