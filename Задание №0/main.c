#include <stdio.h>
#include <CalcFunctions.h>

int main(){
    int error;
    double Num1, Num2;
    char sign;

    while (sign != "S"){
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
            case 'S':
                printf("sqrt(%f) = %f", Num1, root(Num1, error));
                break;
            case 'M':
                printf("|%f| = %f", Num1, module(Num1));
                break;
            case 'N':
                printf("Добрый день!!!\n Вы работаете с операцией 'геометрическая прогрессия'\n Вы указали\n начальный член a0 = %f\n шаг q = %f\n укажите номер члена последовательности, чтоб завершить операцию :", Num1, Num2);
                scanf("%f\n", &Num3);
                printf("%f * (1 - %f^%f)) / (1 - %f) = %f", Num1, Num2, Num3, Num2, geo_prog(Num1, Num2, Num3, error));
            
            default:
                error = 2;
        }
        switch (error){
            case 4:
                printf("step cannot be = 1")
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
