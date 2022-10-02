// จงเขียนโปรแกรมเพื่อรับจำนวนเต็ม 1 จำนวน แล้วแสดงผลว่าจำนวนนั้นเป็นจำนวนคู่ หรือจำนวนคี่ โดยไม่ใช้ % (Modulo) (Level 3)

#include <stdio.h>

int isOdd(float number)
{
    return number / 2 - (int)(number / 2) != 0;
}

int main()
{
    float number;
    scanf("%f", &number);

    if (isOdd(number))
    {
        printf("%.0f is odd", number);
        return 0;
    }

    printf("%.0f is even", number);
    return 0;
}