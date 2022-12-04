#include "set.c"

int main()
{
    set_table_t *my_set = set_table_new(10);
    set_node_t *item = set_insert(my_set, "value", 5);
    set_node_t *item2 = set_insert(my_set, "valueasx", 8);
    set_node_t *item3 = set_insert(my_set, "testtest", 8);
    set_node_t *item_to_remove = set_table_remove(my_set, "value", 5);
    set_node_t *item_to_search = set_table_search(my_set, "valueasx", 8);
    
    printf("%s\n", item_to_remove->key);
    printf("%s\n", item_to_search->key);

    set_node_t** nodes = my_set->nodes;
    for (size_t i = 0; i < my_set->hashmap_size; i++)
    {
        set_node_t* head = nodes[i];
        while (head)
        {
            printf("%s\n", head->key);
            head = head->next;
        }
    }
}