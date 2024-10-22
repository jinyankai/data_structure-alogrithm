//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> graph[MAXN];  // 邻接表存储树
int value[MAXN];          // 每个房间的宝藏价值
int dp[MAXN];             // DP数组，用来存储每个节点的子树最大价值
bool visited[MAXN];       // 记录是否访问过节点
int n;

// DFS后序遍历计算dp数组
int dfs(int u) {
    visited[u] = true;
    dp[u] = value[u];  // 初始化为当前房间的宝藏价值

    // 遍历u的子节点
    for (int v : graph[u]) {
        if (!visited[v]) {
            dp[u] += max(0, dfs(v));  // 如果子树的dp值为负数，则不选取该子树
        }
    }

    return dp[u];  // 返回以u为根的子树的最大值
}

int main() {
    cin >> n;

    // 输入宝藏价值
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
    }

    // 构建树，输入边
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // 初始化dp数组和visited数组
    fill(dp, dp + MAXN, 0);
    fill(visited, visited + MAXN, false);

    // 从节点1开始进行DFS
    dfs(1);

    // 输出dp数组中的最大值，即最大可能获得的宝藏总价值
    int result = *max_element(dp + 1, dp + n + 1);
    cout << result << endl;

    return 0;
}