#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits/stdc++.h"
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList *L) {
    L->elem = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = MAXSIZE;
    return OK;
}

Status Listinput(SqList *La) {
//    printf("put\r\n");
    int i = 0;
    int a = 1;
    while (a != 0) {
        scanf("%d", &a);
        La->elem[i] = a;
        La->length++;
        i++;

    }
    return OK;
}

Status steMUl(SqList *a, SqList b, SqList c) {
    int i, j, k = 0;

    if (b.length == 0 || c.length == 0) return ERROR;
    for (i = 0; i < b.length - 1; i++) {
        for (j = 0; j < c.length - 1; j++) {
            if (b.elem[i] == c.elem[j]) {
                a->elem[k] = b.elem[i];
                k++;
                a->length++;
                for (int q = 1; q < a->length; q++) {
                    if (a->elem[k] == a->elem[q])
                        k--;
                    a->length--;
                }
            }
        }
    }
    return OK;

}

void print_List(SqList L) {
    int i;

    if (L.length == 0) {
        printf("empty class");
        return;
    }
    std::set<int> faq;
    for (i = 0; i <= L.length; i++) {
        if (!faq.count(L.elem[i])) {
            printf("%d ", L.elem[i]);
        }
        faq.insert(L.elem[i]);
    }


}

int main() {
    SqList La, Lb, Lc;
    InitList_Sq(&La);  //初始化3个线性表
    InitList_Sq(&Lb);
    InitList_Sq(&Lc);
    Listinput(&La); //输入La的值
    Listinput(&Lb);//输入Lb的值
    steMUl(&Lc, La, Lb);//求出La和Lb的交集，放在Lc中
    print_List(Lc);//打印交集
    return 0;
}
