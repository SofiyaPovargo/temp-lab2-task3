#include <stdio.h>
#include <string.h>
#include <time.h>
#include "abonent.h"

int yearsSinceConnection(Date connectionDate) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;

    int years = currentYear - connectionDate.year;
    
    if (currentMonth < connectionDate.month || 
        (currentMonth == connectionDate.month && currentDay < connectionDate.day)) {
        years--;
    }
    
    return years;
}

void addTwentyForOldSubscribers(ABON subscribers[], int count) {
    for (int i = 0; i < count; i++) {
        if (yearsSinceConnection(subscribers[i].connectionDate) > 10) {
            subscribers[i].accountBalance += 20.0f;
        }
    }
}

void sortByFullName(ABON subscribers[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(subscribers[i].fullName, subscribers[j].fullName) > 0) {
                ABON temp = subscribers[i];
                subscribers[i] = subscribers[j];
                subscribers[j] = temp;
            }
        }
    }
}

ABON* findSubscriberByPhone(ABON subscribers[], int count, const char* phone) {
    for (int i = 0; i < count; i++) {
        if (strcmp(subscribers[i].phoneNumber, phone) == 0) {
            return &subscribers[i];
        }
    }
    return NULL;
}

int countNegativeBalance(ABON subscribers[], int count) {
    int negCount = 0;
    for (int i = 0; i < count; i++) {
        if (subscribers[i].accountBalance < 0) {
            negCount++;
        }
    }
    return negCount;
}
