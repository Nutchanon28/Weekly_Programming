// จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงค่าจำนวนเฉพาะที่น้อยกว่าตัวเลขตัวนั้นทั้งหมด (Level 3)
#include <stdio.h>

// int mod7(int x)
// {
//   while (x > 7) x = (x&7) + (x>>3);
//   return (x == 7)?0:x;
// }

int main()
{
    int inputNumber;
    scanf("%d", &inputNumber);

    int isPrime;
    for (int i = 2; i < inputNumber; i++)
    {
        isPrime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
        {
            printf("%d ", i);
        }
    }
    return 0;
}