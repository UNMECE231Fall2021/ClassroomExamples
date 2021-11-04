#include "watermelon.hpp"

Watermelon::Watermelon() : Seed("watermelon"), _seeds() {}

Watermelon::Watermelon(const std::vector<Seed> &s) : Seed("watermelon"), 
	_seeds(s.size()) {
	std::copy(s.begin(), s.end(), _seeds.begin());
}
