#ifndef BASE_SEED_HPP
#define BASE_SEED_HPP

#include <iostream>
#include <string>

class Seed {
	protected:
		std::string _name;

	public:
		Seed();
		Seed(std::string name);

		friend std::ostream &operator<<(std::ostream &out, const Seed &s);
};

#endif // BASE_SEED_HPP
