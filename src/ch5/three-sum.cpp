#include "Solution.h"

vector<vector<int>> Solution::three_sum(vector<int> &A, vector<int> &B, vector<int> &C) {
    // 请在这里完成你的代码
    vector<vector<int>> result;
    sort(C.begin(), C.end()); // 对 C 进行排序，以便二分查找

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            int sum = A[i] + B[j];
            // 在 C 中执行二分查找
            if (binary_search(C.begin(), C.end(), sum)) {
                result.push_back({A[i], B[j], sum});
            }
        }
    }

    return result;

}