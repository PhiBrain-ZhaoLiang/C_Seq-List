//
// Created by POG on 2021/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef SEQ_LIST_SEQLIST_H
#define LIST_INIT_SIZE  100 //���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 10 //���Ա�洢�ռ�ķ�������(���洢�ռ䲻��ʱҪ�õ�)

typedef int ElemType;
typedef int KeyType;
typedef struct SeqListRecord SeqList;
//���Ա�ṹ
struct SeqListRecord {
    ElemType *elem;
    int length;
    int listSize;
};

//��ʼ�����Ա�
int initList(SeqList *L);

//�ж����Ա��Ƿ�Ϊ��
bool listEmpty(SeqList *L);

//��ӡ���Ա�
void printList(SeqList *L);

//����Ԫ��
int listInsert(SeqList *L, int index, ElemType elem);

//ɾ��Ԫ��
int listDelete(SeqList *L, int index);

//����Ԫ��λ��
int findElemIndex(SeqList *L, ElemType elem);

//�������Ա�
void destroyList(SeqList *L);

//������Ա�
int clearList(SeqList *L);

//��ȡ���Ա���
int getListLength(SeqList *L);

//��ȡ���Ա�Ԫ��
ElemType getElem(SeqList *L, int index);

//��ȡԪ��elem��ǰһ��Ԫ��
ElemType getPreviousElement(SeqList *L, ElemType elem);

//��ȡԪ��elem����һ��Ԫ��
ElemType getNextElement(SeqList *L, ElemType elem);

#endif //SEQ_LIST_SEQLIST_H


//��ʼ�����Ա�
int initList(SeqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        printf("�ڴ����!\n");
        return -1;
    }
    L->length = -1;
    L->listSize = LIST_INIT_SIZE;
    printf("��ʼ�����!\n");
    return 0;
}

bool listEmpty(SeqList *L) {
    if (L->length > -1) {
        return false;
    } else return true;
}

//��ӡ���Ա�
void printList(SeqList *L) {
    printf("��ӡ����Ԫ��!\n");
    for (int i = 0; i <= L->length; i++) {
        printf("%d\n", L->elem[i]);
    }
    printf("��ӡ����!\n");
}

//����Ԫ��
int listInsert(SeqList *L, int index, ElemType elem) {
    if (index < 0 || index > L->length + 2) {
        printf("�±����!\n");
        return -1;
    }
    if (L->length >= L->listSize) {
        ElemType *newSeqList = (ElemType *) realloc(L->elem, (L->listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newSeqList) {
            printf("�ڴ�������޷������µĿռ�!\n");
            return -1;
        }//�洢�ռ����ʧ��
        L->elem = newSeqList;//�»�ַ
        L->listSize += LIST_INCREMENT;//���Ӵ洢����
    }
    for (int i = L->length; i >= index; i--) {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[index] = elem;
    L->length++;
    printf("%d�ڵ�%dλ����ɹ���\n", elem, index);
    return 0;
}

//ɾ��Ԫ��
int listDelete(SeqList *L, int index) {
    if (index < 0 || index > L->length + 1) {
        printf("�±����!\n");
        return -1;
    }
    for (int i = index; i < L->length; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->elem[L->length] = '\0';
    L->length--;//����1
    return 0;
}

//����Ԫ��λ��
int findElemIndex(SeqList *L, ElemType elem) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == elem) {
            return i;
        }
    }
    return -1;
}

//�������Ա�
void destroyList(SeqList *L) {
    free(L);
}

//������Ա�
int clearList(SeqList *L) {
    for (int i = 0; i <= L->length; i++) {
        L->elem[i] = '\0';
    }
    L->length = 0;
    return 1;
}

//��ȡ���Ա���
int getListLength(SeqList *L) {
    return L->length;
}

//��ȡ���Ա�Ԫ��
ElemType getElem(SeqList *L, int index) {
    if (index < 0 || index > L->length + 1) {
        printf("�±����!\n");
        return -1;
    } else
        return L->elem[index];
}

//��ȡԪ��elem��ǰһ��Ԫ��
ElemType getPreviousElement(SeqList *L, ElemType elem) {
    int elemIndex = findElemIndex(L, elem);
//    printf("%d\n", elemIndex - 1);
    if (elemIndex > 0) {
        return L->elem[elemIndex - 1];
    } else
        return -1;
}

//��ȡԪ��elem����һ��Ԫ��
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