/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;

        while (!q.empty()) {

            vector<int> temp;
            int size = q.size();
            vector<TreeNode*> nodes(size);
            vector<int> value(size);

            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                nodes[i] = top;
                value[i] = top->val;

                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }

            if (lvl % 2 != 0) {
                reverse(value.begin(), value.end());
                for (int j = 0; j < nodes.size(); j++) {
                    nodes[j]->val = value[j];
                }
            }
            
            lvl++;
        }

        return root;
    }
};