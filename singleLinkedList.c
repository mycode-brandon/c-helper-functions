// File: singleLinkedList.c
// Author: Brandon Morgan
// Description: A simple implementation of a linked list 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct list_node {
        char *text;
        struct list_node *next;
    };
    
    struct list_node *tail = NULL;
    struct list_node *head = NULL;
    struct list_node *current = NULL;
    
    char multi_line_string[5][100] = {
        "Hello!",
        "This is a test!",
        "This is the third line.",
        "This is the fourth line.",
        "This is the fifth and final line!"
    };
    
    printf("Creating the linked list...\n");
    for (int i = 0; i < 5; ++i) {
        char *line = (char *) malloc(strlen(multi_line_string[i]+1));
        strcpy(line, multi_line_string[i]);
        
        struct list_node *new = (struct list_node *) malloc(sizeof(struct list_node));

        if (NULL != tail ) {
            tail->next = new;
        }
        
        new->text = line;
        new->next = NULL;
        tail=new;
        
        if (head == NULL) {
            head=new;
        }
        
        printf("current list_node.text (new.text) = %s\n", new->text);
    }
    
    printf("\ntail list_node.text = %s\n", tail->text);
    printf("tail list_node.next = %p\n", tail->next);
        
    printf("head list_node.text = %s\n", head->text);
    printf("head list_node.next = %p\n\n", head->next);
    
    printf("Looping through the linked list...\n");
    for (current = head; current != NULL; current = current->next) {
        printf("Current node: %s\n", current->text);
        printf("\tNext node location: %p\n", current->next);
    }

    return 0;
}
