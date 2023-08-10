// File: dictionary.c
// Author: Brandon Morgan
// Description: A simple implementation of a dictionary object in C using singly linked lists.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Dict {
    struct DictItem *head;
    struct DictItem *tail;
    int length;
};


struct DictItem {
    char *key;
    char *value;
    struct DictItem *next;
};


struct Dict *Dict_new() {
    struct Dict *this_dict = malloc(sizeof(*this_dict));
    this_dict->head = NULL;
    this_dict->tail = NULL;
    this_dict->length = 0;
    return this_dict;
}


void Dict_put(struct Dict *this_dict, char *key, char *value) {
    char *this_key = (char *) malloc(sizeof(key)+1);
    char *this_value = (char *) malloc(sizeof(value)+1);
    strcpy(this_key, key);
    strcpy(this_value, value);
    
    printf("%s\n", this_key);
    printf("%s\n", this_value);
    
    
    struct DictItem *new = (struct DictItem *) malloc(sizeof(struct DictItem));
    new->key = this_key;
    new->value = this_value;
    new->next = NULL;
    
    //printf("%s\n", new->key);
    /*
    if (this_dict->tail != NULL) {
        this_dict->tail->next = new;
    }
        
    this_dict->tail=new;
    if (this_dict->head == NULL) {
        this_dict->head == new;
    }
    */
}


char *Dict_get(struct Dict *this_dict, char *this_key) {
    ;
}


void Dict_pop(struct Dict *this_dict, char *this_key) {
    ;
}

void Dict_print(struct Dict *this_dict) {
    ;
}


void Dict_delete(struct Dict *this_dict) {
    struct DictItem *current, *next;
    current = this_dict->head;
    while(current) {
        free(current->key);
        free(current->value);
        next = current->next;
        free(current);
        current = next;
    }
    free((void *) this_dict);
}


int main() {
    struct Dict *my_dict = Dict_new();
    
    Dict_put(my_dict, "a", "b");

    Dict_delete(my_dict);
    return 0;
}
