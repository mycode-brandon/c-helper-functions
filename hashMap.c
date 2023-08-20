#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_BUCKETS 8

//comment
struct BucketNode {
    //Private Values
    struct BucketNode *__prev;
    struct BucketNode *__next;
    
    //Public Values
    char *key;
    int value;
};


struct HashMap {
    //Private Values
    int __buckets;
    struct BucketNode *__heads[MAX_BUCKETS];
    struct BucketNode *__tails[MAX_BUCKETS];
    
    //Private Methods
    void (*put)(struct HashMap *this_hashmap, char *key, int value);
    void (*dump)(struct HashMap *this_hashmap);
};




int __HashMap_hash(char *key) {
    //printf("key = %s\n", key);
    int bucket = 0;
    int hash = 0;
    
    //Hash function: add int value of char multiplied by 3
    for (char c = *key; c !='\0'; c = *++key) {
        hash += c*3;
        //printf("%c, %d \n", c, ((int) c)*3);
    }
    
    bucket = hash % MAX_BUCKETS;
    printf("Hash = %d\n", hash);
    printf("Bucket = %d\n", bucket);
    // hash function
    // modulo
    
    return bucket;
}


void __HashMap_put(struct HashMap *this_hashmap, char *key, int value) {
    //check if key exists
    printf("test\n");
    int key_exists = 0;
    for (int i = 0; i < MAX_BUCKETS; ++i) {
        for (struct BucketNode *current = this_hashmap->__heads[i]; current != NULL; current = current->__next) {
            if (strcmp(key, current->key) == 0) {
                key_exists = 1;
            }
        }
    }
    //create new bucket node if key doesn't already exist
    if (key_exists == 0) {
        int bucket = __HashMap_hash(key);
        char *this_key = malloc(sizeof(key));
        strcpy_s(this_key, sizeof(this_key), key);
        struct BucketNode *new_BucketNode = (struct BucketNode *) malloc(sizeof(*new_BucketNode));
        
        new_BucketNode->__prev = this_hashmap->__tails[bucket];
        new_BucketNode->__next = NULL;
        new_BucketNode->key = this_key;
        new_BucketNode->value = value;
        this_hashmap->__tails[bucket]->__next = new_BucketNode;
        this_hashmap->__tails[bucket] = new_BucketNode;
        
        //only first node in each bucket
        if (this_hashmap->__heads[bucket] == NULL) {
            this_hashmap->__heads[bucket] = new_BucketNode;
        }
    }
    
}


void __HashMap_dump(struct HashMap *this_hashmap) {
    printf("[");
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (struct BucketNode *current = this_hashmap->__heads[i]; current != NULL; current = current->__next) {
            printf("'%s' : %d, ", current->key, current->value);
        }
    }
    printf("]");
}


struct HashMap *HashMap_new() {
    struct HashMap *new_HashMap = (struct HashMap *) malloc(sizeof(*new_HashMap));
    
    // Assign NULL to heads and tails of each bucket
    new_HashMap->__buckets = MAX_BUCKETS;
    for (int i = 0; i < MAX_BUCKETS; ++i) {
        new_HashMap->__heads[i] = NULL;
        new_HashMap->__tails[i] = NULL;
    }
    
    //Assign internal Methods
    new_HashMap->put = &__HashMap_put;
    new_HashMap->dump = &__HashMap_dump;

    return new_HashMap;
}

int main()
{
    
    struct HashMap *my_hashmap = HashMap_new();
    my_hashmap->put(my_hashmap, "key1", 1);
    my_hashmap->put(my_hashmap, "key1", 2);
    my_hashmap->put(my_hashmap, "key2", 42);
    my_hashmap->put(my_hashmap, "key3", 54);

    my_hashmap->dump(my_hashmap);

    return 0;
}
