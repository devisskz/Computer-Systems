//
// Created by Batyr Issabekov on 4/5/21.
//

#ifndef TEST_RPN_H
#define TEST_RPN_H
double evaluate (char* expression, int* status);
node* add(node* left, node* right);
node* subtract(node*left, node* right);
node* multiply(node* left, node* right);
node* divide(node* left, node*right);
node* power(node* left, node*right);
char* SY_Algorithm(char* expression);
void removeNewLine(char *ptr);
#endif //TEST_RPN_H
