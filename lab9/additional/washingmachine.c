#include <stdio.h>
#include <stdlib.h>

typedef struct Booking
{
    int bookingID;
    int duration;
    struct Booking *next;
    struct Booking *prev;
} Booking;

Booking *createBooking(int id, int duration)
{
    Booking *newBooking = (Booking *)malloc(sizeof(Booking));
    if (!newBooking)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newBooking->bookingID = id;
    newBooking->duration = duration;
    newBooking->next = newBooking->prev = NULL;
    return newBooking;
}

Booking *enqueue(Booking *tail, int duration)
{
    static int bookingID = 1;
    Booking *newBooking = createBooking(bookingID++, duration);

    if (!tail)
    {
        newBooking->next = newBooking->prev = newBooking;
        return newBooking;
    }

    newBooking->next = tail->next;
    newBooking->prev = tail;
    tail->next->prev = newBooking;
    tail->next = newBooking;

    return newBooking;
}

Booking *dequeue(Booking *tail)
{
    if (!tail)
    {
        printf("Queue is empty.\n");
        return NULL;
    }

    Booking *bookingToRemove = tail->next;
    if (bookingToRemove->next == bookingToRemove)
    {
        free(bookingToRemove);
        return NULL;
    }

    tail->next = bookingToRemove->next;
    bookingToRemove->next->prev = tail;
    free(bookingToRemove);

    return tail;
}

void displayQueue(Booking *tail)
{
    if (!tail)
    {
        printf("Queue is empty.\n");
        return;
    }

    Booking *current = tail->next;

    do
    {
        printf("Booking ID: %d, Duration: %d\n", current->bookingID, current->duration);
        current = current->next;
    } while (current != tail->next);

    printf("\n");
}

int main()
{
    Booking *tail = NULL;
    int choice, duration;

    do
    {
        printf("Menu:\n");
        printf("1. Book washing machine\n");
        printf("2. Hand over to next person\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the duration to book the washing machine: ");
            scanf("%d", &duration);
            tail = enqueue(tail, duration);
            printf("Washing machine booked for %d minutes.\n", duration);
            break;
        case 2:
            tail = dequeue(tail);
            printf("Washing machine handed over to the next person.\n");
            break;
        case 3:
            displayQueue(tail);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
    return 0;
}
