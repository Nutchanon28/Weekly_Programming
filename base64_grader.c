// Base64 คืออะไร ช่วยพี่โบ๊ทด้วย!!
// Base64 คือ วิธีการเข้ารหัสข้อมูลรูปแบบหนึ่ง ที่จะเปลี่ยนข้อความ หรือข้อมูลต้นฉบับไปเป็นข้อความ
// หรือข้อมูลชุดใหม่ ที่ไม่สามารถอ่าน หรือรู้ว่าข้อมูลชุดนี้คืออะไร ซึ่งการเข้ารหัสชนิดนี้จะแทนที่ข้อมูลด้วยตัวอักษร 64 ตัว
// นั่นคือที่มาของ BASE64  ซึ่่งวิธีการถอดรหัสด้วยตนเองนั้นค่อนข้างจะซับซ้อน คิอ  จะทําย้อนกลับโดยให้นําข้อมูลมาแปลงเป็นฐานสอง 6 bit มาเรียงต่อกันก่อน
// แล้วนํามาจัดกลุ่ม กลุ่มละ 8 bit โดย bit สุดท้ายที่เหลือไม่ครบ 8 bit ให้ตัดทิ้ง หลังจากนั้นก็แปลงเลขฐานสอง 8 bit แต่ละชุดเป็นข้อมูล ASCII
// โดยในข้อนี้มีอยากให้น้องช่วยพี่โบ๊ทในการเขียนโปรแกรมเพื่อเข้ารหัส Base64 เพราะว่าพี่โบ๊ทไม่ไหวแล้วววววววว โดยน้องๆสามารถศึกษาเพิ่มเติมได้จาก link ที่พี่ใส่ไว้ใน
// เพิ่มเติมเลยครับ
// https://thiti.dev/blog/5979

#include <stdio.h>
#include <string.h>

int two_power(int n)
{
    return (n <= 0 ? 1 : 2 * two_power(n - 1));
}

int int_to_bit(int k)
{
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bit(k / 2)));
}

char bit_to_base64_char(char bit[7])
{
    int number = 0;
    for (int i = 5; i >= 0; i--)
    {
        if (bit[i] == '1')
        {
            number += two_power(5 - i);
        }
    }

    if (number >= 0 && number <= 25)
    {
        number += 65;
    }
    if (number >= 26 && number <= 51)
    {
        number += 71;
    }
    if (number >= 52 && number <= 61)
    {
        number -= 4;
    }
    if (number == 62)
    {
        number = 43;
    }
    if (number == 63)
    {
        number = 47;
    }

    char base64_char = (char)number;

    return base64_char;
}

int main()
{
    char str[100];
    scanf("%[^\n]s", &str);

    int bit[100];
    for (int i = 0; i < strlen(str); i++)
    {
        bit[i] = int_to_bit((int)str[i]);
    }

    char all_bit[1000];
    int last_all_bit_spot = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        char bit_char[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
        int changing_digit = 7;
        while (bit[i] != 0)
        {
            if (bit[i] % 10 == 1)
            {
                bit_char[changing_digit] = '1';
            }
            bit[i] /= 10;

            changing_digit--;
        }

        for (int i = 0; i < 8; i++)
        {
            all_bit[last_all_bit_spot] = bit_char[i];
            last_all_bit_spot++;
        }
    }

    int all_bit_length = last_all_bit_spot;
    int number_of_zero = 6 - (all_bit_length % 6);
    if (number_of_zero == 6)
    {
        number_of_zero = 0;
    }

    for (int i = 0; i < number_of_zero; i++)
    {
        all_bit[last_all_bit_spot] = '0';
        last_all_bit_spot++;
    }

    all_bit[last_all_bit_spot] = '\0';

    char bit_6[7] = {'0', '0', '0', '0', '0', '0', '\0'};
    for (int i = 0; i < strlen(all_bit); i++)
    {
        bit_6[i % 6] = all_bit[i];

        if (i % 6 == 5)
        {
            printf("%c", bit_to_base64_char(bit_6));
        }
    }

    for (int i = 1; i <= number_of_zero; i++)
    {
        if (i % 2 == 0)
        {
            printf("=");
        }     
    }

    return 0;
}