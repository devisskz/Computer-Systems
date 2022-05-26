//
// Created by Batyr Issabekov on 4/5/21.
//

#include <stdbool.h>
#include "stack.h"

// pushes the node into the stack
push(node* node) {
    // first case, if stack is empty
    if (STACK == NULL){
        STACK = node;
    }
    // node points to the head node
    else{
        node->next = STACK;
        // then head points to the current node
        STACK = node;
    }
}
// function that prints the stack
printS(){
    if (STACK == NULL){
        printf("\nThe stack is empty");
    }
    // goes through and prints the values of the nodes
    node* walker = STACK;
    while (walker !=NULL){
        if (walker->type == NUMBER) {
            printf("\n%f", walker->contents.value);
        }
        else{
            printf("\n%c", walker->contents.operator);
        }

        walker = walker->next;
    }
}
// pop
node* pop(){
    if (STACK == NULL){
        printf(errorMessage[EMPTYSTACK]);
    }
    node* walker = STACK;
    // set top to next
    STACK = STACK->next;
    // and original top to null
    walker->next = NULL;

    return walker;
}
// clears the stack
clearStack(){
    // if null, prints the stack is already empty
    if (STACK == NULL){
        //printf("\nThe stack is already empty");
    }
        // otherwise, goes through every node and frees it, sets top to null
    else{
        node* walker = STACK;
        node* temp = walker->next;
        while (walker!=NULL){
            free(pop());
            walker = walker->next;
        }
        STACK = NULL;
    }
}
// returns the first node
node* peek(){
    return STACK;
}
// checks if the top is null or not
bool stackEmpty(){
    if (STACK == NULL){
        printf("\nstack is empty");
        return true;
    }
    else{
        printf("\nstack is not empty");
        return false;
    }
}
