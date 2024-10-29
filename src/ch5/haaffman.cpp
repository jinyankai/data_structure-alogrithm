#include "Solution.h"


TreeNode* huffman(vector<TreeNode*>& tree) {
    int n = tree.size();
    // 创建一个小顶堆
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> q;
    // 把 tree 放入 q 中
    for (int i = 0; i < n; i++) {
        q.push(tree[i]);
    }

    // 请注意，非叶子结点的 symbol 不需要赋值
    // 请在这里完成你的代码
    while (q.size() > 1) {
        TreeNode* left = q.top(); q.pop();
        TreeNode* right = q.top(); q.pop();
        TreeNode* parent = new TreeNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        q.push(parent);
    }

    return q.top();
}