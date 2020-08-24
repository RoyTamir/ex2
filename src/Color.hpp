#pragma once

#include <cstdint>

using std::uint16_t;
class Color {

	uint16_t _R;
	uint16_t _G;
	uint16_t _B;

public:
	Color(uint16_t R, uint16_t G, uint16_t B);
	uint16_t getR() const;
	uint16_t getG() const;
	uint16_t getB() const;
	Color toGray() const;
};
