//
//  main.c
//  07-指针作为函数参数
//
//  Created by swan on 2024/8/20.
//

#include <stdio.h>

///
/// 返回1个整型数组中的最大值和最小值
void getMaxAndMin(int arr[], int len, int *pMax, int *pMin){
    int max = INT32_MIN;
    int min = INT32_MAX;
    
    for (int i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    //max和min的值都需要返回给调用者.
    //思路是这样。
    //让调用者传递两个变量的地址给我。
    //让调用者自己先准备两个变量。然后将这两个变量的地址给我，
    //图数内部是不是可以通过指针 直接 修改 调用者的变量的值.
    *pMax = max;
    *pMin = min;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {123,23,3,4444,3,4,54,6656,6,1};
    int max = 0;
    int min = 0;
    getMaxAndMin(arr, sizeof(arr)/sizeof(arr[0]), &max, &min);
    printf("max = %d\n min = %d\n",max,min);
    return 0;
}
