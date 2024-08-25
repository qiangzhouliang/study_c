/*
 1. 程序默认有10个学生信息
     那就使用1个长度为10的结构体数组来存储就可以了．
     这个数组中就是存储这10个学生的信息。
     很明显。这个数组中存储的学生的信息，是需要被多个函数访问的。
     所以，我们把这个数组定义为全局的.
 
 2. 业务流程
    while(1) {
 
        1）．显示操作菜单。并接收用户的选择。
        2）．判断用户的选择。根据用户的选择来做不同的事情.
     }
 
 3. 模块开发
    1. 增 删 查 改 数据。
 
 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 20

/**
 性别枚举，表示学员的性别
 */
typedef enum {
    GenderMale,
    GenderFemale
} Gender;


/// 学生结构体，表示1个学生数据
typedef struct {
    int id;
    char *name;
    int age;
    Gender gender;
    int score;
} Student;

Student students[NUM] = {
    {1, "jack", 18, GenderMale, 100},
    {2, "rose", 21, GenderFemale, 45},
    {3, "lily", 26, GenderFemale, 23},
    {4, "jim1", 12, GenderMale, 89},
    {5, "poly", 3, GenderMale, 67},
    {6, "meimei", 19, GenderFemale, 89},
    {7, "likai", 31, GenderMale, 88},
    {8, "Qiang", 45, GenderMale, 12},
    {9, "ADong", 29, GenderMale, 76},
    {10, "aSan", 35, GenderMale, 91}
};

/// 代表数组中真正存储了多少数据
int realLength = 10;


/// 显示一级菜单，并接收用户的选择
int showMenu();

/// 查询学生
void query();
/// 新增学生
void addStudent();
/// 删除学生
void deleteStudent();
/// 更新学生
void updateStudent();

/// 显示查询的二级菜单
int showQueryMenu();

/// 查询所有学员
void queryAll();

int main(int argc, const char * argv[]) {
    while (1) {
        // 1 显示操作菜单，并接收用户选择
        int userSelect = showMenu();
        // 2 判断用户的选择，根据用户的选择来做不同的事情
        switch (userSelect) {
            case 1:
                // 查询学生
                query();
                break;
            case 2:
                // 新增学生
                addStudent();
                break;
            case 3:
                // 删除学生
                deleteStudent();
                break;
            case 4:
                // 修改学生
                updateStudent();
                break;
            case 5:
                // 退出系统
                return 0;
        }
    }
    return 0;
}



/// 显示一级菜单，并接收用户的选择
int showMenu(){
    // 1 显示菜单
    printf("************************************************************\n");
    printf("*                        请使用学生管理系统                    *\n");
    printf("*                           1. 查询学生                      *\n");
    printf("*                           2. 新增学生                      *\n");
    printf("*                           3. 删除学生                      *\n");
    printf("*                           4. 修改学生                      *\n");
    printf("*                           5. 退出系统                      *\n");
    printf("************************************************************\n");
    
    // 2 接收用户选择
    printf("请输入你的选择：");
    rewind(stdin);
    int userSelect = 0;
    scanf("%d", &userSelect);
    return userSelect;
}


/// 显示查询的二级菜单
int showQueryMenu(){
    // 1 显示菜单
    printf("**************************欢迎使用学生查询系统******************\n");
    printf("*                           1. 查询所有学生信息               *\n");
    printf("*                           2. 根据编号查询                  *\n");
    printf("*                           3. 根据姓名查询                  *\n");
    printf("*                           4. 根据年龄查询                  *\n");
    printf("*                           5. 根据性别查询                  *\n");
    printf("*                           6. 根据成绩查询                  *\n");
    printf("************************************************************\n");
    // 2 接收用户选择
    printf("请输入你的选择：");
    rewind(stdin);
    int userSelect = 0;
    scanf("%d", &userSelect);
    return userSelect;
}

/// 查询学生
void query(){
    // 1. 显示查询的二级菜单，并别收用户选择
    // 1 显示操作菜单，并接收用户选择
    int userSelect = showQueryMenu();
    // 2. 判断用户的选择，根据用户的选择做出不同的查询
    switch (userSelect) {
        case 1:
            // 查询所有
            queryAll();
            break;
            
        default:
            printf("待后续不补充实现。。。");
            break;
    }
}

/// 查询所有学员
void queryAll(){
    printf("编号\t\t姓名\t\t\t年龄\t\t性别\t\t成绩\n");
    for (int i = 0; i < realLength; i++) {
        Student stu = students[i];
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\n",
               stu.id,stu.name,stu.age,
               stu.gender == GenderMale ? "男" : "女",
               stu.score);
    }
}


/// 新增学生
void addStudent(){
    // 1 输入要新增学生的信息。
    // 1.1 先输入姓名
    printf("请输出新增学生的姓名：");
    char name1[10];   // 举报变量，等方法执行结束后，变量就被回收了
    rewind(stdin);
    fgets(name1, 10, stdin);
    size_t len = strlen(name1);
    if (name1[len-1] == '\n') {
        name1[len-1] = '\0';
    }
    // 将值拷贝到堆内存中
    char *name = calloc(len+1, sizeof(char));
    strcpy(name, name1);
    
    
    // 1.2 输入年龄
    printf("请输出新增学生的年龄：");
    int age = 0;
    scanf("%d", &age);
    // 1.3 输入性别
    printf("请输出新增学生的性别：0 ---> 男   1 ---> 女");
    int gender = 0;
    scanf("%d", &gender);
    // 1.4 输入成绩
    printf("请输出新增学生的成绩：");
    int score = 0;
    scanf("%d", &score);
    
    // 2 创建结构体变量
    
    Student stu = {students[realLength-1].id+1,name, age, gender, score};
    
    
    // 2 将输入的学生的信息保存到数组中
    students[realLength] = stu;
//    printf("students = %s",students[realLength].name);
    realLength++;
    
}
/// 删除学生
void deleteStudent(){
    // 1 先输入要删除的学员编号
    rewind(stdin);
    printf("请输出新增学生的编号：");
    int id = 0;
    scanf("%d", &id);
    
    // 2 在数组中找到对应编号的你那个人，确定在第几个下标，
    int deleteIndex = -1;
    for (int i = 0; i < realLength; i++) {
        if (students[i].id == id) {
            // 就要删除下标为 i 的元素
            deleteIndex = i;
            break;
        }
    }
    if (deleteIndex == -1) {
        printf("你输入的编号有误：");
        return;
    }
    // 然后将后面的元素挨个往上顶
    for (int i = deleteIndex + 1; i < realLength; i++) {
        students[i - 1] = students[i];
    }
    // 删除完毕之后
    realLength--;
    
}
/// 更新学生
void updateStudent(){
    printf("待实现\n");
    return;
}

