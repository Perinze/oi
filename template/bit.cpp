// [1, N]
int bit[maxn], n;

int sum(int i_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

void add(int i_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

int bit[maxn][maxm], n, m;

int sum(int i_, int j_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		for (int j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

void add(int i_, int j_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		for (int j = j_; j <= m; j += j & -j)
			bit[i][j] += x;
}
