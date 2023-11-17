#ifndef MONTY_H_
#define MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list for stack
 * @n: integer
 * @prev: points to the previous element.
 * @next: points to the next element
 *
 * Description: Doubly linked list node struct
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
	* struct instruction_s - opcode and its function
	* @opcode: the opcode
	* @f: function to handle the opcode
	*
	* Description: opcode and its function
	* for stack, queues, LIFO, FIFO
	*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/******Helping*****/
int is_integer(const char *str);
void free_stack(stack_t *stack);
/*******Function_Declarations*******/
void push(stack_t **stack, int value);
void pall(stack_t *stack);
void pint(stack_t *stack);
void pop(stack_t **stack);
void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

void mod(stack_t **stack);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)));
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)));
/************Handling_Errors**********/
void handle_invalid_instruction(char *opcode, unsigned int line_number);

void handle_push_integer_error(unsigned int line_numer);
void handle_pint_empty_stack_error(unsigned int line_number);
void handle_pop_empty_stack_error(unsigned int line_number);
void handle_swap_stack_too_short_error(unsigned int line_number);
void handle_add_stack_too_short(unsigned int line_number);
void handle_sub_stack_too_short_error(unsigned int line_number);
void handle_div_stack_too_short_error(unsigned int line_number);
void handle_division_by_zero(unsigned int line_number);
void handle_mul_stack_too_short_error(unsigned int line_number);
void handle_mod_stack_too_short_error(unsigned int line_number);
void handle_pchar_stack_too_short_error(unsigned int line_number);
#endif /* MONTY_H_ */
