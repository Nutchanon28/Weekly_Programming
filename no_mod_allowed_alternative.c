// จงเขียนโปรแกรมเพื่อรับจำนวนเต็ม 1 จำนวน แล้วแสดงผลว่าจำนวนนั้นเป็นจำนวนคู่ หรือจำนวนคี่ โดยไม่ใช้ % (Modulo) (Level 3)

#include <stdio.h>
#include <string.h>

int isEven(char number[100])
{
    switch ((int)number[strlen(number) - 1] - 48)
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
        return 1;
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        return 0;
    default:
        break;
    }

    return -1;
}

int main()
{
    char number[100];
    scanf("%[0-cd9-]s", number);

    if (isEven(number))
    {
        printf("%s is even", number);
        return 0;
    }

    printf("%s is odd", number);
    return 0;
}