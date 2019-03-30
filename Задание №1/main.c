/*
@author Skalozubov_Max1m
@link http://moria.1586.su/moodle/mod/page/view.php?id=1705
@link https://github.com/mmjax/code_for_school

Проектное задание #1
Калькулятор с возможностью:
подсчёта равенств по вводу например: |.\calc FUNCTION(y=8+9*x) SET(x=8)|
*/
#include <string.h>
#include <stdio.h>
#include "computeFunctions.h"

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        if (0 == strncmp(argv[i], "SET", strlen("SET"))) {
            parseSet(argv[i]);
        }
        if (0 == strncmp(argv[i], "FUNCTION", strlen("FUNCTION")))
            parseFunction(argv[i]);
    }
    computeFunction();
    return 0;
}
