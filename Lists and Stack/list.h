//
// Created by Batyr Issabekov on 3/17/21.
//

#ifndef PS3_LIST_H
#define PS3_LIST_H

#include "node.h"
#include <stdbool.h>


bool  addNode(node* node);
node* findNode(int value);
bool  deleteNode (node* node);
void deleteLargest(void);
void printL();
int countNodes();
void bubbleSort();

#endif //PS3_LIST_H
