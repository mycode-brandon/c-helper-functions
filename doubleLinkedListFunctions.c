// File: doubleLinkedListFunctions.c
// Author: Brandon Morgan
// Description: A simple implementation of a doubly linked list with OOP like methods

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char *text;
    struct ListNode *next;
    struct ListNode *prev;
};
    
struct List {
    struct ListNode *head;
    struct ListNode *tail;
    int length;
    
};

struct List *List_new() {
    struct List *this_list = malloc(sizeof(this_list));
    this_list->head = NULL;
    this_list->tail = NULL;
    this_list->length = 0;
    return this_list;
}

void List_delete(struct List *this_list) {
    struct ListNode *current, *next;
    current = this_list->head;
    while(current) {
        free(current->text);
        next = current->next;
        free(current);
        current = next;
    }
    free((void *)this_list);
}

void List_append(struct List *this_list, char *text) {
    char *line = (char *) malloc(strlen(text)+1);
    strcpy(line, text);
    struct ListNode *new = (struct ListNode *) malloc(sizeof(struct ListNode));
    
    new->prev = this_list->tail;
    
    if (this_list->tail != NULL) {
        this_list->tail->next = new;}
    
    new->text = line;
    new->next = NULL;
    this_list->tail=new;
    
    if (this_list->head == NULL) {
        this_list->head=new;}
        
    this_list->length+=1;
}

void List_remove_byindex(struct List *this_list, int index) {
    int i = 0;
    for (struct ListNode *current_node = this_list->head; current_node != NULL; current_node = current_node->next) {
        if (i == index) {
            struct ListNode *prev = current_node->prev;
            struct ListNode *next = current_node->next;

            if (current_node == this_list->tail) {
                this_list->tail = prev;
                prev->next = NULL;
            }
            else if (current_node == this_list->head) {
                this_list->head = next;
                next->prev = NULL;
            }
            else {
                prev->next = next;
                next->prev = prev;
            }

            free(current_node->text);
            free(current_node);
            break;
        }
        ++i;
    }
    this_list->length = this_list->length-1;
}

void List_print(struct List *this_list) {
    // printf("\n");
    for (struct ListNode *current = this_list->head; current != NULL; current = current->next) {
        printf("%s\n", current->text);
    }
}

int main() {
    
    struct List *my_list = List_new();
    
    char multi_line_string[5][100] = {
        "Hello!",
        "This is a test!",
        "This is the third line.",
        "This is the fourth line.",
        "This is the fifth and final line!"};
    
    List_append(my_list, multi_line_string[0]);
    printf("Added one node...\n");
    List_print(my_list);
    
    List_append(my_list, multi_line_string[1]);
    printf("Added another...\n");
    List_print(my_list);
    
    printf("\nAdded a whole bunch...\n");
    for (int i = 2; i < 5; ++i) {
        List_append(my_list, multi_line_string[i]);
    }
    
    List_print(my_list);
    printf("length of list: %d", my_list->length);
    printf("\n");
    
    printf("\nremoving an element from the list...\n");
    List_remove_byindex(my_list, 4);
    List_print(my_list);
    printf("length of list: %d\n", my_list->length);
    
    printf("\nRemoving the list... \n");
    List_delete(my_list);
    printf("Done!\n");
    
    return 0;
}
