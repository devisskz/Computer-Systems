#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "list.h"

#include <stdbool.h>

int main() {

    // declare the given array
    int array[] = {89, 39, 18, 96, 71, 25, 2, 55, 60, -8, 9, 42, 69, 96, 24};

    //3.1

    // for loop to loop through array
    for (int counter = 0; counter <(sizeof(array)/4); counter++){
        // creates a node
        node *node = createNode(array[counter]);
        // adds that node to list
        addNode(node);
    }
    //helper function that prints the list
    printL();

    //3.2

    deleteLargest();
    printf("\n");
    printL();

    //3.3
    printf("\n%i\n", countNodes());

    //3.4
    bubbleSort();
    printL();

    return 0;
}
