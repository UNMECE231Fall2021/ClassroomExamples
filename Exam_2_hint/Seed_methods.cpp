#include "seed.hpp"

Seed::Seed() : _name{"tofu"} {}
Seed::Seed(std::string name) : _name{name} {}

std::ostream &operator<<(std::ostream &out, const Seed &s) {
	out << "I am a " << s._name << " seed";
	return out;
}
