#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_ds_t stack1;

uint32_t popped_item;
uint32_t topped_item;
uint32_t st_size;

int main()
{

    return_status_t r1 = R_OK;

    r1 |= stack_init(&stack1);
    r1 |= stack_push(&stack1,11);
    r1 |= stack_push(&stack1,22);
    r1 |= stack_push(&stack1,33);
    r1 |= stack_push(&stack1,44);
    r1 |= stack_push(&stack1,55);
    r1 |= stack_push(&stack1,66);
    printf("=========================\n");
    r1 |= stack_top(&stack1,&topped_item);

    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);

    r1 |= stack_top(&stack1,&topped_item);

    printf("====================\n");
    printf("\ninitialize r1 again \n");
    r1 |= stack_init(&stack1);
    r1 |= stack_push(&stack1,10);
    r1 |= stack_push(&stack1,11);
    r1 |= stack_push(&stack1,12);
    r1 |= stack_push(&stack1,13);
    r1 |= stack_push(&stack1,14);


    r1 |= stack_size(&stack1,&st_size);
    printf("stack1 size is: %i\n",st_size);

    r1 |= stack_display(&stack1);

    r1 |= stack_pop(&stack1,&popped_item);
    r1 |= stack_pop(&stack1,&popped_item);

    r1 |= stack_display(&stack1);

    printf("r1 return state: %i\n",r1);


    return 0;
}
