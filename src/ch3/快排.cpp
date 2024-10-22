//
// Created by 21077 on 2024/10/22.
//
#include "QuickSort.h"

int QuickSort::partition(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
    int random_index = p + std::rand() % (q - p + 1);
    std::swap(nums[p], nums[random_index]); // Swap with the first element
    int pivot = nums[q];
    int i = p - 1;
    for(int j = p ; j < q; j++) {
        if(nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1],nums[q]);
    return i + 1;
}

void QuickSort::quick_sort(std::vector<int>& nums, int l, int r) {
    // 请在这里完成你的代码
    if(l < r) {
        int mid = partition(nums, l, r);
        quick_sort(nums, l, mid - 1);
        quick_sort(nums, mid + 1, r);
    }

}
void QuickSort::mysort(std::vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1)
        return;
    quick_sort(nums, 0, nums.size() - 1);
}