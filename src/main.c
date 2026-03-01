#include <stdio.h>
#include <string.h>
#include "abonent.h"

#define MAX_SUBSCRIBERS 12

int main() {
    ABON subscribers[MAX_SUBSCRIBERS];
    int count;
    char searchPhone[20];
    ABON* found;

    printf("=== Система учёта абонентов ===\n");

    count = createAbonentArray(subscribers);
   
    sortByFullName(subscribers, count);
    printf("\n--- После сортировки по алфавиту ---\n");
    for (int i = 0; i < count; i++) {
        printSubscriber(&subscribers[i]);
    }

    addTwentyForOldSubscribers(subscribers, count);
    printf("\n--- После добавления 20 руб. абонентам со стажем >10 лет ---\n");
    for (int i = 0; i < count; i++) {
        printSubscriber(&subscribers[i]);
    }

    printf("\n--- Абоненты с отрицательным балансом ---\n");
    printNegativeBalanceSubscribers(subscribers, count);

    printf("\nВведите номер телефона для поиска: ");
    fgets(searchPhone, sizeof(searchPhone), stdin);
    searchPhone[strcspn(searchPhone, "\n")] = 0;

    found = findSubscriberByPhone(subscribers, count, searchPhone);
    if (found != NULL) {
        printf("\nАбонент найден:\n");
        printSubscriber(found);
    } else {
        printf("Абонент с номером %s не найден.\n", searchPhone);
    }

    return 0;
}
