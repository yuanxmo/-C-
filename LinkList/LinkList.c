#include "LinkList.h"


void ListNode_print_Link(LinkList listNode) {
    if (listNode == NULL) {
        printf("NO LinkList!\n");
        return;
    }
    ListNode *p = listNode->next;
    printf("Head->");
    while (p != NULL) {
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

ListNode *ListNode_init() {
    LinkList head = (LinkList)malloc(sizeof(ListNode));
    if (head == NULL)
        return head;
    head->next = NULL;
    return head;
}

void ListNode_destroy(LinkList *listNode) {
    // 对链表判空
    if ((*listNode) == NULL)
        return;
    ListNode *p = (*listNode)->next;
    ListNode *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    free(*listNode);
    *listNode = NULL;
}

int ListNode_insert_head(
    LinkList listNode, int data
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL)
        return 0;
    p->data = data;
    p->next = listNode->next;
    listNode->next = p;
    return 1;
}

int ListNode_insert_tail(
    LinkList listNode, int data
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode;
    while (p->next != NULL)
        p = p->next;
    ListNode *q = (ListNode*)malloc(sizeof(ListNode));
    if (q == NULL)
        return 0;
    q->data = data;
    q->next = NULL;
    p->next = q;
    return 1;
}

int ListNode_insert_index(
    LinkList listNode,
    int data,
    int index
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode->next;
    int i = 0;
    while (p->next != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (i != index - 1)
        return 0;
    ListNode *q = (ListNode*)malloc(sizeof(ListNode));
    if (q == NULL)
        return 0;
    q->data = data;
    q->next = p->next;
    p->next = q;
    return 1;
}

int ListNode_delete_index(
    LinkList listNode, 
    int index
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode->next;
    int i = 0;
    while (p->next != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (i != index - 1 || p->next == NULL)
        return 0;
    p->next = p->next->next;
    return 1;
}

int ListNode_update_index(
    LinkList listNode, 
    int data, int index
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode->next;
    int i = 0;
    while (p->next != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (i != index - 1 ||p->next == NULL)
        return 0;
    p->data = data;
    return 1;
}

int ListNode_get_index(
    LinkList listNode,
    int index,
    int *ans
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode->next;
    int i = 0;
    while (p->next != NULL && i < index) {
        p = p->next;
        i++;
    }
    if (i != index || p->next == NULL)
        return 0;
    *ans = p->data;
    return 1;
}

int ListNode_get_length(
    LinkList listNode
) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode->next;
    int i = 0;
    while (p->next != NULL) {
        p = p->next;
        i++;
    }
    return i;
}