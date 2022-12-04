#include "linkedlist.c"
#include "set.h"

#define to_set_node(x) (set_node_t *)(x)

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new(const size_t hashmap_size)
{
    set_table_t *table = malloc(sizeof(set_table_t));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t *));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

set_node_t *set_table_search(set_table_t *table, const char *key, const size_t key_len)
{
    set_table_t *current_table = table;
    if (!table)
    {
        return NULL;
    }

    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % current_table->hashmap_size;
    set_node_t *item = current_table->nodes[index];

    if (!item)
    {
        return NULL;
    }

    set_node_t *tail = NULL;
    while (item)
    {
        tail = item;
        item = item->next;
        if (tail->key == key)
        {
            return tail;
        }
    }
    return NULL;
}

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    if (set_table_search(table, key, key_len))
    {
        return NULL;
    }

    set_node_t *new_item = malloc(sizeof(set_node_t));
    if (!new_item)
    {
        return NULL;
    }

    new_item->key = key;
    new_item->key_len = key_len;

    return to_set_node(list_append(to_list(&table->nodes[index]), to_list_node(new_item)));
}

set_node_t *set_table_remove(set_table_t *table, const char *key, const size_t key_len)
{
    set_table_t *current_table = table;
    if (!table)
    {
        return NULL;
    }

    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % current_table->hashmap_size;

    set_node_t *item_to_remove = set_table_search(table, key, key_len);
    if (!item_to_remove)
    {
        return NULL;
    }

    return to_set_node(list_remove(to_list(&table->nodes[index]), to_list_node(item_to_remove)));
}

