const double eps = 1e-10;

double add(double a, double b) {
	if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct point {
	double x, y;
	point() {}
	point(double nx, double ny): x(nx), y(ny) {}
	point operator+(const point &p) {
		return point(add(x, p.x), add(y, p.y));
	}
	point operator-(const point &p) {
		return point(add(x, -p.x), add(y, -p.y));
	}
	point operator*(double d) {
		return point(x * d, y * d);
	}
	double operator*(const point &p) {
		return add(x * p.x, y * p.y);
	}
	double operator^(const point &p) {
		return add(x * p.y, -y * p.x);
	}
};

bool onseg(const point &p1, const point &p2, const point &q) {
	return (p1 - q) ^ (p2 - q) == 0 && (p1 - q) * (p2 - q) <= 0;
}

point intersection(const point &p1, const point &p2, const point &q1, const point &q2) {
	return p1 + (p2 - p1) * ((q2 - q1) ^ (q1 - p1) / (q2 - q1) ^ (p2 - p1));
}