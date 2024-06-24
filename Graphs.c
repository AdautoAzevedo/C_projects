#include <stdio.h>
#include <stdlib.h>

//Structure for a node in adjacency list
struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

//Structure for adjacency list
struct AdjList {
	struct AdjListNode* head; //Pointer to the head node
};

struct Graph {
	int V; //Number of vertices
	struct AdjList* array; //Array of adjacency lists
};

struct AdjListNode* newAdjListNode(int dest) {
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	
	//Create an array of adjacency lists
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
	
	//Initialize each adjacency list as empty
	int i;
	for (i = 0; i<V; i++) {
		graph->array[i].head = NULL;
	}
	
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
}

void printGraph(struct Graph* graph) {
	int v;
	for (v = 0; v < graph->V; v++) {
		struct AdjListNode* temp = graph->array[v].head;
		printf("\nAdjacency list of vertex %d\n head");
		while (temp) {
			printf("-> %d");
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int V = 5;
	
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	
	printf("Graph representation:\n");
	printGraph(graph);
	
	return 0;
}
