#include <stdio.h>

struct time
{
    int hour;
    int min;
    int sec;
};

struct time addTime(struct time t1, struct time t2)
{
    struct time result;

    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.sec %= 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;

    return result;
}

struct time diffTime(struct time t1, struct time t2)
{
    struct time result;

    int t1_seconds = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int t2_seconds = t2.hour * 3600 + t2.min * 60 + t2.sec;

    int diff_seconds = t1_seconds - t2_seconds;

    if (diff_seconds < 0)
        diff_seconds = -diff_seconds;

    result.hour = diff_seconds / 3600;
    diff_seconds %= 3600;
    result.min = diff_seconds / 60;
    result.sec = diff_seconds % 60;

    return result;
}

void readTime(struct time *t)
{
    printf("Enter hours: ");
    scanf("%d", &t->hour);
    printf("Enter minutes: ");
    scanf("%d", &t->min);
    printf("Enter seconds: ");
    scanf("%d", &t->sec);
}

void displayTime(struct time t)
{
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

int main()
{
    struct time time1, time2, sum, difference;

    printf("Enter time 1:\n");
    readTime(&time1);

    printf("Enter time 2:\n");
    readTime(&time2);

    sum = addTime(time1, time2);
    difference = diffTime(time1, time2);

    printf("Time 1: ");
    displayTime(time1);

    printf("Time 2: ");
    displayTime(time2);

    printf("Sum of times: ");
    displayTime(sum);

    printf("Difference between times: ");
    displayTime(difference);

    return 0;
}
