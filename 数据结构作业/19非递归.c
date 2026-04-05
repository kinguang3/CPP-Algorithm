//非递归实现
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;
    int n;
    int state;
    int temp;
} Frame;

typedef struct {
    Frame *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (Frame*)malloc(sizeof(Frame) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void push(Stack *s, Frame f) {
    if (s->top + 1 >= s->capacity) {
        s->capacity *= 2;
        s->data = (Frame*)realloc(s->data, sizeof(Frame) * s->capacity);
    }
    s->data[++s->top] = f;
}

Frame pop(Stack *s) {
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void freeStack(Stack *s) {
    free(s->data);
    free(s);
}

int ackermann(int m, int n) {
    Stack *stack = createStack(1024);
    
    Frame init = {m, n, 0, 0};
    push(stack, init);
    
    int result = 0;
    
    while (!isEmpty(stack)) {
        Frame current = pop(stack);
        int m_val = current.m;
        int n_val = current.n;
        
        if (current.state == 1) {
            push(stack, (Frame){m_val - 1, current.temp, 0, 0});
            continue;
        }
        
        if (m_val == 0) {
            result = n_val + 1;
            
            if (!isEmpty(stack)) {
                Frame waiting = pop(stack);
                waiting.temp = result;
                waiting.state = 1;
                push(stack, waiting);
            }
        } 
        else if (n_val == 0) {
            push(stack, (Frame){m_val - 1, 1, 0, 0});
        } 
        else {
            push(stack, (Frame){m_val, n_val, 1, 0});
            push(stack, (Frame){m_val, n_val - 1, 0, 0});
        }
    }
    
    freeStack(stack);
    return result;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", ackermann(m, n));
    return 0;
}