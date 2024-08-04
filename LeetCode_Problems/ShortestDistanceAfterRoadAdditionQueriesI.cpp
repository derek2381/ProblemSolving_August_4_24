// problem link
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/



class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, vector<int>> adj; // Use an adjacency list for graph representation

        // Initialize the map with the initial road structure
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }

        for (const vector<int>& query : queries) {
            int x = query[0], y = query[1];
            adj[x].push_back(y);

            // Perform BFS to find the shortest path from 0 to n-1
            vector<int> dist(n, -1); // -1 indicates unvisited
            queue<int> q;
            q.push(0);
            dist[0] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (neighbor != -1 && dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }

            res.push_back(dist[n - 1]);
        }

        return res;
    }
};
