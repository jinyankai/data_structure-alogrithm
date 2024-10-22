//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    long long n;
    cin >> n;  // 读取数组长度
    vector<long long> arr(n);

    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];  // 读取数组元素
    }

    unordered_map<long long, vector<long long>> pos;
    for (long long i = 0; i < n; ++i) {
        pos[arr[i]].push_back(i);  // 存储每个数字在数组中的所有位置
    }

    vector<long long> next_pos(n, -1);
    for (const auto& p : pos) {
        const vector<long long>& indices = p.second;
        for (long long i = 0; i < indices.size() - 1; ++i) {
            next_pos[indices[i]] = indices[i + 1];  // 存储每个位置的下一个相同数字的位置
        }
    }

    vector<long long> dp(n + 1, 0);

    for (long long i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];  // 不选择当前数的情况

        if (next_pos[i] != -1) {
            long long j = next_pos[i];
            int is_choose_j = 0;  // 判断是否选择下一个相同数
            if (next_pos[j] != -1 && dp[j] != dp[j + 1]) {
                is_choose_j = 1;  // 如果下一个相同数被选择，标记为1
            }
            // 选择当前数及下一个相同数，跳过重叠部分
            dp[i] = max(dp[i], (j - i + 1 - is_choose_j) + dp[j]);
        }
    }

    cout << dp[0] << endl;  // 输出从第0个位置开始的最大可拿走数量
    return 0;
}