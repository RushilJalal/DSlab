#include <stdio.h>

// Function to calculate the length of a string
int stringLength(const char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void stringConcatenate(char result[], const char str1[], const char str2[])
{
    int i, j;

    for (i = 0; str1[i] != '\0'; i++)
    {
        result[i] = str1[i];
    }

    for (j = 0; str2[j] != '\0'; j++)
    {
        result[i + j] = str2[j];
    }

    result[i + j] = '\0';
}

// Function to compare two strings
int stringCompare(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0')
            return 0;
        i++;
    }
    return str1[i] - str2[i];
}

// Function to insert a substring into a string
void stringInsert(char str[], int pos, const char subStr[])
{
    int lenStr = stringLength(str);
    int lenSubStr = stringLength(subStr);
    // makes room for substring
    for (int i = lenStr + lenSubStr; i >= pos + lenSubStr; i--)
    {
        str[i] = str[i - lenSubStr];
    }
    // inserts substring in the room created
    for (int i = pos, j = 0; j < lenSubStr; i++, j++)
    {
        str[i] = subStr[j];
    }
    str[lenStr + lenSubStr] = '\0';
}

// Function to delete a substring from a string
void stringDelete(char str[], int pos, int len)
{
    int lenStr = stringLength(str);

    for (int i = pos; i < lenStr - len; i++)
    {
        str[i] = str[i + len];
    }

    str[lenStr - len] = '\0';
}

int main()
{
    char str1[100], str2[100], result[200], subStr[100];
    int pos, length;

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    printf("Length of string 1: %d\n", stringLength(str1));

    stringConcatenate(result, str1, str2);
    printf("Concatenated string: %s\n", result);

    int comparison = stringCompare(str1, str2);
    if (comparison == 0)
        printf("Strings are equal.\n");
    else if (comparison < 0)
        printf("String 1 is smaller than string 2.\n");
    else
        printf("String 1 is greater than string 2.\n");

    printf("Enter the position to insert substring: ");
    scanf("%d", &pos);
    printf("Enter the substring to insert: ");
    scanf("%s", subStr);
    stringInsert(str1, pos, subStr);
    printf("String after insertion: %s\n", str1);

    printf("Enter the position to delete substring: ");
    scanf("%d", &pos);
    printf("Enter the length of substring to delete: ");
    scanf("%d", &length);
    stringDelete(str1, pos, length);
    printf("String after deletion: %s\n", str1);

    return 0;
}
