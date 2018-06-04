#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;
Node* insert(Node *head, int value)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = value;
	//printf("Hello\n");
	if(head == NULL)
	{
		new_node->next = NULL;
		return new_node;
	}
	else
	{
		new_node->next = head;
		return new_node;
	}
}
int count = 0;
void print(Node *head, int positionFromTail)
{
	if(head != NULL)
	{
		print(head->next, positionFromTail);
		if(count == positionFromTail)
			printf("Data: %i Count: %i\n",head->data,count);
		count++;
	}
}
void print_list(Node *head)
{
	while(head != NULL)
	{
		printf("Data: %i\n",head->data);
		head = head->next;
	}
}
void merge_two_list(Node *headA, Node *headB)
{
	Node *head = (Node*) malloc(sizeof(Node));
	head = NULL;
	while(headA != NULL && headB != NULL)
	{
		if(headA->data < headB->data)
		{
			
		}
	}
}
int main()
{
	Node *head_a = (Node*) malloc(sizeof(Node));
	head_a = NULL;
	head_a = insert(head_a,30);
	head_a = insert(head_a,20);
	head_a = insert(head_a,10);
	Node *head_b = (Node*) malloc(sizeof(Node));
	head_b = NULL;
	head_b = insert(head_b,25);
	head_b = insert(head_b,15);
	head_b = insert(head_b,5);

	print_list(head_a);
	print_list(head_b);

	return 0;
}
