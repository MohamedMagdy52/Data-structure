
#include "stack.h"

/**
  * @brief check if the stack is full
  * @param *my_stack pointer to the stack
  * @retval return the state of the stack
  */
static stack_state_t stack_full(stack_ds_t *my_stack)
{
    stack_state_t ret = STACK_NOT_FULL;
    if(my_stack->stack_pointer == STACK_MAX_SIZE-1)
    {
        ret = STACK_FULL;           // 1
    }

    return ret;
}

/**
  * @brief check if the stack is empty
  * @param *my_stack pointer to the stack
  * @retval return the state of the stack
  */

static stack_state_t stack_empty(stack_ds_t *my_stack)
{
    stack_state_t ret = STACK_NOT_FULL;              //2
    if(my_stack->stack_pointer == -1)
    {
        ret = STACK_EMPTY;                         // 0
    }

    return ret;
}

/**
  * @brief set stack_pointer to -1, set all elements to 0
  * @param *my_stack pointer to the stack
  * @retval return the error state
  */
return_status_t stack_init(stack_ds_t *my_stack)
{
    uint32_t counter = 0;
    return_status_t ret;
    //pointer validation
    if(my_stack == NULL)
    {
        ret = R_NOK;
    }
    else
    {
        ret = R_OK;
        //set stack_pointer to -1
        my_stack->stack_pointer = -1;
        //set all elements to 0
        for(counter = 0; counter < STACK_MAX_SIZE; counter++)
        {
            my_stack->data[counter] = 0;
        }
    }

    return ret;
}

/**
  * @brief push value into the stack
  * @param *my_stack pointer to the stack, value to be pushed
  * @retval return the error state
  */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value)
{
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (stack_full(my_stack) == STACK_FULL))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUG
        printf("Error, item not pushed!\n");
        #endif // STACK_DEBUG
    }
    else
    {
        ret = R_OK;
        (my_stack->stack_pointer)++;
        my_stack->data[my_stack->stack_pointer] = value;
        #ifdef STACK_DEBUG
        printf("%i has been pushed\n",value);
        #endif // STACK_DEBUG
    }

    return ret;
}

/**
  * @brief pop value from the stack, return it through a pointer
  * @param *my_stack pointer to the stack, pointer to return the popped item through it
  * @retval return the error state
  */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *ret_value)
{
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == ret_value)  || (stack_empty(my_stack) == STACK_EMPTY))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUG
        printf("Error item not popped!\n");
        #endif // STACK_DEBUG
    }
    else
    {
        *ret_value = my_stack->data[my_stack->stack_pointer];
        (my_stack->stack_pointer)--;
        ret = R_OK;
        #ifdef STACK_DEBUG
        printf("%i has been popped\n",*ret_value);
        #endif // STACK_DEBUG
    }

    return ret;
}

/**
  * @brief get the top element of the stack, return it through a pointer
  * @param *my_stack pointer to the stack, pointer to return the popped item through it
  * @retval return the error state
  */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *ret_value)
{
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == ret_value) || (stack_empty(my_stack) == STACK_EMPTY))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUG
        printf("Error, can't apply top operation!\n");
        #endif // STACK_DEBUG
    }
    else
    {
        *ret_value = my_stack->data[my_stack->stack_pointer];
        #ifdef STACK_DEBUG
        printf("%i is the top item \n",*ret_value);
        #endif // STACK_DEBUG
        ret = R_OK;
    }

    return ret;
}
/**
  * @brief get the stack size (number of elements in the stack)
  * @param *my_stack pointer to the stack, pointer to return the size through it
  * @retval return the error state
  */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *ret_value)
{
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == ret_value))
    {
        ret = R_NOK;
        #ifdef STACK_DEBUG
        printf("Error, can't apply stack_size operation!\n");
        #endif // STACK_DEBUG
    }
    else
    {

        *ret_value = (my_stack->stack_pointer)+1;
        ret = R_OK;

        #ifdef STACK_DEBUG
        printf("size of stack is: %i\n",*ret_value);
        #endif // STACK_DEBUG
    }


    return ret;
}
/**
  * @brief print the elements of the stack
  * @param *my_stack pointer to the stack
  * @retval return the error state
  */
return_status_t stack_display(stack_ds_t *my_stack)
{
    return_status_t ret;
    ret = R_NOK;
    if(NULL == my_stack || (stack_empty(my_stack) == STACK_EMPTY))
    {
        ret = R_NOK;
    }
    else
    {
        ret = R_OK;
        sint32_t count;
        printf("stack elements: ");
        for(count = my_stack->stack_pointer; count>=0; count--)
        {
            printf("%i\t",my_stack->data[count]);
        }

        printf("\n");
    }

    return ret;
}
