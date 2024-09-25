#include "SeqList.h"



void SeqList_print(SeqList *seqList) {
    if (!seqList)
        return;
    for (int i = 0; i < seqList->size; i++)
        printf("%d ", seqList->array[i]);
    printf("\n");
}

int get_SeqList_length(SeqList *seqList) {
    // 判断动态数组是否为空
    if (seqList == NULL)
        return 0;
    return seqList->size;
}

SeqList *SeqList_init() {
    // 声明动态数组变量，并分配内存
    SeqList *seqList = (SeqList*)malloc(sizeof(SeqList));
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

int insert_SeqList(
    SeqList *seqList,
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

int insert_SeqList_by_index(
    SeqList *seqList,
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
        // 备份数组地址
        int *p = seqList->array;
        seqList->array = (int*)realloc(
            seqList->array, 
            sizeof(int) * seqList->capicity
        );
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

int delete_SeqList_by_index(
    SeqList *seqList,
    int index
) {
    // 判断数组是否为空 || 判断下标是否合法
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    for (int i = index; i < seqList->size - 1; i++)
        seqList->array[i] = seqList->array[i+1];
    seqList->size --;
    return 1;
}

int update_SeqList_by_index(
    SeqList *seqList,
    int index,
    int value
) {
    // 判断数组是否为空 || 判断下标是否合法
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    seqList->array[ index ] = value;
    return 1;
}

int get_SeqList_by_index(
    SeqList *seqList,
    int index,
    int *ans
) {
    // 判断是否合法
    if (
        seqList == NULL || // 是否为空
        index >= seqList->size || // 下标是否合法
        index < 0
    ) {
        return 0;
    }
    *ans = seqList->array[ index ];
    return 1;
}

int clear_SeqList(SeqList *seqList) {
    if (seqList == NULL)
        return 0;
    int *p = seqList->array;
    seqList->capicity = SEQLIST_DEFAULT_CAPICITY;
    seqList->size = SEQLIST_DEFAULT_SIZE;
    seqList->array = (int*)malloc(sizeof(int) * seqList->capicity);
    free(p);
    return 1;
}

int destory_SeqList(SeqList **seqList) {
    if (!seqList)
        return 0;
    free((*seqList)->array);
    (*seqList)->array = NULL;
    free(*seqList);
    *seqList = NULL;
    return 1;
}



