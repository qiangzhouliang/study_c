/*
 1．我们前面学习了很多种的数据类型
     int
     double
     float
     char
     数组
     指针
     ......
     不同的数据类型的变量是用来保存不同类型的数据的.
 
 2. 没有我们所需的类型变量怎么办？
    那么我们就自己定义这样的数据类型。
    指定这个数据类型的变量由哪些小变量合成的.
 
    新类型NewType:int, int, char*，double；基本类型组成
 
    NewType type;
 
 3. 使用结构体来创建新的数据类型。
    语法格式：
    
    struct 新类型名称 {
         //在这里面写上，你创建的新类型是由哪些变量联合而成的.
         数据类型1 小变量名称1；
         数据类型2 小变量名称2；
         数据类型3 小变量名称3；
    };
 
     struct Student{
         char *name;
         int age;
         int score;
         float height;
     };
     代表我们新创建了1个数据类型。这个数据类型的名称叫做 struct Worker.
     这个新的类型是由 1个char* int int float的小变量联合而成的.
 
 4，声明结构体类型的变量.
     1）．我们使用结构体仅仅是创建了1个新的类型而已，并没有变量。
         结构体的作用：是在指定新的数据类型是由哪些小变量组合而成的。
 
     2）．声明结构体类型的变量，
        语法格式：
        struct 新类型名称 变量名；
        
        struct Student stu;
        代表声明了1个 struct Student类型的变量.变量名字叫做stu
        这个时候，stu才是1个变量，才会在内存中申请空间.
 
        这个变量中，是由这个新的结构体类型规定的小变量组合而成的，
        
        这个结构体大变量是由结构体类型规定的小变量组合而成的.
 
     3）．结构体变量的类型：
 
        struct Student stu;
        这个时候stu结构结构体变量的类型是struct Student. 而不是Student
    
 5. 结构体变量的初始化
     1）．意义：为结构体变量中的小变量赋值.
     2）．初始化的语法：
         结构体变量名称.小变量名(成员) = 数据；
 
 6. 什么时候我们自己要定义结构体
    当我们要保存一个数据，发现这个数据是一个大数据，这个数据是由其他的小数据联合起来组成的。
    那么这个时候
    先使用结构体类自定义这个数据类型由哪些小变量合成的
    让后再根据这个结构体类型声明变量 来保存数据.

 7．使用结构体需要注意的几个小问题。
    1）．一定要先使用结构体定义新的类型.然后才可以根据这个类型 声明这个类型的变量.
    2）．结构体变量是1个变量，所以可以批量声明。
        struct Student xiaoHua, j im, meimei, lilei;
    3）。结构体的名称的的命名规范，要求每一个单词的首字母大写，
 
    4）．我们之前，是先声明结构体类型，再根据这个类型声明变量．
        实际上这两步 可以简化为1个步骤。
 
         struct Worker{
             char name[10];
             int age;
             double salary;
         } darren, jack;
        声明结构体类型的同时，声明结构体类型的变量.
 
    5）．匿名结构体
        就是这个结构体类型没有名称。
 
         struct {
             char name[10];
             int age;
             double salary;
         } jack;
 
         a. 只能在声明结构体的同时就创建变量.
         b. 不能单独的声明这个结构体类型的变量，
 
 */

#include "结构体的基本使用.h"

struct Student{
    char *name;
    int age;
    int score;
    float height;
};

void 结构体的基本使用(void){
    
    // jack 17 100 189.8
    struct Student stu;
    stu.name = "jack";
    stu.age = 17;
    stu.score = 100;
    stu.height = 189.8f;
    
    printf("姓名：%s，年龄：%d 成绩：%d 身高：%.2f\n", stu.name,stu.age,stu.score,stu.height);
    
    
}
