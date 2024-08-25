/*
 结构体嵌套
 
 什么时候会有这种情况
 
 当我们在为结构体定义成员的时候，发现某个成员也是1个大数据 需要其他的几个小变量合起来描述
 那么这个时候你就可以再定义1个数据类型。来表示这个类型。
 
 */

#include "4-结构体嵌套.h"
/// 日期
struct Date {
    int year;
    int month;
    int day;
};

/// 表示一个人
struct Person{
    char *name;
    int age;
    double money;
    // 出生日期
    struct Date birthday;
};


void 结构体嵌套(){
    
    struct Person xiaoMing = {"小明", 18, 10001,{2000, 12, 31}};
}
