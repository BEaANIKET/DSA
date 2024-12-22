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

        function<long long(int, int)> dfs = [&](int currNode, int parentNode) -> long long {
            long long sum = 0;

            for (auto edge : adj[currNode]) {
                if (edge != parentNode) {
                    sum += dfs(edge, currNode);
                }
            }

            sum += values[currNode];
            sum %= k;
            if (sum == 0){
                components++;
                sum = 0;
                return 0;
            }

            return sum;
        };

        dfs(0, -1);

        return components;
    }
};
