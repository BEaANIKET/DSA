class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Create adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        // DFS function to calculate subtree sums
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long sum = values[node];

            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    sum += dfs(neighbor, node);
                }
            }

            // Check if the subtree sum is divisible by k
            if (sum % k == 0) {
                components++;
                return 0; // Reset the sum for a new component
            }

            return sum; // Return the current sum
        };

        // Start DFS from node 0
        dfs(0, -1);

        return components;
    }
};
