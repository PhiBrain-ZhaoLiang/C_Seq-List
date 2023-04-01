#include <stdio.h>
#include "SeqList.h"

int main() {
    SeqList seqList;
    initList(&seqList);
//    printf("执行插入操作!\n");
//    listInsert(&seqList, 1, 8);
//    listInsert(&seqList, 2, 4);
//    listInsert(&seqList, 3, 7);
//    listInsert(&seqList, 4, 2);
//    listInsert(&seqList, 5, 9);
//    listInsert(&seqList, 6, 10);
//    listInsert(&seqList, 7, 1);
//    listInsert(&seqList, 8, 5);
//    InsertSort(&seqList);
    //添加10个数字给线性表list
    /*for (int i = 0; i < 10; i++) {
        listInsert(&seqList, i, i);
    }*/
//    printf("插入操作结束!\n");
//    printList(&seqList);
//    printf("当前线性表是否为空：%d\n", listEmpty(&seqList));
//    listInsert(&seqList, 5, 11);
    printList(&seqList);
//    printf("当前线性表长度为：%d\n", getListLength(&seqList));
//    printf("第2位元素：%d\n", getElem(&seqList, 2));
//    printf("第0位元素的前一位元素:%d\n", getPreviousElement(&seqList, 0));
//    printf("第9位元素的后一位元素:%d\n", getNextElement(&seqList, 9));
//    printf("第1位元素的前一位元素:%d\n", getPreviousElement(&seqList, 1));
//    printf("第8位元素的后一位元素:%d\n", getNextElement(&seqList, 8));
//    printf("第1位元素的后一位元素:%d\n", getNextElement(&seqList, 1));
//    printf("执行删除操作!\n");
//    listDelete(&seqList, 5);
//    printf("删除操作结束!\n");
//    printList(&seqList);
//    int indexElem = 7;
//    int index = findElemIndex(&seqList, indexElem);
//    printf("%d的位置在第%d位\n", indexElem, index);
//    indexElem = 10;
//    index = findElemIndex(&seqList, indexElem);
//    printf("%d的位置在第%d位\n", indexElem, index);
//    clearList(&seqList);
//    for (int i = 0; i <= 11; i++) {
//        printf("%d\n", seqList.elem[i]);
//    }
//    destroyList(&seqList);
//    printf("销毁后第0个元素：%d\n", seqList.elem[0]);
    return 0;
}


