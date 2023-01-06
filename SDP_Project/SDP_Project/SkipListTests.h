#ifndef _SKIPLIST_TESTS_HPP
#define _SKIPLIST_TESTS_HPP

#include "doctest.h"
#include "SkipList.h"

TEST_CASE("Тестване на добавяне на елемент в края")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);

	CHECK_EQ(list.getStart()->data, 4);
	CHECK_EQ(list.getEnd()->data,10);
	
}
TEST_CASE("Тестване на премахване на елемент в началото")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.removeElementBegining();
	list.removeElementBegining();
	CHECK(!list.getStart());
	CHECK(!list.getEnd());

}
TEST_CASE("Тестване на премахване на елемент в края")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.removeElementEnd();
	list.removeElementEnd();
	CHECK(!list.getStart());
	CHECK(!list.getEnd());
}
TEST_CASE("Тестване дали работи добавянето на връзка skip")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.addElementEnd(20);
	list.addElementEnd(50);
	list.addElementEnd(40);
	list.addElementEnd(30);
	list.addSkipToElement(10, 40);
	Element<int>* curr = list.getStart();
	curr = curr->next;
	CHECK_EQ(curr->skipTo->data, 40);
}
TEST_CASE("Тестване на метод, който връща елемент по стойност")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.addElementEnd(20);
	list.addElementEnd(50);
	CHECK(!list.getElement(2));
	CHECK_EQ(list.getElement(10), list.getStart()->next);
}
TEST_CASE("Тестване на copy конструктор и оператор равно")
{
	SkipList<int> list;
	list.addElementEnd(4);
	list.addElementEnd(10);
	list.addElementEnd(20);
	list.addElementEnd(50);
	SkipList<int> newList{ list };
	SkipList<int> copiedList;
	copiedList = newList;
	list.removeElementBegining();
	CHECK_EQ(copiedList.getStart()->data, 4);
	CHECK_EQ(newList.getStart()->data, 4);
}
#endif // !_SKIPLISTTESTS_HPP

