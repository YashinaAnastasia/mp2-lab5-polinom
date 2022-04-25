#pragma once
#include <iostream>

class TMonom {
public:
	double coef;
	int x, y, z;

	TMonom() : x(0), y(0), z(-1), coef(0) {}

	TMonom(double coef, int x, int y, int z) : x(x), y(y), z(z), coef(coef) {}

	TMonom& operator+(const TMonom& m) const {
		TMonom result(*this);
		result.coef += m.coef;
		return result;
	}

	bool operator==(const TMonom& m) const {
		return (m.x == x && m.y == y && m.z == z);
	}

	bool operator>(const TMonom& m) const {
		if (x > m.x) return true;
		if (x < m.x) return false;

		if (y > m.y) return true;
		if (y < m.y) return false;

		if (z > m.z) return true;
		if (z < m.z) return false;

		return false;
	}

	bool operator<(const TMonom& m) const {
		return !(*this > m);
	}

	friend std::ostream& operator<<(std::ostream& os, const TMonom& m) {
		os << m.coef << "*x^" << m.x << "*y^" << m.y << "*z^" << m.z;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, TMonom& m) {
		is >> m.coef >> m.x >> m.y >> m.z;
		return is;
	}
};

