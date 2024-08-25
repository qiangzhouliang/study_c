/*
 1）．指针当然可以作为函数的返回值
     但是，不能返回局部变量的地址．
     换句话说：你返回的指针指向的变量一定要保证在函数结束之后，那个空间没有被回收还存在。
     
 2）．如果你就是要返回1个指针，那么你就要保证这个指针指向的空间在函数结束以后仍然存在。
     那么这个时候，就可以将空间申请在堆区，然后返回堆区的地址.
     
     一定要记得，调用者使用了完之后，记得free

 3.注意，
     1）．可以返回局部变量的值。但是不能返回局部变量的地址，
     2）．如果你非要返回指针，那么就应该把这个空间申请在堆区.
 */
#include <stdio.h>
#include <stdlib.h>

int *test(){
    int *arr = calloc(3, sizeof(int));
    *arr = 10;
    *(arr+1) = 20;
    *(arr+2) = 30;
    return arr;
}

int main(int argc, const char * argv[]) {
    int *arr = test();
    for (int i = 0; i < 3; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
