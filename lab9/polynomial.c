#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
} Node;

Node *createNode(int coef, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

Node *insertTerm(Node *head, int coef, int exp)
{
    Node *newNode = createNode(coef, exp);
    newNode->next = head;
    return newNode;
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            result = insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            result = insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
            {
                result = insertTerm(result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        result = insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        result = insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(Node *head)
{
    if (!head)
    {
        printf("0");
        return;
    }

    while (head != NULL)
    {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    poly1 = insertTerm(poly1, 5, 3);
    poly1 = insertTerm(poly1, -2, 2);

    poly2 = insertTerm(poly2, 3, 4);
    poly2 = insertTerm(poly2, -2, 2);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Node *sum = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(sum);
    return 0;
}
