//
// Created by 21077 on 2024/11/2.
//
#include "Solution.h"

long long Solution::minimum_spanning_tree(int n, vector<vector<int>>& edges) {
    // 创建邻接表
    vector<vector<pair<int, int>>> graph(n+1);
    for (const auto& edge : edges) {
        if (edge[0] <= n && edge[1] <= n) { // 确保节点在有效范围内
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]); // 因为是无向图
        }
    }

    // 优先队列，存储 {权重, 目标节点}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> inMST(n+1, false); // 记录节点是否在最小生成树中
    long long mst_weight = 0; // 最小生成树的权重
    int edges_used = 0;

    // 从节点 0 开始
    pq.emplace(0, 1); // 从节点 0 开始，权重为 0

    while (!pq.empty() && edges_used < n) {
        auto [weight, u] = pq.top();
        pq.pop();

        // 如果这个节点已经在 MST 中，跳过
        if (inMST[u]) continue;

        // 加入 MST
        inMST[u] = true;
        mst_weight += weight;
        edges_used++;

        // 调试信息
        //cout << "Adding node " << u << " to MST with edge weight " << weight << endl;

        // 更新优先队列
        for (const auto& [v, edge_weight] : graph[u]) {
            if (!inMST[v]) {
                pq.emplace(edge_weight, v);
            }
        }
    }

    // 检查是否包含所有节点


    return mst_weight;
}