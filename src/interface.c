#include <stdio.h>
#include <string.h>
#include "abonent.h"

ABON inputSubscriber() {
    ABON sub;
    
    printf("Введите фамилию и инициалы: ");
    fgets(sub.fullName, sizeof(sub.fullName), stdin);
    sub.fullName[strcspn(sub.fullName, "\n")] = 0; // удаляем \n
    
    printf("Введите номер телефона: ");
    fgets(sub.phoneNumber, sizeof(sub.phoneNumber), stdin);
    sub.phoneNumber[strcspn(sub.phoneNumber, "\n")] = 0;
    
    printf("Введите год подключения: ");
    scanf("%d", &sub.connectionDate.year);
    printf("Введите месяц подключения: ");
    scanf("%d", &sub.connectionDate.month);
    printf("Введите день подключения: ");
    scanf("%d", &sub.connectionDate.day);
    
    printf("Введите начисленную сумму: ");
    scanf("%f", &sub.accruedAmount);
    
    printf("Введите сумму на счету: ");
    scanf("%f", &sub.accountBalance);
    
    getchar(); // очистка буфера после scanf
    
    return sub;
}

int createAbonentArray(ABON subscribers[]) {
    int count;
    printf("Сколько абонентов ввести (макс. 12)? ");
    scanf("%d", &count);
    getchar(); // очистка буфера
    
    if (count > 12) count = 12;
    if (count < 1) count = 1;
    
    for (int i = 0; i < count; i++) {
        printf("\n--- Абонент %d ---\n", i + 1);
        subscribers[i] = inputSubscriber();
    }
    
    return count;
}

void printSubscriber(const ABON* sub) {
    printf("ФИО: %s\n", sub->fullName);
    printf("Телефон: %s\n", sub->phoneNumber);
    printf("Дата подключения: %04d-%02d-%02d\n", 
           sub->connectionDate.year, sub->connectionDate.month, sub->connectionDate.day);
    printf("Начислено: %.2f\n", sub->accruedAmount);
    printf("Баланс: %.2f\n", sub->accountBalance);
    printf("------------------------\n");
}

void printNegativeBalanceSubscribers(ABON subscribers[], int count) {
    int found = 0;
    for (int i =  0; i < count; i++) {
        float netBalance = subscribers[i].accountBalance - subscribers[i].accruedAmount;
        if (netBalance < 0) {
            printf("\nАбонент с отрицательным балансом после вычета начислений:\n");
            printSubscriber(&subscribers[i]);
            printf("Чистый баланс: %.2f\n", netBalance);
            found = 1;
        }
    }
    if (!found) {
        printf("Нет абонентов с отрицательным балансом.\n");
    }
}

int createAbonentArray(ABON subscribers[]);
void printSubscriber(const ABON* sub);
void printNegativeBalanceSubscribers(ABON subscribers[], int count);