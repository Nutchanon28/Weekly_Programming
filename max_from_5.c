//  จงเขียนฟังก์ชั่นเพื่อหาตัวเลขที่มีค่ามากที่สุดจากอินพุทตัวเลข 2 ตัว (Level 3)
//  จงใช้ฟังก์ชั่นในข้อ 41 เพื่อหาตัวเลขที่มากที่สุดจากอินพุทตัวเลข 5 ตัว (Level 3)

#include <stdio.h>

int max(int number1, int number2)
{
    return number1 > number2 ? number1 : number2;
}

int main()
{
    int number, maximum_number;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &number);
        maximum_number = i == 0 ? number : max(maximum_number, number);
    }

    printf("%d", maximum_number);
    return 0;
}