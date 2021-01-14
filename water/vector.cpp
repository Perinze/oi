#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;

vector<int> vct[10000];

int main()
{
	unsigned int N;
	scanf("%u", &N);

	for (int i = 0; i < N; i++)
		if (!vct[i].empty())
			vct[i].clear();

	return 0;
}
