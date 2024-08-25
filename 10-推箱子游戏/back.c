///*
// 1. 应该将我们地图上的每一个格子的类型保存起来.
//    墙：
//    路：
//    人：
//    箱子：
//    并且地图是1个有行有列的表格。所以所以二维数组来保存我们的地图是非常合适的了.
// 
// 2. 游戏的流程
//    while(1){
//         1）．打印地图．
//         2）．接收输入小人的前进方向，
//         3）. 根据小人的前进方向来前进或者推箱子。
//    }
//     
// 
// 
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#define rows 10
//#define cols 11
//
/////
///// 地图数组，用来保存地图上的每一个格子的类型
//char map[rows][cols] = {
//    "##########",
//    "#  ####  #",
//    "# X####  #",
//    "# O      #",
//    "######   #",
//    "#  ####  #",
//    "#        #",
//    "#   ######",
//    "#         ",
//    "##########",
//};
//
//// 小人当前所在的行坐标 默认在第 3 行
//int personCurrentRow = 3;
//// 小人当前所在的列坐标 默认在第 2 列
//int personCurrentCol = 2;
//
//
/////
///// 根据 map 数组打印地图
//void showMap();
//
///**
//* 接收输入小人的前进方向
//* @return 前进方向
//*/
//char enterDirection();
//
//
///**
// *向左走
// */
//void moveToLeft();
///**
// *向上走
// */
//void moveToUp();
///**
// *向右走
// */
//void moveToRight();
///**
// *向下走
// */
//void moveToDown();
//
//
//int main1(int argc, const char * argv[]) {
//    
//    while (1) {
//        system("clear");
//        //1. 打印地图
//        showMap();
//        
//        //2. 接收输入小人的前进方向
//        char dir = enterDirection();
//        
//        // 3. 根据小人的前进方向，来移动小人或者推箱子
//        switch (dir) {
//            case 'a':
//            case 'A':
//                // 向左
//                moveToLeft();
//                break;
//            case 'w':
//            case 'W':
//                // 向上
//                moveToUp();
//                break;
//            case 'd':
//            case 'D':
//                // 向右
//                moveToRight();
//                break;
//            case 's':
//            case 'S':
//                // 向下
//                moveToDown();
//                break;
//            case 'q':
//            case 'Q':
//                printf("你得智商真低\n");
//                return 0;
//        }
//        
//    }
//    
//    
//    return 0;
//}
//
//
//void showMap(){
//    for (int i = 0; i < rows; i++) {
//        printf("%s\n", map[i]);
//    }
//}
//
///**
//* 接收输入小人的前进方向
//* @return 前进方向
//*/
//char enterDirection(){
//    printf("请输入小人的前方向 a.左 w.上 d.右 s.下 q.结束\n");
//    char dir = 'a';
//    // 清空缓存区
//    rewind(stdin);
//    scanf("%c", &dir);
//    return dir;
//}
//
///**
// *向左走
// */
//void moveToLeft(){
//    // 下一个位置
//    int personNextRow = personCurrentRow;
//    int personNextCol = personCurrentCol - 1;
//    
//    // 3 判断小人的上一个坐标是一个什么格子
//    if (map[personNextRow][personNextCol] == ' ') {
//        // 说明是个路，小人移动
//        // 将上1个格子赋值为0 小人现在的位置赋值为 ' '
//        map[personNextRow][personNextCol] = 'O';
//        map[personCurrentRow][personCurrentCol] = ' ';
//        // 小人已经移动了，那么就要改变小人的位置
//        personCurrentRow = personNextRow;
//        personCurrentCol = personNextCol;
//    } else if (map[personNextRow][personNextCol] == 'X'){
//        // 说明上1个格子是1个箱子，判断能不能推
//        //1. 找到箱子上面的格子的坐标
//        //  计算箱子上面的坐标
//        int boxNextRow = personNextRow;
//        int boxNextCol = personNextCol - 1;
//        if (map[boxNextRow][boxNextCol] == ' ') {
//            // 推
//            // a. 把当前箱子的上1个格子设置为箱子
//            map[boxNextRow][boxNextCol] = 'X';
//            // b. 把当前箱子的格子设置为小人
//            map[personNextRow][personNextCol] = 'O';
//            // c. 把小人的位置设置为空格
//            map[personCurrentRow][personCurrentCol] = ' ';
//            // 小人已经移动了，那么就要改变小人的位置
//            personCurrentRow = personNextRow;
//            personCurrentCol = personNextCol;
//        }
//    }
//}
///**
// *向上走
// */
//void moveToUp(){
//    //1. 要把小人向上移动.
//    //   就要知道小人的上1个格子的类型.
//    //   如果上面是1个墙 不能动.
//    //   如果上面是个路：移动，
//    //   如果上面是箱子，判断箱子上面是什么
//    //   路：推
//    //   墙：不动.
//    
//    // 2.首页 要拿到小人的上1个坐标
//    // 要拿到小人的上1个坐标，就要拿到小人现在的坐标
//    // 根据小人现在的坐标 计算小人的上1个坐标
//    // 上1个坐标相对于小人的左边 行-1 列不变.
//    int personNextRow = personCurrentRow - 1;
//    int personNextCol = personCurrentCol;
//    
//    // 3 判断小人的上一个坐标是一个什么格子
//    if (map[personNextRow][personNextCol] == ' ') {
//        // 说明是个路，小人移动
//        // 将上1个格子赋值为0 小人现在的位置赋值为 ' '
//        map[personNextRow][personNextCol] = 'O';
//        map[personCurrentRow][personCurrentCol] = ' ';
//        // 小人已经移动了，那么就要改变小人的位置
//        personCurrentRow = personNextRow;
//        personCurrentCol = personNextCol;
//    } else if (map[personNextRow][personNextCol] == 'X'){
//        // 说明上1个格子是1个箱子，判断能不能推
//        //1. 找到箱子上面的格子的坐标
//        //  计算箱子上面的坐标
//        int boxNextRow = personNextRow - 1;
//        int boxNextCol = personNextCol;
//        if (map[boxNextRow][boxNextCol] == ' ') {
//            // 推
//            // a. 把当前箱子的上1个格子设置为箱子
//            map[boxNextRow][boxNextCol] = 'X';
//            // b. 把当前箱子的格子设置为小人
//            map[personNextRow][personNextCol] = 'O';
//            // c. 把小人的位置设置为空格
//            map[personCurrentRow][personCurrentCol] = ' ';
//            // 小人已经移动了，那么就要改变小人的位置
//            personCurrentRow = personNextRow;
//            personCurrentCol = personNextCol;
//        }
//    }
//}
///**
// *向右走
// */
//void moveToRight(){
//    // 下一个位置
//    int personNextRow = personCurrentRow;
//    int personNextCol = personCurrentCol + 1;
//    
//    // 3 判断小人的上一个坐标是一个什么格子
//    if (map[personNextRow][personNextCol] == ' ') {
//        // 说明是个路，小人移动
//        // 将上1个格子赋值为0 小人现在的位置赋值为 ' '
//        map[personNextRow][personNextCol] = 'O';
//        map[personCurrentRow][personCurrentCol] = ' ';
//        // 小人已经移动了，那么就要改变小人的位置
//        personCurrentRow = personNextRow;
//        personCurrentCol = personNextCol;
//    } else if (map[personNextRow][personNextCol] == 'X'){
//        // 说明上1个格子是1个箱子，判断能不能推
//        //1. 找到箱子上面的格子的坐标
//        //  计算箱子上面的坐标
//        int boxNextRow = personNextRow;
//        int boxNextCol = personNextCol + 1;
//        if (map[boxNextRow][boxNextCol] == ' ') {
//            // 推
//            // a. 把当前箱子的上1个格子设置为箱子
//            map[boxNextRow][boxNextCol] = 'X';
//            // b. 把当前箱子的格子设置为小人
//            map[personNextRow][personNextCol] = 'O';
//            // c. 把小人的位置设置为空格
//            map[personCurrentRow][personCurrentCol] = ' ';
//            // 小人已经移动了，那么就要改变小人的位置
//            personCurrentRow = personNextRow;
//            personCurrentCol = personNextCol;
//        }
//    }
//}
///**
// *向下走
// */
//void moveToDown(){
//    // 下一个位置
//    int personNextRow = personCurrentRow + 1;
//    int personNextCol = personCurrentCol;
//    
//    // 3 判断小人的上一个坐标是一个什么格子
//    if (map[personNextRow][personNextCol] == ' ') {
//        // 说明是个路，小人移动
//        // 将上1个格子赋值为0 小人现在的位置赋值为 ' '
//        map[personNextRow][personNextCol] = 'O';
//        map[personCurrentRow][personCurrentCol] = ' ';
//        // 小人已经移动了，那么就要改变小人的位置
//        personCurrentRow = personNextRow;
//        personCurrentCol = personNextCol;
//    } else if (map[personNextRow][personNextCol] == 'X'){
//        // 说明上1个格子是1个箱子，判断能不能推
//        //1. 找到箱子上面的格子的坐标
//        //  计算箱子上面的坐标
//        int boxNextRow = personNextRow;
//        int boxNextCol = personNextCol + 1;
//        if (map[boxNextRow][boxNextCol] == ' ') {
//            // 推
//            // a. 把当前箱子的上1个格子设置为箱子
//            map[boxNextRow][boxNextCol] = 'X';
//            // b. 把当前箱子的格子设置为小人
//            map[personNextRow][personNextCol] = 'O';
//            // c. 把小人的位置设置为空格
//            map[personCurrentRow][personCurrentCol] = ' ';
//            // 小人已经移动了，那么就要改变小人的位置
//            personCurrentRow = personNextRow;
//            personCurrentCol = personNextCol;
//        }
//    }
//}
