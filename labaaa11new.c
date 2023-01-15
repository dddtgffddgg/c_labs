#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPUTERS 100

struct Computer {
    char processor[50];
    int memory;
    int disk;
    char video_adapter[50];
    int cost;
    int purchase_year;
};

struct Computer computers[MAX_COMPUTERS];
int computer_count = 0;

// Функция добавления компьютера в список
void add_computer() {
    if (computer_count == MAX_COMPUTERS) {
        printf("Error: cannot add more computers (limit reached)\n");
        return;
    }

    struct Computer new_computer;
    printf("Enter processor: ");
    scanf("%s", new_computer.processor);
    printf("Enter memory (in GB): ");
    scanf("%d", &new_computer.memory);
    printf("Enter disk (in GB): ");
    scanf("%d", &new_computer.disk);
    printf("Enter video adapter: ");
    scanf("%s", new_computer.video_adapter);
    printf("Enter cost: ");
    scanf("%d", &new_computer.cost);
    printf("Enter purchase year: ");
    scanf("%d", &new_computer.purchase_year);

    computers[computer_count] = new_computer;
    computer_count++;
    printf("Computer added successfully\n");
}

// Функция удаления компьютера из списка
void remove_computer() {
    int id;
    printf("Enter the id of the computer to remove: ");
    scanf("%d", &id);

    if (id < 0 || id >= computer_count) {
        printf("Error: invalid id\n");
        return;
    }

    for (int i = id; i < computer_count - 1; i++) {
        computers[i] = computers[i-1];
    }
    computer_count--;
    printf("Computer removed successfully\n");
}

// Функция просмотра списка компьютеров
void view_computers() {
    for (int i = 0; i < computer_count; i++) {
        struct Computer c = computers[i];
        printf("%d. Processor: %s\n Memory: %dGB\n Disk: %dGB\n Video adapter: %s\n Cost: %d\n Purchase year: %d\n", 
            i+1, c.processor, c.memory, c.disk, c.video_adapter, c.cost, c.purchase_year);
    }
}

// Функция получения данных о компьютерах,
void get_outdated_computers() {
int current_year = 2022; // замените на текущий год
int update_after_years = 5; // количество лет, после которых нужно обновлять компьютер
printf("Outdated computers (need update after %d years of use):\n", update_after_years);
for (int i = 0; i < computer_count; i++) {
    struct Computer c = computers[i];
    if (current_year - c.purchase_year > update_after_years) {
        printf("%d. Processor: %s\n, Memory: %dGB\n, Disk: %dGB\n, Video adapter: %s\n, Cost: %d\n, Purchase year: %d\n",
            i+1, c.processor, c.memory, c.disk, c.video_adapter, c.cost, c.purchase_year);
    }
}
}

int main() {
while (1) {
printf("1. Add computer\n");
printf("2. Remove computer\n");
printf("3. View computers\n");
printf("4. Get outdated computers\n");
printf("5. Exit\n");
 int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) add_computer();
    else if (choice == 2) remove_computer();
    else if (choice == 3) view_computers();
    else if (choice == 4) get_outdated_computers();
    else if (choice == 5) break;
    else printf("Invalid choice\n");
}
return 0;
}

