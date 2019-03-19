/*
@author Skalozubov_Max1m
@link http://moria.1586.su/moodle/mod/page/view.php?id=1705
@link https://github.com/mmjax/code_for_school

Проектное задание #0
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
@param num1(делитель), num2 (делимое), error (возможные ошибки);
@return num1 / num2 or error;
@throws ошибок не найдено (0), есть ошибка[-и] (1);
*/
double dev(double num1, double num2, int *error){
    if (0 != num2){
        *error = 0;
        return num1 / num2;   
    }
    *error = 1;
    return 0;    
}


/*
@exempl (квадратный корень числа) sqrt(4) = 2;
@param num1 (подкоренное значение), error (возможные ошибки);
@return sqrt(num1) or error;
@throws ошибок не найдено (0), есть ошибка[-и] (3);
*/
double root(double num1, int *error){
    if (num1 > 0){
        *error = 0;
        return sqrt(num1);
    }
    *error = 3;
    return 0;        
}


/*
@exempl (модуль числа) |-4| = 4;
@param num1 (число в модуле);
@return |num1|;
@throws ошибок не найдено (0);
*/
double computeModule(double num1, int *error){
    if (0 <= num1){
        return num1;
    }
    return num1 * (-1);

}


/*
@exempl (сумма геометрической последовательности) Sn = 2 * (1 - 2^4) / (1 - 2) = 30;, (геометрическая прогрессия) a = 2, 4, 8, ..., 256, (произведение геометрической прогрессии) Pn = pow(a0 * an, n / 2)
@param bn (первоначальное число), q (шаг), n (номер члена геометрической прогрессии);
@return сумма геометрической прогрессии & произведение геометрической прогрессии & члены геометрической прогрессии or error;
@throws ошибок не найдено (0);
*/

void computeGeoProg(double bn, int q){
    int n; 
    double geoSum = bn, geoCump = 1;
    scanf("%d", &n);
    for(int i = 1; i <=n; i++){
        bn *= q;
        printf("%lg ", bn);
        geoSum += bn;
        geoCump *= bn;
    }
    printf("composition of progression = %lg\n", geoCump);
    printf("sum of progression = %lg\n", geoSum);
}