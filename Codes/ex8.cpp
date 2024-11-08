#include <iostream>
#include <climits>
using namespace std;
const int MAX = 100;
struct Edge
{
    int v;
    int weight;
};
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[MAX];
    bool sptSet[MAX];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t" << dist[i] << endl;
    }
}
int main()
{
    int V, E, u, v, w, src;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    int graph[MAX][MAX] = {0};
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    cout << "Enter the source vertex: ";
    cin >> src;
    dijkstra(graph, V, src);
    return 0;
}
