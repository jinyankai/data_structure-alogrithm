//
// Created by 21077 on 2024/10/22.
//
#include "Solution.h"


vector<vector<int>> Solution::round_robin_schedule(int k) {
    vector<vector<int>> s(k, vector<int>(k, 0));
    // 填充第一列为运动员编号
    int i,j,t,n,tmp;

    n = 2;//从2开始一步一步延申
    s[0][0] = 1;s[0][1] = 2;
    s[1][0] = 2;s[1][1] = 1;
    for(t = 4; t <= k ; t *= 2){
        tmp = n;
        n = n * 2;
        for(i = tmp ; i < n; i++){
            for(j = 0 ; j < tmp; j++){
                s[i][j] = s[i-tmp][j] + tmp;
            }
        }
        for(i = 0 ; i < tmp; i++){
            for(j = tmp  ; j < n; j++){
                s[i][j] = s[i+tmp][(j+tmp)%n];
            }
        }
        for(i = tmp ; i < n; i++){
            for(j = tmp ; j < n; j++){
                s[i][j] = s[i-tmp][j-tmp];
            }
        }

    }
    return s;

}