//
// Created by 21077 on 2024/10/22.
//
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> s(n);
    unordered_map<long long, long long> mp;  // 用于存储每个数的频率

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        mp[s[i]]++;
    }

    // 找到最大值
    long long max_num = 0;
    for (auto& pair : mp) {
        max_num = max(max_num, pair.first);
    }

    // dp 数组，大小为最大值 + 1

    vector<long long> dp(max_num + 1, 0);

    // 动态规划
    dp[1] = mp[1];  // 处理数字1
    for (int i = 2; i <= max_num; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * mp[i]);
    }

    // 输出最大和
    cout << dp[max_num] << endl;
    return 0;
}