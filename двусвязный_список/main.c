#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char surname[20];
    char name[20];
    char car_number[10];
    char date_of_birth[10];
    long long int registration_number;
} Data;

typedef struct Node {
    Data data;
    struct Node * next;
    struct Node * prev;
} Node;

void print (Node * list);
void print (Node * list) {
    for (Node * p = list -> next; p != list; p = p -> next) {
        printf("Suranme: %s, Name: %s, Car number: %s, Date of birth: %s, Registration number: %lld", p -> data.surname, p -> data.name, p -> data.car_number, p -> data.date_of_birth, p -> data.registration_number);
        printf("\n");
    }
}

int main() {
    Node z, a = {{"Pogosyan", "Samvel", "A001UE", "11-01-2006", 435368592759678}};
    Node b = {{"Pogosyan", "Nadya", "A001UE", "11-01-2007", 319283746587582}};
    Node c = {{"Melnikov", "Egor", "A001UE", "11-01-2008", 456283746589182}};
    Node * list = &z;
    z.next = &a;    z.prev = &c;
    a.next = &b;    a.prev = &z;
    b.next = &c;    b.prev = &a;
    c.next = &z;    c.prev = &b;

    print(list);
    printf("\n");

    return 0;
}