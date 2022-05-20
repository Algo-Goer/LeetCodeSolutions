// C 简单选择排序
#include <stdio.h>
#include <stdlib.h>
void swap(int *p1, int *p2)
{
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
    // 不借助第三变量也可以 a = a ^ b; b = a ^ b; a = a ^ b; 但是增加程序难以辨析程度，借助t交换即可
}
// 打印数组
void printArray(const int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}
void selectionSort(int *array, int size)
{
    // [19] [54] [4] [30] ...
    //  ?    ?
    // 要获得最小元素的下标才能交货
    int minv, min;                     // 存最小值和下标
    for (int i = 0; i < size - 1; ++i) // size-1: 最后一个剩下的元素无需比较
    {
        minv = array[i];
        min = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < minv)
            {
                minv = array[j];
                min = j;
            }
        }
        // 把找到的最小跟i这个位置交换，也有可能还是i，直接换可以，也可以写一句
        if (min - i)                      // 如果min - i不是0
            swap(&array[i], &array[min]); // C 交换只能用指针
        printf("%d: ", i);                // 把i换到位了
        printArray(array, size);
    }
}
int main()
{
    int array[6] = {19, 54, 4, 30, 70, 2};
    printArray(array, 6);
    selectionSort(array, 6); // 数组一共六个元素排序   // 或selectionSort(array, 0, 6);  排序0~5
    printArray(array, 6);
    return 0;
}