#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Graph
{
	int v;
	int e;
	int **adj;
} Graph;

typedef struct Queue
{
	Node *front, *rear;
} Queue;

Node *newNode(int data)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Queue *creatQueue()
{
	Queue *temp = malloc(sizeof(Queue));
	temp->front = temp->rear = NULL;
	return temp;
}

void enQueue(Queue *q, int data)
{
	void *temp = newNode(data);
	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(Queue *q)
{
	if (q->front == NULL)
	{
		return;
	}
	q->front = q->front->next;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}

void push(Node **n, int data)
{
	Node *temp = newNode(data);

	if (*n == NULL)
	{
		*n = temp;
		return;
	}

	Node *p = *n;
	while (p->next)
	{
		p = p->next;
	}
	p->next = temp;
	return;
}

void stackPush(Node **top, int data)
{
	Node *temp = newNode(data);
	if (*top == NULL)
	{
		*top = temp;
		return;
	}
	temp->next = *top;
	*top = temp;
}

int stackPop(Node **top)
{
	int popped = 0;
	if (*top == NULL)
	{
		printf("Stack is empty can't pop\n");
		return -1;
	}
	else
	{
		popped = (*top)->data;
		*top = (*top)->next;
		return popped;
	}
}
void printStack(Node *top)
{
	if (top == NULL)
	{
		return;
	}
	while (top)
	{
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}

Graph *makeGraph(int v, int e)
{
	Graph *g = malloc(sizeof(Graph));
	g->v = v;
	g->e = e;
	g->adj = malloc(v * sizeof(int *));
	for (int i = 0; i < v; i++)
	{
		g->adj[i] = malloc(g->v * sizeof(int));
		memset(g->adj[i], 0, g->v * sizeof(int));
	}
	return g;
}

void addEdge(Graph *g, int start, int e)
{
	g->adj[start][e] = 1;
	g->adj[e][start] = 1;
}

void BFS(Graph *g, int start)
{
	_Bool *visited = malloc(g->v * sizeof(_Bool));
	memset(visited, 0, g->v * sizeof(_Bool));
	Queue *q = creatQueue();
	enQueue(q, start);
	visited[start] = 1;

	int vis = 0;
	while (q->front != NULL)
	{
		vis = q->front->data;
		printf("%d ", vis);
		deQueue(q);
		for (int i = 0; i < g->v; i++)
		{
			if (g->adj[vis][i] == 1 && (!visited[i]))
			{
				enQueue(q, i);
				visited[i] = 1;
			}
		}
	}
}

void DFS(Graph *g, int start){
	_Bool *visited = malloc(g->v * sizeof(_Bool));
	memset(visited, 0, g->v * sizeof(_Bool));
	Node *stack = NULL;
	stackPush(&stack, start);
	visited[start] = 1;
	printf("%d ",start);
	int vis = 0;
	while (stack != NULL){
		vis = stack->data;
		if(visited[vis]==0){
			printf("%d ", vis);
		}
		visited[vis] = 1;
		for (int i = 0; i < g->v; i++){
			if (g->adj[vis][i] && !visited[i]){
				stackPush(&stack, i);
				break;
			}
			if (i == ((g->v) - 1)){
				stackPop(&stack);
			}
		}
	}
}

int main()
{
	Graph *g = makeGraph(9, 11);

	addEdge(g, 1, 2);
	addEdge(g, 1, 8);
	addEdge(g, 1, 3);
	addEdge(g, 2, 4);
	addEdge(g, 2, 5);
	addEdge(g, 2, 8);
	addEdge(g, 3, 6);
	addEdge(g, 3, 7);
	addEdge(g, 4, 8);
	addEdge(g, 5, 8);
	addEdge(g, 6, 8);
	addEdge(g, 7, 8);

	for(int i=1;i<9;i++){
		DFS(g,i);
		printf("\n");
	}
}