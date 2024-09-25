#include "SeqList.h"
#include "SeqList.c"

int main() {
    // 数据初始化
    printf("数组初始化...\n");
    SeqList* seq_list = SeqList_init();
    for (int i = 0; i < 35; i++) {
        int flag = insert_SeqList(seq_list, i);
    }

    // 打印数组测试
    printf("数组: ");
    SeqList_print(seq_list);
    printf("\n");

    // 获取动态数组占用的大小功能测试
    printf("获取动态数组占用的大小功能测试\n");
    int size = get_SeqList_length(seq_list);
    printf("动态数组大小为: %d\n", size);
    printf("\n");

    // 向数组尾部添加元素功能测试
    printf("向数组尾部添加元素功能测试, 添加:10\n");
    int flag = insert_SeqList(seq_list, 10);
    printf("数组: ");
    SeqList_print(seq_list);
    printf("\n");

    // 按下标插入功能测试
    printf("按下标插入功能测试, 下标: 3, 添加: 1\n");
    flag = insert_SeqList_by_index(seq_list, 3, 1);
    printf("数组: ");
    SeqList_print(seq_list);
    printf("\n");

    // 删除数组指定位置(下标)功能测试
    printf("删除数组指定位置(下标)功能测试, 下标: 3\n");
    flag = delete_SeqList_by_index(seq_list, 3);
    SeqList_print(seq_list);
    printf("\n");

    // 修改数组指定位置(下标)的值功能测试
    printf("修改数组指定位置(下标)的值功能测试, 下标: 30, 值: 100\n");
    flag = update_SeqList_by_index(seq_list, 30, 100);
    SeqList_print(seq_list);
    printf("\n");

    // 获取下标为 index 的值
    printf("获取下标为 index 的值, 下标: 2\n");
    int p;
    flag = get_SeqList_by_index(seq_list, 2, &p);
    printf("值: %d\n", flag, p);

    // 清空数组, 并转换为初始状态功能测试
    printf("清空数组, 并转换为初始状态功能测试\n");
    flag = clear_SeqList(seq_list);
    printf("数组: ");
    SeqList_print(seq_list);
    printf("\n");

    // 销毁数组, 释放内存功能测试
    printf("销毁数组, 释放内存功能测试\n");
    flag = destory_SeqList(&seq_list);
    printf("\n");
    

    system("pause");
    return 0;
}