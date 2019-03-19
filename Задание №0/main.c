#include <stdio.h>
#include "CalcFunctions.h"

int main(){
    int error;
    double num1, num2, num3;
    char sign;
    sign = 0;
    printf("to exit press 'e'\n");
    while (sign != 'e'){
        switch (error){
            case 6:
                printf("n < 0, n must be greater then 0 :(");
                break;
            case 5:
                printf("n <= a0, n must be greater or equal to a0");
                break;
            case 4:
                printf("step cannot be = 1");
                break;
            case 3:
                printf("a negative number cannot be the root");
                break;
            case 2:
                printf("invalid input\n");
                break;
            case 1:
                printf("cannot be divided by 0\n");
                break;
        }
        error = 0;
        scanf("%lg %c %lg", &num1, &sign, &num2);
        switch(sign){
            case '+':
                printf("%lg + %lg = %lg\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%lg - %lg = %lg\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%lg * %lg = %lg\n", num1, num2, num1 * num2);
                break;
            case '/':
                num3 = dev(num1, num2, &error);
                if (0 == error)
                    printf("%lg / %lg = %lg\n", num1, num2, num3);
                break;
            case 'S':
                num2 = root(num1, &error);
                if (0 == error)
                    printf("sqrt(%lg) = %lg\n", num1, num2);
                break;
            case 'M':
                printf("|%lg| = %lg\n", num1, computeModule(num1, &error));
                break;
            case 'G':
                computeGeoProg(num1, num2);
                break;
            
            default:
                error = 2;
                break;
        }
        return 0;
    }
}
