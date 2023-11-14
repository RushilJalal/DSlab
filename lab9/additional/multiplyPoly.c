#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int coef, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node *insertTerm(Node *header, int coef, int exp)
{
    Node *newNode = createNode(coef, exp);
    newNode->next = header->next;
    newNode->prev = header;
    header->next->prev = newNode;
    header->next = newNode;
    return header;
}

Node *multiplyPolynomials(Node *poly1, Node *poly2)
{
    Node *resultHeader = createNode(0, 0);
    Node *result = resultHeader;

    Node *current1 = poly1->next;

    while (current1 != poly1)
    {
        Node *current2 = poly2->next;

        while (current2 != poly2)
        {
            int coef = current1->coefficient * current2->coefficient;
            int exp = current1->exponent + current2->exponent;

            resultHeader = insertTerm(resultHeader, coef, exp);

            current2 = current2->next;
        }

        current1 = current1->next;
    }

    return result;
}

void displayPolynomial(Node *header)
{
    Node *current = header->next;

    while (current != header)
    {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;

        if (current != header)
        {
            printf(" + ");
        }
    }

    printf("\n");
}

void freeList(Node *header)
{
    Node *current = header->next;
    Node *next = NULL;

    while (current != header)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(header);
}

int main()
{
    Node *poly1Header = createNode(0, 0);
    Node *poly2Header = createNode(0, 0);

    poly1Header = insertTerm(poly1Header, 2, 3);
    poly1Header = insertTerm(poly1Header, -3, 2);
    poly1Header = insertTerm(poly1Header, 1, 0);

    poly2Header = insertTerm(poly2Header, 4, 2);
    poly2Header = insertTerm(poly2Header, -1, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1Header);

    printf("Polynomial 2: ");
    displayPolynomial(poly2Header);

    Node *result = multiplyPolynomials(poly1Header, poly2Header);

    printf("Product of the polynomials: ");
    displayPolynomial(result);

    return 0;
}
