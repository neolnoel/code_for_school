#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARGNUM 256

char argName[ARGNUM];
int argVal[ARGNUM];
int argCnt = 0;
char y, x;
int a, b;

/*
@example 
@param
@return
@throws
*/
int parseFunction(char *str) {
    getY(str);
    getAX(str);
    getB(str);

    return 0;
}


/*
@example 
@param
@return
@throws
*/
int parseSet(char *str) {
    int i;
    for (i = 4;  i < strlen(str) && str[i] != '='; i++) ;
    if (1 == isdigit(str[i+1])){
        argVal[argCnt] = atoi((char *)(&str[i+1]));
        argName[argCnt] = str[i-1];
    }
    else {
        argVal[argCnt] = atoi((char *)(&str[4]));
        argName[argCnt] = str[i+1];
    }
    argCnt++;
    return 0;
}


/*
@example 
@param
@return
@throws
*/
int computeFunction(void) {
    int i;
    for (i = 0; i < argCnt; i++)
        printf("%c = %d\n", argName[i], argVal[i]);
    return 0;
}

/*
@example 
@param
@return
@throws
*/
int getY(char *str) {
    return 0;
}

/*
@example 
@param
@return
@throws
*/
int getAX(char *str) {
    return 0;
}

/*
@example 
@param
@return
@throws
*/
int getB(char *str) {
    return 0;
}
