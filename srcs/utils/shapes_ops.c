/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:43:12 by rkanmado          #+#    #+#             */
/*   Updated: 2023/05/07 13:38:11 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void init_stack(t_st *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

static void adding_process(t_st *stack, t_sh **new)
{
    t_sh *newtmp;

    newtmp = *new;
    if (stack->tail == NULL)
    {
        newtmp->next = NULL;
        newtmp->prev = NULL;
        stack->tail = newtmp;
        stack->head = newtmp;
    }
    else
    {
        newtmp->next = NULL;
        newtmp->prev = stack->tail;
        stack->tail->next = newtmp;
        stack->tail = newtmp;
    }
}

void ft_unshift(t_st *stack, void *info, t_shtype type)
{
    t_sh *new;

    new = (t_sh *)malloc(sizeof(t_sh));
    if (new == NULL)
        ft_error("Error \n");
    new->i = info;
    new->type = type;
    adding_process(stack, &new);
    stack->size++;
    return;
}

/* Add a new node at the top into existing double link list */
void ft_push(t_st *stack, void*info)
{
    t_sh *new;

    new = (t_sh *)malloc(sizeof(t_sh));
    if (new == NULL)
        ft_error("Error \n");
    new->i = info;
    new->next = stack->head;
    new->prev = NULL;
    if (stack->tail == NULL)
    {
        stack->tail = new;
        stack->head = new;
    }
    else
    {
        stack->head->prev = new;
        stack->head = new;
    }
    stack->size++;
    return;
}

/* pop top element of a stack into doubly linked list */
void* ft_pop(t_st *stack)
{
    void* info;
    t_sh *tmp;

    if (stack->head == NULL)
        ft_error("Error \n");
    info = stack->head->i;
    tmp = stack->head;
    if (stack->head->next == NULL)
    {
        stack->head = NULL;
        stack->tail = NULL;
    }
    else
    {
        stack->head = stack->head->next;
        stack->head->prev = NULL;
    }
    if (stack->head != NULL)
        stack->head->prev = NULL;
    stack->size--;
    free(tmp);
    return (info);
}

/* Function that duplicate a stack bundle */
t_st duplicate_stack(t_st *stack)
{
    t_st new;
    t_sh *current;

    init_stack(&new);
    current = stack->head;
    if (current == NULL)
        return (new);
    while (current != NULL && current->next != NULL)
    {
        ft_unshift(&new, current->i, current->type);
        current = current->next;
    }
    ft_unshift(&new, current->i, current->type);
    return (new);
}