/*
 1. 应该将我们地图上的每一个格子的类型保存起来.
    墙：
    路：
    人：
    箱子：
    并且地图是1个有行有列的表格。所以所以二维数组来保存我们的地图是非常合适的了.
 
 2. 游戏的流程
    while(1){
         1）．打印地图．
         2）．接收输入小人的前进方向，
         3）. 根据小人的前进方向来前进或者推箱子。
    }
 */

#include <stdio.h>
#include <stdlib.h>
#define rows 10
#define cols 11

///
/// 地图数组，用来保存地图上的每一个格子的类型
char map[rows][cols] = {
    "##########",
    "#  ####  #",
    "# X####  #",
    "# O      #",
    "######   #",
    "#  ####  #",
    "#        #",
    "#   ######",
    "#         ",
    "##########",
};

// 小人当前所在的行坐标 默认在第 3 行
int personCurrentRow = 3;
// 小人当前所在的列坐标 默认在第 2 列
int personCurrentCol = 2;


///
/// 根据 map 数组打印地图
void showMap();

/// 根据小人的前进方向得到小人的下一个坐标
void getNextPosition(char dir, const int currentRow, const int currentCol, int *pPersonNextRow, int *pPersonNextCol);

/**
* 接收输入小人的前进方向
* @return 前进方向
*/
char enterDirection();

/// 移动小人
void moveP(char dir);


int main(int argc, const char * argv[]) {
    
    while (1) {
        system("clear");
        //1. 打印地图
        showMap();
        
        //2. 接收输入小人的前进方向
        char dir = enterDirection();
        
        // 3. 根据小人的前进方向，来移动小人或者推箱子
        if (dir == 'q' || dir == 'Q') {
            // 结束
            printf("你得智商真低\n");
            return 0;
        } else {
            moveP(dir);
        }
    }
    
    return 0;
}


void showMap(){
    for (int i = 0; i < rows; i++) {
        printf("%s\n", map[i]);
    }
}

/**
* 接收输入小人的前进方向
* @return 前进方向
*/
char enterDirection(){
    printf("请输入小人的前方向 a.左 w.上 d.右 s.下 q.结束\n");
    char dir = 'a';
    // 清空缓存区
    rewind(stdin);
    scanf("%c", &dir);
    return dir;
}

/// 移动小人
void moveP(char dir){
    //1. 拿到小人下一个位置
    // 根据小人的前进方向而不同
    // 这段代码做的事情：是根据小人的前进方向计算出小人的下个坐标
    int personNextRow = 0;
    int personNextCol = 0;
    getNextPosition(dir,personCurrentRow,personCurrentCol, &personNextRow, &personNextCol);
    
    // 2 判断小人的上一个坐标是一个什么格子
    if (map[personNextRow][personNextCol] == ' ') {
        // 说明是个路，小人移动
        // 将上1个格子赋值为0 小人现在的位置赋值为 ' '
        map[personNextRow][personNextCol] = 'O';
        map[personCurrentRow][personCurrentCol] = ' ';
        // 小人已经移动了，那么就要改变小人的位置
        personCurrentRow = personNextRow;
        personCurrentCol = personNextCol;
    } else if (map[personNextRow][personNextCol] == 'X'){
        // 说明上1个格子是1个箱子，判断能不能推
        //1. 找到箱子上面的格子的坐标
        //  计算箱子上面的坐标
        int boxNextRow = 0;
        int boxNextCol = 0;
        getNextPosition(dir,personNextRow,personNextCol, &boxNextRow, &boxNextCol);
        if (map[boxNextRow][boxNextCol] == ' ') {
            // 推
            // a. 把当前箱子的上1个格子设置为箱子
            map[boxNextRow][boxNextCol] = 'X';
            // b. 把当前箱子的格子设置为小人
            map[personNextRow][personNextCol] = 'O';
            // c. 把小人的位置设置为空格
            map[personCurrentRow][personCurrentCol] = ' ';
            // 小人已经移动了，那么就要改变小人的位置
            personCurrentRow = personNextRow;
            personCurrentCol = personNextCol;
        }
    }
    
    
}

/// 根据小人的前进方向得到小人的下一个坐标
void getNextPosition(char dir,const int currentRow, const int currentCol, int *pPersonNextRow, int *pPersonNextCol){
    
    int personNextRow = 0;
    int personNextCol = 0;
    switch (dir) {
        case 'a':
        case 'A':
            // 向左
            personNextRow = currentRow;
            personNextCol = currentCol - 1;
            break;
        case 'w':
        case 'W':
            // 向上
            personNextRow = currentRow - 1;
            personNextCol = currentCol;
            break;
        case 'd':
        case 'D':
            // 向右
            personNextRow = currentRow;
            personNextCol = currentCol + 1;
            break;
        case 's':
        case 'S':
            // 向下
            personNextRow = currentRow + 1;
            personNextCol = currentCol;
            break;
    }
    *pPersonNextRow = personNextRow;
    *pPersonNextCol = personNextCol;
}
