#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print(Node * list);  // +
void print_back(Node * list);  // +
int is_empty(Node * list);  // +
void init(Node * list); // +
void insert(Node * list, Node * t); // +
void insert_before(Node * list, Node * t); // +
void list_remove (Node * t);  // +
Node * add_front(Node * list, Data d); // +
Node * add_back(Node * list, Data d); // +
Data list_pop_front (Node * list);  // +
Data list_pop_back (Node * list);  // +
Data list_delete(Node * t);  // +
void clear(Node * list);  // +

void init(Node * list) {
    list -> next = list;
    list -> prev = list;
}

int is_empty(Node * list) {
    return list -> prev == list && list -> next == list;
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

void list_remove (Node * t) {
    Node * p = t -> prev;  // 1
    Node * q = t -> next;  // 2
    p -> next = q;
    q -> prev = p;

}

Node * add_front(Node * list, Data d) {
    Node * p = malloc(sizeof(Node));
    p -> data = d;
    insert(list, p);
    return p;
}

Node * add_back(Node * list, Data d) {
    return add_front(list -> prev, d);
}

Data list_delete(Node * t) {
    list_remove(t);
    Data d = t -> data;
    free(t);
    return d;
}

Data list_pop_front (Node * list) {
    return list_delete(list -> next);
}
Data list_pop_back (Node * list) {
    return list_delete(list -> prev);
}

void clear(Node * list) {
    while (!is_empty(list)) {
        list_pop_front(list); // list_pop_back(list)
    }
}

void print_it(Data d, void * arg) {
    fprintf((FILE *)arg, "Surname: %s, Name: %s, Car number: %s, Date of birth: %s, Registration numbers: %lld\n", d.surname, d.name, d.car_number, d.date_of_birth, d.registration_number);
    fprintf((FILE *)arg, "\n");
}

void foreach(Node * list, void (*func)(Data d, void * a), void * arg) {
    for (Node * p = list -> next; p != list; p = p -> next) {
        func(p -> data, arg);
    }
}

void save(Node * list, FILE * fout) {
    foreach(list, print_it, fout);
    printf("\n");
}

void * filtered_node(Node * list) {
    Node * list_tmp = list; 
    for (Node * p = list_tmp -> next; p != list_tmp; p = p -> next) {
        char f_l = (p -> data.surname)[0];
        if (f_l == 'S') {
            list_remove(p);
        }
    }
    return list_tmp;
}

// void load(Node * list, FILE * f) {
//     f = fopen("save.txt", "r");
//     Data data_res[3];
//     for (int i = 0; i < 3; i++) {
//     }
// }

void test_foreach() {
    Node z;
    Node * list = &z;

    Node * list_read = &z;

    Data test_data1[] = {
        {"Pogosyan", "Samvel", "A001UE", "11-01-2006", 435368592759678},
        {"Smirnov", "Evgenie", "S002EV", "11-01-2007", 319283746587582},
        {"Melnikov", "Egor", "M003OV", "11-01-2008", 456283746589182},
    };
    init(list);
    init(list_read);
    for (size_t i = 0; i < sizeof(test_data1) / sizeof(test_data1[0]); i++) {
        add_front(list, test_data1[i]);
    }
    print(list);
    FILE * f = fopen("save.txt", "w");
    FILE * fs = fopen("filtered_save.txt", "w");
    save(list, stdin);
    save(list, stdout);
    save(list, f);
    load(list_read, f);

    fclose(f);

    Node * new_filtered_list = filtered_node(list);

    save(new_filtered_list, fs);

    fclose(fs);
    clear(list);
}

void test0() {
    Node z, a = {{"Pogosyan", "Samvel", "A001UE", "11-01-2006", 435368592759678}};
    Node b = {{"Smirnov", "Evgenie", "S002EV", "11-01-2007", 319283746587582}};
    Node c = {{"Melnikov", "Egor", "M003OV", "11-01-2008", 456283746589182}};
    Node u = {{"Kuzin", "Gosha", "K004GA", "23-11-2005", 567892346178342}};
    Node w = {{"Sokun", "Misha", "C005AC", "25-11-2002", 123456789087635}};
    Node * list = &z;
    // z.next = &a;    z.prev = &c;
    // a.next = &b;    a.prev = &z;
    // b.next = &c;    b.prev = &a;
    // c.next = &z;    c.prev = &b;

    init(list);
    printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

    insert(list, &c);
    print(list);
    printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

    insert(list, &b);

    print(list);
    print_back(list);

    insert(list, &a);

    print(list);
    print_back(list);

    insert(&a, &u);
    print(list);
    print_back(list);

    insert_before(&u, &w);
    print(list);
    print_back(list);

    list_remove(&u);
    print(list);
    print_back(list);

    list_remove(&w);
    print(list);
    print_back(list);
}

void test_alloc() {
    Node z;
    Node * list = &z;
    Data test_data1[] = {
        {"Pogosyan", "Samvel", "A001UE", "11-01-2006", 435368592759678},
        {"Smirnov", "Evgenie", "S002EV", "11-01-2007", 319283746587582},
        {"Melnikov", "Egor", "M003OV", "11-01-2008", 456283746589182}
    };
    Data test_data2[] = {
        {"Kuzin", "Gosha", "K004GA", "23-11-2005", 567892346178342},
        {"Sokun", "Misha", "C005AC", "25-11-2002", 123456789087635}
    };

    init(list);
    printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

    Node * t;
    for (size_t i = 0; i < sizeof(test_data1)/sizeof(test_data1[0]); i++) {
        t = add_front(list, test_data1[i]);
        print(list);
        printf("Pushed: Registration number: %lld\n", t -> data.registration_number);
    }
    for (size_t i = 0; i < sizeof(test_data2)/sizeof(test_data2[0]); i++) {
        t = add_back(list, test_data2[i]);
        print(list);
        printf("Pushed back: Registration number: %lld\n", t -> data.registration_number);
    }

    printf("Empty %s\n", is_empty(list) ? "YES" : "NO");

    t = list -> next -> next;

    Data res;
    res = list_delete(t);
    print(list);
    printf("Deleted: %lld\n", res.registration_number);

    res = list_pop_front(list);
    print(list);
    printf("poped front: %lld\n", res.registration_number);

    res = list_pop_back(list);
    print(list);
    printf("poped back: %lld\n", res.registration_number);

    clear(list);

    printf("Empty %s\n", is_empty(list) ? "YES" : "NO");
}

int main() {
    // test0()
    // test_alloc();
    test_foreach();

    return 0;
}