#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a node and its weight
struct Node {
    int vertex, weight;
    Node(int v, int w) : vertex(v), weight(w) {}
    
    // Custom comparator for the priority queue to create a min-heap
    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    
    // Vector to store the shortest distance from source to each node
    vector<int> distances(n, numeric_limits<int>::max());
    
    // Priority queue to store {weight, vertex}
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Initialize distance of source node
    distances[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        int u = pq.top().vertex;
        int currentDistance = pq.top().weight;
        pq.pop();

        // If a shorter path to u has already been found, skip
        if (currentDistance > distances[u]) {
            continue;
        }

        // Iterate through all adjacent vertices of u
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If a shorter path to v is found
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(Node(v, distances[v]));
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source (" << source << ")" << endl;
    for (int i = 0; i < n; i++) {
        if (distances[i] == numeric_limits<int>::max()) {
             cout << i << "\tINF" << endl;
        } else {
             cout << i << "\t" << distances[i] << endl;
        }
    }
}

int main() {
    // Number of vertices in the graph
    int n = 5;

    // Adjacency list representation of the graph: vector of vectors of pairs (vertex, weight)
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges (undirected graph for this example)
    graph[0].push_back({1, 9});
    graph[0].push_back({2, 6});
    graph[0].push_back({3, 5});
    graph[0].push_back({4, 3});
    
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 4});
    
    // Adding reverse edges for undirected graph
    graph[1].push_back({0, 9});
    graph[2].push_back({0, 6});
    graph[3].push_back({0, 5});
    graph[4].push_back({0, 3});
    
    graph[1].push_back({2, 2});
    graph[3].push_back({2, 4});

    cout << "Running Dijkstra's Algorithm:" << endl;
    dijkstra(graph, 0);

    return 0;
}
