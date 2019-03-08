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


/*
@exempl (деление двух чисел) 4 / 2 = 2;
@param Num1(делитель), Num2 (делимое), error (возможные ошибки);
@return Num1 / Num2 or error;
@throws ошибок не найдено (0), есть ошибка[-и] (1);
*/
double dev(double Num1, double Num2, int error){
    if (0 == Num2){
        error = 1;
        return 0;
    }
    error = 0;
    return Num1 / Num2;
}


/*
@exempl ...;
@param ...;
@return ...;
@throws ...;
*/
double ...(...){

}

