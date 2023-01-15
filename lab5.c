#include <stdio.h>

float rec(float x, float y)
{
    if (y == 1)
        return x;
    else if (y == 0)
        return 0;
    else
    {
        y -= 1;
        return x + rec(x, y);
    }
}

float cyc(float a, float b)
{
    if (a == 0 || b == 0)
        return 0;
    float S, d;

    S = 0;
    for (d = 1; d <= b; d++)
        S += a;

    return S;
}

int main()
{
    float a, b;

    printf("Enter a: ");
    scanf("%f", &a);

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Recursion  : %f\n", rec(a, b));
    printf("Cycle: %f\n", cyc(a, b));

    return 0;
}
