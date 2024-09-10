/*** 
 * 使用C语言实现动态数组源代码
 * @author runoob
 * @version 1.2
*/

#ifndef SEQLIST_H
#define SEQLIST_H


#include <stdio.h>
#include <stdlib.h>

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










#endif