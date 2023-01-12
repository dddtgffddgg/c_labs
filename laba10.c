# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

void fill (int str, int stb, float ** A)
{

    int x, j; // индексы массива
    int t;

    for (x = 0; x < str; x ++)
        for (j = 0; j < stb; j ++)
            A [x][j] = rand () % 40 - 19;
}

void printdm (int str, int stb, float ** A)
{
    int x, j;

    printf ("\n");
    for (x = 0; x < str; x ++)
    {
        for (j = 0; j < stb; j ++)
            printf ("%7.2f ", A [x][j]);
        printf ("\n");
    }

    printf ("\n");
}

float searchmax (int str, int stb, float ** A)
{
    float max;

    int x, j;

    int max_x, max_j;

    max = A [0][0];
    max_x = 0;
    max_j = 0;
    for (x = 0; x < str; x ++)
        for (j = 0; j < stb; j ++)
            if (fabs (A [x][j]) > fabs (max))
            {
                max = A [x][j];
                max_x = x;
                max_j = j;
            }

    return A [max_x][max_j];
}

void delenie (int str, int stb, float ** A, float max)
{

    int x, j;

    for (x = 0; x < str; x ++)
        for (j = 0; j < stb; j ++)
        {
            if (x - j == 0)
                A [x][j] = A [x][j] / max;

            if (x - j == -1)
                A [x][j] = A [x][j] / max;

            if (x - j == 1)
                A [x][j] = A [x][j] / max;

            if (x + j == stb - 1)
            {
                if (x - j != 0 && x - j != -1 && x - j != 1)
                {
                    A [x][j] = A [x][j] / max;
                }
            }

            if ((x + j == stb - 2) && (x - j != -1) && (x - j != 1))
            {
                if (x - j != 0 && x - j != -1 && x - j != 1)
                {
                    A [x][j] = A [x][j] / max;
                }
            }
            if (x + j == stb && x - j != -1 && x - j != 1)
            {
                if (x - j != 0 && x - j != -1 && x - j != 1)
                {
                    A [x][j] = A [x][j] / max;
                }
            }
        }
}

int main ()
{
    int str;
    int stb;
    int x, j;

    printf ("Line: ");
    scanf ("%i", & str);
    fflush (stdin);

    printf ("Column: ");
    scanf ("%i", & stb);
    fflush (stdin);

    float ** A = (float **) malloc (str * sizeof (float *));

    if (A == NULL)
    {
        printf ("Memory allocation error!\n");
        exit (EXIT_FAILURE);
    }

    for (x = 0; x < str; x ++)
        A [x] = malloc (stb * sizeof (float));

    srand (time (NULL));
    fill (str, stb, A);

    printf ("\nthe matrix:");
    printdm (str, stb, A);

    float max;
    max = searchmax (str, stb, A);

    printf ("MAX: %7.2f\n", max);

    delenie (str, stb, A, max);

    printf ("\nresult:");
    printdm (str, stb, A);

    for (x = 0; x < str; x ++)
        free (A [x]);
    free (A);

    printf ("Memory Return OS\n");

    return 0;
}
