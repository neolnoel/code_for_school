#include <stdio.h>
#include "CalcFunctions.c"

int main(){
    int error;
    double Num1, Num2, Num3;
    char sign;
    sign = 0;
    pritf("to exit press 'e'\n");
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
        scanf("%lg %c %lg", &Num1, &sign, &Num2);
        switch(sign){
            case '+':
                printf("%lg + %lg = %lg\n", Num1, Num2, Num1 + Num2);
                break;
            case '-':
                printf("%lg - %lg = %lg\n", Num1, Num2, Num1 - Num2);
                break;
            case '*':
                printf("%lg * %lg = %lg\n", Num1, Num2, Num1 * Num2);
                break;
            case '/':
                Num3 = dev(Num1, Num2, &error);
                if (0 == error)
                    printf("%lg / %lg = %lg\n", Num1, Num2, Num3);
                break;
            case 'S':
                Num2 = root(Num1, &error);
                if (0 == error)
                    printf("sqrt(%lg) = %lg\n", Num1, Num2);
                break;
            case 'M':
                printf("|%lg| = %lg\n", Num1, computeModule(Num1, &error));
                break;
            case 'G':
                computeGeoProg(Num1, Num2, &error);
                break;
            
            default:
                error = 2;
                break;
        }
        return 0;
    }
}
