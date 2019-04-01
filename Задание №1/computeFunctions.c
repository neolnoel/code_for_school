#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "computeFunctions.h"

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
    int i;
    for (i = 9;  i < strlen(str) && str[i] != '='; i++) ;
    if ('(' == str[i-2]){
        y = str[i-1];
        printf("y = %c\n", y);
    }
    else{
        y = str[i+1];
        printf("y = %c\n", y);            
    }
    return 0;
}

/*
@example 
@param
@return
@throws
*/

int getAX(char *str) {
    int i;
    for (i = 11;  i < strlen(str) && str[i] != '*'; i++) ;
    if (1 == isdigit(str[i+1])){
        x = str[i-1];
        a = atoi((char *)(&str[i+1]));
        printf("num = %d\nname = %c\n", a, x);
        
    }
    else {
        x = str[i+1];
        for (i--; str[i] != '(' && 1 == isdigit(str[i]); i--) ;
        a = atoi((char *)(&str[i]));
        printf("num = %d\nname = %c\n", a, x);
    }
    return 0;
}

/*
@example 
@param
@return
@throws
(y=8+469*x)
*/
int getB(char *str) {
    int i;
    for (i = 9; i < strlen(str) && str[i] != '*' && str[i] != '+'; i++) ;
    if ('*' == str[i]){
        for(i++; i < strlen(str) && str[i] != '+'; i++) ;
        b = atoi((char *)(&str[i+1]));
        printf("b = %d\n", b);
    }
    else {
        for (i--; str[i] != '(' && 1 == isdigit(str[i]); i--) ;
        b = atoi((char *)(&str[i+1]));
        printf("b = %d\n", b);
    }
    
    return 0;
}
