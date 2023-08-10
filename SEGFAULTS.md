### My First Segfault
File: doubleLinkedListFunctions.c

Reason: free() memory of struct inside for loop, except the top of the loop wastrying to access the just freed memory to check if the current ListNode was NULL. 

Fix: add break statement after free() to end the loop

Alternative: Use an integer index to loop instead of the actual linked list nodes. However, I like the current method better as it doesn't break when an index greater than the length of the list is input. The loop will only traverse the linked list and go no further. Also, all the intializations happen at the top of the loop and I don't need to place them manually inside the loop as well as add another conditional to make sure we don't traverse past the tail.


    void List_remove_byindex(struct List *this_list, int index) {
        int i = 0;

        // THE FOR LOOP CONDITION ACCESSES CURRENT_NODE
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
                free(current_node); //THE ISSUE
                break; // THE FIX
            }
            ++i;
        }
        this_list->length = this_list->length-1;
    }

### My Second Segfault