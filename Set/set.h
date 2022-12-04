typedef struct set_node
{
    struct set_node *next;
    size_t key_len;
    const char *key;
} set_node_t;

typedef struct set_table
{
    struct set_node **nodes;
    size_t hashmap_size;
} set_table_t;

size_t djb33x_hash(const char *key, const size_t keylen);

set_table_t *set_table_new(const size_t hashmap_size);

set_node_t *set_table_search(set_table_t *table, const char *key, const size_t key_len);

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);

set_node_t *set_table_remove(set_table_t *table, const char *key, const size_t key_len);
