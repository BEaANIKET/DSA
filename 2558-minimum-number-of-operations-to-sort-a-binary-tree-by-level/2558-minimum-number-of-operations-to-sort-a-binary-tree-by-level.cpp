class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        auto cmp = [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        };

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> values;

            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front) {
                    values.push_back(front->val);
                    pq.push({front->val, i}); 
                }

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            vector<int> sortedValues(values.begin(), values.end());
            sort(sortedValues.begin(), sortedValues.end());
            unordered_map<int, int> indexMap;

            for (int i = 0; i < values.size(); i++) {
                indexMap[values[i]] = i;
            }

            for (int i = 0; i < values.size(); i++) {
                if (values[i] == sortedValues[i]) continue;

                count++;
                int correctIndex = indexMap[sortedValues[i]];

                indexMap[values[i]] = correctIndex;
                indexMap[sortedValues[i]] = i;

                swap(values[i], values[correctIndex]);
            }
        }

        return count;
    }
};
