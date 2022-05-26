//
// Created by Batyr Issabekov on 4/5/21.
//

#ifndef TEST_ERRORS_H
#define TEST_ERRORS_H
// error messages array
enum dataerror{NOMEMORY, EMPTYSTACK, TOOMANYNUMS, OPERATORERROR, EMPTYSTRING};

char* errorMessage[] = {"error, out of memory", "error, empty stack","error, too many numbers", "operator error", "error, empty string"};

#endif //TEST_ERRORS_H
