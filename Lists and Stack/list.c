//
// Created by Batyr Issabekov on 3/17/21.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"


typedef struct node {
    int value;
    node *next;
} node;

node* HEAD = NULL; // the list
node *walker = NULL; //walker
node *temp = NULL; //upstream



bool  addNode(node* node){
    if (HEAD == NULL) { // if the head is null
        HEAD = node; //create a new node that is going to be our list
        return true;
    }
    //otherwise
    else{
        walker = HEAD; //start from beginning
        while(walker->next!=NULL){ //while we don't reach end
            walker = walker->next; //walker keeps walking
        }
        walker->next = node; //put the node
        walker = NULL; //set walker to null
        return true;
    }
}

// helper function to print list

void printL(){
    walker = HEAD; //sets walker to head
    while(walker != NULL) { //while walker is not null
        printf("%i ", walker->value); //print every value of walker
        walker = walker->next; //walker keeps walking
    }
    walker = NULL; //set walker to null, for future use
}

node* findNode(int value){
    temp = HEAD; //set temp to HEAD
    walker = HEAD; //set walker to head

    while (walker!=NULL){
        if (walker->value > value){ // if current value of walker is more than input value
            value = walker->value; // set value to the value of walker
        }
        walker = walker->next; //traverse the list
    }
    walker = NULL;// set walker to null, we are done with it
    while(temp !=NULL) { //traverse the list again
        if(temp->value == value){ //if the node with the value is found
            return temp; //return the node
        }
        temp=temp->next; // traverse the list
    }
    temp = NULL; //set temp to null, we are done with it
}

void deleteLargest(void){
    temp = findNode(HEAD->value); // set the found node to temp
    int max = temp->value; // make a holder for the value

    deleteNode(temp); // calls delete node to delete first found number in list

    walker = HEAD; // set walker to head
    int sameNumberCounter = 0; // set counter to 0

    while(walker!=NULL) { // traverse through list
        if (max == walker->value){ // if another node with the number is found
            sameNumberCounter++; // increments counter
        }
        walker=walker->next; // traverses through list
    }
    while (sameNumberCounter>0){ // while loop that calls deleteLargest enough times to delete all nodes
        deleteLargest();
        sameNumberCounter--;
    }
}

bool  deleteNode (node* node) {
    if (HEAD == NULL) { // in case of an empty list, returns false
        return false;
    }

    else {
        walker = HEAD; //set walker to head
        temp = HEAD;// set temp to head, (upstream)
        if (walker->value == node->value){ //if the very first node is the number we are looking for
            HEAD = HEAD->next; // sets head to the next node
            node->next = NULL; //sets the current node to null
            free(node); //frees the node and memory
        }


        walker = HEAD->next; // sets walker to second node in list
        while (walker != NULL){ // traverses through list
            if (node->value == walker->value) { // if the number is found
                temp->next = walker->next; // sets temp (upstream) to the next pointer of walker
                node->next = NULL; //sets the node next pointer to null
                free(node); //frees the node #freeNode
            }
            walker = walker->next; // traverses through list, walker is one node ahead
            temp = temp->next; // traverses through list
        }
    }
    temp = NULL; // set pointers to null, we are done with them
    walker = NULL;
    return true; //returns true in case of success
}

int countNodes(){
    walker = HEAD; //initialize, set walker and counter
    int counter = 0;
    while (walker!=NULL){ // traverse the list
        counter++; // counter increments
        walker = walker->next; //walker traverses the list
    }
    walker = NULL;
    return counter; //returns the number of nodes
}

void swap()

void bubbleSort() {
    // declare a head pointer
    node* head = HEAD;
    // enter a while true loop
    while (true) {
        bool changes = false; // set swap as false initially

        // declare pointers
        node *prev1 = NULL;
        node *prev2 = head;
        //pointing at first and second node
        node *walker1 = head;
        node *walker2 = walker1->next;

        //while second walker is not at the end of the list
        while (walker2 != NULL) {
            // if value of first node is more than second node
            if (walker1->value > walker2->value) {
                // swapping..

                //set boolean swap to true
                changes = true;
                // temp points to next
                temp = walker2->next;
                // if the pointer is null, we are at the start, so
                if (prev1 == NULL) {
                    // point head to second node
                    head = walker2;
                }
                // otherwise, previous node points at second node of the list
                else {
                    prev1->next = walker2;
                }
                // swapping nodes
                prev2->next = walker1;
                walker2->next = walker1->next;
                walker1->next = temp;

                // change nodes with each other, as we have changed them around
                walker2 = walker1;
                walker1 = walker2;
            }
            // assign pointers
            prev1 = walker1;
            walker1 = walker1->next;
            prev2 = walker2;
            walker2 = walker2->next;
        }
        // when we reach here, if changes is false
        // that means we did not change anything
        if (!changes) {
            //break out of the loop
            break;
        }
    }
    //set main HEAD to head node
        HEAD = head;
}