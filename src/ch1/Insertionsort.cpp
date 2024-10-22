//
// Created by 21077 on 2024/10/22.
//
#include "InsertionSort.h"
// 通过插入排序对int队列nums进行升序排序
// @param
// nums: 完整的待排序队列，最终排序的结果应存放在nums中
void InsertionSort::mysort(std::vector<int>& nums) {
    // 请在这里完成你的代码
    for (size_t i = 1; i < nums.size(); ++i) {
        int key = nums[i];
        size_t j = i;
        // 移动元素，以便找到插入位置
        while (j > 0 && nums[j - 1] > key) {
            nums[j] = nums[j - 1];
            --j;
        }
        // 插入 key 到正确位置
        nums[j] = key;
    }
}