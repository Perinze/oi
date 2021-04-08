#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	struct Node* next;
	struct Node* previous;
} node;

int N;
node** map;	// point to every chain node i

void init(int N)
{
	// init the first node
	node* first = (node*)malloc(sizeof(node));
	first->id = 1;
	first->previous = NULL;
	first->next = NULL;

	// init the map
	map = (node**)malloc((N + 1) * sizeof(node*));
	map[0] = first;	// map[0] is head
	map[1] = first;
}

void insert(int id, int k, int p)
{
	node* new = (node*)malloc(sizeof(node));
	new->id = id;
	map[id] = new;
	if (p == 0)	// left
	{
		// get k and k's previous
		node* nxt = map[k];
		node* pre = nxt->previous;

		// connect new and k
		new->next = nxt;
		nxt->previous = new;

		// if k is the front
		if (pre == NULL)
		{
			// set new the front
			new->previous = NULL;
			map[0] = new;
		}
		else
		{
			pre->next = new;
			new->previous = pre;
		}
	}
	else	// if (p == 1)
	{
		node* pre = map[k];
		node* nxt = pre->next;

		pre->next = new;
		new->previous = pre;

		if (nxt == NULL)
		{
			new->next = NULL;
		}
		else
		{
			new->next = nxt;
			nxt->previous = new;
		}
	}
}

void rm(int x)
{
	node* n = map[x];
	node* pre = n->previous;
	node* nxt = n->next;
	//printf("in rm(%d) %d %d %d\n", x, pre->id, n->id, nxt->id);
	
	if (pre == NULL && nxt != NULL)	// node is head
	{
		//printf("set %d head\n", nxt->id);
		map[0] = nxt;
	}
	if (pre != NULL)
	{
		//printf("set %d->next %d\n", pre->id, nxt->id);
		pre->next = nxt;
	}
	if (nxt != NULL)
	{
		//printf("set %d->previous %d\n", nxt->id, pre->id);
		nxt->previous = pre;
	}
	n->previous = NULL;
	n->next = NULL;
	//putchar('\n');
}

void print_chain()
{
	node* n = map[0];
	printf("%d", n->id);
	n = n->next;
	while (n != NULL)
	{
		printf(" %d", n->id);
		n = n->next;
	}
	putchar('\n');
}

int main()
{
	scanf("%d", &N);
	init(N);
	int i;
	for (i = 2; i <= N; i++)
	{
		int k, p;
		scanf("%d %d", &k, &p);
		insert(i, k, p);
	}
	//print_chain();

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int x;
		scanf("%d", &x);
		rm(x);
	}
	print_chain();
	return 0;
}
