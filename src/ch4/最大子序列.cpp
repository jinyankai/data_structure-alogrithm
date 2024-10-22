//
// Created by 21077 on 2024/10/22.
//
#include "Solution.h"
#include <bits/stdc++.h>
using namespace std;
long long Solution::find_maximum_subarray(vector<int> &arr) {
    // 请在这里完成你的代码
    int n = arr.size();
    long long currentMax = arr[0];  // 当前子序列的最大和
    long long globalMax = arr[0];   // 全局最大和

    for (int i = 1; i < n; i++) {
        currentMax = max(static_cast<long long>(arr[i]), currentMax + arr[i]);  // 动态规划状态转移方程
        globalMax = max(globalMax, currentMax);         // 更新全局最大和
    }

    return globalMax;  // 返回最大和
}