#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;



void push(Node **root, int data)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if (*root == NULL)
	{
		*root = temp;
		return;
	}
	Node *p = *root;
	while (1)
	{
		if (data > p->data)
		{
			if (p->right)
				p = p->right;
			else
			{
				p->right = temp;
				break;
			}
		}
		else if (data < p->data)
		{
			if (p->left)
				p = p->left;
			else
			{
				p->left = temp;
				break;
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	Node *root = NULL;
	push(&root, 4);
	push(&root, 3);
	push(&root, 5);
}