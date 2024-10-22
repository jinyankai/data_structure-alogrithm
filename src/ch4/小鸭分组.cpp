//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>
using namespace std;
const int N = 10005;
long long f[N], g[N];

void solve(int s) {
    int total = s * (s + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl; // 无法分成两个等和子集
        return;
    }
    int target = total / 2;
    g[0] = 1; // 不选物品，方案数为1

    for (int i = 1; i <= s; ++i) {
        for (int j = target; j >= i; --j) {
            f[j] = max(f[j], f[j - i] + i); // 状态转移
            if (f[j] == f[j - i] + i) {
                g[j] += g[j - i]; // 统计方案数
            }
            else {
                continue;
            }
        }
    }

    cout << g[target] / 2 << endl; // 输出方案数
}

int main() {
    int s;
    cin >> s;
    solve(s);
    return 0;
}