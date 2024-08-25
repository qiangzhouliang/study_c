/*
 1．结构体变量，是个变量.
    struct Student xiaoMing = ｛"小明”，18,100｝；
    xiaoMing首先是1个变量，类型是struct Student类型的.
    既然xiaoMing是1个变量，那么这个变量肯定就是有地址的，既然有地址，那么就可以声明1个指针指向这个结构体变量。
 
 2．结构体指针的声明
    1）.格式：
        struct 结构体类型名称* 指针名；
 
        struct Student *pStu;
        声明了1个pStu指针变量，这个指针变量的类型是struct Student*.
        这个指针就只能指向struct Student类型的变量.
 
     2）．初始化：
        a．取出结构体变量的地址。
             使用取地址运算符 &
             就可以取出结构体变量的地址，
        
        b，将地址赋值给指针变量.
             truct Student xiaoMing = {"小明", 18, 100};
             struct Student *pStu = &xiaoMing;
 
     3）.如何使用指向结构体变量的指针来间接的访问这个结构体变量呢？
        a．（*结构体指针名）.成员，
            (*pStu).age = 18;
 
        b. 使用 -> 来访问
            pStu -> age = 18;
 */

#include "3-结构体指针.h"

struct Student{
    char *name;
    int age;
    int score;
};


void 结构体指针(){
    
    struct Student xiaoMing = {"小明", 18, 100};
    
    struct Student *pStu = &xiaoMing;
    pStu->age = 28;
    
    
    
}
