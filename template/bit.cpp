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

// range modify, range query, 
int bit[2][maxn], n; // bit[0] stores d[i] = a[i] - a[i - 1], bit[1] stores (i - 1) * d[i]

int query(int *bit, int i_) // query a[i], not prefix sum pre[i]
{
	int s = 0;
	for (int i = i_; i > 0; i -= i & -i)
		s += bit[i];
	return s;
}

void add(int *bit, int i_, int x)
{
	for (int i = i_; i <= n; i += i & -i)
		bit[i] += x;
}

int query(int i)
{
    return i * query(bit[0], i) - query(bit[1], i);
}

int query(int l, int r) // query sum of [l, r]
{
    return query(r) - query(l - 1);
}

void add(int l, int r, int x) // add x to every element of [l, r]
{
	add(bit[0], l, x), add(bit[0], r + 1, -x);
    add(bit[1], l, (l - 1) * x), add(bit[1], r + 1, r * (-x));
}
