#include "Solution.h"

//最终思路感谢陈煜同学的指导
//与我之前的思路相比更加简洁，增加了蛋糕指针



bool compareChild(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // 按照最大需求值排序
}
bool compareCake(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0]; // 按照蛋糕尺寸排序
}

int Solution::assign_cake(vector<vector<int>>& g, vector<vector<int>>& s) {
    // 对孩子和蛋糕分别排序
    sort(g.begin(), g.end(), compareChild);
    sort(s.begin(), s.end(), compareCake);

    int ans = 0;
    int j = 0;  // 用于遍历蛋糕

    for (int i = 0; i < g.size(); i++) {
        // 找到满足当前孩子需求的蛋糕
        for(int j = 0 ; j < s.size() ; j++){
            if(s[j][0]>g[i][1]) break;//超过上线，直接跳过如果蛋糕尺寸大于孩子的最大需求，那么这个孩子无法接受这个蛋糕，且因为蛋糕和孩子都已经排序，后续蛋糕只会更大，因此不需要再检查后续蛋糕，直接跳出循环。

            if(s[j][1]==0 || s[j][0]<g[i][0]) continue;//如果蛋糕数量为 0，表示该尺寸的蛋糕已经分配完毕，跳过继续查找下一个蛋糕。
//如果蛋糕尺寸小于孩子的最小需求，说明这个蛋糕不符合当前孩子的需求，也跳过。
            //满足条件
            ans++;
            s[j][1]--;
            break;
        }
    }

    return ans;
}