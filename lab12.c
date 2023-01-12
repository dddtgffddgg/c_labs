# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

# define N 100

struct COMP
{
    int flag; // 0 - запись удалена; 1 - запись существует
    int ID; // идентификатор записи (уникальный номер записи)
    char cpu [80]; // процессор
    int ram; // объём оперативной памяти
    int hdd; // объём жёсткого диска
    char gpu [80]; // видеоадаптер
    int cost; // стоимость
    int year; // год закупки
};


void prob ()
{
    printf ("%13c", ' ');
}


int index_free (struct COMP A [])
{

    int i;

    for (i = 0; i < N; i ++)
        if (A [i].flag == 0)
            return i;
}

int spisok_empty (struct COMP A [])
{

    int flag;

    int i;

    flag = 0;
    for (i = 0; i < N; i ++)
        if (A [i].flag != 0)
            flag = 1;

    return flag;
}

void init_sp (struct COMP A [])
{
    int i;

    for (i = 0; i < N; i ++)
    {
        A [i].flag = 0;
        A [i].ID = i + 1;
    }
}
void add_L (struct COMP A [])
{
    int index;

    index = index_free (A);

    int ID;
    ID = A [index].ID;
    struct COMP comp;
    int L;

    printf ("\n  Fill in the data:\n");

    printf (" processor: ");
    fgets (comp.cpu, 80, stdin);
    L = strlen (comp.cpu);
    comp.cpu [L - 1] = '\0';
    fflush (stdin);

    printf (" he amount of RAM (GB): ");
    scanf ("%i", & comp.ram);
    fflush (stdin);

    printf (" Hard disk capacity (TB): ");
    scanf ("%i", & comp.hdd);
    fflush (stdin);

    printf (" videoadapter: ");
    fgets (comp.gpu, 80, stdin);
    L = strlen (comp.gpu);
    comp.gpu [L - 1] = '\0';
    fflush (stdin);

    printf (" Cost (RUB): ");
    scanf ("%i", & comp.cost);
    fflush (stdin);

    printf (" Year of purchase: ");
    scanf ("%i", & comp.year);
    fflush (stdin);

    comp.flag = 1;

    comp.ID = ID;

    A [index] = comp;

    printf ("\n Data recorded ");
}


void del_z (struct COMP A [], int ID)
{
    struct COMP comp;

    if (A [ID - 1].flag == 0)
        printf (" This entry ,skf elfktyf hfymit ");
    else
    {
        A [ID - 1].flag = 0;
        printf (" Record deleted ");
    }
}

void print_sp (struct COMP A [])
{
    if (spisok_empty (A) == 0)
    {
        printf ("   List pust ");
        return;
    }

    printf (" List pc:\n");
    printf ("%3s %6s %5s %5s %5s %7s %5s\n",
            "ID", "CPU", "RAM", "НDD", "GPU", "PRICE", "YEAR");

    int i;
    struct COMP comp;

    for (i = 0; i < N; i ++)
    {
        comp = A [i];

        if (comp.flag != 0)
            printf ("%3i. %5s %5i %5i %5s %7i %5i\n",
                    comp.ID, comp.cpu, comp.ram, comp.hdd,
                    comp.gpu, comp.cost, comp.year);
    }

    printf ("\n");
}


void update_sp (struct COMP A [])
{
    system ("cls");

    print_sp (A);

    if (spisok_empty (A) == 0)
        return;

    int tek_year;

    printf (" Current year: ");
    scanf ("%i", & tek_year);
    fflush (stdin);

    int let;

    printf (" The update will be required after: ");
    scanf ("%i", & let);
    fflush (stdin);

    printf ("\n   List of required:\n");
    printf ("%3s %6s %5s %5s %5s %7s %5s\n",
            "ID", "CPU", "RAM", "НDD", "GPU", "PRICE", "YEAR");

    struct COMP comp;
    int i;

    for (i = 0; i < N; i ++)
    {
        comp = A [i];

        if (tek_year - comp.year >= let && comp.flag != 0)
        {
            printf ("%3i. %5s %5i %5i %5s %7i %5i\n",
                    comp.ID, comp.cpu, comp.ram, comp.hdd,
                    comp.gpu, comp.cost, comp.year);
        }
    }
}


void write_file (struct COMP A [])
{
    FILE * F;

    struct COMP comp;

    int i;

    F = fopen ("data.bin", "wb");
    if (F == NULL)
        printf ("The record file cannot be created.... \n");

    for (i = 0; i < N; i ++)
    {
        comp = A [i];
        fwrite (& comp, sizeof (comp), 1, F);
    }

    fclose (F);
}

void poisk_file (struct COMP A [])
{

    FILE * F;
    int i;

    struct COMP comp;

    F = fopen ("data.bin", "rb");

    if (F == NULL)
        return;
    else
    {
        printf (" File detected.\n");

        for (i = 0; i < N; i ++)
        {
            fread (& comp, sizeof (comp), 1, F);
            A [i] = comp;
        }
    }

    printf (" The list of entries is read.\n");
    printf (" press Enter ");
}


int main ()
{
    struct COMP A [N];

    init_sp (A);

    int ID;

    poisk_file (A);

    int n_menu = 100;
    while (n_menu != 0)
    {
        system ("cls");

        printf ("\n\n\n\n\n");

        prob ();
        printf ("List of PC records\n\n");

        prob ();
        printf ("menu:\n\n");

        prob ();
        printf ("1 - Add an entry to the top of the list\n");

        prob ();
        printf ("2 - Delete an entry\n");

        prob ();
        printf ("3 - Viewing the list\n");

        prob ();
        printf ("4 - Data about PCs requiring updates\n\n");

        prob ();
        printf ("0 - Saving. Completion of work\n\n");

        prob ();
        printf ("Menu number: ");

        scanf ("%i", & n_menu);
        fflush (stdin);

        switch (n_menu)
        {
            case 0 :
                write_file (A);
                n_menu = 0;
                break;

            case 1 :
                system ("cls");
                add_L (A);
                break;

            case 2 :
                system ("cls");

                print_sp (A);

                if (spisok_empty (A) != 0)
                {
                    printf (" Enter the ID of the record you want to delete: ");
                    scanf ("%i", & ID);
                    fflush (stdin);

                    del_z (A, ID);
                }
                break;

            case 3 :
                system ("cls");
                print_sp (A);
                break;

            case 4 :
                update_sp (A);
                break;

            default :
            {
                prob ();
                printf ("Error: There is no such thing in the menu ");
            }
        }
    }

    printf ("\n");
    prob ();
    printf ("Completion of the program....  ");

    return 0;
}
