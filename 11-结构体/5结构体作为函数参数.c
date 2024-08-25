/*
 1. 结构体作为函数参数
 
     1）.结构体是我们自定义的一种数据类型，也是一种数据类型 所以当然可以作为函数的参数.
     2）．结构体作为参数传值 是 值传递。
     3）．如果你就是希望函数的内部可以修改实参结构体变量的值，那么就是要指针，
 
 2. 结构体作为函数的返回值
 
     1）．结构体类型完全可以作为函数的返回值.
     2）．在返回的时候 直接将这个结构体变量的值返回即可，
     3）．如果你要返回结构体变量的地址，那么就要把这个结构体变量创建在堆区.
 
 
 
 */
#include <stdio.h>
struct Student{
    char *name;
    int age;
    int score;
};

// 判断1个学生的成绩是否及格
void panDuanXueSheng(struct Student stu){
    if (stu.score >= 60) {
        printf("恭喜%s，你及格了\n", stu.name);
    } else {
        printf("不好意思%s，你落榜了\n", stu.name);
    }
}


void 结构体作为函数参数(){
    struct Student xiaoMing = {"小明", 18, 100};
    panDuanXueSheng(xiaoMing);
}

