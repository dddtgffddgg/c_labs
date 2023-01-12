#include <stdio.h>
int main()
{
    float x,y,z;
    printf("Введите x ->");
    scanf("%f", &x);
    printf("Введите y ->");
    scanf("%f", &y);
    printf("Введите z ->");
    scanf("%f", &z);
    float max, else1, else2;
    if ( x >= y && x >= z)
    {
        max = x;
        else1 = y;
        else2 = z;
    }
    if ( y >= x && y >= z)
    {
        max = y; 
        else1 = x;
        else2 = z;
    }
    if ( z >= x && z >= y)
    {
        max = z;
        else1 = x;
        else2 = y;

    }
    float sum = else1 + else2;
    float g = sum - max;
    if (max > sum) 
    {
        printf("%lf", max);
    }
    else
    printf("%lf", g);
  return 0;
}
