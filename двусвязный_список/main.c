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

void print(Node * list);
void print_back(Node * list);
int is_empty(Node * list);
void init(Node * list);
void insert(Node * list, Node * t);
void insert_before(Node * list, Node * t);
void list_remove (Node * t);
Node * add_front(Node * list, Node * t);
Node * add_back(Node * list, Node * t);
Data pop_front (Node * list);
Data pop_back (Node * list);
Data delete(Node * t);
void clear(Node * list);

void init(Node * list) {
    list -> next = list;
    list -> prev = list;
}

void print(Node * list) {
    for (Node * p = list -> next; p != list; p = p -> next) {
        printf("Suranme: %s, Name: %s, Car number: %s, Date of birth: %s, Registration number: %lld", p -> data.surname, p -> data.name, p -> data.car_number, p -> data.date_of_birth, p -> data.registration_number);
        printf("\n");
    }
    printf("\n");
}


void print_back(Node * list) {
    for (Node * p = list -> prev; p != list; p = p -> prev) {
        printf("Suranme: %s, Name: %s, Car number: %s, Date of birth: %s, Registration number: %lld", p -> data.surname, p -> data.name, p -> data.car_number, p -> data.date_of_birth, p -> data.registration_number);
        printf("\n");
    }
    printf("\n");
}

void insert(Node * p, Node * t) {
    Node * q = p -> next;  // &b
    t -> prev = p;
    t -> next = q;
    p -> next = t;
    q -> prev = t;
}

void insert_before(Node * q, Node * t) {
    insert(q -> prev, t);
}

int main() {
    Node z, a = {{"Pogosyan", "Samvel", "A001UE", "11-01-2006", 435368592759678}};
    Node b = {{"Pogosyan", "Nadya", "A001UE", "11-01-2007", 319283746587582}};
    Node c = {{"Melnikov", "Egor", "A001UE", "11-01-2008", 456283746589182}};
    Node u = {{"Kuzin", "Gosha", "B002CA", "23-11-2005", 123456789087635}};
    Node * list = &z;
    // z.next = &a;    z.prev = &c;
    // a.next = &b;    a.prev = &z;
    // b.next = &c;    b.prev = &a;
    // c.next = &z;    c.prev = &b;

    init(list);

    insert(list, &c);
    print(list);

    insert(list, &b);

    print(list);
    print_back(list);

    insert(list, &a);

    print(list);
    print_back(list);

    insert(&a, &u);
    print(list);
    print_back(list);

    return 0;
}