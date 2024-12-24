class Solution {
public:

    pair<int, int> findFarDistanceFrom(vector<vector<int>> &adj, int ele) {
        queue<int> q;
        vector<bool> visited(adj.size(), false); 
        q.push(ele);
        visited[ele] = true;

        int last = ele;
        int lvl = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();
                last = front;

                for (int neighbor : adj[front]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            lvl++;
        }

        return {last, lvl - 1};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1; 
        int n2 = edges2.size() + 1; 

        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        pair<int, int> end1 = findFarDistanceFrom(adj1, 0);
        pair<int, int> d1 = findFarDistanceFrom(adj1, end1.first);

        pair<int, int> end2 = findFarDistanceFrom(adj2, 0);
        pair<int, int> d2 = findFarDistanceFrom(adj2, end2.first);

        int d3 = (d1.second+1)/2 + (d2.second+1)/2 + 1;


        return max(d1.second, max(d2.second, d3));
    }
};
