#include<stdio.h>

struct linearList {
    int data[100];
    int length;
};

int insertEle(struct linearList *L, int i, int *element) {
    if (i >= L->length || i <= 0) {
        return 0;
    } else {
        for (int k = (i - 1); k < L->length; k++) {
            L->data[k + 1] = L->data[k];
        }
        L->data[i - 1] = *element;
        L->length++;
        return 1;
    }
}

int printEle(struct linearList L, int i) {
    if (i >= L.length || i <= 0) {
        return 0;
    } else {
        printf("%d ", L.data[i - 1]);
        return 1;
    }
}

int main() {

    struct linearList list;
    int size;
    scanf("%d", &size);
    list.length = size;
    for (int i = 1; i <= size; i++) {
        int e;
        scanf("%d", &e);
        insertEle(&list, i, &e);
    }

    for (int i = 1; i <= size; i++) {
        printEle(list, i);
    }

    return 0;
}
