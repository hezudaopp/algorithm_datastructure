/* 
 * File:   stack_sq_main.c
 * Author: jawinton
 *
 * Created on 2010��9��20��, ����11:05
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack_sq.h"
/*
 * 
 */
int main(int argc, char** argv) {
/*
    conversion(2345,16);
    lineEdit();
*/
    printf("\n%d",bracketsCheck("int main(int argc, char** argv) {conversion(2345,16);lineEdit()}"));
    return (EXIT_SUCCESS);
}

