#pragma once

class Color {

	int _R;
	int _G;
	int _B;

public:
	Color(int R, int G, int B);
	int getR() const;
	int getG() const;
	int getB() const;
	Color toGray() const;
};
