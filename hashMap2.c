#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_BUCKETS 8


struct BucketNode {
    //Private Values
    struct BucketNode *__prev;
    struct BucketNode *__next;
    char *__key;
    int __value;
};

struct HashMap {
    //Private Values
    int __buckets;
    struct BucketNode *__heads[MAX_BUCKETS];
    struct BucketNode *__tails[MAX_BUCKETS];
    
    //Public Methods
    void (*put)(struct HashMap *this_hashmap, char *key, int value);
    void (*dump)(struct HashMap *this_hashmap);
};

void __HashMap_put(struct HashMap *this, char *key, int value) {
    int key_exists = 0;

    if (key_exists == 0) {
        int bucket = 1;
        char *this_key = malloc(sizeof(key));
        strcpy(this_key, key);
        struct BucketNode *new_node = (struct BucketNode *) malloc(sizeof(*new_node));

        new_node->__key = this_key;
        new_node->__value = value;

        if (this->__heads[bucket] == NULL) {
            new_node->__prev = NULL;
            new_node->__next = NULL;
            this->__heads[bucket] = new_node;
            this->__tails[bucket] = new_node;
        } else {
            new_node->__prev = this->__tails[bucket];
            new_node->__next = NULL;
            this->__tails[bucket]->__next = new_node;
            this->__tails[bucket] = new_node;
        }
    }
}

void __HashMap_dump(struct HashMap *this) {
    printf("(BUCKETS=%d, [", MAX_BUCKETS);
    for (int i = 0; i < MAX_BUCKETS; ++i) {
        for (struct BucketNode *current = this->__heads[i]; current != NULL; current = current->__next) {
            if (current->__next != NULL) {
                printf("\"%s\" : %d, ", current->__key, current->__value);
            } else {
                printf("\"%s\" : %d", current->__key, current->__value);
            }
        }
    }
    printf("])\n");
}

struct HashMap *HashMap_new() {
    // Initialize new hashmap memory and heads and tails bucketnodes for each bucket
    struct HashMap *new = (struct HashMap *) malloc(sizeof(*new));
    new->__buckets = MAX_BUCKETS;
    for (int i = 0; i < MAX_BUCKETS; ++i) {
        new->__heads[i] = NULL;
        new->__tails[i] = NULL;
        printf("bucket: %d, &head: %p, &tail: %p\n", i, new->__heads[i], new->__tails[i]);
    }

    // Assign Internal Methods
    new->dump = &__HashMap_dump;
    new->put = &__HashMap_put;
    
    return new;
}

int main() {
    struct HashMap *my_hashmap = HashMap_new();

    my_hashmap->dump(my_hashmap);
    my_hashmap->put(my_hashmap, "key1", 1);
    my_hashmap->put(my_hashmap, "key2", 2);
    my_hashmap->put(my_hashmap, "key3", 3);
    my_hashmap->dump(my_hashmap);

    return 0;
}
