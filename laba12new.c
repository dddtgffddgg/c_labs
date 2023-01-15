#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPUTERS 100

struct Computer {
    char processor[50];
    int memory;
    int storage;
    char video_adapter[50];
    float cost;
    int purchase_year;
} computers[MAX_COMPUTERS];
int computer_count = 0;

void add_computer(struct Computer new_computer) {
    if (computer_count < MAX_COMPUTERS) {
        computers[computer_count++] = new_computer;
    }
}

void delete_computer(int index) {
    if (index >= 0 && index < computer_count) {
        for (int i = index; i < computer_count - 1; i++) {
            computers[i] = computers[i+1];
            }
        computer_count--;
    }
}

void print_computer(struct Computer c) {
    printf("Processor: %s\n", c.processor);
    printf("Memory: %d GB\n", c.memory);
    printf("Storage: %d GB\n", c.storage);
    printf("Video adapter: %s\n", c.video_adapter);
    printf("Cost:%.2f\n", c.cost);
    printf("Purchase year: %d\n", c.purchase_year);
}

void print_computers() {
    for (int i = 0; i < computer_count; i++) {
        printf("Computer %d:\n", i+1);
        print_computer(computers[i]);
        printf("\n");
    }
}

void print_outdated_computers(int current_year) {
    for (int i = 0; i < computer_count; i++) {
        if (current_year - computers[i].purchase_year > 5) {
            printf("Outdated computer %d:\n", i+1);
            print_computer(computers[i]);
            printf("\n");
        }
    }
}

void save_computers() {
    FILE *fp = fopen("computers.dat", "w");
    if (fp != NULL) {
        fwrite(&computer_count, sizeof(int), 1, fp);
        fwrite(computers, sizeof(struct Computer), computer_count, fp);
        fclose(fp);
    } else {
        printf("Failed to save computers.\n");
    }
}

void load_computers() {
    FILE *fp = fopen("computers.dat", "r");
    if (fp != NULL) {
        fread(&computer_count, sizeof(int), 1, fp);
        fread(computers, sizeof(struct Computer), computer_count, fp);
        fclose(fp);
    } else {
        printf("Failed to load computers.\n");
    }
}

int main() {
    int choice;
    int current_year = 2023;
    load_computers();
    while (1) {
        printf("1. Add computer\n");
        printf("2. Delete computer\n");
        printf("3. Print all computers\n");
        printf("4. Print outdated computers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            struct Computer new_computer;
            printf("Enter processor: ");
            scanf("%s", new_computer.processor);
            printf("Enter memory (in GB): ");
            scanf("%d", &new_computer.memory);
            printf("Enter storage (in GB): ");
            scanf("%d", &new_computer.storage);
            printf("Enter video adapter: ");
            scanf("%s", new_computer.video_adapter);
            printf("Enter cost: ");
            scanf("%f", &new_computer.cost);
            printf("Enter purchase year: ");
            scanf("%d", &new_computer.purchase_year);
            add_computer(new_computer);
        } else if (choice == 2) {
            int index;
            printf("Enter index of computer to delete: ");
            scanf("%d", &index);
            delete_computer(index - 1);
        } else if (choice == 3) {
            print_computers();
        } else if (choice == 4) {
            print_outdated_computers(current_year);
        } else if (choice == 5) {
            save_computers();
            break;
        }
    }
    return 0;
}
