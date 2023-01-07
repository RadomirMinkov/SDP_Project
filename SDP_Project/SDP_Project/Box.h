#ifndef _BOX_HPP
#define _BOX_HPP
#include <string>
#include <vector>
#include <set>
template <class T>
class Box
{
private:
	T name;
	std::set<T> souvenirs;
	std::vector<Box<T>> insideBoxes;
public:
	Box() = default;
	Box(T const& _name);

	bool addSouvenir(T const&);
	bool addBox(Box const&);

	bool removeSouvenir(T const&);
	bool removeBox(Box const&);

	T const& getName() const { return name; }
	std::set<T> const& getSouvenirs()const { return souvenirs; }
	std::set<T>& getSouvenirs() { return souvenirs; }
	std::vector<Box> const& getInsideBoxes() const { return insideBoxes; }
	std::vector<Box>& getInsideBoxes() { return insideBoxes; }
};
template <class T>
Box<T>::Box(T const& _name) : name(_name)
{
}
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
#endif // !_BOX_HPP



