#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

struct Node {
	int vertex;
	struct Node* next;
};

struct Node* createNode(int v) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph {
	int numVertices;
	struct Node** adjLists;
};

struct Graph* createGraph(int vertices) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(struct Node*));
	
	int i;
	for (i = 0; i< vertices; i++) {
		graph->adjLists[i] = NULL;
	}
	
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	struct Node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
	
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
	struct Node* adjList = graph->adjLists[vertex];
	struct Node* temp = adjList;
	
	visited[vertex] = 1;
	printf("Visited %d \n", vertex);
	
	while (temp != NULL) {
		int connectedVertex = temp->vertex;
		
		if (visited[connectedVertex] == 0) {
			DFS(graph, connectedVertex);
		}
		temp = temp->next;
	}
}

int main() {
	int vertices = 4;
	struct Graph* graph = createGraph(vertices);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	
	int i;
	for (i = 0; i< vertices; i++) {
		visited[i] = 0;
	}
	
	DFS(graph, 0);
	
	return 0;
}
