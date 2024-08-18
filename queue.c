#include <stdio.h>
#define max 10

int Enqueue(int [], int , int);
int Dequeue(int [], int , int );
void display(int [], int , int );
void peek(int [], int , int );

int main(){
    int Q[max], ch, f = -1, r = -1;

    while (1) {
        printf("\n\nQueue Operations: ");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                r = Enqueue(Q, f, r);
                if (f == -1) f = 0;
                break;

            case 2:
                f = Dequeue(Q, f, r);
                if (f == -1) r = -1;
                break;

            case 3:
                peek(Q, f, r);
                break;

            case 4:
                display(Q, f, r);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int Enqueue(int Q[], int f, int r) {
    int x;
    if ((r + 1) % max == f) {
        printf("Queue is full!\n");
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &x);
        r = (r + 1) % max;
        Q[r] = x;
        printf("%d enqueued to queue\n", x);
    }
    return r;
}

int Dequeue(int Q[], int f, int r) {
    int x;
    if (f == -1 && r == -1) {
        printf("Queue is empty!\n");
    } else {
        x = Q[f];
        printf("%d dequeued from queue\n", x);
        if (f == r) {
            f = -1; // Queue is empty after this dequeue
        } else {
            f = (f + 1) % max;
        }
    }
    return f;
}

void peek(int Q[], int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", Q[f]);
    }
}

void display(int Q[], int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        int i = f;
        while (i != r) {
            printf("%d ", Q[i]);
            i = (i + 1) % max;
        }
        printf("%d ", Q[r]);
    }
}
