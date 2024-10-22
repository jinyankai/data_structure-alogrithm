//
// Created by 21077 on 2024/10/22.
//


#include "MyStack.h"// 栈的头文件

// 判断栈空, 若为空栈,则Empty()返回true；否则返回false
bool MyStack::Empty() {
    //请在这里完成你的代码
    return top == -1;
}

// 判断栈满，若栈满，则Full()为true；否则为false
bool MyStack::Full() {
    //请在这里完成你的代码
    return top == MAXLENG-1;
}

// 元素e进栈，若栈满，则无法成功插入，插入成功返回true，否则返回false
// @param
// e: 将要入栈的元素
bool MyStack::Push(ElementType e) {
    //请在这里完成你的代码
    if (Full()) {
        return false; // 栈满时，无法插入元素
    }
    elem[++top] = e; // 将元素插入栈顶
    return true;
}

// 栈的顶元素拷贝到e，若栈为空，则无法拷贝，返回false，成功拷贝则返回true
// @param
// e: 指向存放栈顶元素地址的指针
bool MyStack::Gettop(ElementType &e) {
    //请在这里完成你的代码
    if (Empty()) {
        return false; // 栈为空时，无法拷贝元素
    }
    e = elem[top]; // 将栈顶元素赋值给 e
    return true;
}

// 删除栈s的顶元素，并将删除的元素赋给e带出，若栈空，则无法成功删除，删除成功返回true，否则返回false
// @param
// e: 指向存放出栈元素地址的指针
bool MyStack::Pop(ElementType &e) {
    //请在这里完成你的代码
    if (Empty()) {
        return false; // 栈为空时，无法删除元素
    }
    e = elem[top--]; // 将栈顶元素赋值给 e，并将栈顶指针减 1
    return true;
}