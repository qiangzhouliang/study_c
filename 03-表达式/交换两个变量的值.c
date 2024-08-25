/*
 1. 交换两个变量的值
    1). 声明第三个临时变量来交换
     int num1 = 10;
     int num2 = 20;
     
     // 声明第三个临时变量来交换
     int temp = num1;
     num1 = num2;
     num2 = temp;
    2). 两数相加在相减
     int num1 = 10;
     int num2 = 20;
     
     // 两数相加在相减
     num1 = num1 + num2; // num1 = 30
     num2 = num1 - num2;  // num2 = 30 - 10 = 20
     num1 = num1 - num2;
 
    3). 使用异或运算交换两个变量的值
     num1 = num1 ^ num2;
     num2 = num1 ^ num2;
     num1 = num1 ^ num2;
 */

#include "交换两个变量的值.h"

void exchangeValue(void){
    int num1 = 10;
    int num2 = 20;
    
    // 声明第三个临时变量来交换
//    int temp = num1;
//    num1 = num2;
//    num2 = temp;
    
    // 两数相加在相减
//    num1 = num1 + num2; // num1 = 300
//    num2 = num1 - num2;  // num2 = 300 - 100 = 200
//    num1 = num1 - num2;
    
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    
    printf("num1 = %d, num2 = %d\n", num1, num2);
}
