/*
 1. 结构体数组
    1）.需要保存5个学生的信息，
 
        a．声明5个结构体变量.来保存，分别来保存，
           这样虽然可以，但是数据非常难以管理。
 
        b. 使用结构体数组来保存他们
 
    2). 声明1个结构体数组
 
        struct 结构体类型名称 数组名称[数组长度];
 
        struct Student students[5];
 
        表示我们声明了1个长度为5的数组•
        数组名称叫做students
        数组长度为5个
        数组的元素的类型是struct Student类型.
 
        所以，这个数组可以存储5个struct Student类型变量.
 
 2. 结构体数组初始化
    1）先声明结构体数组，用下标一个一个赋值。
 
      注意：当我们为结构体数组的元素赋值的时候。如果直接使用大括弧来初始化。
           就必须要前面加1个小括弧，来告诉编译器我们的给的数据类型，
 
     struct Student students[5];
     students[0] = (struct Student){"小明1", 16, 56};
     students[1] = (struct Student){"小明2", 18, 100};
     students[2] = (struct Student){"小明3", 19, 10};
     students[3] = (struct Student){"小明4", 21, 100};
     students[4] = (struct Student){"小明5", 13, 3};
 
    2）.在声明结构体数组的同时，就为所有的元素初始化.
         struct Student students[] = {
             {"小明1", 16, 56},
             {"小明2", 18, 100},
             {"小明3", 19, 10},
             {"小明4", 21, 100},
             {"小明5", 13, 3}
         };
 
 
 3.结构体数组的长度计算。
 
     1）.先使用sizeof计算出数组占用的总的字节数.
     2）.使用总宇节数 除以 每1个元素占用的字节数.
     int len = sizeof(students) / sizeof(struct Student);
 */
#include "2结构体数组.h"

struct Student{
    char *name;
    int age;
    int score;
};


void 结构体数组(void){
    
//    struct Student s1 = {"小明1", 16, 56};
//    struct Student s2 = {"小明2", 18, 100};
//    struct Student s3 = {"小明3", 19, 10};
//    struct Student s4 = {"小明4", 21, 100};
//    struct Student s5 = {"小明5", 13, 3};
    
//    struct Student students[5];
//    students[0] = (struct Student){"小明1", 16, 56};
//    students[1] = (struct Student){"小明2", 18, 100};
//    students[2] = (struct Student){"小明3", 19, 10};
//    students[3] = (struct Student){"小明4", 21, 100};
//    students[4] = (struct Student){"小明5", 13, 3};
    
    struct Student students[] = {
        {"小明1", 16, 56},
        {"小明2", 18, 100},
        {"小明3", 19, 10},
        {"小明4", 21, 100},
        {"小明5", 13, 3}
    };
    
    int len = sizeof(students) / sizeof(struct Student);
    printf("len = %d\n", len);
    
    for (int i = 0; i < 5; i++) {
        printf("姓名：%s，年龄：%d 成绩：%d \n", students[i].name,students[i].age,students[i].score);
    }
    
    
}
