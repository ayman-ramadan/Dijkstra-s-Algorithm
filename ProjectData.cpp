#include <iostream>
#include <limits.h>
using namespace std;
// Number of vertices in the graph
#define Vertex 9

int minDistance(int dist[], bool SPTSet[]) // Shortest path tree
{
    int min = INT_MAX;
    int min_index;
    
    for (int v = 0; v < Vertex; v++) {
        if (SPTSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    char charArray[9] = {'A','B','C','D','E','F','G','H','I'};
    cout << "Vertex \t \t Distance from Source (A) TO the distenation (Each node) " << endl;
    for (int i = 0; i < Vertex; i++) {
        cout << charArray[i] << "\t\t\t" << dist[i] << endl;
    }

    // For the applecation
    cout<<"The Shortest Distance From Summed To HQ is : "<< dist[4] << " Mil" << endl; 
    //cout << charArray[4] << "\t" 
}
void printProgress(int iteration, int vertex, int distance)
{
    char charArray[9] = {'A','B','C','D','E','F','G','H','I'};
    cout << "Iteration " << iteration << ": Visited Vertex " << charArray[vertex] << ", Distance = " << distance <<endl;
}

// adjacency matrix implementation
void dijkstra(int graph[Vertex][Vertex], int source)
{
    int dist[Vertex];
    bool SPTSet[Vertex];

    for (int i = 0; i < Vertex; i++) {
        dist[i] = INT_MAX;
        SPTSet[i] = false;
    }

    dist[source] = 0; // Distance of source vertex from itself is always = 0 

     // Find shortest path for all vertices
    for (int count = 0; count < Vertex - 1; count++) {
        int u = minDistance(dist, SPTSet); //first iteration (sourse)
        SPTSet[u] = true;

        // Update distance value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < Vertex; v++) {
            if (!SPTSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                printProgress(count + 1, v, dist[v]);
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[Vertex][Vertex] = {
        { 0, 5, 0, 0, 0, 0, 0, 9, 0 },
        { 5, 0, 9, 0, 0, 0, 0,12, 0 },
        { 0, 9, 0, 6, 0, 3, 0, 0, 2 },
        { 0, 0, 6, 0, 8,14, 0, 0, 0 },
        { 0, 0, 0, 8, 0,10, 0, 0, 0 },
        { 0, 0, 3, 14,10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 9, 12,0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };
    
    cout << "Dijkstra's Algorithm Progress:" <<endl;
    dijkstra(graph, 0);

    return 0;
}