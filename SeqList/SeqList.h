/*** 
 * 使用C语言实现动态数组源代码
 * @author YuanxMo
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


/**
 * 动态数组结构类型的定义
 * @param (int*)array 动态数组元素首指针
 * @param (int)size 动态数组实际占用的大小
 * @param (int)capicity 动态数组实际分配的容量
 */
typedef struct SeqList {
    int* array;
    int size;
    int capicity;
} SeqList;

/**
 * 初始化动态数组
 * @return 初始化完成的动态数组指针
 */
SeqList* SeqList_init() {
    SeqList* seq_list = (SeqList*)malloc(sizeof(SeqList));
    seq_list->size = SEQLIST_DEFAULT_SIZE;
    seq_list->capicity = SEQLIST_DEFAULT_CAPICITY;
    seq_list->array = (int*)malloc(sizeof(int) * seq_list->capicity);
    return seq_list;
}










#endif