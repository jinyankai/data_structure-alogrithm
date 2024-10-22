//
// Created by 21077 on 2024/10/22.
//
#include <iostream>
#include <vector>

class MergeSort {
public:
    int mergeCompareCount = 0;  // 归并排序比较次数

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

    // 归并两个有序子数组
    void merge(std::vector<int> &nums, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            mergeCompareCount++;  // 计数比较次数
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int m = 0; m < temp.size(); ++m) {
            nums[left + m] = temp[m];
        }
    }
};

class InsertionSort {
public:
    int insertionCompareCount = 0;  // 插入排序比较次数

    // 插入排序实现
    void mysort(std::vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i;
            while (j > 0) {
                insertionCompareCount++;  // 计数比较次数
                if (nums[j - 1] > key) {
                    nums[j] = nums[j - 1];
                    --j;
                } else {
                    break;  // 若不再比较，则无需计数
                }
            }
            nums[j] = key;
        }
    }
};

int main() {
    int N;
    std::cin >> N;  // 读入数的个数

    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];  // 读入待排序数
    }

    // 复制原数组以用于两种不同排序算法
    std::vector<int> numsForMergeSort = nums;
    std::vector<int> numsForInsertionSort = nums;

    // 归并排序
    MergeSort mergeSorter;
    mergeSorter.merge_sort_aux(numsForMergeSort, 0, N - 1);

    // 插入排序
    InsertionSort insertionSorter;
    insertionSorter.mysort(numsForInsertionSort);

    // 输出比较次数
    std::cout << mergeSorter.mergeCompareCount << " " << insertionSorter.insertionCompareCount << std::endl;

    return 0;
}