#include <stdio.h>
#include <string.h>

const int INF = 100000;
unsigned int Mem[101];
unsigned int timestamp[101];
unsigned int map[10001];
int time;
int mem_s;
int back;

void push(int dat)
{
	if (back <= mem_s)	
	{
		timestamp[back] = time;
		map[dat] = back;
		Mem[back++] = dat;
	}
	else
	{
		int lotime = INF, p = 0;
		for (int i = 1; i <= mem_s; i++)
		{
			if (timestamp[i] < lotime)
			{
				lotime = timestamp[i];
				p = i;
			}
		}
		map[Mem[p]] = 0;
		timestamp[p] = time;
		map[dat] = p;
		Mem[p] = dat;
	}
}

void update(int dat)
{
	timestamp[map[dat]] = time;
}

void request(int dat)
{
	if (map[dat]) update(dat);
	else push(dat);
	time++;
}

void print_mem()
{
	for (int i = 1; i <= mem_s; i++)
	{
		printf("%d %d\n", i, Mem[i]);
	}
}

void solve()
{
	int req_t;
	scanf("%d %d", &req_t, &mem_s);
	memset(Mem, 0, sizeof(Mem));
	memset(timestamp, 0, sizeof(timestamp));
	memset(map, 0, sizeof(map));
	back = 1, time = 0;
	for (int r = 0; r < req_t; r++)
	{
		int dat;
		scanf("%d", &dat);
		request(dat);
	}
	print_mem();
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) solve();
	return 0;
}
