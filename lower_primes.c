// จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงค่าจำนวนเฉพาะที่น้อยกว่าตัวเลขตัวนั้นทั้งหมด (Level 3)
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//typedef enum { false, true } bool;

bool isPrime(int number)
{
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int inputNumber;
    scanf("%d", &inputNumber);

    if (inputNumber > 2)
    {
        printf("2 ");
    }
    

    for (int i = 3; i < inputNumber; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        } 
    }
    
    return 0;
}