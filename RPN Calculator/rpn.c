//
// Created by Batyr Issabekov on 4/5/21.
//

#include "rpn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//#include "stack.c"
#include <string.h>
#include <ctype.h>

#define MAXBUFF 100


// Dijkstra's Shunting-Yard Algorithm (from Wikipedia)

// initialize the output array
char* outputArray[MAXBUFF];

char* SY_Algorithm(char* expression){


    // Checking if string is empty
    if (expression == "\0" || expression == NULL){
        printf(errorMessage[EMPTYSTRING]);
    }

    int length = strlen(expression);

    // Checking if the input is valid

    for (int i=0;i<length; i++) {
        if (!isdigit(expression[i])) {
            if (expression[i]=='-')
                continue;
            if (expression[i]==' ')
                continue;
            if(expression[i]=='(')
                continue;
            if(expression[i]=='+')
                continue;
            if(expression[i]=='/')
                continue;
            if(expression[i]==')')
                continue;
            if(expression[i]=='*')
                continue;
            if(expression[i]=='^')
                continue;
            if(expression[i]=='\n') {
                //strcat(outputArray, " ");
                continue;
            }
            else
                // we are here if there is an operator error
                printf(errorMessage[OPERATORERROR]);
                exit(1);
        }
        else
            continue;
    }


    char* token = strtok(expression," ");


    // scan the string
    while (token){
        // declare a precedence and node pointers
        int precedence;
        node* node_operator;

        // if token is an operator
        if (strstr(token,"+") || (strstr(token,"-")) || strstr(token,"*")
        || (strstr(token,"/")) || strstr(token,"^")) {
            // set precedence accordingly
            if((strstr(token,"+")) ||(strstr(token,"-"))) {
                precedence = 2;
                node_operator = createNode(0, OPERATOR, token[0], precedence);
            }
            else if((strstr(token,"*")) ||(strstr(token,"/"))) {
                precedence = 3;
                node_operator = createNode(0, OPERATOR, token[0], precedence);
            }
            else if(strstr(token,"^")){
                precedence = 4;
                node_operator = createNode(0,OPERATOR,token[0],precedence);
            }
            // while there is an operator on the stack, check for precedence and add to output accordingly
            while (peek() && ((peek()->precedence > node_operator->precedence) || (peek()->precedence == node_operator->precedence)) && (peek()->contents.operator !='(')) {
                strcat(outputArray, &pop()->contents.operator);
            }
            // push the operator into the stack
            push(node_operator);

        }
        // case if the token is a left bracket
        else if (strstr(token,"(")){
            precedence=0;
            node_operator = createNode(0, OPERATOR, token[0], precedence);
            push(node_operator);
        }
        // case if the token is a right bracket
        else if (strstr(token,")")){
            while((peek()->contents.operator)!='('){
                strcat(outputArray, &pop()->contents.operator);
                // if it is the last node and it is not a left bracket
                if((peek()->next == NULL) && (peek()->contents.operator!='(')){
                    printf(errorMessage[OPERATORERROR]);
                    exit(1);
                }
            }
            // if the operator at the top is a left bracket
            if (peek()->contents.operator == '('){
                // discard the operator
                free(pop());
            }
        }

        // otherwise, it is a number, we add it to output array
        else{
            // add spaces between for future conversion from char to double
            strcat(outputArray, " ");
            //sprintf(outputArray, "%f ", token);
            strcat(outputArray, token);
            strcat(outputArray, " ");
        }

        token = strtok(NULL, " ");

    }
    while (STACK != NULL){
        strcat(outputArray, " ");
        strcat(outputArray, &pop()->contents.operator);

    }
    //char* s = outputArray;
    //printf("\n %s \n ", outputArray);
    //printf(outputArray);
//    int length_o = strlen(outputArray);
//    for (int i=0;i<length; i++) {
//        if (outputArray[i]=='\n')
//            outputArray[i]=' ';
//            continue;
//    }
    return outputArray;
}
// helper function to get rid of new line operators on input

void removeNewLine(char *temp) {
    // while character array is not null and character is not a new line operator
    while((temp != NULL) && (*temp != '\n')) {
        // go through the array
        temp++;
    }
    // we are here if \n was found
    *temp = '\0';
}



//initially status is 0
int *status = 0;

//evaluate function
double evaluate (char* expression, int* status){
    // clears stack on a new call
    clearStack();
    // checks if the expression array is empty
    if (expression == ""){
        printf(errorMessage[EMPTYSTRING]);
        exit(1);
    }
    if(expression == '\0'){
        printf(errorMessage[OPERATORERROR]);
        return 0;
    }

    // declare a token with intial strtok input
    char* token = strtok(expression," ");

    // parse

    while (token){

        // cases for +, -, *, ^, /
        // every node is freed after call
        if (strstr(token,"+")){
            // if stack is empty, it is an error
            if (STACK == NULL){
                printf("\n%s",errorMessage[OPERATORERROR]);
                break;
            }

            node*right = pop();
            node*left = pop();

            push(add(left,right));


            free(left);
            free(right);

        }
        // same implementation for +,_,/,*
        if (strstr(token,"-")){
            if (STACK == NULL){
                printf(errorMessage[EMPTYSTACK]);
                return 0;
            }

            node* right = pop();
            node* left = pop();
            subtract(left,right);
            free(left);
            free(right);


        }
        if (strstr(token,"*")){
            if (STACK == NULL){
                printf(errorMessage[EMPTYSTACK]);
                return 0;
            }
            node*right = pop();
            node*left = pop();
            multiply(left, right);
            free(left);
            free(right);


        }
        if (strstr(token,"/")){
            if (STACK == NULL){
                printf(errorMessage[EMPTYSTACK]);
                return 0;
            }
            node*right = pop();
            node*left = pop();
            divide(left, right);
            free(left);
            free(right);


        }
        if (strstr(token,"^")){
            if (STACK == NULL){
                printf(errorMessage[EMPTYSTACK]);
                return 0;
            }
            node*right = pop();
            node*left = pop();
            power(left, right);
            free(left);
            free(right);

        }


        char *p;


        // strtod source: tutorialspoint, converting str to int

        if (!strstr(token,"+") && !strstr(token,"-") && !strstr(token,"*") && !strstr(token,"/") && !strstr(token,"^")) {
            push(createNode(strtod(token, &p), NUMBER, '\0', -1));
        }





        token = strtok(NULL, " ");

    }

    return peek()->contents.value;
}

// add, multiply, divide functions (based on ps1)
node* add(node*left, node*right){

    double result = left->contents.value+right->contents.value;

    node* return_node = createNode(result, NUMBER,'\0',-1);

    return return_node;
}
node* multiply(node*left, node*right){
    double result = (left->contents.value) * (right->contents.value);
    push(createNode(result, NUMBER,'\0',-1));
    return STACK;
}
node* divide(node*left,node* right){
    double result = left->contents.value/right->contents.value;
    push(createNode(result, NUMBER,'\0',-1));
    return STACK;
}
node* subtract(node*left,node*right){
    double result = left->contents.value - right->contents.value;
    push(createNode(result, NUMBER,'\0',-1));
    return STACK;
}
node* power(node*left, node*right){
    double result=1;
    for(int counter=0; counter<right->contents.value; counter++) {
        result*=left->contents.value;
    }
    push(createNode(result, NUMBER,'\0',-1));
    return STACK;
}
