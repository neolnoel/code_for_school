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
double dev(double Num1, double Num2, int error){
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
double root(double Num1, int error){
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
double module(double Num1, int error){
    if (0 <= Num1){
        *error = 0;
        return Num1;
    }
    *error = 0;
    return Num1 * (-1);

}


/*
@exempl (геоиетрическая последовательность) Sn = 2 * (1 - 2^4) / (1 - 2) = 30;
@param Num1 (первоначальное число), Num2 (шаг), Num3 (номер члена геометрической прогрессии);
@return сумма геометрической прогрессии и произведение геометрической прогрессии or error;
@throws ошибок не найдено (0), есть ошибка[-и] (4);
*/
double geo_prog(double Num1, double Num2, double Num3, int error){
    if (1 != Num2){
        *error = 0;
        return Num1 * (1 - pow(Num2, Num3)) / (1 - Num2);
    }
    *error = 4;
    return 0;
}
