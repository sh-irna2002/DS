#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n; // Number of vertices in the graph
int adj[MAX][MAX] = {0}; // Adjacency Matrix initialized to 0

void create_graph();
int queue[MAX], front = -1, rear = -1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int indegree(int v);

int main() {
    int i, v, count, topo_order[MAX], indeg[MAX];

    create_graph();

    // Find the indegree of each vertex
    for (i = 0; i < n; i++) {
        indeg[i] = indegree(i);
        if (indeg[i] == 0)
            insert_queue(i);
    }

    count = 0;

    while (!isEmpty_queue() && count < n) {
        v = delete_queue();
        topo_order[count++] = v; // Add vertex v to topo_order array

        // Delete all edges going from vertex v
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                adj[v][i] = 0;
                indeg[i] = indeg[i] - 1;
                if (indeg[i] == 0)
                    insert_queue(i);
            }
        }
    }

    if (count < n) {
        printf("\nNo topological ordering possible, graph contains cycle\n");
        exit(1);
    }

    printf("\nVertices in topological order are:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");

    return 0;
}

// Function to insert an element into the queue
void insert_queue(int vertex) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow\n");
    } else {
        if (front == -1) // If queue is initially empty
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to check if the queue is empty
int isEmpty_queue() {
    return (front == -1 || front > rear);
}

// Function to delete an element from the queue
int delete_queue() {
    if (isEmpty_queue()) {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

// Function to calculate the indegree of a vertex
int indegree(int v) {
    int i, in_deg = 0;
    for (i = 0; i < n; i++) {
        if (adj[i][v] == 1)
            in_deg++;
    }
    return in_deg;
}

// Function to create the graph
void create_graph() {
    int i, max_edges, origin, destin;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        printf("\nEnter edge %d (-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if (origin == -1 && destin == -1)
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("\nInvalid edge!\n");
            i--;
        } else {
            adj[origin][destin] = 1;
        }
    }
}
