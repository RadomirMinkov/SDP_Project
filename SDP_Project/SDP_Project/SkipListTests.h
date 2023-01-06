#ifndef _SKIPLIST_TESTS_HPP
#define _SKIPLIST_TESTS_HPP

#include "doctest.h"
#include "SkipList.h"

TEST_CASE("�������� �� �������� �� ������� � ����")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);

	CHECK_EQ(list.getStart()->data, 4);
	CHECK_EQ(list.getEnd()->data,10);
	
}
TEST_CASE("�������� �� ���������� �� ������� � ��������")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.removeElementBegining();
	list.removeElementBegining();
	CHECK(!list.getStart());
	CHECK(!list.getEnd());

}
TEST_CASE("�������� �� ���������� �� ������� � ����")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.removeElementEnd();
	list.removeElementEnd();
	CHECK(!list.getStart());
	CHECK(!list.getEnd());

}
TEST_CASE("�������� �� ��������� �� �������")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.addElementEnd(20);
	list.addElementEnd(30);
	list.addElementEnd(15);
	list.addElementEnd(18);
	CHECK_EQ(list.print(),"4 -> 10   10 -> 20   20 -> 30   30 -> 15   15 -> 18   ");
	std::cout << '\n';
}

#endif // !_SKIPLISTTESTS_HPP

