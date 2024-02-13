#include <iostream>
#include "linked_list.h"


using namespace std;

struct node * create_linked_list(int n) {
    if (n == 0) {
        return NULL;
    } else {
        struct node * root = new node;
        root->data = -1;
        struct node * linked_list = root;

        for (int i = 0 ; i < n; i++) {

            if (i < n-1){
            linked_list->next = new node;
            linked_list->data = i+1;
            linked_list = linked_list->next;
            }
            //Final node points to itself
            else{
            linked_list->next = linked_list;
            linked_list->data = i+1;
            }

        }


        return root;
    }
}

void pointerJumping(node * head) {
    node* curr = head;
    node* end;
    node* next;
    //Travel through linked list until we get the final node, which points to itself
    while (curr->next != curr) {
        curr = curr->next;
    }
    //Back to the start and point every LL to the last node
    end = curr;
    curr = head;
    while (curr->next != curr) {
        next = curr->next;
        curr->next = end;
        curr = next;
    }

}

int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node * linked_list = start;

        for (int i = 0; i < node_number -1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node * start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements
	Returns true otherwise
*/
bool update_data_in_linked_list(struct node * start, 
    int node_to_update, 
    int update_val, 
    int total_elements) {

        return true;

    }