//
//  main.c
//  06-排序算法
//
//  Created by swan on 2024/8/11.
//

#include <stdio.h>

///
/// 从大到小排序
void selectSort(int arr[], int len){
    // 数组中有len个数据，要比较len-1轮
    for (int i = 0; i < len - 1; i++) { // 外层控制循环轮数
        for (int j = i+1; j < len; j++) {
            ///每一轮做的事情
            ///拿下标为i的元素 和后面的所有的元素进行比较
            ///arr[i] i+1  len-1
            ///将后面的所有的元素遍历出来
        
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

///
/// 冒泡 从大到小排序
void maoPaoSort(int arr[], int len){
    // 数组中有len个数据，要比较len-1轮
    for (int i = 0; i < len - 1; i++) { // 外层控制循环轮数
        /// 每一轮比较多少次
        /// 第i轮比较 len - 1 - i
        /// 写1个内层循环。循环 len - 1 - i 次
        for (int j = 0; j < len - 1 - i; j++) {
        
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

///
/// 二分 找出 key 在这个数组中的下标
int erFenSort(int arr[], int len, int key){
    int min = 0;
    int max = len -1;
    int mid = len / 2;
    
    while (key != arr[mid] && max != -1) {
        // 判断大小关系
        if(arr[mid] > key){
            // 说明在左边
            max = mid - 1;
        } else {
            // 说明在右边
            min = mid + 1;
        }
        mid = (min + max) / 2;
    }
    if (max == -1) {
        return -1;
    }
    return mid;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {12,23,45,6,78,989,9};
//    selectSort(arr, sizeof(arr)/sizeof(arr[0]));
//    maoPaoSort(arr, sizeof(arr)/sizeof(arr[0]));
//    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
//        printf("%d\t",arr[i]);
//    }
    
    int arr1[] = {12,23,45,66,78,989,999};
    int index = erFenSort(arr1, sizeof(arr1)/sizeof(arr1[0]), 23);
    printf("下标为：%d\t",index);
    
    printf("Hello, World!\n");
    return 0;
}
