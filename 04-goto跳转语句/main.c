//
//  main.c
//  04-goto跳转语句
//
//  Created by swan on 2024/8/9.
//

#include <stdio.h>

///
///ceshi
void test(){
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
loop:
    printf("goto 跳转语句!\n");
    printf("goto 跳转语句1!\n");
    printf("goto 跳转语句2!\n");
    printf("goto 跳转语句3!\n");
    printf("goto 跳转语句4!\n");
    printf("goto 跳转语句5!\n");
    printf("goto 跳转语句6!\n");
    goto loop;
    return 0;
}
