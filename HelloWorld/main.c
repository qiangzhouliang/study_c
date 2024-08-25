/**
 1. 左大括号是另起一行还是在同一行，自己喜欢，但是要统一
 
 2. 当我们运行程序 就好将我们写的代码交给CPU去执行
    CPU从什么地方开始执行我的代码？
    
    当我们把一个程序交给CPU去执行的时候。CPU只会执行 main 函数当中的代码
    别的地方的代码是不会去执行的
 
 3. 所以一个标准的c程序中有且必须只能有1个main函数
 
 4. 所以 我们写的代码如果想要被 CPU 执行，就必须写在main函数中
 
 5. CPU在执行main函数的代码的时候
    是从上到下的一句一句执行的
    只有在上1局执行完毕之后才会执行下一句
 
 6. 在程序一开始的时候就好执行 main函数，所有main函数是程序的入口
    当main函数中的代码执行完毕之后，程序就会自动结束
    所以 main 函数也是程序的出口
 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
