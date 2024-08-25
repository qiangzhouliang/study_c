//
//  main.c
//  08-多级指针
//
//  Created by swan on 2024/8/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num = 10;
    int* p1 = &num; //p1是1个一级指针.存储的是num变量的地址.
    int** p2 = &p1;//p2是1个二级指针，存储的是一级指针变量p1的地址。
    
    //1.打印num变量的地址.
    printf("num变量的地址：%p\n",&num);  // num 变量的地址
    //2.打印p1变量的值，
    printf("p1指针变量的值是：%p\n",p1); // 和上面输出一样
    //3.打印p1指针变量的地址.
    printf("p1指针变量的地址是：%p\n",&p1);// 输出 p1 变量的地址
    //4.打印p2变量的值.
    printf("p2指针变量的值是：%p\n", p2);// 和上面输出一样
    //5.打印p2的地址。
    printf("p2指针变量的地址是：%p\n",&p2);// p2的地址
    return 0;
}
