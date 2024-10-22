//
// Created by 21077 on 2024/10/22.
//
#include "ThreeWayQuickSort.h"

void ThreeWayQuickSort::three_way_quick_sort(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
    if (q <= p) return;
    int random_index = p + std::rand() % (q - p + 1); // 随机选择基准
    std::swap(nums[p], nums[random_index]);

    int pivot = nums[p]; // 选择基准
    int lt = p;          // 小于基准的部分
    int gt = q;          // 大于基准的部分
    int i = p + 1;       // 当前比较的元素

    while (i <= gt) {
        if (nums[i] < pivot) {
            std::swap(nums[lt++], nums[i++]);
        } else if (nums[i] > pivot) {
            std::swap(nums[i], nums[gt--]);
        } else {
            i++;
        }
    }

    three_way_quick_sort(nums, p, lt - 1); // 递归排序小于基准的部分
    three_way_quick_sort(nums, gt + 1, q); // 递归排序大于基准的部分

}
void ThreeWayQuickSort::mysort(std::vector<int>& nums) {
    if(nums.size() == 0)
        return;
    three_way_quick_sort(nums, 0, nums.size() - 1);
}