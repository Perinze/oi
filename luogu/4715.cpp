#include <iostream>
using namespace std;

int tree[128];
int map[128];

inline int lkid(int x)
{
	return x * 2;
}

inline int rkid(int x)
{
	return x * 2 + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < (1 << N); i++)
	{
		int w;
		cin >> w;
		tree[i] = w;
		map[i] = i + 1;
	}
	for (int i = (1 << (N - 1)); i > 1; i /= 2)
	{
		//cout << "i=" << i << endl;
		for (int j = 0; j < i; j++)
		{
			int a = lkid(j), b = rkid(j);
			tree[j] = max(tree[a], tree[b]);
			map[j] = tree[a]>tree[b]?map[a]:map[b];
			//cout << tree[j] << ' ';
		}
		//cout << endl;
	}
	cout << ((tree[1]>tree[0])?map[0]:map[1]);

	return 0;
}
