#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

typedef struct {
    int data;
    /* other feild */
} element;

typedef struct stack *stackPointer;
typedef struct stack {
    element item;
    stackPointer next;
} stack;

stackPointer top[MAX_STACK]; // to store the each stack's top

void build_a_stack(int idx) {
    if (idx >= MAX_STACK) {
        printf("over the max size of stacks\n");
        exit(0);
    }
    
    stackPointer tmp;
    tmp = NULL; // set the top to nullptr
    top[idx] = tmp;
}

void push(element x, int idx) {
    stackPointer tmp;
    tmp = (stackPointer)malloc(sizeof(stack));
    tmp->item = x;
    /* if stack is not empty */
    if (top[idx]) {
        tmp->next = top[idx];
    }
    top[idx] = tmp;
}

element pop(int idx) {
    stackPointer tmp;
    /* if stack is not empty */
    if (top[idx]) {
        tmp = top[idx];
        top[idx] = top[idx]->next;
        return tmp->item;   
    }
    else {
        printf("stack is empty !\n");
        exit(0);
    }
}

void print_stack(stackPointer st) {
    for (; st; st = st->next) {
        printf("%d ", (st->item).data);        
    }
    printf("\n");
}

int main () {
    int idx; // point to which stack

    /* build the first stack (idx = 0) */
    idx = 0;
    build_a_stack(idx);
    
    element e1 = {1};
    element e2 = {2};

    push(e1, idx);
    push(e2, idx);
    printf("pop element = %d\n", pop(idx).data);

    print_stack(top[idx]);
    
}