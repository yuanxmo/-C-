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
    int *array;
    int size;
    int capicity;
} SeqList;


/**
 * 打印动态数组
 * 
 * @param (SeqList*)seqList 待打印的动态数组结构类型的指针
 */
void SeqList_print(SeqList *seqList);

/**
 * 获取动态数组占用的大小
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 动态数组占用的大小
 */
int get_SeqList_length(SeqList *seqList);

/**
 * 初始化动态数组
 * 
 * @return 初始化完成的动态数组指针
 */
SeqList *SeqList_init();

/**
 * 向数组尾部添加元素
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)value 需要插入的值
 * @return 1 表示成功, 0 表示失败
 */
int insert_SeqList(SeqList *seqList, int value);

/**
 * 向数组指定位置插入值
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)index 指定位置(下标)
 * @param (int)value 值
 * @return 1 表示成功, 0 表示失败
 */
int insert_SeqList_by_index(SeqList *seqList, int index, int value);

/**
 * 删除数组指定位置(下标)
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)index 指定位置(下标)
 * @return 1 表示成功, 0 表示失败
 */
int delete_SeqList_by_index(SeqList *seqList,int index);

/**
 * 修改数组指定位置(下标)的值
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)index 指定位置(下标)
 * @param (int)value 值
 * @return 1 表示成功, 0 表示失败
 */
int update_SeqList_by_index(
    SeqList *seqList,
    int index,
    int value
);

/**
 * 获取下标为 index 的值
 * 
 * @param (SeqList*)seqList 动态数组结构类型的指针
 * @param (int)index 需要获取动态数组元素的下标
 * @param (int*)ans 储存结果的值
 * @return 1 表示成功, 0 表示失败
 */
int get_SeqList_by_index(SeqList *seqList, int index, int *ans);

/**
 * 清空数组, 并转换为初始状态
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 1 表示成功, 0 表示失败
 */
int clear_SeqList(SeqList *seqList);

/**
 * 销毁数组, 释放内存
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 1 表示成功, 0 表示失败
 */
int destory_SeqList(SeqList **seqList);


#endif