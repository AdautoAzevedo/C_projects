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

/* Functions to implement a BFS function */

// Creating a queue

struct Queue {
	int items[MAX];
	int front;
	int rear;
};

struct Queue* createQueue() {
	struct Queue* q = malloc(sizeof(struct Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(struct Queue* q) {
	return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
	if (q->rear == MAX -1) {
		printf("\nQueue if FULL!!");
	} else {
		if (q->front == -1) q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

int dequeue(struct Queue* q) {
	int item;
	if (isEmpty(q)) {
		printf("Queue is empty");
		item = -1;
	} else {
		item = q->items[q->front];
		q->front++;
		
		//Check if the front value is grater than rear (the list got empty)
		if (q->front > q->rear) {
			q->front = q->rear = -1;
		}
	}
	
	return item;
}

void printQueue(struct Queue* q) {
	int i = q->front;

	if (isEmpty(q)) {
		printf("Queue is empty");
	} else {
		for (i = q->front; i < q->rear + 1; i++) {
			printf("%d ", q->items[i]);
		}
	}
}

void BFS(struct Graph* graph, int startVertex) {
	struct Queue* q = createQueue();
	
	visited[startVertex] = 1;
	enqueue(q, startVertex);
	
	while (!isEmpty(q)) {
		printQueue(q);
		int currentVertex = dequeue(q);
		printf("Visited %d\n", currentVertex);
		
		struct Node* temp = graph -> adjLists[currentVertex];
		while (temp) {
			int adjVertex = temp->vertex;
			
			if(visited[adjVertex] == 0) {
				visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
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
	printf("DFS traversal starting from vertex 0:\n");
	DFS(graph, 0);
	
	// Reset visited array for BFS
	for (i = 0; i < vertices; i++) {
		visited[i] = 0;
	}

	printf("\nBFS traversal starting from vertex 0:\n");
	BFS(graph, 0);
	
	return 0;
}
