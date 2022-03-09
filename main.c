#include <stdio.h>

struct student {
    int age;
    char name[20];
} s1;

void add() {
    FILE *fw;
    fw = fopen("student.txt", "a");

    printf("Enter id: ");
    scanf("%d", &s1.age);
    printf("Enter name: ");
    scanf("%s", &s1.name);

    fwrite(&s1, sizeof(struct student), 1, fw);
    fclose(fw);
}

void read() {
    FILE *fr;
    fr = fopen("student.txt", "r");
    if (fr == NULL) {
        printf("Unable to open file");
    }
    while (fread(&s1, sizeof(s1), 1, fr)) {
        printf("\nThe id of student is %d and name is %s", s1.age, s1.name);
    }
    fclose(fr);
}


void update() {
    int id, id1, choice_ = 0;
    FILE *fr;
    FILE *fw;
    fr = fopen("student.txt", "r");
    fw = fopen("updated.txt", "w");
    printf("Enter id to update");
    scanf("%d", &id);
    while (fread(&s1, sizeof(s1), 1, fr)) {
        if (s1.age == id) {
            printf("what do you want to update 1.name 2.age : ");
            scanf("%d", &choice_);
            if (choice_ == 1) {
                printf("Enter new name: ");
                scanf("%s", &s1.name);
            } else if (choice_ == 2) {
                printf("Enter new age: ");
                scanf("%d", &s1.age);
            } else {
                printf("Invalid choice");
            }

            fwrite(&s1, sizeof(s1), 1, fw);
        } else {
            fwrite(&s1, sizeof(s1), 1, fw);
        }
    }
    fclose(fw);
    fclose(fr);
    remove("student.txt");
    rename("updated.txt", "student.txt");

}

int main() {
    int choice;
    printf("What operation you want to perform (1-add/2-read/3-exit/4-update)? ");
    scanf("%d", &choice);
    while (choice != 3) {
        switch (choice) {

            case 1:
                add();
                printf("\nEnter choice again: ");
                scanf("%d", &choice);
                break;
            case 2:
                read();
                printf("\nEnter choice again: ");
                scanf("%d", &choice);
                break;
            case 4:
                update();
                printf("\nEnter choice again: ");
                scanf("%d", &choice);
                break;
            case 3:
                return 1;
            default:
                printf("\nEnter choice");
                scanf("%d", &choice);

        }
    }

    return 0;
}