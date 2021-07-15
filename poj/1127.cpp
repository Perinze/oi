#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 15;
const double eps = 1e-10;

double add(double a, double b) {
	if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct point {
	double x, y;
	point() {}
	point(double nx, double ny): x(nx), y(ny) {}
	point operator+(point p) {
		return point(add(x, p.x), add(y, p.y));
	}
	point operator-(point p) {
		return point(add(x, -p.x), add(y, -p.y));
	}
	point operator*(double d) {
		return point(x * d, y * d);
	}
	double operator*(point p) {
		return add(x * p.x, y * p.y);
	}
	double operator^(point p) {
		return add(x * p.y, -y * p.x);
	}
};

bool onseg(point p1, point p2, point q) {
	return ((p1 - q) ^ (p2 - q)) == 0 && ((p1 - q) * (p2 - q)) <= 0;
}

point intersection(point p1, point p2, point q1, point q2) {
	return p1 + (p2 - p1) * (((q2 - q1) ^ (q1 - p1)) / ((q2 - q1) ^ (p2 - p1)));
}

int n;
point p[maxn], q[maxn];
bool g[maxn][maxn];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		memset(g, 0, sizeof(g));
		int x1, y1, x2, y2;
		for (int i = 1; i <= n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			p[i] = point(x1, y1);
			q[i] = point(x2, y2);
		}
		for (int i = 1; i <= n; i++) {
			g[i][i] = true;
			for (int j = i + 1; j <= n; j++) {
				// parallel
				if (((p[i] - q[i]) ^ (p[j] - q[j])) == 0) {
					g[i][j] = g[j][i] = onseg(p[i], q[i], p[j])
									 || onseg(p[i], q[i], q[j])
									 || onseg(p[j], q[j], p[i])
									 || onseg(p[j], q[j], q[i]);
				} else {
					point r = intersection(p[i], q[i], p[j], q[j]);
					g[i][j] = g[j][i] = onseg(p[i], q[i], r) && onseg(p[j], q[j], r);
				}
				//if (g[i][j]) clog << i << " and " << j << " intersects" << endl;
				//else clog << i << " and " << j << " not intersects" << endl;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] |= g[i][k] && g[k][j];
				}
			}
		}
		int a, b;
		while (cin >> a >> b && a && b) {
			cout << (g[a][b] ? "CONNECTED" : "NOT CONNECTED") << endl;
		}
	}
	return 0;
}