#include <stdio.h>
#include "CalcFunctions.c"

int main(){
    int error;
    double Num1, Num2;
    char sign;

    while (sign != "A"){
        scanf("%f %c %f", &Num1, &sign, &Num2);
        switch(sign){
            case '+':
                printf("%f + %f = %f", Num1, Num2, Num1 + Num2);
                error = 0;
                break;
            case '-':
                printf("%f - %f = %f", Num1, Num2, Num1 - Num2);
                error = 0;
                break;
            case '*':
                printf("%f * %f = %f", Num1, Num2, Num1 * Num2);
                error = 0;
                break;
            case '/':
                printf("%f / %f = %f", Num1, Num2, dev(Num1, Num2, error));
                break;
            default:
                error = 2;
        }
        switch (error){
            case 2:
                printf("invalid input\n");
                break;
            case 1:
                printf("cannot be divided by 0\n");
                break;
        }
    }
    return 0;
}