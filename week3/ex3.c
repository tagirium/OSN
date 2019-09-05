#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node_t;

void print_list(node_t *head)
{
	node_t *it = head;
	while (it!=NULL)
	{
		printf("%d\n", it->val);
		it = it->next;
	}
}

int add_index(node_t **head, int val, int pos)
{
	if (pos==0)
	{
		node_t * it;
		it = (node_t*) malloc(sizeof(node_t));
		it->val = val;
		it->next = *head;
		*head = it;
		return 0;
	}
	node_t * it = *head;
	node_t * new_node;
	for(int i=0; i<pos; i++)
	{
		if (it==NULL)
			return 1;
		it=it->next;
	}
	new_node = (node_t*) malloc(sizeof(node_t));
	new_node ->val = val;
	new_node ->next = it->next;
	it->next = new_node;
	return 0;
}

int main()
{
	node_t *head = (node_t*) malloc(sizeof(node_t));
	for (int i = 0; i < 7; i++)
		add_index(&head, 2 * i + 1, i);
	print_list(head);
}
