#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doublylinkedlist.h"
#define to_list(x) (list_node_t **)(x)
#define to_list_node(x) (list_node_t *)(x)
#define to_string_item(x) (string_item_t *)(x)

list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }

    int list_size = 0;
    list_node_t *current_head_for_size = *head;
    while (current_head_for_size)
    {
        current_head_for_size = current_head_for_size->next;
        list_size++;
    }

    *head = (*head)->next;
    if (list_size > 1)
    {
        (*head)->prev = NULL;
    }
    current_head->next = NULL;
    return current_head;
}

string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item)
    {
        return NULL;
    }
    item->string = string;

    return item;
}

list_node_t *list_remove(list_node_t **head, list_node_t *item)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }

    int list_size = 0;
    list_node_t *current_head_for_size = *head;
    while (current_head_for_size)
    {
        current_head_for_size = current_head_for_size->next;
        list_size++;
    }

    for (size_t i = 0; i < list_size; i++)
    {
        if (current_head != item)
        {
            current_head = current_head->next;
            continue;
        }
        else
        {
            if (i == 0)
            {
                list_pop(head);
                break;
            }
            else
            {

                if (i == list_size - 1)
                {
                    current_head->prev->next = NULL;
                }
                else
                {
                    current_head->next->prev = current_head->prev;
                    current_head->prev->next = current_head->next;
                    current_head->next = NULL;
                }
                current_head->prev = NULL;
                break;
            }
        }
    }

    return current_head;
}

list_node_t *list_insert_after(list_node_t **head, list_node_t *item_to_add, list_node_t *after)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }

    int list_size = 0;
    list_node_t *current_head_for_size = *head;
    while (current_head_for_size)
    {
        current_head_for_size = current_head_for_size->next;
        list_size++;
    }

    list_node_t *tail = list_get_tail(head);
    list_append(head, item_to_add);
    for (size_t i = 0; i < list_size; i++)
    {
        if (current_head != after)
        {
            current_head = current_head->next;
            continue;
        }
        else
        {
            if (i == list_size - 1)
            {
                break;
            }
            else
            {
                tail->next = NULL;
                item_to_add->prev = current_head;
                item_to_add->next = current_head->next;
                item_to_add->next->prev = item_to_add;
                current_head->next = item_to_add;
                break;
            }
        }
    }
    return item_to_add;
}

list_node_t *list_insert_before(list_node_t **head, list_node_t *item_to_add, list_node_t *before)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }

    int list_size = 0;
    list_node_t *current_head_for_size = *head;
    while (current_head_for_size)
    {
        current_head_for_size = current_head_for_size->next;
        list_size++;
    }

    list_node_t *tail = list_get_tail(head);
    list_append(head, item_to_add);
    for (size_t i = 0; i < list_size; i++)
    {
        if (current_head != before)
        {
            current_head = current_head->next;
            continue;
        }
        else
        {
            tail->next = NULL;
            if (i == 0)
            {
                *head = item_to_add;
                item_to_add->prev = NULL;
                current_head->prev = item_to_add;
                item_to_add->next = current_head;
                break;
            }
            else
            {
                item_to_add->prev = current_head->prev;
                current_head->prev = item_to_add;
                item_to_add->next = current_head;
                item_to_add->prev->next = item_to_add;
                break;
            }
        }
    }
    return item_to_add;
}

list_node_t *list_shuffle(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }

    int list_size = 0;
    while (current_head)
    {
        current_head = current_head->next;
        list_size++;
    }

    list_node_t **items = malloc(sizeof(list_node_t *) * list_size);
    for (size_t i = 0; i < list_size; i++)
    {
        items[i] = list_get_tail(head);
        list_remove(head, items[i]);
    }

    int random_num;
    int found;
    int *randomlist = malloc(sizeof(int) * (list_size - 1));
    for (int i = 0; i < list_size; i++)
    {
        do
        {
            srand(time(NULL));
            random_num = rand() % list_size;
            found = 1;
            for (int j = 0; j < i; j++)
            {
                if (randomlist[j] == random_num)
                {
                    found = 0;
                }
            }
        } while (!found);
        randomlist[i] = random_num;
    }

    for (size_t i = 0; i < list_size; i++)
    {
        list_append(head, items[randomlist[i]]);
    }

    free(items);
    free(randomlist);
    return *head;
}