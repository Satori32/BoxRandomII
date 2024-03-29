#include <iostream>

#include "BoxRandom.h"

int main() {
	BoxRandomII<std::size_t> B;
	std::size_t L = 16;
	for (std::size_t i = 0; i < L; i++) {
		B.Push(i);
	}
	std::mt19937 mt(0xdeadbeef);
	B.Shuffle(mt);
	for (std::size_t i = 0; i < B.Size(); i++) {
		std::cout << B.Get() << ',';
		B.Forward();
	}
	std::cout<<std::endl;

	return 0;
}