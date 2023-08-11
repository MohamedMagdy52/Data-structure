#ifndef STACK_H_
#define STACK_H_

#include "std_types.h"

#define STACK_MAX_SIZE 5

#define STACK_DEBUG               /*remove comment to activate debugging mode*/

typedef struct stack_ds
{
    sint32_t stack_pointer;
    uint32_t data[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum stack_state
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL
}stack_state_t;


/**
  * @brief set stack_pointer to -1, set all elements to 0
  * @param *my_stack pointer to the stack
  * @retval return the error state
  */
return_status_t stack_init(stack_ds_t *my_stack);

/**
  * @brief push parameters into the stack
  * @param *my_stack pointer to the stack, value to be pushed
  * @retval return the error state
  */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value);

/**
  * @brief pop value from the stack, return it through a pointer
  * @param *my_stack pointer to the stack, pointer to return the popped item through it
  * @retval return the error state
  */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *ret_value);

/**
  * @brief get the top element of the stack, return it through a pointer
  * @param *my_stack pointer to the stack, pointer to return the popped item through it
  * @retval return the error state
  */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *ret_value);

/**
  * @brief get the stack size (number of elements in the stack)
  * @param *my_stack pointer to the stack, pointer to return the size through it
  * @retval return the error state
  */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *ret_value);

/**
  * @brief print the elements of the stack
  * @param *my_stack pointer to the stack
  * @retval return the error state
  */
return_status_t stack_display(stack_ds_t *my_stack);



#endif // STACK_H_
