#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <set>
#include <algorithm>

using namespace std;

// Define Point structure for TSP
struct Point
{
    int x, y;
};

// Function to calculate distance between two points for TSP
double distance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Nearest Neighbor Heuristic for TSP
double nearestNeighbor(vector<Point> &points)
{
    int n = points.size();
    vector<bool> visited(n, false);
    double totalDistance = 0.0;
    int current = 0;
    visited[current] = true;
    int count = 1;

    while (count < n)
    {
        double minDist = INT_MAX;
        int nextCity = -1;

        // Find the nearest unvisited city
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                double dist = distance(points[current], points[i]);
                if (dist < minDist)
                {
                    minDist = dist;
                    nextCity = i;
                }
            }
        }

        // Move to the next city
        visited[nextCity] = true;
        totalDistance += minDist;
        current = nextCity;
        count++;
    }

    // Return to the starting city
    totalDistance += distance(points[current], points[0]);

    return totalDistance;
}

// Graph representation for Vertex Cover
struct Graph
{
    int V;
    vector<vector<int>> adj;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void vertexCover()
    {
        vector<bool> visited(V, false);
        vector<int> cover;

        // Greedy approximation for Vertex Cover
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                for (int v : adj[u])
                {
                    if (!visited[v])
                    {
                        visited[u] = visited[v] = true;
                        cover.push_back(u);
                        cover.push_back(v);
                        break;
                    }
                }
            }
        }

        cout << "Vertex Cover: ";
        for (int i : cover)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

// Greedy Set Cover 1-Approximation Algorithm
set<int> greedySetCover(const vector<set<int>> &sets, const set<int> &universe)
{
    set<int> cover;
    set<int> uncovered = universe;

    while (!uncovered.empty())
    {
        int bestSetIndex = -1;
        int maxCoverCount = 0;
        set<int> bestSet;

        // Find the set that covers the most uncovered elements
        for (int i = 0; i < sets.size(); i++)
        {
            int count = 0;
            set<int> intersection;
            set_intersection(sets[i].begin(), sets[i].end(), uncovered.begin(), uncovered.end(),
                             inserter(intersection, intersection.begin()));
            if (intersection.size() > maxCoverCount)
            {
                maxCoverCount = intersection.size();
                bestSet = sets[i];
                bestSetIndex = i;
            }
        }

        // Add the best set to the cover and update uncovered
        cover.insert(bestSet.begin(), bestSet.end());
        set<int> temp;
        set_difference(uncovered.begin(), uncovered.end(), bestSet.begin(), bestSet.end(),
                       inserter(temp, temp.begin()));
        uncovered = temp;
    }

    return cover;
}

// Main Menu for choosing the algorithm
void displayMenu()
{
    cout << "-------------------------------------------------" << endl;
    cout << "Select a problem to solve using Approximation Algorithms:" << endl;
    cout << "1. Traveling Salesman Problem (TSP)" << endl;
    cout << "2. Vertex Cover Problem" << endl;
    cout << "3. Set Cover Problem" << endl;
    cout << "4. Exit" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

// Main function to test all algorithms
int main()
{
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Testing Traveling Salesman Problem (TSP):" << endl;
            vector<Point> points = {{0, 0}, {1, 2}, {2, 4}, {3, 1}, {4, 3}};
            double tspResult = nearestNeighbor(points);
            cout << "Approximate TSP solution distance: " << tspResult << endl
                 << endl;
            break;
        }
        case 2:
        {
            cout << "Testing Vertex Cover Problem:" << endl;
            Graph g(5);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(1, 3);
            g.addEdge(2, 4);
            g.vertexCover();
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Testing Set Cover Problem:" << endl;
            set<int> universe = {1, 2, 3, 4, 5, 6};
            vector<set<int>> sets = {{1, 2, 3}, {2, 4}, {3, 5}, {4, 6}};
            set<int> cover = greedySetCover(sets, universe);
            cout << "Set Cover: ";
            for (int x : cover)
            {
                cout << x << " ";
            }
            cout << endl;
            break;
        }
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please select again." << endl;
        }

    } while (choice != 4);

    return 0;
}