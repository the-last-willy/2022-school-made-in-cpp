#include <decl.hpp>

#include <cmath>
#include <iostream>

using namespace decl;
using namespace decl::detail;

struct floor_ {};

template<typename C, typename Ty>
Ty recipe(C, floor_, Ty x) {
	std::cout << "floor" << std::endl;
	return std::floor(x);
}

struct fract {};

template<typename Ty>
auto prerequisites(fract, Ty) -> targets<floor_>;

template<typename C, typename Ty>
Ty recipe(C c, fract, Ty x) {
	std::cout << "fract" << std::endl;
	return x - c.ref<floor_>();
}

int main() {
	auto [i] = make<floor_>(4.5);
}
