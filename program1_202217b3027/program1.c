#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, i, pos;

void main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        // Call the appropriate function based on the user's choice
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter a correct choice.");
        }
        
        printf("\nDo you want to continue::: ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of nodes");
    scanf("%d", &n);
    
    // Input elements into the list
    for (i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position u want to delete: ");
    scanf("%d", &pos);
    
    if (pos >= n || pos < 0) {
        printf("\nInvalid position.");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    
    printf("\nThe elements after deletion: ");
    display();
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to searched: ");
    scanf("%d", &e);
    
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    int p;
    printf("\nEnter the position u need to insert: ");
    scanf("%d", &pos);
    
    if (pos > n || pos < 0) {
        printf("\nInvalid position.");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        
        b[pos] = p;
        n++;
    }
    
    printf("\nThe list after insertion: ");
    display();
}

void display() {
    printf("\nThe elements of the list are: ");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}