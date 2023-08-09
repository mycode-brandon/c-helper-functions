// File: doubleLinkedListFunctions.c
// Author: Brandon Morgan
// Description: A simple implementation of a doubly linked list with functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char *text;
    struct ListNode *next;
    struct ListNode *prev;};
    
struct List {
    struct ListNode *head;
    struct ListNode *tail;};

void append_ListNode(struct List *this_list, char *text) {
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
}

void remove_ListNode(struct ListNode *this_node, struct List *this_list) {
    ;
}

void print_List(struct List *this_list) {
    for (struct ListNode *current = this_list->head; current != NULL; current = current->next) {
        printf("%s\n", current->text);
    }
}

int main() {
    
    struct List my_list;
    my_list.head = NULL;
    my_list.tail = NULL;
    
    char multi_line_string[5][100] = {
        "Hello!",
        "This is a test!",
        "This is the third line.",
        "This is the fourth line.",
        "This is the fifth and final line!"};
    
    append_ListNode(&my_list, multi_line_string[0]);
    printf("Added one node...\n");
    print_List(&my_list);
    
    append_ListNode(&my_list, multi_line_string[1]);
    printf("Added another...\n");
    print_List(&my_list);
    
    printf("\nAdded a whole bunch...\n");
    for (int i = 2; i < 5; ++i) {
        append_ListNode(&my_list, multi_line_string[i]);
    }
    print_List(&my_list);
    
    return 0;
}
