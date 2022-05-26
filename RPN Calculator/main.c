#include <stdio.h>
#include "node.c"
#include "rpn.c"
#include "stack.c"

int main(int argc, char *argv[]) {


    char* dataLine[MAXBUFF]; //to store input strings


    FILE *input = fopen(argv[1], "r"); //must exist

    if (!input) {
        perror("I/O error: ");
        return -1;
    }

    FILE *data = fopen(argv[2], "w+");
    perror("Error: ");

    while (fgets(dataLine, MAXBUFF, input)) {
        // tried different things with memset, but had no luck

        //memset(str,'\0',MAXBUFF);
        //memset(dataLine,'\0',MAXBUFF);

        // call to function to remove new lines
        removeNewLine(dataLine);

        fprintf(data,"Infix: %s \n", dataLine);

        //printf("%s %s\n", argv[1], argv[2]);
        char* str = SY_Algorithm(dataLine);

        fprintf(data,"Postfix: %s \n", str);


        fprintf(data, "Result: %f \n", evaluate(str, status));
        memset(str,'\000',MAXBUFF);
        memset(dataLine,'\000',MAXBUFF);

    }

    fclose(input);
    short fstatus = fclose(data);



    return 0;

}
