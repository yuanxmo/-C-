/*** 
 * 使用C语言实现动态数组源代码
 * @author YuanxMo
 * @since 2024/9/10
 * @version 1.0
*/

#ifndef SEQLIST_H
#define SEQLIST_H

// 头文件
#include <stdio.h>
#include <stdlib.h>

// 动态数组默认容量
#define SEQLIST_DEFAULT_CAPICITY 20
// 动态数组默认实际占用大小
#define SEQLIST_DEFAULT_SIZE 0
// 动态数组默认扩容大小
#define SEQLIST_DEFAULT_ADD_CAPICITY 10


/**
 * 动态数组结构类型的定义
 * 
 * @param (int*)array 动态数组元素首指针
 * @param (int)size 动态数组实际的大小
 * @param (int)capicity 动态数组实际分配的容量
 */
typedef struct SeqList {
    int* array;
    int size;
    int capicity;
} SeqList;


/**
 * 打印动态数组
 * 
 * @param (SeqList*)seqList 待打印的动态数组结构类型的指针
 */
void SeqList_print(SeqList* seqList) {
    for (int i = 0; i < seqList->size; i++)
        printf("%d ", seqList->array[i]);
    printf("\n");
}

/**
 * 初始化动态数组
 * 
 * @return 初始化完成的动态数组指针
 */
SeqList* SeqList_init() {
    // 声明动态数组变量，并分配内存
    SeqList* seqList = (SeqList*)malloc(sizeof(SeqList));
    // 判断是否分配成功
    if (seqList == NULL) {
        printf("动态数组初始化失败!\n");
        return NULL;
    }
    // 为动态数组 capicity 赋值
    seqList->capicity = SEQLIST_DEFAULT_CAPICITY;
    // 为动态数组 size 参数赋值
    seqList->size = SEQLIST_DEFAULT_SIZE;
    // 为动态数组分配内存
    seqList->array = (int*)malloc(sizeof(int) * seqList->capicity);
    // 返回动态数组指针
    return seqList;
}

/**
 * 获取动态数组占用的大小
 * 
 * @return 动态数组占用的大小
 */
int get_SeqList_length(SeqList* seqList) {
    // 判断动态数组是否为空
    if (seqList == NULL)
        return 0;
    return seqList->size;
}

/**
 * 获取下标为 index 的值
 * 
 * @param (SeqList*)seqList 动态数组结构类型的指针
 * @param (int)index 需要获取动态数组元素的下标
 * @param (int*)value 储存结果的值
 * @return 1 表示成功, 0 表示失败
 */
int get_SeqList_by_index(
    SeqList* seqList,
    int index,
    int* value
) {
    // 判断是否合法
    if (
        seqList == NULL || // 是否为空
        index >= seqList->size || // 下标是否合法
        index < 0
    ) {
        return 0;
    }
    return seqList->array[ index ];
}

/**
 * 向数组尾部添加元素
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)value 需要插入的值
 * @return 1 表示成功, 0 表示失败
 */
int insert_SeqList(
    SeqList* seqList,
    int value
) {
    // 判断数组是否为空
    if (seqList == NULL)
        return 0;
    // 判断容量是否充足
    if (seqList->size >= seqList->capicity) {
        // 数组扩容
        seqList->capicity += SEQLIST_DEFAULT_ADD_CAPICITY;
        int *p = seqList->array;
        seqList->array = (int*)realloc(seqList->array, sizeof(int) * seqList->capicity);
        // 判断扩容是否成功
        if (seqList->array == NULL) {
            seqList->array = p;
            return 0;
        }
    }
    // 插入操作
    seqList->array[ seqList->size++ ] = value;
    return 1;
}

/**
 * 向数组指定位置插入值
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)index 指定位置(下标)
 * @param (int)value 值
 * @return 1 表示成功, 0 表示失败
 */
int insert_SeqList_by_index(
    SeqList* seqList,
    int index,
    int value
) {
    // 判断数组是否为空 || 判断下标是否合法
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    // 判断容量是否充足
    if (seqList->size >= seqList->capicity) {
        // 数组扩容
        seqList->capicity += SEQLIST_DEFAULT_ADD_CAPICITY;
        int *p = seqList->array;
        seqList->array = (int*)realloc(seqList->array, sizeof(int) * seqList->capicity);
        // 判断扩容是否成功
        if (seqList->array == NULL) {
            seqList->array = p;
            return 0;
        }
    }
    for (int i = seqList->size; i > index; i--) 
        seqList->array[i] = seqList->array[ i-1 ];
    seqList->array[ index ] = value;
    seqList->size ++;
    return 1;
}





#endif