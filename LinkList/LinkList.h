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

/**
 * 以 ()->()->NULL 形式打印链表
 * 
 * @param (ListNode*) listNode 链表结点指针
 */
void ListNode_print_Link(ListNode* listNode) {
    if (listNode == NULL)
        return;
    ListNode* p = listNode->next;
    printf("Head->");
    while (p != NULL) {
        printf("%d ->", p->data);
    }
    printf("NULL\n");
}











#endif