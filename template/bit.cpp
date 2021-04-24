// [1, N]
int bit[maxn], n;

int query(int i_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

inline int query(int i, int j)
{
	return query(j) - query(i - 1);
}

int add(int i_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

// [1, N][1, M]
int bit[maxn][maxm], n, m;

int query(int i_, int j_)
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		for (int j = j_; j > 0; j -= j & -j)
			s += bit[i][j];
	return s;
}

inline int query(int i1, int j1, int i2, int j2)
{
    return query(i2, j2) - query(i1 - 1, j2) - query(i2, j1 - 1) + query(i1 - 1, j1 - 1);
}

void add(int i_, int j_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		for (int j = j_; j <= m; j += j & -j)
			bit[i][j] += x;
}

// range modify, point query, range query O(n)
int bit[maxn], n; // bit stores d[i] = a[i] - a[i - 1]

int query(int i_) // query a[i], not prefix sum pre[i]
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

void add(int l, int r, int x) // add x to every element of [l, r]
{
	add(l, x), add(r + 1, -x);
}