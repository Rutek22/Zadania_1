#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node * next;
} node_t;


void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
    printf("\n");
}


void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}


// Zadanie 1
void add_first(node_t ** head, int val) {
    node_t * new_node = (node_t *) malloc(sizeof(node_t));

    if (new_node == NULL) {
        printf("Nie udalo sie zaalokowac pamieci dla nowego wezla.\n");
        return;
    }

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}


// Zadanie 2
void pop(node_t ** head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie mozna usunac elementu.\n");
        return;
    }

    node_t * temp = *head;
    *head = (*head)->next;
    free(temp);
}


// Zadanie 3
void remove_last(node_t ** head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie mozna usunac ostatniego elementu.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node_t * current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}


// Zadanie 4
void remove_by_index(node_t ** head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie mozna usunac elementu.\n");
        return;
    }

    if (index == 0) {
        node_t * temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node_t * current = *head;
    int i = 0;
    while (i < index - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    if (current->next == NULL) {
        printf("Podany indeks wykracza poza zakres listy.\n");
        return;
    }

    node_t * temp = current->next;
    current->next = current->next->next;
    free(temp);
}


// Zadanie 5
void remove_by_value(node_t ** head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie mozna usunac elementu.\n");
        return;
    }

    if ((*head)->val == value) {
        node_t * temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node_t * current = *head;
    while (current->next != NULL && current->next->val != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element o podanej wartosci nie zostal znaleziony.\n");
        return;
    }

    node_t * temp = current->next;
    current->next = current->next->next;
    free(temp);
}


// Zadaeni 6
void insert_at_index(node_t ** head, int index, int value) {
    if (index < 0) {
        printf("Podany indeks jest nieprawidlowy.\n");
        return;
    }

    if (index == 0) {
        node_t * new_node = (node_t *)malloc(sizeof(node_t));
        if (new_node == NULL) {
            printf("Nie udalo sie zaalokowac pamieci dla nowego wezla.\n");
            return;
        }
        new_node->val = value;
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t * current = *head;
    for (int i = 0; i < index - 1; ++i) {
        if (current == NULL) {
            printf("Podany indeks wykracza poza zakres listy.\n");
            return;
        }
        current = current->next;
    }

    node_t * new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Nie udalo sie zaalokowac pamieci dla nowego wezla.\n");
        return;
    }
    new_node->val = value;
    new_node->next = current->next;
    current->next = new_node;
}


int main() {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    printf("Lista bazowa:\n");
    print_list(head);

    printf("Push:\n");
    push(head, 4);
    print_list(head);

    printf("add_first:\n");
    add_first(&head, 0);
    print_list(head);

    printf("pop:\n");
    pop(&head);
    print_list(head);

    printf("remove_last:\n");
    remove_last(&head);
    print_list(head);

    printf("remove_by_index:\n");
    remove_by_index(&head, 1);
    print_list(head);

    printf("remove_by_value:\n");
    remove_by_value(&head, 3);
    print_list(head);

    printf("insert_at_index:\n");
    insert_at_index(&head, 1, 2);
    print_list(head);
}
