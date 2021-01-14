#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int dat;
	struct node* next;
} node;

node* init();
void add(node*, int);

int main()
{
	node* head = init(head);
	for (int i = 0; i < 32; i++)
		add(head, i);

	node* n = head->next;
	while (n != NULL)
	{
		printf("%d\n", n->dat);
		n = n->next;
	}
	return 0;
}

node* init()
{
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

void add(node* V, int dat)
{
	while (V->next != NULL)
		V = V->next;
	node* new = (node*)malloc(sizeof(node));
	new->dat = dat;
	new->next = NULL;
	V->next = new;
}
