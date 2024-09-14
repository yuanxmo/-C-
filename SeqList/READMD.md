# 动态数组

> Writted by *YuanxMo* on *2024/9/14*
>
> email：yxm8880707@163.com
>
> github：https://github.com/yuanxmo

## 1. 前言

​	数组（array）是一种线性数据结构，可以将相同类型的元素存储在连续的内存空间中。C语言的数组可以用来存储一系列数据，但其中往往是一系列相同类型的变量，C语言的原生数组仅支持固定大小，不支持动态创建，这可能会导致内存空间的浪费（定义的数组过大），系统健壮性不强等问题。故实现可以动态调整大小的数组极为关键。

> ​	一般定义静态数组后，系统会为其分配对应长度的连续内存，但是，在不同的应用场景中，可能会随着数据量的不断增多，数组需要的内存可能是一个非常庞大的量，这让我们在系统初期也要为数组提供一个非常大的内存空间，系统初期的数据量并没有这么大，这无疑会导致内存空间的浪费。
>
> ​	同时，由于数组的长度固定，我们的系统在后期的数据量可能会超出数组的容量，新增的数据无法存入数组中，使数据丢失，严重还可能引发数组越界（通常为段错误，segmentation fault），这会导致系统的可靠性、数据的安全性降低。

​	所以，我们可以自己实现一个可以动态调整大小的数据，于是我们就有了动态数组的概念，动态数组能在程序运行中动态更改自己的大小，以此减少C语言静态数组为程序带来的隐患。

​	本文详细讨论了C语言动态数组的初始化，增删改查等操作，便于我们打下学习数据结构的基础。

## 2. 必要知识

* C语言基础知识
* C语言内存管理函数
  * malloc()
  * realloc()
  * free()
* C语言头文件编写

### 2.1 C语言基础知识

> 包括基础语法、数据类型、变量常量、运算符、循环、判断、函数、数组、指针等内容，在此不再赘述

### 2.2 C语言内存管理函数

#### 2.2.1 malloc() 函数

```c
void *malloc(size_t size)
```

1. 功能：可以分配所需要的内存空间，并且返回一个指向它的指针。

2. 参数：
   * size -- 分配的内存大小，以字节为单位

3. 返回值：函数返回一个指针，指向分配的内存空间，如果分配失败，则返回 NULL

4. 实例

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *nums = NULL;
    nums = (int*)malloc(sizeof(int) * 10);
    return 0;
}
```

> 主函数中，首先初始化一个整形指针**nums**为**NULL**；通过**malloc**函数分配足够储存10个整数的内存，并将**首地址赋值给nums**，此时，nums就成为了一个大小为10的int类型数组。

#### 2.2.2 realloc() 函数

```c
void *realloc(void *ptr, size_t size)
```

1. 功能：尝试调整之前调用**malloc()**或calloc()函数所分配的内存**ptr指针指向的内存空间的大小**

2. 参数：
   * ptr：该指针指向需要重新调整大小的内存块，该内存块之前是用malloc()、realloc()、realloc()进行分配内存的。
   * size：内存块新的大小，以字节为单位。
3. 返回值：
   * 如果原指针指向的内存有足够的连续空间，则扩大原指针指向的内存，将原指针返回。
   * 如果原指针指向的内存无足够的连续空间，则在内存其他区域按照**size**指定的大小分配空间，将原指针指向的内存空间储存的数据从头到尾拷贝到新分配的内存区域，而后释放原指针指向的内存空间（自动释放，**无需free()**），同时返回新分配的内存区域的首地址。
   * 分配失败则返回空指针NULL。

**realloc() 函数存在不安全性，使用时务必小心斟酌！！！**

4. 实例

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *nums = NULL;
    nums = (int*)malloc(sizeof(int) * 10); 
    int *nums_backup = nums;
    nums = (int*)realloc(nums, sizeof(int) * 20);
    if (nums) {
        printf("分配内存成功!\n");
        if (nums == nums_backup)
            printf("原指针指向的内存有足够的连续空间\n");
        else
            printf("原指针指向的内存无足够的连续空间\n");
    }
    else {
        printf("分配失败!\n");
        nums = nums_backup;
    }
    return 0;
}
```

> 继malloc函数实例讲解，尝试使用**realloc函数**将nums的内存扩展至20个整数大小，如果扩展成功，则比较两次的地址，输出相应的信息，分配失败,则将nums从指向NULL还原为指向原内存块。

#### 2.2.3 free() 函数

```c
void free(void *ptr)
```

1. 功能：**释放**之前通过**malloc**、**calloc**或**realloc**分配的内存，避免内存泄漏造成内存碎片，回收不再使用的内存空间，需要注意的是，**原指针仍然指向已释放的内存**，应将原指针设为*NULL*或*重新分配*。

2. 参数：
   * ptr：该指针指向一个要释放的内存空间，该内存空间之前是通过调用**malloc**、**calloc**、**realloc**进行分配的。
3. 该函数无返回值。
4. 实例

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *nums = NULL;
    nums = (int*)malloc(sizeof(int) * 10);
    free(nums);
    nums = NULL;
    return 0;
}
```

> *继malloc函数实例讲解*，调用*free函数* **释放** *nums指向的内存*，避免内存泄露造成内存碎片；将**nums重新设为NULL（重中之重）**，确保不会误使用已释放的内存地址。

### 2.3 C语言头文件（***.h）编写

1. C语言头文件通常包含以下内容：
   * 宏定义：常用于定义配置选项或简单的常量
   * 类型定义（*typedef*）:简化复杂类型的命名
   * 函数声明：声明模块对外提供的函数接口
   * 全局变量声明：声明供其他文件使用的全局变量或静态变量
   * 结构体与枚举：定义数据结构类型
   * 同时还需**预处理指令 *#ifndef*、#*define*、*#endif* 来预防头文件被重复包含的问题**
2. 实例

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// 宏定义
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 类型定义
typedef struct {
    int x;
    int y;
} Point;

// 函数声明
void print_point(Point p);

// 全局变量声明
extern int global_var;

#endif // MY_HEADER_H
```

## 3. 动态数组结构类型

### 3.1 结构体定义

```c
typedef struct SeqList {
    int* array;
    int size;
    int capicity;
} SeqList;
```

### 3.2 结构体参数

> 1. *(int\*)array 动态数组元素首指针*
> 2. *(int)size 动态数组实际的大小*
> 3. *(int)capicity 动态数组实际分配的容量*

## 4. 函数功能

### 4.1 函数定义

```c
void SeqList_print(SeqList* seqList);
int get_SeqList_length(SeqList* seqList);
SeqList *SeqList_init();
int insert_SeqList(SeqList *seqList, int value);
int insert_SeqList_by_index(SeqList *seqList, int index, int value);
int delete_SeqList_by_index(SeqList *seqList, int index);
int update_SeqList_by_index(SeqList *seqList, int index, int value);
int get_SeqList_by_index(SeqList *seqList, int index, int *ans);
int clear_SeqList(SeqList *seqList);
int destory_SeqList(SeqList **seqList);
```

### 4.2 函数功能

> 1. *void SeqList_print(SeqList\* seqList)*
>    * 打印动态数组
> 2. *int get_SeqList_length(SeqList\* seqList)* 
>    * 获取动态数组占用的大小
>
> 3. *SeqList \*SeqList_init()*
>    * 初始化动态数组
>
> 4. *int insert_SeqList(SeqList \*seqList, int value)*
>    * 向数组尾部添加元素
>
> 5. *int insert_SeqList_by_index(SeqList \*seqList,  int index,  int value)*
>    * 向数组指定位置插入值
>
> 6. *int delete_SeqList_by_index(SeqList \*seqList,  int index)*
>    * 删除数组指定位置(下标)
>
> 7. *int update_SeqList_by_index(SeqList \*seqList,  int index,  int value)*
>    * 修改数组指定位置(下标)的值
>
> 8. *int get_SeqList_by_index(SeqList \*seqList,  int index,  int \*ans)*
>    * 获取下标为 index 的值
>
> 9. *int clear_SeqList(SeqList \*seqList)*
>    * 清空数组, 并转换为初始状态
>
> 10. *int destory_SeqList(SeqList \*\*seqList)*
>     * 销毁数组, 释放内存

## 5. 具体实现

### 5.1 宏定义

#### 5.1.1 代码

```c
// 动态数组默认容量
#define SEQLIST_DEFAULT_CAPICITY 20
// 动态数组默认实际占用大小
#define SEQLIST_DEFAULT_SIZE 0
// 动态数组默认扩容大小
#define SEQLIST_DEFAULT_ADD_CAPICITY 10
```

#### 5.1.2 思路

> 宏定义设置动态数组默认参数
>
> 1. *SEQLIST_DEFAULT_CAPICITY*：初始容量为20
> 2. *SEQLIST_DEFAULT_SIZE*：初始实际占用大小为0
> 3. *SEQLIST_DEFAULT_ADD_CAPICITY*：扩容时，默认增加容量为10

### 5.2 动态数组结构类型定义

#### 5.2.1 代码

```c
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
```

#### 5.2.2 思路

> 结构类型定义；定义了一个名为**SeqList**的动态数组结构：
>
> 1. int* array：存储数组元素的首指针；
>
> 2. int size：记录数组当前的实际大小；
>
> 3. int capacity：表示数组已分配的最大容量。用于支持动态扩展。

### 5.3 打印动态数组

#### 5.3.1 代码

```c
/**
 * 打印动态数组
 * 
 * @param (SeqList*)seqList 待打印的动态数组结构类型的指针
 */
void SeqList_print(SeqList* seqList) {
    if (!seqList)
        return;
    for (int i = 0; i < seqList->size; i++)
        printf("%d ", seqList->array[i]);
    printf("\n");
}
```

#### 5.3.2 思路

> 1. 打印前提：
>    * 检查传入的*(SeqList\*)seqList*指针是否为空，为空则返回*0*
>
> 2. 遍历动态数组每个元素并打印
> 3. 打印完成后换行

### 5.3 获取动态数组占用的大小

#### 5.3.1 代码

```c
/**
 * 获取动态数组占用的大小
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 动态数组占用的大小
 */
int get_SeqList_length(SeqList* seqList) {
    // 判断动态数组是否为空
    if (seqList == NULL)
        return 0;
    return seqList->size;
}
```

#### 5.3.2 思路

> 1. 首先检查传入的*(SeqList\*)seqList*是否为空，为空则返回*0*
> 2. 返回动态数组占用的大小，即*seqLIst->size*

### 5.4 初始化动态数组

#### 5.4.1 代码

```c
/**
 * 初始化动态数组
 * 
 * @return 初始化完成的动态数组指针
 */
SeqList *SeqList_init() {
    SeqList *seqList = (SeqList*)malloc(sizeof(SeqList));
    if (seqList == NULL) {
        printf("动态数组初始化失败!\n");
        return NULL;
    }
    seqList->capicity = SEQLIST_DEFAULT_CAPICITY;
    seqList->size = SEQLIST_DEFAULT_SIZE;
    seqList->array = (int*)malloc(sizeof(int) * seqList->capicity);
    return seqList;
}
```

#### 5.4.2 思路

> 1. 通过**malloc函数**分配内存给*SeqList结构体*，将内存空间的指针返回并赋值给**seqList指针**，并检查是否分配成功
>    * 分配失败则返回空指针
> 2. 设置默认容量和大小（*宏定义*）
> 3. 为实际存储的数据的数组按*seqList指针指向的结构体*中的**capacity**的大小分配内存，
> 4. 最终**返回**初始化后的动态数组**结构类型指针**

### 5.5 向数组尾部添加元素

#### 5.5.1 代码

```c
/**
 * 向数组尾部添加元素
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)value 需要插入的值
 * @return 1 表示成功, 0 表示失败
 */
int insert_SeqList(
    SeqList *seqList,
    int value
) {
    if (seqList == NULL)
        return 0;
    if (seqList->size >= seqList->capicity) {
        seqList->capicity += SEQLIST_DEFAULT_ADD_CAPICITY;
        int *p = seqList->array;
        seqList->array = (int*)realloc(seqList->array, sizeof(int) * seqList->capicity);
        if (seqList->array == NULL) {
            seqList->array = p;
            return 0;
        }
    }
    seqList->array[ seqList->size++ ] = value;
    return 1;
}
```

#### 5.5.2 思路

> 函数返回值：
>
> * **1** 表示该操作成功
> * **0** 表示该操作失败
>
> 1. 首先检查传入的 *(SeqList\*)seqList* 指针是否为空
>    * 为空则返回 **0**
> 2. 检查数组的容量是否充足，容量不足则进行扩容操
>    1. 扩容大小默认为 *SEQLIST_DEFAULT_ADD_CAPICITY*
>    2. 使用 **realloc函数** 调整数组指针指向的内存大小
>       * 调整成功，则进行插入操作
>       * 调整失败，则将 *seqList* 指针从指向NULL**还原**为指向原内存块，函数返回 **0**
> 3. 插入操作：在数组末尾插入新值，并将数组大小加一
> 4. 插入成功，函数返回 **1**

### 5.6 向数组指定位置插入值

#### 5.6.1 代码

```c
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
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    if (seqList->size >= seqList->capicity) {
        seqList->capicity += SEQLIST_DEFAULT_ADD_CAPICITY;
        int *p = seqList->array;
        seqList->array = (int*)realloc(
            seqList->array, 
            sizeof(int) * seqList->capicity
        );
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
```

#### 5.6.2 思路

> 1. 首先检查传入的 *(SeqList\*)seqList* 指针是否为空，检查下标是否合法
>    * 一项不通过则返回 **0**
> 2. 与 **5.5** 第二步相同
> 3. 将插入位置及其之后的所有元素向后移动一位
> 4. 在指定位置插入新值，并更新数组大小
> 5. 插入成功，函数返回 **1**

### 5.7 删除数组指定位置(下标)

#### 5.7.1 代码

```c
/**
 * 删除数组指定位置(下标)
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @param (int)index 指定位置(下标)
 * @return 1 表示成功, 0 表示失败
 */
int delete_SeqList_by_index(
    SeqList *seqList,
    int index
) {
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    for (int i = index; i < seqList->size - 1; i++)
        seqList->array[i] = seqList->array[i+1];
    seqList->size --;
    return 1;
}
```

#### 5.7.2 思路

> 1. 检查数组不为空且下标合法
>    * 一项不通过则返回 **0**
> 2. 然后将待删元素之后的所有元素向前移动一位
> 3. 减小数组大小
> 4. 删除成功，函数返回 **1**

### 5.8 修改数组指定位置(下标)的值

#### 5.8.1 代码

```c
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
) {
    if (seqList == NULL || index < 0  || index >= seqList->size)
        return 0;
    seqList->array[ index ] = value;
    return 1;
}
```

#### 5.8.2 思路

> 1. 检查数组不为空且下标合法
>    * 一项不通过则返回 **0**
> 2. 修改值：将指定下标位置的值更新为给定的新值
> 3. 修改成功，函数返回 **1**

### 5.9 获取下标为 index 的值

#### 5.9.1 代码

```c
/**
 * 获取下标为 index 的值
 * 
 * @param (SeqList*)seqList 动态数组结构类型的指针
 * @param (int)index 需要获取动态数组元素的下标
 * @param (int*)ans 储存结果的值
 * @return 1 表示成功, 0 表示失败
 */
int get_SeqList_by_index(
    SeqList *seqList,
    int index,
    int *ans
) {
    if (
        seqList == NULL ||
        index >= seqList->size ||
        index < 0
    ) {
        return 0;
    }
    *ans = seqList->array[ index ];
    return 1;
}
```

#### 5.9.2 思路

> 1. 检查数组不为空且下标合法
>    * 一项不通过则返回 **0**
> 2. 将seqList中index位置的元素值赋给ans指向的变量
> 3. 获取成功，函数返回 **1**

### 5.10 清空数组, 并转换为初始状态

#### 5.10.1 代码

```c
/**
 * 清空数组, 并转换为初始状态
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 1 表示成功, 0 表示失败
 */
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
```

#### 5.10.2 思路

> 1. 检查传入的 *(SeqList\*)seqList* 指针是否为空
>    * 为空则返回 **0**
> 2. 保存原数组指针，重置 seqList 的*容量*和*大小*为**默认值**
> 3. 按 *SEQLIST_DEFAULT_SIZE* 重新分配内存给 *seqList->array*，释放旧数组内存
> 4. 清空成功，函数返回 **1**

### 5.11 销毁数组, 释放内存

#### 5.11.1 代码

```c
/**
 * 销毁数组, 释放内存
 * 
 * @param (SeqList*)seqList 动态数组结构类型指针
 * @return 1 表示成功, 0 表示失败
 */
int destory_SeqList(SeqList** seqList) {
    if (!seqList)
        return 0;
    free((*seqList)->array);
    (*seqList)->array = NULL;
    free(*seqList);
    *seqList = NULL;
    return 1;
}
```

#### 5.11.2 思路

> 1. 检查传入的 *(SeqList\*)seqList* 指针是否为空
>    * 为空则返回 **0**
> 2. 释放 *seqList->array* 内存，并将指针置空
> 3. 释放动态数组结构体内存，并将指针置空
> 4. 成功，函数返回 **1**

**需要注意的是，在传入参数时， *seqList* 为 *二级指针*，若为一级指针的话，调用此函数，并*不能改变实参指向的内存地址*，需要传入二级指针才能解决此问题**

 ## 结语

1. 在处理**数组扩容**的操作时，需要用到 **realloc函数** 调整内存的大小，在此过程中，需确保内存的安全，即 **在调用 realloc函数 调整内存时，需先*备份原指针指向的内存地址*，而后调用 realloc函数 调整内存，判断是否指针是否为空，为空则 *将指针还原为指向备份指针指向的内存空间（原指针指向的内存空间）*。 **
2. 在**销毁数组**时，传参需传**二级指针**，否则**不能保证主函数中实参指向*NULL***，注：一级指针并不能改变主函数中实参（指针）指向的内存空间（因为释放内存后，指针要置空）

> 很高兴你能看到这里
> 本人联系方式：yxm8880707@163.com