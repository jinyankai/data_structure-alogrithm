//
// Created by 21077 on 2024/10/22.
//
#include "Solution.h"
#include <bits/stdc++.h>
vector<int> Solution::perfect_permutation(int N) {
    // 比较小的数字直接返回。
    if (N == 1) return {1};
    if (N == 2) return {1, 2};
    if (N == 3) return {1, 3, 2};
    if (N == 4) return {1, 3, 2, 4};
    // 从{1,3,2,4}，4个数字开始构建漂亮数组，当然从{1}开始构建也可以
    vector<int> temp = {1, 3, 2, 4};
    while (temp.size() < N) {
        for (auto& i : temp) {
            i = i * 2 - 1;
        }
        int s = temp.size();
        for (int i = 0; i < s; i++) {
            temp.push_back(temp[i] + 1);
        }
    }
    // 删除不需要的数字
    temp.erase(remove_if(temp.begin(), temp.end(), [=](int i) { return i > N; }), temp.end());
    return temp;


}