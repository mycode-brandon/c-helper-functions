#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_BUCKETS 8


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
    //printf("Hash = %d\n", hash);
    //printf("Bucket = %d\n", bucket);
    // hash function
    // modulo
    
    return bucket;
}


void __HashMap_put(struct HashMap *this_hashmap, char *key, int value) {
    int bucket = __HashMap_hash(key);
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
}


/*
//Put
void __Dict_put(struct Dict *self, char *key, int value) {
    ;
}


//Get
int __Dict_get(struct Dict *self, char *key) {
    ;
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
    ;
}


//Destructor
void __Dict_delete(struct Dict *self) {
    ;
}


//Constructor
struct Dict *Dict_new(){
    ;
}
*/


int main()
{
    
    struct HashMap *my_hashmap = HashMap_new();
    my_hashmap->put(my_hashmap, "key1", 1);

    return 0;
}
