// File: dictionary.c
// Author: Brandon Morgan
// Description: A simple implementation of a dictionary object in C using singly linked lists.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DictNode {
    char *key;
    char *value;
    struct DictNode *next;
};

struct Dict {
    struct DictNode *head;
    struct DictNode *tail;
    int length;
};

struct Dict *Dict_new() {
    struct Dict *this_dict = (struct Dict *) malloc(sizeof(*this_dict));
    this_dict->head = NULL;
    this_dict->tail = NULL;
    this_dict->length = 0;
}

int main() {
    
    struct Dict *my_dict = Dict_new();
    
    struct DictNode *new_node = (struct DictNode *) malloc(sizeof(*new_node));

    char keys[5][100] = {
        "key1",
        "key2",
        "key3",
        "key4",
        "key5"
    };
    
    char values[5][100] = {
        "val1",
        "val2",
        "val3",
        "val4",
        "val5"
    };
    
    new_node->key = keys[0];
    new_node->value = values[0];
    
    my_dict->head = new_node;
    my_dict->tail = new_node;
    
    struct DictNode *new_node2 = (struct DictNode *) malloc(sizeof(*new_node));
    new_node2->key = keys[1];
    new_node2->value = values[1];
    my_dict->tail->next = new_node2;
    my_dict->tail = new_node2;
    
    printf("my_dict->head = %p\n", my_dict->head);
    printf("my_dict->tail = %p\n", my_dict->tail);
    for (struct DictNode *current = my_dict->head; current != NULL; current = current->next) {
        printf("%s\n", current->key);
        printf("%s\n", current->value);
        printf("%p\n", current);
    }
    
    return 0;
}
