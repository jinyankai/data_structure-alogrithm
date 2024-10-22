//
// Created by 21077 on 2024/10/22.
//
#include <bits/stdc++.h>
#define maxn 30
using namespace std;

vector<vector<int>> mp; // 二维数组，存储每个数的变化路径
map<int,int> countnums; // 记录每个数出现的次数
map<int,int> countstep; // 记录每个数的步数

int main(){
    int n, q;
    cin >> n >> q; // 输入数组的大小n和需要相同值的数量q
    mp.resize(n, vector<int>(maxn, -1)); // 初始化mp，大小为n x maxn，初始值为-1

    // 处理每个输入的数
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp; // 输入每个数
        mp[i][0] = tmp; // 将原始数存入mp
        countnums[tmp]++; // 更新该数的出现次数
        countstep[tmp] = 0; // 初始化该数的步数为0

        // 将每个数除以2，填充mp的其余列
        int j, val;
        for (j = 1, val = tmp / 2; j < maxn && val > 0; j++, val /= 2) {
            mp[i][j] = val; // 存储每次除以2后的值
        }
        mp[i][j] = 0; // 将当前行的最后一个元素设为0
    }

    // 更新每个数的出现次数和步数
    for (int j = 1; j < maxn; j++) {
        for (int i = 0; i < n; i++) {
            // 如果该数的出现次数已达到q或值为-1，跳过
            if ((countnums[mp[i][j]] >= q) || (mp[i][j] == -1)) {
                continue;
            } else {
                countnums[mp[i][j]]++; // 增加该数的出现次数
                countstep[mp[i][j]] += j; // 累加步数
            }
        }
    }

    // 对于出现次数不足q的数，将其步数设为无穷大
    for (auto &e : countnums) {
        int index = e.first;
        int number = e.second;
        if (number < q) {
            countstep[index] = INT_MAX; // 步数设为无穷大
        }
    }

    int ans = INT_MAX; // 初始化答案为无穷大
    for (auto &e : countstep) {
        ans = min(ans, e.second); // 找到最小的步数
    }

    cout << ans; // 输出最小变化次数
    return 0; // 返回0，表示程序结束
}