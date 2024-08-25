/**
 1. 字符串数组排序
    将字符串数组中的每一个字符串以 字母的顺序排序。
 
 2. 存储指针的数组每一个元素的类型是1个指针
    而每1个指针都是占据8个字节.
 
    我们在求存储指针的数组的长度：用总字节数 /8.
 
 
 
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char *countries[] =
    {
        "Nepal",
        "Cambodia",
        "Afghanistan",
        "China",
        "Singapore",
        "Bangladesh",
        "India",
        "Maldives",
        "South Korea",
        "Bhutan",
        "Japan",
        "Sikkim",
        "Sri Lanka",
        "Burma",
        "North Korea" ,
        "Laos",
        "Malaysia",
        "Indonesia",
        "Turkey",
        "Mongolia",
        "Pakistan",
        "Philippines",
        "Vietnam",
        "Palestine"
    };
    
    // 1 先计算数组的长度
//    int len = sizeof(countries) / 8;
    int len = sizeof(countries) / sizeof(countries[0]);
//    printf("len = %d\n", len);
    // 2 使用冒泡排序
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            int res = strcmp(countries[j], countries[j+1]);
            if (res > 0) { // 说明 j 比 j+1小，交换位置
                char *temp = countries[j];
                countries[j] = countries[j+1];
                countries[j+1] = temp;
            }
        }
    }
    
    // 2 打印结果
    for (int i = 0; i < len - 1; i++) {
        printf("%s\n", countries[i]);
    }
    
    return 0;
}
