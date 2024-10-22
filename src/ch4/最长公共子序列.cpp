//
// Created by 21077 on 2024/10/22.
//
#include "Solution.h"

int Solution::lcs(string s, string t, vector<vector<int>> &c, vector<vector<int>>  &b) {
    // 注意，string 类型是 C++ 的字符串类型，可以通过 s[0] 来访问 s 的第一个字符

    int n = s.size(), m = t.size();
    c.resize(n + 1);
    b.resize(n + 1);
    for(int i = 0; i <= n; i++) {
        c[i].resize(m + 1, 0);
        b[i].resize(m + 1, 0);
    }
    // 以上是数组初始化操作，请在下面完成你的代码

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 填充dp表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 相同字符，增加长度
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 取较大值
            }
        }
    }

    return dp[m][n]; // 返回LCS长度

}