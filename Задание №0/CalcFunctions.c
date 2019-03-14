/*
@author Skalozubov_Max1m
@link http://moria.1586.su/moodle/mod/page/view.php?id=1705
@link https://github.com/mmjax/code_for_school

Проектное задание #1
Калькулятор с возможностью:
Сложения двух чисел, вычитания двух чисел, 
умножения двух чисел, деления двух чисел, 
извлечение квадратного корня из числа, вывод модуля числа, 
геометрическая последовательность.
*/
#include <stdio.h>
#include <math.h>


/*
@exempl (деление двух чисел) 4 / 2 = 2;
@param Num1(делитель), Num2 (делимое), error (возможные ошибки);
@return Num1 / Num2 or error;
@throws ошибок не найдено (0), есть ошибка[-и] (1);
*/
double dev(double Num1, double Num2, int *error){
    if (0 != Num2){
        *error = 0;
        return Num1 / Num2;   
    }
    *error = 1;
    return 0;    
}


/*
@exempl (квадратный корень числа) sqrt(4) = 2;
@param Num1 (подкоренное значение), error (возможные ошибки);
@return sqrt(Num1) or error;
@throws ошибок не найдено (0), есть ошибка[-и] (3);
*/
double root(double Num1, int *error){
    if (Num1 > 0){
        *error = 0;
        return sqrt(Num1);
    }
    *error = 3;
    return 0;        
}


/*
@exempl (модуль числа) |-4| = 4;
@param Num1 (число в модуле);
@return |Num1|;
@throws ошибок не найдено (0);
*/
double computeModule(double Num1, int *error){
    if (0 <= Num1){
        *error = 0;
        return Num1;
    }
    *error = 0;
    return Num1 * (-1);

}


/*
@exempl (сумма геометрической последовательности) Sn = 2 * (1 - 2^4) / (1 - 2) = 30;, (геометрическая прогрессия) a = 2, 4, 8, ..., 256, @exampl (произведение геометрической прогрессии) Pn = pow(a0 * an, n / 2)
@param Num1 (первоначальное число), Num2 (шаг), Num3 (номер члена геометрической прогрессии);
@return сумма геометрической прогрессии or error;
@throws ошибок не найдено (0), есть ошибка[-и] (4, 5, 6);
*/
void computeGeoProg(double a0, int q, int *error){
    if (q > 0){
        double geoSum, geoCump;
        int n, i;
        geoSum = 0;
        geoCump = 1;
        printf("enter number of members: ");
        scanf("%d", &n);
        if (a0 <= n){
            for (i = a0; i <= n + 1; i++){
                printf("%lg ", a0);
                a0 = a0 *q;
                geoCump = geoCump * a0;
                geoSum = geoSum + a0;
            }
            printf("%lg\n", a0);
            printf("composition of progression = %lg\n", geoCump);
            printf("sum of progression = %lg\n", geoSum);
        }
        else *error = 5;
    }
    else *error = 6;
    }