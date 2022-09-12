// by Bourbxn
// เพชรในตม
// เพชรในตมที่ไม่ใช่สำนวนอะดิ แย่แล้ว!!!

// Specification
// Input
// บรรทัดที่ 1: ตัวเลขจำนวนเต็ม หากน้อยกว่า 3 ให้แสดง "ERROR!"
// Output
// เพชรในตมมมมม~
// Sample Case
// Case 1
// 3

// -*-
// *-*
// -*-

// Case 2
// 4

// -*-
// *-*
// *-*
// -*-

// Case 3
// 5

// --*--
// -*-*-
// *---*
// -*-*-
// --*--

// this is an attempt without using middle. big mistake
#include <stdio.h>

int main()
{
    int number;
    int isEven;
    scanf("%d", &number);

    if (number < 3)
    {
        printf("ERROR!");
        return 0;
    }
    

    isEven = number % 2 == 0;
    if (isEven)
        number++;

    // change array length for gigantic diamonds
    char bottom_half[10000];
    char top_half[10000];

    int row = isEven ? number / 2 : number / 2 + 1;
    int column = isEven ? number - 2 : number;
    int margin_start = 0, margin_end = column - 1;
    int column_index = 0, bottom_half_index = 0, top_half_index = 0;

    for (int i = 0; i < column * row; i++)
    {
        if (column_index == margin_start || column_index == margin_end)
            bottom_half[bottom_half_index] = '*';
        else
            bottom_half[bottom_half_index] = '-';

        column_index++;
        bottom_half_index++;

        if ((i + 1) % column == 0)
        {
            margin_start++;
            margin_end--;

            bottom_half[bottom_half_index] = '\n';
            bottom_half_index++;

            column_index = 0;
        }
    }
    bottom_half[bottom_half_index] = '\0';

    margin_start--;
    margin_end++;

    for (int i = isEven ? 0 : column; i < column * row; i++)
    {
        if (column_index == margin_start || column_index == margin_end)
            top_half[top_half_index] = '*';
        else
            top_half[top_half_index] = '-';

        column_index++;
        top_half_index++;

        if ((i + 1) % column == 0)
        {
            margin_start++;
            margin_end--;

            top_half[top_half_index] = '\n';
            top_half_index++;

            column_index = 0;
        }
    }
    top_half[top_half_index] = '\0';

    printf("%s", top_half);
    printf("%s", bottom_half);

    return 0;
}