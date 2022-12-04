typedef struct list_node
{
    struct list_node *prev;
    struct list_node *next;
} list_node_t;

typedef struct string_item
{
    list_node_t node;
    const char *string;
} string_item_t;

list_node_t *list_get_tail(list_node_t **head);

list_node_t *list_append(list_node_t **head, list_node_t *item);

list_node_t *list_pop(list_node_t **head);

string_item_t *string_item_new(const char *string);

list_node_t *list_remove(list_node_t **head, list_node_t *item);

list_node_t *list_insert_after(list_node_t **head, list_node_t *item_to_add, list_node_t *after);

list_node_t *list_insert_before(list_node_t **head, list_node_t *item_to_add, list_node_t *before);

list_node_t *list_shuffle(list_node_t **head);