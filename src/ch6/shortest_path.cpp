//
// Created by 21077 on 2024/11/2.
//
#include "Solution.h"

long long Solution::shortest_path(int n, vector<vector<int>>& edges) {
    // 创建邻接表
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& edge : edges) {
        if (edge[0] <= n && edge[1] <= n) { // 确保节点在有效范围内
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]); // 因为是无向图
        }
    }

    // 初始化距离和访问标记
    vector<long long> dis(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    // 起点
    pq.emplace(0, 1);
    dis[1] = 0;

    while (!pq.empty()) {
        auto [w, y] = pq.top();
        pq.pop();

        // 如果已经访问过，跳过
        if (vis[y]) continue;
        vis[y] = true;

        // 遍历邻接节点
        for (const auto& e : graph[y]) {
            int des = e.first; // 目标节点
            long long d = e.second; // 边的权重

            // 更新距离
            if (!vis[des] && w + d < dis[des]) {
                dis[des] = w + d;
                pq.emplace(dis[des], des);
            }
        }
    }

    // 如果到达目标节点的距离仍然是无穷大，表示不可达
    return dis[n] == LLONG_MAX ? -1 : dis[n];
}