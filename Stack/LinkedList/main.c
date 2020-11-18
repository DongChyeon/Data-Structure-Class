#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack = makeStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStackItems(stack);

    pop(stack);
    printStackItems(stack);

    makeStackEmpty(stack);
    printStackItems(stack);

    deleteStack(stack);

    return 0;
}