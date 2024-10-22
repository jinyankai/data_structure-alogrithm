//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>
using namespace std;

// 比较两个整数并返回较大者
int max(int a, int b) {
    return a > b ? a : b;
}

// 计算从节点 p 开始的资源总和
int calculateResource(vector<int> &tree, int index) {
    int size = tree.size();
    // 如果当前索引超出范围或节点值为 -1，返回 0
    if (index >= size || tree[index] == -1) return 0;

    // 递归计算左子树和右子树的资源总和，并加上当前节点值
    int total = max(calculateResource(tree, 2 * index + 1), calculateResource(tree, 2 * index + 2)) + tree[index];
    return total;
}

int main(void) {
    // 节点在数组中的位置关系：左子节点是 2*n + 1，右子节点是 2*n + 2
    vector<int> tree; // 存储二叉树的节点值
    int currentLeaf, totalNodes, height = 0; // 当前节点值，总节点数，高度
    long long specialSum = 0; // 特殊节点和

    // 从标准输入读取节点值，直到输入结束
    while (cin >> currentLeaf) tree.push_back(currentLeaf);

    // 如果树的根节点为 -1，输出 0
    if (tree[0] == -1) {
        cout << 0 << endl << 0 << endl << 0;
        return 0;
    }

    totalNodes = tree.size();
    currentLeaf = 0;

    // 计算树的高度
    if (totalNodes) {
        currentLeaf = 1;
        while (currentLeaf <= totalNodes) {
            currentLeaf *= 2;
            height++;
        }
    }

    bool hasLeftChild = false, hasRightChild = false; // 标记左右子节点是否存在
    for (int i = 0; i < totalNodes; ++i) {
        // 检查左子节点是否存在
        if (i * 2 + 1 < totalNodes && tree[i * 2 + 1] != -1) hasLeftChild = true;
        // 检查右子节点是否存在
        if (i * 2 + 2 < totalNodes && tree[i * 2 + 2] != -1) hasRightChild = true;

        // 如果当前节点至少有一个子节点
        if (hasLeftChild || hasRightChild) {
            // 检查当前节点是否是特殊节点
            if (hasLeftChild && hasRightChild && tree[i] > tree[i * 2 + 1] && tree[i] > tree[i * 2 + 2]) {
                specialSum += tree[i]; // 当前节点大于左右子节点，加入特殊节点和
            } else if (hasLeftChild && tree[i] > tree[i * 2 + 1] && !hasRightChild) {
                specialSum += tree[i]; // 当前节点大于左子节点，且没有右子节点，加入特殊节点和
            } else if (hasRightChild && tree[i] > tree[i * 2 + 2] && !hasLeftChild) {
                specialSum += tree[i]; // 当前节点大于右子节点，且没有左子节点，加入特殊节点和
            }
        }
        // 重置左右子节点存在标记
        hasLeftChild = false;
        hasRightChild = false;
    }

    // 输出树的高度
    cout << height << endl;
    // 输出资源总和
    cout << calculateResource(tree, 0) << endl;
    // 输出特殊节点和
    cout << specialSum << endl;

    return 0; // 返回程序结束
}