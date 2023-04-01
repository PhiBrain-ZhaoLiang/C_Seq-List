//
// Created by POG on 2021/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef SEQ_LIST_SEQLIST_H
#define LIST_INIT_SIZE  100 //线性表存储空间的初始分配量
#define LIST_INCREMENT 10 //线性表存储空间的分配增量(当存储空间不够时要用到)

typedef int ElemType;
typedef int KeyType;
typedef struct SeqListRecord SeqList;
//线性表结构
struct SeqListRecord {
    ElemType *elem;
    int length;
    int listSize;
};

//初始化线性表
int initList(SeqList *L);

//判断线性表是否为空
bool listEmpty(SeqList *L);

//打印线性表
void printList(SeqList *L);

//插入元素
int listInsert(SeqList *L, int index, ElemType elem);

//删除元素
int listDelete(SeqList *L, int index);

//查找元素位置
int findElemIndex(SeqList *L, ElemType elem);

//销毁线性表
void destroyList(SeqList *L);

//清空线性表
int clearList(SeqList *L);

//获取线性表长度
int getListLength(SeqList *L);

//获取线性表元素
ElemType getElem(SeqList *L, int index);

//获取元素elem的前一个元素
ElemType getPreviousElement(SeqList *L, ElemType elem);

//获取元素elem的下一个元素
ElemType getNextElement(SeqList *L, ElemType elem);

#endif //SEQ_LIST_SEQLIST_H


//初始化线性表
int initList(SeqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        printf("内存溢出!\n");
        return -1;
    }
    L->length = -1;
    L->listSize = LIST_INIT_SIZE;
    printf("初始化完成!\n");
    return 0;
}

bool listEmpty(SeqList *L) {
    if (L->length > -1) {
        return false;
    } else return true;
}

//打印线性表
void printList(SeqList *L) {
    printf("打印所有元素!\n");
    for (int i = 0; i <= L->length; i++) {
        printf("%d\n", L->elem[i]);
    }
    printf("打印结束!\n");
}

//插入元素
int listInsert(SeqList *L, int index, ElemType elem) {
    if (index < 0 || index > L->length + 2) {
        printf("下标溢出!\n");
        return -1;
    }
    if (L->length >= L->listSize) {
        ElemType *newSeqList = (ElemType *) realloc(L->elem, (L->listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newSeqList) {
            printf("内存溢出，无法分配新的空间!\n");
            return -1;
        }//存储空间分配失败
        L->elem = newSeqList;//新基址
        L->listSize += LIST_INCREMENT;//增加存储容量
    }
    for (int i = L->length; i >= index; i--) {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[index] = elem;
    L->length++;
    printf("%d在第%d位插入成功！\n", elem, index);
    return 0;
}

//删除元素
int listDelete(SeqList *L, int index) {
    if (index < 0 || index > L->length + 1) {
        printf("下标溢出!\n");
        return -1;
    }
    for (int i = index; i < L->length; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->elem[L->length] = '\0';
    L->length--;//表长减1
    return 0;
}

//查找元素位置
int findElemIndex(SeqList *L, ElemType elem) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == elem) {
            return i;
        }
    }
    return -1;
}

//销毁线性表
void destroyList(SeqList *L) {
    free(L);
}

//清空线性表
int clearList(SeqList *L) {
    for (int i = 0; i <= L->length; i++) {
        L->elem[i] = '\0';
    }
    L->length = 0;
    return 1;
}

//获取线性表长度
int getListLength(SeqList *L) {
    return L->length;
}

//获取线性表元素
ElemType getElem(SeqList *L, int index) {
    if (index < 0 || index > L->length + 1) {
        printf("下标溢出!\n");
        return -1;
    } else
        return L->elem[index];
}

//获取元素elem的前一个元素
ElemType getPreviousElement(SeqList *L, ElemType elem) {
    int elemIndex = findElemIndex(L, elem);
//    printf("%d\n", elemIndex - 1);
    if (elemIndex > 0) {
        return L->elem[elemIndex - 1];
    } else
        return -1;
}

//获取元素elem的下一个元素
ElemType getNextElement(SeqList *L, ElemType elem) {
    int elemIndex = findElemIndex(L, elem);
//    printf("%d\n", elemIndex - 1);
    if (elemIndex != -1 && elemIndex < L->length) {
        return L->elem[elemIndex + 1];
    } else
        return -1;
}

int SeqSearch(SeqList L, KeyType key) {
    int i;
    L.elem[0] = key;
    for (i = L.length; L.elem[i] != key; i--);
    return i;
}

int BinSearch(SeqList L, KeyType key) {
    int low, high, mid;
    low = 1;
    high = L.length;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        } else if (L.elem[mid] > key) {
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return 0;
}

void InsertSort(SeqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->elem[i] < L->elem[i - 1]) {
            L->elem[0] = L->elem[i];
            for (j = i - 1; L->elem[0] < L->elem[j]; j--) {
                L->elem[j + 1] = L->elem[j];
            }
            L->elem[j + 1] = L->elem[0];
        }
    }
}