/*** 
 * 使用C语言实现单链表源代码
 * @author YuanxMo
 * @since 2024/9/13
 * @version 1.0
*/

#ifndef LINK_LIST_H
#define LINK_LIST_H

// 头文件
#include <stdio.h>
#include <stdlib.h>


/**
 * 链表结点结构类型的定义
 * 
 * @param (int)data 数据域
 * @param (struct Node*)next 指针域
 */
typedef struct Node {
    int data;
    struct Node* next;
} ListNode, *LinkList;












#endif