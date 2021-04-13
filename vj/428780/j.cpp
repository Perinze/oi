#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll base1 = 859247592;
const ll base2 = 2347813021;

ll gethash(mat map, mat &hash, int h, int w)
{
    hash = map;
    for (int i = 0; i < h; i++)
        for (int j = 1; j < w; j++)
            hash[i][j] += hash[i][j - 1] * base1;
    for (int j = 0; j < w; j++)
        for (int i = 1; i < h; i++)
            hash[i][j] += hash[i - 1][j] * base2;
    return hash[h - 1][w - 1];
}