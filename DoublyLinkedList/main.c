#include "doublylinkedlist.c"

int main()
{
    string_item_t *my_doubly_linked_list = NULL;
    string_item_t *hello_world = string_item_new("Hello World");
    string_item_t *test001 = string_item_new("Test001");
    string_item_t *test002 = string_item_new("Test002");
    string_item_t *last_item = string_item_new("Last Item of the Doubly Linked List");
    list_append(to_list(&my_doubly_linked_list), to_list_node(hello_world));
    list_append(to_list(&my_doubly_linked_list), to_list_node(test001));
    list_append(to_list(&my_doubly_linked_list), to_list_node(test002));
    list_append(to_list(&my_doubly_linked_list), to_list_node(last_item));

    list_remove(to_list(&my_doubly_linked_list), to_list_node(last_item));
    my_doubly_linked_list = to_string_item(list_shuffle(to_list(&my_doubly_linked_list)));

    while (my_doubly_linked_list)
    {
        printf("%s\n", my_doubly_linked_list->string);
        my_doubly_linked_list = to_string_item(my_doubly_linked_list->node.next);
    }
    
    return 0;
}