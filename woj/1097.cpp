#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B)
{
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++)
	{
		for (int k = 0; k < B.size(); k++)
		{
			for (int j = 0; j < B[0].size(); j++)
			{
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
			}
		}
	}
	return C;
}

mat pow(mat A, ll n)
{
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); i++)
	{
		B[i][i] = 1;
	}
	while (n > 0)
	{
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

void solve()
{
	int n; cin >> n;
	mat A(2, vec(2));
	A[0][0] = 1; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 0;
	A = pow(A, n);
	cout << A[1][0] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
