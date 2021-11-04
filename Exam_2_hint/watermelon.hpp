#include "seed.hpp"
#include <vector>

class Watermelon : public Seed {
	private:
		std::vector<Seed> _seeds;
	public:
		Watermelon();
		Watermelon(const std::vector<Seed> &s);
};
