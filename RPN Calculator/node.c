//
// Created by Batyr Issabekov on 4/5/21.
//

#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
enum datatype{NUMBER, OPERATOR};

typedef struct node {
    union{
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node *next;
} node;

// reworked createNode to fit for our new node
node* createNode(double value, int type, char operator, int precedence) {
    node* newNode = (struct node*) malloc(sizeof(node)); //cast the node
    if (newNode == NULL) {
        printf(errorMessage[NOMEMORY]);
        return NULL;
    }
    if (operator=='\0') { // if the operator is empty on the input
        newNode->contents.value = value; //set value to input value
    }
    else{ // otherwise, set the operator value to the node
        newNode->contents.operator = operator;
    }
    //newNode->contents.operator=operator;
    //newNode->contents.value=value;
    newNode->type = type; //set type to input type
    newNode->precedence=precedence; // set precedence
    newNode->next = NULL; // set next pointer to null
    return newNode; //return the new node
}
