#pragma once
#include <vector>
#include <random>
#include <cstdint>


template <class T>
class BoxRandomII {
public:
	typedef T ValueType;

	bool Push(const T& In) {
		Box.push_back(In);
		return true;
	}

	const T& Get()const {
		return Box[Idx % Box.size()];
	}

	template<class Rnd>
	bool Shuffle(Rnd& R) {
		std::shuffle(Box.begin(), Box.end(), R);
		Idx = 0;
		return true;
	}
	bool Randomize(const unsigned int& Seed=0) {
		std::mt19937 mt(Seed);
		std::shuffle(Box.begin(), Box.end(), mt);
		Idx = 0;
		return true;
	}
	std::intmax_t Remaining() const{
		return ((std::intmax_t)Box.size()) - Idx;
	}

	const T& operator [](std::size_t In)const {
		return Box[In%Box.size()];
	}
	bool Forward() {
		Idx++;
		Idx %= Box.size();
		return true;
	}
	bool Round() {
		Idx %= Box.size();
		return true;
	}
	std::size_t Now() {
		return Idx;
	}
	std::size_t Size() {
		return Box.size();
	}

	bool Clear() {
		Box.clear();
		Idx = 0;
		return 0;
	}

	typename std::vector<T>::const_iterator begin()const {
		return Box.cbegin();
	}
	typename std::vector<T>::const_iterator end()const {
		return Box.cend();
	}
protected:
	std::vector<T> Box;
	std::size_t Idx = 0;
};