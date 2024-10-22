//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>

class MergeSort {
public:
    long long inversionCount = 0;  // 逆序对的数量

    // 归并排序辅助函数
    void merge_sort_aux(std::vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        merge_sort_aux(nums, left, mid);
        merge_sort_aux(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    // 归并两个有序子数组，并计算逆序对
    void merge(std::vector<int> &nums, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                // 如果左边的元素大于右边的元素，说明存在逆序对
                // 逆序对的个数就是左边剩余元素的数量
                inversionCount += (mid - i + 1);
            }
        }

        // 处理剩余的元素
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // 将排序后的数组复制回原数组
        for (int m = 0; m < temp.size(); ++m) {
            nums[left + m] = temp[m];
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    MergeSort mergeSorter;
    mergeSorter.merge_sort_aux(nums, 0, n - 1);

    std::cout << mergeSorter.inversionCount << std::endl;

    return 0;
}