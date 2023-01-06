#ifndef _SKIPLIST_HPP
#define _SKIPLIST_HPP
#include <iostream>
template <class T>
struct Element
{
	T data;
	Element* next;
	Element* skipTo;
	Element(T _data, Element<T>* _next = nullptr, Element<T>* _skipTo = nullptr)
		:data{ _data }, next{ _next }, skipTo{ _skipTo } {}
};
template <class T>
class SkipList
{
private:
	Element<T>* start;
	Element<T>* end;
	size_t size{ 0 };
	void copyElements(SkipList<T> const&);
	void copySkipRelations(SkipList<T> const&);
	void copy(SkipList<T> const&);
	void clear();
public:
	SkipList() :start{ nullptr }, end{ nullptr }, size{ 0 } {}
	SkipList(SkipList<T> const&);
	SkipList<T> const& operator=(SkipList<T> const&);
	~SkipList();

	bool addElementEnd(T const&);
	bool addSkipToElement(T const& from, T const& to);
	bool removeElementBegining();
	bool removeElementEnd();
	bool removeEl(Element<T>*);
	void print(std::ostream& os= std::cout)const;

	Element<T>* getStart() const { return start; }
	Element<T>* getEnd() const { return end; }
	size_t getSize() const { return size; }
};
template <class T>
void SkipList<T>::copyElements(SkipList<T> const& other)
{
	Element<T>* iter = other->start;
	while (iter)
	{
		iter = iter->next;
		addElementEnd(iter->name);
	}
}
template <class T>
void SkipList<T>::copySkipRelations(SkipList<T> const& other)
{
	Element<T>* iter = other->start;
	while (iter)
	{
		if (iter->skipTo)
		{
			addSkipToElement(iter->data,iter->skipTo);
		}
		iter = iter->next;
	}
}
template <class T>
SkipList<T> const& SkipList<T>::operator=(SkipList<T> const& other)
{
	if (*this != other)
	{
		clear();
		copy(other);
	}
}
template <class T>
void SkipList<T>::print(std::ostream& os)const
{
	Element<T>* curr = start;
	while (curr)
	{
		if (curr->next)
		{
			std::cout << curr->data << " -> " << curr->next->data << "   ";
		}
		if (curr->skipTo)
		{
			std::cout << curr->data << " -> " << curr->skipTo->data << '\n';
		}
		curr = curr->next;
	}
}
template <class T>
void SkipList<T>::copy(SkipList<T> const& other)
{
	copyElements(other);
	copySkipRelations(other);
}
template <class T>
void SkipList<T>::clear()
{
	while (start)
		removeElementBegining();
}
template <class T>
SkipList<T>::SkipList<T>(SkipList<T> const& other) : start{ nullptr }, end{ nullptr }
{
	this->copy(other);
}
template <class T>
SkipList<T>::~SkipList()
{
	this->clear();
}
template <class T>
bool SkipList<T>::addSkipToElement(T const& from, T const& to)
{
	Element<T>* curr = start;
	while (curr && curr->data != from)
		curr = curr->next;
	if (!curr)
		return false;
	Element<T>* elFrom = curr;
	while (curr && curr->data != to)
		curr = curr->next;
	if (!curr)
		return false;
	elFrom->skipTo = curr;
	return true;
}
template <class T>
bool SkipList<T>::addElementEnd(T const& data)
{
	if (!(start || end))
	{
		start = end = new Element<T>{ data };
		size++;
		return true;
	}
	Element<T>* toAdd = new Element<T>{ data };
	Element<T>* curr = start;
	while (curr != end && curr->data != data)
		curr = curr->next;
	if (curr->data == data)
		return false;
	end->next = toAdd;
	end = toAdd;
	size++;
	return true;
}
template <class T>
bool SkipList<T>::removeElementBegining()
{
	return removeEl(start);
}
template <class T>
bool SkipList<T>::removeElementEnd()
{
	return removeEl(end);
}
template <class T>
bool SkipList<T>::removeEl(Element<T>* element)
{
	if (!(start || end))
		return false;
	if (start == element)
	{
		Element<T>* toDelete = start;
		start = start->next;
		delete toDelete;
		start = end = nullptr;
		size--;
		return true;
	}
	Element<T>* curr = start;
	while (curr->next && curr->next != element)
		curr = curr->next;
	if (!curr)
		return false;
	if (curr->next == end)
		end = curr;
	Element<T>* toDelete = curr->next;
	curr->next = toDelete->next;
	delete toDelete;
	size--;
	return true;

}
#endif // !_SKIPLIST_HPP


