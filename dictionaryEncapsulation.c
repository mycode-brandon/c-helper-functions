// File: dictionaryEncapsulation.c
// Author: Brandon Morgan
// Description: A dictionary class implementation using a doubly linked list, function pointers as methods, and naming conventions to make things "private". Explores encapsulation methodology in a non OOP language.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DictNode {
    //Private Values
    struct DictNode *__prev;
    struct DictNode *__next;
    
    //Public Values
    char *key;
    int value;
};


struct Dict {
    //Private Values
    struct DictNode *__head;
    struct DictNode *__tail;
    int __length;
    
    //Public Methods
    void (*put)(struct Dict *self, char *key, int value);
    int  (*get)(struct Dict *self, char *key);
    void (*pop)(struct Dict *self, char *key);
    int  (*length)(struct Dict *self);
    void (*dump)(struct Dict *self);
    void (*delete)(struct Dict *self);
};


//Put
void __Dict_put(struct Dict *self, char *key, int value) {
    
    char *this_key   = (char *) malloc(sizeof(key)+1);
    int  this_value = value;
    
    strcpy(this_key, key);
    
    
    int key_exists = 0;
    for (struct DictNode *test = self->__head; test != NULL; test = test->__next) {
        char *test_key = (char *) malloc(sizeof(test->key)+1);
        strcpy(test_key, test->key);
        if (strcmp(test_key, this_key) == 0) {
            test->value = this_value;
            key_exists = 1;
            free(test_key);
            break;
        }
    }
    
    if (key_exists == 0) {
        struct DictNode *new_node = (struct DictNode *) malloc(sizeof(*new_node));
        
        new_node->key    = this_key;
        new_node->value  = this_value;
        new_node->__prev = self->__tail;
        new_node->__next = NULL;
        
        if (self->__tail != NULL) {
            self->__tail->__next = new_node;
        }
        self->__tail = new_node;
        
        //Only first function call for each Dict
        if (self->__head == NULL) {
            self->__head = new_node;
        }
    
        //Increase Length
        self->__length += 1;
    }
}


//Get
int __Dict_get(struct Dict *self, char *key) {
    char *this_key = (char *) malloc(sizeof(key)+1);
    strcpy(this_key, key);
    
    int key_exists = 0;
    int value;
    for (struct DictNode *current = self->__head; current != NULL; current = current->__next) {
        char *test_key = (char *) malloc(sizeof(current->key)+1);
        strcpy(test_key, current->key);
        if (strcmp(test_key, this_key) == 0) {
            key_exists = 1;
            value = current->value;
            free(test_key);
            break;
        }
    }
    if (key_exists == 0) {
        return 0;
    } else {
        return value;
    }
}


//Pop
int __Dict_pop(struct Dict *self, char *key) {
    ;
}


//Length
int __Dict_length(struct Dict *self) {
    return self->__length;
}


//Dump
void __Dict_dump(struct Dict *self) {
    struct DictNode *current;
    printf("Dictionary(length=%d, [", self->__length);
    for (current = self->__head; current != NULL; current = current->__next) {
        if (current->__next != NULL) {
            printf("%s=%d, ", current->key, current->value);
        } else {
            printf("%s=%d", current->key, current->value);
        }
    }
    printf("])\n");
}


//Destructor
void __Dict_delete(struct Dict *self) {
    struct DictNode *current;
    struct DictNode *next;
    current = self->__head;
    //free each node
    while(current) {
        free(current->key); //value isn't allocated so only key needs free()
        next = current->__next;
        free(current);
        current = next;
    }
    free(self); //free the Dict struct
    printf("Dictionary has been deleted.\n");
}


//Constructor
struct Dict *Dict_new(){
    struct Dict *new_Dict = malloc(sizeof(*new_Dict));
    
    new_Dict->__head  = NULL;
    new_Dict->__tail  = NULL;
    new_Dict->__length = 0;
    
    new_Dict->put    = &__Dict_put;
    new_Dict->get    = &__Dict_get;
    new_Dict->length = &__Dict_length;
    new_Dict->dump   = &__Dict_dump;
    new_Dict->delete = &__Dict_delete;
    
    printf("Dictionary has been created.\n");
    return new_Dict;
}


int main()
{
    struct Dict *my_dict = Dict_new();
    
    my_dict->put(my_dict, "key1", 42);
    my_dict->dump(my_dict);
    my_dict->put(my_dict, "key1", 43);
    my_dict->dump(my_dict);
    my_dict->put(my_dict, "key2", 44);
    my_dict->dump(my_dict);
    my_dict->put(my_dict, "key3", 45);
    my_dict->dump(my_dict);
    
    printf("get my_dict['key6'] = %d\n",my_dict->get(my_dict, "key6"));
    printf("get my_dict['key1'] = %d\n",my_dict->get(my_dict, "key1"));
    printf("get my_dict['key2'] = %d\n",my_dict->get(my_dict, "key2"));
    printf("get my_dict['key3'] = %d\n",my_dict->get(my_dict, "key3"));
    

    printf("Length=%d\n", my_dict->length(my_dict));
    
    my_dict->delete(my_dict);

    return 0;
}
