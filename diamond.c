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

#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    scanf("%d", &number);
    int isEven;

    if (number < 3)
    {
        printf("ERROR!");
        return 0;
    }

    if (number % 2 == 0)
    {
        isEven = 1;
        number -= 1;
    }

    for (int i = 1; i <= number; i++)
    {
        int middle = (number + 1) / 2;
        int distance_from_middle = 0;
        for (int j = 1; j <= number; j++)
        {

            if (i >= middle)
            {
                distance_from_middle = fabs(number - i);
            }
            if (i < middle)
            {
                distance_from_middle = fabs(1 - i);
            }

            if (j == middle - distance_from_middle || j == middle + distance_from_middle)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }

        if (i == middle && isEven == 1)
        {
            printf("\n");
            for (int k = 1; k <= number; k++)
            {
                if (k == 1 || k == number)
                {
                    printf("*");
                }else{
                    printf("-");
                }

            }
        }
        printf("\n");
    }

    return 0;
}