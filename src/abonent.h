#ifndef ABONENT_H
#define ABONENT_H

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char fullName[100];      
    char phoneNumber[20];     
    Date connectionDate;  
    float accruedAmount;  
    float accountBalance;    
} ABON;

void addTwentyForOldSubscribers(ABON subscribers[], int count);
void sortByFullName(ABON subscribers[], int count);
ABON* findSubscriberByPhone(ABON subscribers[], int count, const char* phone);
int countNegativeBalance(ABON subscribers[], int count);
int yearsSinceConnection(Date connectionDate);

int createAbonentArray(ABON subscribers[]);
void printSubscriber(const ABON* sub);
void printNegativeBalanceSubscribers(ABON subscribers[], int count);

#endif