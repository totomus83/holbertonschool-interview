#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 * Return: new head of reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second_half, *first_half;
    listint_t *tmp;
    int result = 1;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return (1);

    slow = fast = *head;

    /* Find middle of list */
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    second_half = reverse_list(slow->next);
    first_half = *head;

    /* Compare both halves */
    tmp = second_half;
    while (tmp != NULL)
    {
        if (first_half->n != tmp->n)
        {
            result = 0;
            break;
        }
        first_half = first_half->next;
        tmp = tmp->next;
    }

    /* Restore the list (optional) */
    slow->next = reverse_list(second_half);

    return (result);
}
