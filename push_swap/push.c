#include "push_swap.h"

void push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*a == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
}
void push_a(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b == NULL)
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
}
void swap_a(t_stack **a)
{
    t_stack *temp;

    if (*a == NULL || (*a)->next == NULL)
        return;
    temp = (*a)->next;
    (*a)->next = temp->next;
    temp->next = *a;
    *a = temp;
}

void swap_b(t_stack **b)
{
    t_stack *temp;

    if (*b == NULL || (*b)->next == NULL)
        return;
    temp = (*b)->next;
    (*b)->next = temp->next;
    temp->next = *b;
    *b = temp;
}

void swap_ab(t_stack **a, t_stack **b)
{
    swap_a(a);
    swap_b(b);
}

void rotate_a(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    if (*a == NULL || (*a)->next == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    last = *a;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
}

void rotate_b(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    if (*b == NULL || (*b)->next == NULL)
        return;
    temp = *b;
    *b = (*b)->next;
    last = *b;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
}

void rotate_ab(t_stack **a, t_stack **b)
{
    rotate_a(a);
    rotate_b(b);
}

void reverse_rotate_a(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    if (*a == NULL || (*a)->next == NULL)
        return;
    last = *a;
    while (last->next->next != NULL)
        last = last->next;
    temp = last->next;
    last->next = NULL;
    temp->next = *a;
    *a = temp;
}

void reverse_rotate_b(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    if (*b == NULL || (*b)->next == NULL)
        return;
    last = *b;
    while (last->next->next != NULL)
        last = last->next;
    temp = last->next;
    last->next = NULL;
    temp->next = *b;
    *b = temp;
}

void reverse_rotate_ab(t_stack **a, t_stack **b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
}


