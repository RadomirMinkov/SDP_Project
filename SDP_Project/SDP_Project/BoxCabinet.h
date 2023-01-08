#ifndef _BOXCABINET_HPP
#define _BOXCABINET_HPP
#include <vector>
#include "Box.h"
class BoxCabinet
{
private:
	std::list<Box<std::string>>cabinet;
	
public:
	BoxCabinet() = default;
	BoxCabinet(BoxCabinet const& other) = delete;
	BoxCabinet const& operator=(BoxCabinet const&) = delete;
	~BoxCabinet() {};

	void optimizeBoxCabinet();
	void optimizeBoxCabinetHelper(std::vector<std::string>);
	std::list<Box<std::string>> const& getCabinet() const { return cabinet; }
	std::list<Box<std::string>>& getCabinet() { return cabinet; }
};
#endif

