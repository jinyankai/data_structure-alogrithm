//
// Created by 21077 on 2024/10/22.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>ans;

    deque<int>qmax;//维持最大值的队列
    for(int r=0;r<n;r++)
    {
        while(!qmax.empty()&&nums[qmax.back()]<=nums[r])
        {
            qmax.pop_back();//这是维持队列由大到小的结构
            //将队尾所有比新数字小的数字全部弹出
        }
        qmax.push_back(r);

        if(qmax.front()==r-k)
        {
            qmax.pop_front();//这是最大值对应下标已经不在窗口中的情况
            //因为r-l=k
        }

        if(r>=k-1)
        {
            ans.push_back(nums[qmax.front()]);
            //窗口已经成型，就直接加入数字
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans = maxSlidingWindow(nums,k);
    for(auto e:ans){
        cout<<e<<" ";
    }

    return 0;
}
