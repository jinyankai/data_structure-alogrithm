//
// Created by 21077 on 2024/10/22.
//
#include "Solution.h"
int Solution::find_maximum_crossing_subarray(vector<int> &A, int low, int mid, int high) {
    // 请在这里完成你的代码
    int sum = 0;
    int left_sum = INT_MIN;

    // 计算左侧的最大和
    for (int i = mid; i >= low; --i) {
        sum += A[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MIN;

    // 计算右侧的最大和
    for (int i = mid + 1; i <= high; ++i) {
        sum += A[i];
        right_sum = max(right_sum, sum);
    }

    return max(left_sum + right_sum, max(left_sum, right_sum));

    return 0;
}
int Solution::find_maximum_subarray(vector<int> &A, int low, int high) {
    // 请在这里完成你的代码
    if (low == high) {
        return A[low]; // 基本情况：只有一个元素
    }

    int mid = low + (high - low) / 2;

    // 递归计算
    return max(find_maximum_subarray(A, low, mid),
               max(find_maximum_subarray(A, mid + 1, high),
                   find_maximum_crossing_subarray(A, low, mid, high)));

    return 0;
}