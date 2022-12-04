typedef struct set_node
{
    struct set_node *next;
    size_t key_len;
    const void *key;
    const void *value;
} set_node_t;

typedef struct set_table
{
    struct set_node **nodes;
    size_t hashmap_size;
    size_t num_collision;
} set_table_t;

size_t djb33x_hash(const char *key, const size_t keylen);

set_table_t *dictionary_table_new(const size_t hashmap_size);

set_table_t * increase_hashmap_size(set_table_t *table);

set_node_t *dictionary_search(set_table_t *table, const void *key, const size_t key_len);

set_node_t *dictionary_insert(set_table_t *table, const void *key, const void *value, const size_t key_len);

set_node_t *dictionary_removal(set_table_t *table, const void *key, const size_t key_len);

