//
// Created by 21077 on 2024/10/22.
//
#include"SqList.h"
using namespace std;
void insert(SqList& list, int num){
    //在此处添加代码

    auto it = list.begin();
    while (it != list.end() && *it < num) {
        ++it;
    }

    // 将num插入到找到的位置
    list.insert(it, num);
}