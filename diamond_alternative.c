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

int create_triangle(int, int, char *, int *, int *, int);

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

    create_triangle(column, row, bottom_half, &margin_start, &margin_end, 1);

    margin_start--;
    margin_end++;

    create_triangle(column, row, top_half, &margin_start, &margin_end, isEven);

    printf("%s", top_half);
    printf("%s", bottom_half);

    return 0;
}

int create_triangle(int column, int row, char *str, int *margin_start, int *margin_end, int required_first_line)
{
    int column_index = 0, array_index = 0;

    for (int i = required_first_line ? 0 : column; i < column * row; i++)
    {
        if (column_index == *margin_start || column_index == *margin_end)
        {
            str[array_index] = '*';
        }
        else
        {
            str[array_index] = '-';
        }

        column_index++;
        array_index++;

        if (column_index % column == 0)
        {
            // this doesn't work as intented
            // *margin_start++;
            // *margin_end--;

            *margin_start = *margin_start + 1;
            *margin_end = *margin_end - 1;

            str[array_index] = '\n';
            array_index++;

            column_index = 0;
        }
    }
    str[array_index] = '\0';

    return 0;
}
