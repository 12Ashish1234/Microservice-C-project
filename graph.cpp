#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <gtest/gtest.h>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    vector<int> dijkstra(int start, int n) {
        vector<int> dist(n, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (auto &[neighbor, weight] : adj[node]) {
                int newDist = dist[node] + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        return dist;
    }
};

TEST(GraphTest, DijkstraBasic) {
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    
    vector<int> distances = g.dijkstra(0, 4);
    vector<int> expected = {0, 3, 1, 4};
    ASSERT_EQ(distances, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
