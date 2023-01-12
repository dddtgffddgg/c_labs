# include <stdio.h>

int rec (int x, int y)
{
    if (y == 1)
        return x;
    else
    {
        y -= 1;
        return x + rec (x, y);
    }
}

int cyc (int a, int b)
{
    int S, d;

    S = 0;
    for (d = 1; d <= b; d ++)
        S += a;

    return S;
}

int main ()
{
    int a, b;

    printf ("Enter a: ");
    scanf ("%d", & a);

    printf ("Enter b: ");
    scanf ("%d", & b);

    printf ("Recursion  : %i\n", rec (a, b));
    printf ("Cycle: %i\n", cyc (a, b));

    return 0;
}
