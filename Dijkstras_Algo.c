#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5
void dijkstra(int graph[V][V], int src) 
{
    int dist[V], visited[V] = {0}; 
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) 
    {
        int u = -1;
        for (int v = 0; v < V; v++) 
        {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) 
            {
                u = v;
            }
        }
        visited[u] = 1; 
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) 
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}
int main() 
{
    int graph[V][V] = 
    {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    dijkstra(graph, 0); 
    return 0;
}
