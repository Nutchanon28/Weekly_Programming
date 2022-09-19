//  จงเขียนฟังก์ชั่นเพื่อหาตัวเลขที่มีค่ามากที่สุดจากอินพุทตัวเลข 2 ตัว (Level 3)
//  จงใช้ฟังก์ชั่นในข้อ 41 เพื่อหาตัวเลขที่มากที่สุดจากอินพุทตัวเลข 5 ตัว (Level 3)

#include <stdio.h>

int max(int, int);

int main()
{
    int numbers[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("%d", max(numbers[0], max(max(numbers[1], numbers[2]), max(numbers[3], numbers[4]))));
    return 0;
}

int max(int number1, int number2)
{
    return number1 > number2 ? number1 : number2;
}