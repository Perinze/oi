#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

double add(double a, double b) {
	if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct point {
	double x, y, z;
	point() {}
	point(double nx, double ny, double nz): x(nx), y(ny), z(nz) {}
	point operator+(const point &p) {
		return point(add(x, p.x), add(y, p.y), add(z, p.z));
	}
	point operator-(const point &p) {
		return point(add(x, -p.x), add(y, -p.y), add(z, -p.z));
	}
	point operator*(double d) {
		return point(x * d, y * d, z * d);
	}
	double mod() {
		return sqrt(x * x + y * y + z * z);
	}
};

point A, B, C, D;
double k1, k2;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		double x, y, z;
		cin >> x >> y >> z;
		A = point(x, y, z);
		cin >> x >> y >> z;
		B = point(x, y, z);
		cin >> x >> y >> z;
		C = point(x, y, z);
		cin >> x >> y >> z;
		D = point(x, y, z);
		cin >> k1 >> k2;

		point AB = B - A;
		double dAB = AB.mod();
		double dAO1 = dAB * (k1 / (k1 + 1) + k1 / (k1 * k1 - 1));
		point AO1 = AB * (dAO1 / dAB);
		point O1 = A + AO1;
		double R1 = dAB * k1 / (k1 * k1 - 1);
		//cout << "R1 " << R1 << endl;

		point CD = D - C;
		double dCD = CD.mod();
		double dCO2 = dCD * (k2 / (k2 + 1) + k2 / (k2 * k2 - 1));
		point CO2 = CD * (dCO2 / dCD);
		point O2 = C + CO2;
		double R2 = dCD * k2 / (k2 * k2 - 1);
		//cout << "R2 " << R2 << endl;
		point O1O2 = O2 - O1;
		double d = O1O2.mod();
		double V1 = 4.0 / 3.0 * M_PI * R1 * R1 * R1;
		double V2 = 4.0 / 3.0 * M_PI * R2 * R2 * R2;
		if (max(R1, R2) - min(R1, R2) - d >= -eps) {
			cout << min(V1, V2) << endl;
			continue;
		}
		
		if (R1 + R2 - d <= eps) {
			cout << 0 << endl;
			continue;
		}
		if (abs(d) < eps) {
			cout << min(V1, V2) << endl;
			continue;
		}

		double cosa = (R2 * R2 + d * d - R1 * R1) / (R2 * 2 * d);
		double h1 = R2 * (1 - cosa);
		double cosb = (R1 * R1 + d * d - R2 * R2) / (R1 * 2 * d);
		double h2 = R1 * (1 - cosb);
		double V = M_PI * ((R2 * 3 - h1) * h1 * h1 + (R1 * 3 - h2) * h2 * h2) / 3.0;
		cout << V << endl;
	}
	return 0;
}