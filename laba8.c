#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main ()
{
int c;

    while (1)
{
    c = getch();
    if (c == 27)
    continue;
    if (c == 0)
{
    c = getch ();
    if (c >= 59 && c <= 65 || c == 67 || c == 68)
{
    continue;
}
    if (c == 66)
    break;
}
    if (c == 224)
{
    c = getch ();
    if (c == 133 || c == 134)
{
    continue;
}
    if (c >= 80 && c <= 83)
{
    continue;
}
    if (c >= 71 && c <= 73 || c == 75 || c == 77 || c == 79)
{
    continue;
}
}
    printf ("%c", toupper (c));
}
    return 0;
}
