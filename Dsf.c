#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};
struct Node* stack = NULL;

struct Graph{
    int vertices;
    struct Node** adjList;
};
struct Graph* graph = NULL;

struct Node* newNode(int value,struct Node* link){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->link = link;
    return temp;
}

void push(int value){
    struct Node* temp = newNode(value,stack);
    stack = temp;
}
int pop(){
    if(stack == NULL){
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack->data;
    struct Node* temp = stack;
    stack = stack->link;
    free(temp);
    return value;
}
void createGraph(int n){
    graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = n;
    graph->adjList = (struct Node**)malloc(n*sizeof(struct Node*));
    for(int i = 0; i < n;++i){
        graph->adjList[i] = NULL;
    }
}
void addEdge(int src, int value){
    graph->adjList[src] = newNode(value,graph->adjList[src]);
    graph->adjList[value] = newNode(src,graph->adjList[value]);
}
void DFS(int begin){
    int* visited = (int*)malloc(graph->vertices*sizeof(int));
    for(int i = 0;i < graph->vertices;++i) visited[i] = 0;
    push(begin);
    while(stack != NULL){
        int vertex = pop();
        if(!visited[vertex]){
            visited[vertex] = 1;
            printf("%d ",vertex);
            struct Node* temp = graph->adjList[vertex];
            while(temp != NULL){
                if(!visited[temp->data]) push(temp->data);
                temp = temp->link;
            }
        }
    }
    printf("\n");
}
void main(){
    int nv, option, e, v;
    printf("Enter no of vertices: ");
    scanf("%d",&nv);
    createGraph(nv);
    while(1){
        printf("1: Add edge\n2: DFS traversal\n3: Exit\nEnter an option: ");
        scanf("%d",&option);
        if(option == 1){
            printf("Enter edge value and map value: ");
            scanf("%d%d",&e,&v);
            addEdge(e,v);
        }else if(option == 2){
            printf("Enter starting vertex: ");
            scanf("%d",&v);
            DFS(v);
        }else if(option == 3){
            break;
        }else{
            printf("invalid option\n");
        }
    }
}
