#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;

struct listNode {
    int data;
    listPointer link;
};

void insert(listPointer *ptr, int num) {
    listPointer tmp = (listPointer)malloc(sizeof(struct listNode));
    tmp->data = num;

    if (*ptr) {
        tmp->link = (*ptr)->link;
        (*ptr)->link = tmp;
    }
    else {
        tmp->link = NULL;
        *ptr = tmp;
    }
}

// trail is precede of the 'del'
void delete(listPointer *ptr, listPointer trail) {
    if (trail) {
        trail->link = (trail->link)->link;
    }
    else {
        (*ptr) = (*ptr)->link;
    }
    free(trail->link);
}

void print(listPointer list) {
    for (; list; list = list->link) {
        printf("%d ", list->data);
    }
    printf("\n");
}

int main() {
    listPointer list = NULL;
    listPointer trail = NULL;

    insert(&list, 3);
    insert(&list, 4);

    trail = list;
    
    delete(&list, trail);
    print(list);
}