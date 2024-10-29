#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//感谢陈煜同学提供的修改思路，语文之前思路相比，在对适应地点分类结果是相同的，但是我没有把只满足一种适应的情况和两组都满足的情况放在一起选择
// s[0]: 存储 Farmer John 适应但奶牛不适应的地点所需力气
// s[1]: 存储奶牛适应但 Farmer John 不适应的地点所需力气
// s[2]: 存储 Farmer John 和奶牛都适应的地点所需力气，以及合并后的组合力气
vector<int> locationCosts[3];

int main() {
    int numLocations, minAdaptableLocations;
    cin >> numLocations >> minAdaptableLocations;

    // 输入每个地点的信息
    for (int i = 1; i <= numLocations; i++) {
        int cost, farmerAdapt, cowAdapt;
        cin >> cost >> farmerAdapt >> cowAdapt;

        // 根据 Farmer John 和奶牛的适应性，将力气需求分类
        if (farmerAdapt == 1 && cowAdapt == 1) {
            locationCosts[2].push_back(cost);  // Farmer 和奶牛都适应
        } else if (farmerAdapt == 1) {
            locationCosts[0].push_back(cost);  // 仅 Farmer 适应
        } else if (cowAdapt == 1) {
            locationCosts[1].push_back(cost);  // 仅奶牛适应
        }
    }

    // 对 Farmer John 适应和奶牛适应的地点分别按力气需求从小到大排序
    sort(locationCosts[0].begin(), locationCosts[0].end());
    sort(locationCosts[1].begin(), locationCosts[1].end());

    // 将 Farmer John 和奶牛各自适应的最小力气组合成一项，放入 `locationCosts[2]`
    for (int i = 0; i < min(locationCosts[0].size(), locationCosts[1].size()); i++) {
        locationCosts[2].push_back(locationCosts[0][i] + locationCosts[1][i]);
    }

    // 如果合适的地点数少于要求的适应地点数，输出 -1 表示无法满足需求
    if (locationCosts[2].size() < minAdaptableLocations) {
        printf("-1");
        return 0;
    }

    // 对所有满足条件的组合地点按力气从小到大排序
    sort(locationCosts[2].begin(), locationCosts[2].end());

    // 计算满足条件的最小总力气
    long long totalCost = 0;
    for (int i = 0; i < minAdaptableLocations; i++) {
        totalCost += 1LL * locationCosts[2][i];  // 累加最小的力气值
    }

    cout << totalCost;
    return 0;
}