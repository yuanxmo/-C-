#include "LinkList.c"

void test_LinkList_init_destory();
void test_LinkList_print();
void test_LinkList_insert_head(LinkList listNode);
void test_LinkList_insert_tail(LinkList listNode);
void test_LinkList_insert_index(LinkList listNode);
void test_LinkList_delete_index(LinkList listNode);
void test_LinkList_update_index(LinkList listNode);
void test_LinkList_get_index(LinkList listNode);
void test_LinkList_get_length(LinkList listNode);

int main() {
    // 测试链表初始化和销毁链表
    test_LinkList_init_destory();
    printf("\n");
    // 测试打印空链表
    test_LinkList_print();
    printf("\n");
    ListNode* listNode = ListNode_init();
    // 测试头插法
    test_LinkList_insert_head(listNode);
    printf("\n");
    // 测试尾插法
    test_LinkList_insert_tail(listNode);
    printf("\n");
    // 测试指定位置插入结点
    test_LinkList_insert_index(listNode);
    printf("\n");
    // 测试删除指定位置节点
    test_LinkList_delete_index(listNode);
    printf("\n");
    // 测试更新指定位置节点
    test_LinkList_update_index(listNode);
    printf("\n");
    // 测试获取指定位置结点
    int ans = 0;
    test_LinkList_get_index(listNode);
    printf("\n");
    // 测试获取链表长度
    test_LinkList_get_length(listNode);
    printf("\n");
    
    // 销毁链表
    printf("销毁链表\n");
    ListNode_destroy(&listNode);
    ListNode_print_Link(listNode);
    
    system("pause");
    return 0;
}

/**
 * 测试链表初始化和销毁链表
 */
void test_LinkList_init_destory() {
    int flag = 0;
    // 测试初始化链表
    printf("测试初始化链表... \n");
    ListNode* listNode = ListNode_init();
    if ( listNode ) {
        printf("初始化成功!\n");
        flag = 1;
    }
    else
        printf("初始化失败!\n");
    if (!flag) {
        printf("链表未初始化, 无法测试销毁链表!\n");
        return;
    }
    printf("测试销毁链表... \n");
    ListNode_destroy(&listNode);
    if ( listNode ) {
        printf("销毁失败!\n");
    } else {
        printf("销毁成功!\n");
    }
}

/**
 * 测试打印链表
 */
void test_LinkList_print() {
    // 测试打印未分配内存的链表
    ListNode* listNode = NULL;
    printf("测试打印空链表: \n");
    ListNode_print_Link(listNode);
    // 测试打印空链表
    listNode = ListNode_init();
    printf("测试打印空链表: \n");
    ListNode_print_Link(listNode);
    ListNode_destroy(&listNode);
}

/**
 * 测试头插法
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_insert_head(LinkList listNode) {
    printf("测试头插法... \n");
    const int INSERT_VALUE[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf(
            "第 %d 次头插法插入: %d\n",
            i+1, INSERT_VALUE[i]
        );
        if (
            ListNode_insert_head(
                listNode,
                INSERT_VALUE[i]
            )
        ) {
            printf("插入成功!\n");
            ListNode_print_Link(listNode);
        } else {
            printf("插入失败!\n");
        }
    }
}

/**
 * 测试尾插法
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_insert_tail(
    LinkList listNode
) {
    printf("测试尾插法... \n");
    const int INSERT_VALUE[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("第 %d 次尾插法插入: %d\n", i+1, INSERT_VALUE[i]);
        if (
            ListNode_insert_tail(
                listNode, 
                INSERT_VALUE[i]
            )
        ) {
            printf("插入成功!\n");
            ListNode_print_Link(listNode);
        } else {
            printf("插入失败!\n");
        }
    }
}

/**
 * 测试指定位置插入结点
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_insert_index(
    LinkList listNode
) {
    printf("测试指定位置插入... \n");
    const int INSERT_INDEX[5] = {1, 2, 3, 1000, 9999};
    const int INSERT_VALUE[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf(
            "第 %d 次指定位置插入: value: %d, index: %d\n",
            i+1, INSERT_VALUE[i], INSERT_INDEX[i]
        );
        if (
            ListNode_insert_index(
                listNode,
                INSERT_VALUE[i],
                INSERT_INDEX[i]
            )
        ) {
            printf("插入成功!\n");
            ListNode_print_Link(listNode);
        } else {
            printf("插入失败!\n");
        };
    }
}

/**
 * 测试删除指定位置节点
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_delete_index(
    LinkList listNode
) {
    printf("测试删除指定位置节点... \n");
    const int DELETE_INDEX[5] = {1, 2, 3, 1000, 9999};
    for (int i = 0; i < 5; i++) {
        printf(
            "第 %d 次删除指定位置节点: index: %d\n",
            i+1, DELETE_INDEX[i]
        );
        if (
            ListNode_delete_index(
                listNode, 
                DELETE_INDEX[i]
            )
        ) {
            printf("删除成功!\n");
            ListNode_print_Link(listNode);
        } else {
            printf("删除失败!\n");
        }
    }
}

/**
 * 测试更新指定位置节点
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_update_index(
    LinkList listNode
) {
    printf("测试更新指定位置节点... \n");
    const int UPDATE_VALUE[5] = {0, 0, 0, 0, 0};
    const int UPDATE_INDEX[5] = {1, 2, 3, 1000, 9999};
    for (int i = 0; i < 5; i++) {
        printf(
            "第 %d 次更新: value: %d, index: %d\n",
            i+1, UPDATE_VALUE[i], UPDATE_INDEX[i]
        );
        if (
            ListNode_update_index(
                listNode,
                UPDATE_VALUE[i],
                UPDATE_INDEX[i]
            )
        ) {
            printf("更新成功!\n");
            ListNode_print_Link(listNode);
        } else {
            printf("更新失败!\n");
        }
    }
}

/**
 * 测试获取指定位置节点
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_get_index(
    LinkList listNode
) {
    printf("测试获取指定位置节点... \n");
    const int GET_INDEX[5] = {1, 2, 3, 1000, 9999};
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        printf(
            "第 %d 次获取: index: %d\n",
            i+1, GET_INDEX[i]
        );
        if (
            ListNode_get_index(
                listNode,
                GET_INDEX[i],
                &ans
            )
        ) {
            printf("获取成功, 值为: %d\n", ans);
        } else {
            printf("获取失败!\n");
        }
    }
}

/**
 * 测试获取链表长度
 * 
 * @param (LinkList)listNode 链表
 */
void test_LinkList_get_length(
    LinkList listNode
) {
    printf("测试获取链表长度... \n");
    int ans = ListNode_get_length(listNode);
    printf("链表长度为: %d\n", ans);
}