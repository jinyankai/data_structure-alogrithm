//
// Created by 21077 on 2024/10/22.
//
#include "MergeSort.h"

// 通过归并排序对int队列nums中的[left, right]区间进行升序排序
// @param
// nums: 完整的待排序队列，最终排序的结果应存放在nums中
// left: 当前排序区间的左端点
// right: 当前排序区间的右端点
void merge(std::vector<int> &nums, int left, int mid, int right)
{
    // 创建临时数组以存放合并后的结果
    std::vector<int> temp(right - left + 1);

    int i = left;      // 左半部分的起始位置
    int j = mid + 1;   // 右半部分的起始位置
    int k = 0;         // 临时数组的索引

    // 将两个有序区间合并
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // 如果左半部分有剩余
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // 如果右半部分有剩余
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // 将合并结果复制回原数组
    for (int m = 0; m < temp.size(); ++m) {
        nums[left + m] = temp[m];
    }
}
void MergeSort::merge_sort_aux(std::vector<int> &nums, int left, int right)
{


    // 递归结束条件：区间只有一个元素或无元素
    if (left >= right) {
        return;
    }

    // 找到中间点，将数组分为两部分
    int mid = left + (right - left) / 2;

    // 对左半部分排序
    merge_sort_aux(nums, left, mid);

    // 对右半部分排序
    merge_sort_aux(nums, mid + 1, right);

    // 合并两部分
    merge(nums, left, mid, right);
}