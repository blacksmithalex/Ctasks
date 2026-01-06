/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> A;
        A.push(root);
        while (!A.empty())
        {
            vector<int> level;
            int l_size;
            l_size = A.size();
            for (int i = 0; i < l_size; i++)
            {
                TreeNode *node = A.front();
                A.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                {
                    A.push(node->left);
                }
                if (node->right != nullptr)
                {
                    A.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
                
    }
};