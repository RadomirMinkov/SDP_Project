#ifndef _BOX_HPP
#define _BOX_HPP
#include <string>
#include <vector>
#include <set>
#include <list>
template <class T>
class Box
{
private:
	T name;
	std::set<T> souvenirs;
	std::list<Box<T>*> insideBoxes;
	void copyPointer(Box<T>* const& other);
	void copy(Box<T> const& other);
	void clear();
public:
	Box() = default;
	Box(T const& _name);
	Box(Box<T>* const& other);
	Box(Box<T> const& other);
	Box<T> const& operator=(Box<T> const&) = delete;
	~Box() { clear(); }
	bool addSouvenir(T const&);
	void addBox(Box* const&);
	bool addBox(T const& name);
	void addName(T const& _name) { name = _name; }

	bool removeSouvenir(T const&);
	bool removeBox(Box<T>* const&);
	bool removeBox(T const& _name);

	T const& getName() const { return name; }
	std::set<T> const& getSouvenirs()const { return souvenirs; }
	std::set<T>& getSouvenirs() { return souvenirs; }
	std::list<Box<T>*> const& getInsideBoxes() const { return insideBoxes; }
	std::list<Box<T>*>& getInsideBoxes() { return insideBoxes; }

	void destroyBox(Box<T>* box);
};
template <class T>
void Box<T>::clear()
{
	for (Box<T>* box : insideBoxes)
	{
		destroyBox(box);
	}
}
template <class T>
Box<T>::Box(Box<T> const& other)
{
	copy(other);
}
template <class T>
void Box<T>::copyPointer(Box<T>* const& other)
{
	name = other->name;
	souvenirs = other->souvenirs;
	for (Box<T>* box : other->getInsideBoxes())
	{
		Box<T>* elToAdd = new Box<T>{ box };
		insideBoxes.push_back(elToAdd);
	}
}
template <class T>
void Box<T>::copy(Box<T> const& other)
{
	name = other.name;
	souvenirs = other.souvenirs;
	for (Box<T>* box : other.getInsideBoxes())
	{
		Box<T>* elToAdd = new Box<T>{ box };
		insideBoxes.push_back(elToAdd);
	}
}
template <class T>
Box<T>::Box(Box<T>* const& other)
{
	copyPointer(other);
}
template <class T>
void addContentFromOneBoxToAnother(Box<T>*& first, Box<T>* const& second)
{
	for (T const& element : second->getSouvenirs())
	{
		first->getSouvenirs().insert(element);
	}
	for (Box<T>* _box : second->getInsideBoxes())
	{
		first->getInsideBoxes().push_back(_box);
	}
}
template <class T>
Box<T>::Box(T const& _name) : name(_name) {}

template <class T>
bool Box<T>::addSouvenir(T const& souvenir)
{
	if (souvenirs.count(souvenir) == 0)
	{
		souvenirs.insert(souvenir);
		return true;
	}
	return false;
}
template <class T>
bool Box<T>::removeSouvenir(T const& souvenir)
{
	if (souvenirs.count(souvenir))
	{
		souvenirs.erase(souvenir);
		return true;
	}
	return false;
}
template <class T>
bool Box<T>::addBox(T const& _name)
{
	for (Box<T>* element : insideBoxes)
	{
		if (element->getName() == _name)
			return false;
	}
	Box<T>* elToAdd= new Box<T>{ _name };
	insideBoxes.push_back(elToAdd);
	return true;
}
template <class T>
void Box<T>::addBox(Box<T>* const& newBox)
{
	for (Box<T>* element : insideBoxes)
	{
		if (element == newBox)
		{
			addContentFromOneBoxToAnother(element, newBox);
			return;
		}
	}
	Box<T>* elToAdd = new Box<T>{ newBox };
	insideBoxes.push_back(elToAdd);
}
template <class T>
void Box<T>::destroyBox(Box<T>* box)
{
	if (box)
	{
		for (Box<T>* boxEl : box->getInsideBoxes())
		{
			destroyBox(boxEl);
		}
		delete box;
	}
}
template <class T>
bool Box<T>::removeBox(T const& boxName)
{
	Box<T>* toDel = new Box<T>;
	for (Box<T>* box : insideBoxes)
	{
		if (box->getName() == boxName)
		{
			toDel = box;
		}
	}
	if (toDel->getName().empty())
	{
		return false;
	}
	insideBoxes.remove(toDel);
	destroyBox(toDel);
}
template <class T>
bool Box<T>::removeBox(Box<T>* const& toDel)
{
	return removeBox(toDel->name);
}
#endif // !_BOX_HPP



