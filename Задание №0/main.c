#include <stdio.h>
#include "CalcFunctions.c"

int main(){
    int error;
    double Num1, Num2, Num3;
    char sign;

    while (sign != 'S'){
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
                printf("%f / %f = %f", Num1, Num2, dev(Num1, Num2, &error));
                break;
            case 'S':
                printf("sqrt(%f) = %f", Num1, root(Num1, &error));
                break;
            case 'M':
                printf("|%f| = %f", Num1, computeModule(Num1, &error));
                break;
            case 'N':
                printf("Добрый день!!!\n Вы работаете с операцией 'геометрическая прогрессия'\n Вы указали\n начальный член a0 = %f\n шаг q = %f\n укажите номер члена последовательности, чтоб завершить операцию :", Num1, Num2);
                computeGeoProg(Num1, Num2, &error);
            
            default:
                error = 2;
        }
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
    }
    return 0;
}
