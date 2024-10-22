//
// Created by 21077 on 2024/10/22.
//

#include<iostream>
#include <vector>

using namespace std;

struct node{
    int num;
    node *prior, *next;
};

using Linklist = node*;

void changeList(Linklist &list) {
    if (list == nullptr || list->next == list) return; // 空链表或只有一个元素

    vector<node*> oddNodes;  // 奇数索引节点
    vector<node*> evenNodes; // 偶数索引节点

    node* current = list->next; // 指向第一个有效节点
    int index = 1; // 计数器（从1开始）

    while (current != list) {
        if (index % 2 != 0) {
            oddNodes.push_back(current);  // 奇数索引
        } else {
            evenNodes.push_back(current); // 偶数索引
        }
        current = current->next;
        index++;
    }

    // 重新排列链表：奇数索引节点正序连接，偶数索引节点逆序连接
    node* newTail = list; // 新链表的尾部指针，初始化为虚拟头节点

    // 连接奇数索引节点
    for (node* odd : oddNodes) {
        newTail->next = odd;
        odd->prior = newTail;
        newTail = odd;
    }

    // 连接偶数索引节点（逆序）
    for (int i = evenNodes.size() - 1; i >= 0; --i) {
        newTail->next = evenNodes[i];
        evenNodes[i]->prior = newTail;
        newTail = evenNodes[i];
    }

    // 尾节点连接回头节点，形成环
    newTail->next = list;
    list->prior = newTail;
}

int main(){
    int n;
    Linklist head, tail, point;
    head = tail = new node();
    cin >> n;
    for(int i = 0; i < n; i++){
        point = new node();
        cin >> point->num;
        tail->next = point;
        point->prior = tail;
        tail = point;
    }
    head->prior = tail;
    tail->next = head;
    changeList(head);
    point = head->next;
    while(point != head->prior){
        cout << point->num << " ";
        point = point->next;
    }
    cout << point->num;
    return 0;
}