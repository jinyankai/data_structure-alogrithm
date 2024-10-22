//
// Created by 21077 on 2024/10/22.
//
#include "HeapSort.h"
int heap_size ;
int length;
void HeapSort::max_heapify(std::vector<int>& nums, int i) {
    // 请在这里完成你的代码
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap_size && nums[left] > nums[largest]) {
        largest = left;
    }
    if (right <= heap_size && nums[right] > nums[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        max_heapify(nums, largest);
    }
}
void HeapSort::build_max_heap(std::vector<int>& nums) {
    // 请在这里完成你的代码
    heap_size = length;
    for (int i = length / 2; i >= 1; i--) {
        max_heapify(nums, i);
    }

}
void HeapSort::mysort(std::vector<int>& nums) {
    length = nums.size();
    nums.insert(nums.begin(), 0); // 在开头插入一个元素，使得待排序元素下标从1开始
    build_max_heap(nums);
    for (int i = length; i > 1; i--) {
        std::swap(nums[1], nums[i]); // 交换堆顶与最后一个元素
        heap_size--; // 减少堆的大小
        max_heapify(nums, 1); // 恢复最大堆性质
    }
    nums.erase(nums.begin()); // 删除开头的元素


    // 删除开头元素
}