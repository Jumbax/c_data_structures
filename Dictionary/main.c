#include "dictionary.c"

int main()
{
    set_table_t *my_dict = dictionary_table_new(10);
    set_node_t *item = dictionary_insert(my_dict, "hi", "goodbye", 2);
    set_node_t *item2 = dictionary_insert(my_dict, "yes", "no", 3);
    set_node_t *item3 = dictionary_insert(my_dict, "good", "bad", 4);
    set_node_t *item4 = dictionary_insert(my_dict, "slow", "fast", 4);
    set_node_t *item5 = dictionary_insert(my_dict, "help", "kappa", 4);
    set_node_t *item6 = dictionary_insert(my_dict, "test", "megatest", 4);
    set_node_t *item7 = dictionary_insert(my_dict, "mike", "supermike", 4);
    set_node_t *item8 = dictionary_insert(my_dict, "book", "page", 4);
    set_node_t *item9 = dictionary_insert(my_dict, "home", "house", 4);
    set_node_t *item10 = dictionary_insert(my_dict, "cat", "dog", 3);
    int a = 10;
    int b = a*2;
    set_node_t *item11 = dictionary_insert(my_dict, &a, &b, 2);
    set_node_t *item_to_remove = dictionary_removal(my_dict, "good", 4);

    printf("%s\n", (char *)item->value);
    printf("%s\n", (char *)item2->value);
    printf("%s\n", (char *)item3->value);
    printf("%s\n", (char *)item4->value);
    printf("%s\n", (char *)item5->value);
    printf("%s\n", (char *)item6->value);
    printf("%s\n", (char *)item7->value);
    printf("%s\n", (char *)item8->value);
    printf("%s\n", (char *)item9->value);
    printf("%s\n", (char *)item10->value);
    printf("%d\n", *(int *)item11->value);
    printf("%s\n", (char *)item_to_remove->value);

    return 0;
}