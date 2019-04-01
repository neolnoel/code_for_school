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
@example FUNCTION(y=8+46*x) |y = y, b = 8, a = 46, x = x|
@param str(текущий аргумент)
@return 0
@throws -
@uses "computeFunctions.h"
*/
int parseFunction(char *str) {
    getY(str);
    getAX(str);
    getB(str);

    return 0;
}


/*
@example SET(z=9) |argName[i] = z, argVal[i] = 9| 
@param str(текущий аргумент)
@return 0
@throws -
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
@example \calc FUNCTION(y=8+1*x) SET(x=8) |y(8) = 9|
@param void
@return 0
@throws HAVE NO 'z' VARIABLE , HAVE NO FUNCTION AT ALL , CANNOT SET CONSTANT
*/
int computeFunction(void) {
    int i;
    for (i = 0; i < argCnt; i++)
        if (x != argName[i])
            printf("HAVE NO '%c' VARIABLE\n", argName[i]);
        else if (y == argName[i] && x == argName[i])
            printf("HAVE NO FUNCTION AT ALL\n");
        else if (y == argName[i])
            printf("CANNOT SET CONSTANT\n");
        else
        printf("%c(%d) = %d\n", y, argVal[i], (argVal[i] * a) + b);
    return 0;
}

/*
@example FUNCTION(z=8+1*x) |y = z|
@param str(текущий аргумент)
@return 0
@throws -
*/
int getY(char *str) {
    int i;
    for (i = 9;  i < strlen(str) && str[i] != '='; i++) ;
    if ('(' == str[i-2])
        y = str[i-1];
    else
        y = str[i+1];       
    return 0;
}

/*
@example UNCTION(z=8+1*y) |a = 1 , x = y|
@param str(текущий аргумент)
@return 0
@throws -
*/

int getAX(char *str) {
    int i;
    for (i = 11;  i < strlen(str) && str[i] != '*'; i++) ;
    if (1 == isdigit(str[i+1])){
        x = str[i-1];
        a = atoi((char *)(&str[i+1]));
    }
    else {
        x = str[i+1];
        for (i--; str[i] != '(' && 1 == isdigit(str[i]); i--) ;
        a = atoi((char *)(&str[i]));
    }
    return 0;
}

/*
@example UNCTION(z=8+1*x) |b = 8|
@param str(текущий аргумент)
@return 0
@throws -
(y=8+469*x)
*/
int getB(char *str) {
    int i;
    for (i = 9; i < strlen(str) && str[i] != '*' && str[i] != '+'; i++) ;
    if ('*' == str[i]){
        for(i++; i < strlen(str) && str[i] != '+'; i++) ;
        b = atoi((char *)(&str[i+1]));
    }
    else {
        for (i--; str[i] != '(' && 1 == isdigit(str[i]); i--) ;
        b = atoi((char *)(&str[i+1]));
    }
    
    return 0;
}
