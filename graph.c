#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct Graph{
    int v;
    int e;
    int **adj;
}Graph;

typedef struct Queue{
    Node * front,*rear;
}Queue;

Node * newNode(int data){
    Node * temp=malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

Queue * creatQueue(){
    Queue * temp=malloc(sizeof(Queue));
    temp->front=temp->rear=NULL;
    return temp;
}

void enQueue(Queue * q,int data){
    void* temp=newNode(data);
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

void deQueue(Queue * q){
    if(q->front==NULL){
        return;
    }
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
}

void push(Node ** n,int data){
    Node * temp=newNode(data);
    
    if(*n==NULL){
        *n=temp;
        return;
    }
    
    Node * p=*n;
    while(p->next){
        p=p->next;
    }
    p->next=temp;
    return;
}
void fill(int * arr,int n){
    for(int i=0;i<n;i++){
        *(arr+i)=0;
    }
}
Graph * makeGraph(int v,int e){
    Graph * g=malloc(sizeof(Graph));
    g->v=v;
    g->e=e;
    g->adj=malloc(v*sizeof(int*));
    for(int i=0;i<v;i++){
        g->adj[i]=malloc(5*sizeof(int));
        fill(g->adj[i],v);
    }
    return g;
}

void addEdge(Graph * g,int start,int e){
    g->adj[start][e]=1;
    g->adj[e][start]=1;
}


void BFS(Graph * g,int start){
    _Bool * visited=malloc(g->v*sizeof(_Bool));
    for(int i=0;i<g->v;i++){
        visited[i]=0;
    }
    Queue * q=creatQueue();
    enQueue(q,start);
    visited[start]=1;
    
    int vis=0;
    while(q->front!=NULL){
        vis=q->front->data;
        printf("%d ",vis);
        deQueue(q);
        for(int i=0;i<g->v;i++){
            if (g->adj[vis][i] == 1 && (!visited[i])) {
                enQueue(q,i);
                visited[i] = 1;
            }
        }
    }
}
int main(){
    Graph * g=makeGraph(5,4);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,3);
    BFS(g,0);
}