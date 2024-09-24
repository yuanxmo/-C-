#include "LinkList.h"

int main() {
    ListNode* listNode = ListNode_init();
    ListNode_insert_head(listNode, 1);
    ListNode_print_Link(listNode);
    ListNode_insert_head(listNode, 2);
    ListNode_print_Link(listNode);
    ListNode_insert_head(listNode, 3);
    ListNode_print_Link(listNode);
    ListNode_insert_tail(listNode, 4);
    ListNode_print_Link(listNode);
    ListNode_insert_tail(listNode, 5);
    ListNode_print_Link(listNode);
    ListNode_insert_index(listNode, 6, 2);
    ListNode_print_Link(listNode);
    ListNode_delete_index(listNode, 2);
    ListNode_print_Link(listNode);
    ListNode_destroy(&listNode);
    ListNode_print_Link(listNode);
    
    system("pause");
    return 0;
}