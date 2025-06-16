#include <stdio.h>
#define Size 10

void printArray(int *array) {
    for (int i = 0; i < Size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
        printf("*(%p + %d) = %d\n\n", (void*)array, i, array[i]);
    }
}

int findminimum(int *array) {
    int minimum = array[0];
    for (int i = 1; i < Size; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

int findmaximum(int *array) {
    int maximum = array[0];
    for (int i = 1; i < Size; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

float findaverage(int *array) {
    int sum = 0;
    for (int i = 0; i < Size; i++) {
        sum += array[i];
    }
    return (float)sum / Size;
}

int save(int *array) {
    FILE *fptr = fopen("tablica.txt", "w");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < Size; i++) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    return 0;
}

int load(int *array) {
    FILE *fptr = fopen("tablica.txt", "r");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < Size; i++) {
        fscanf(fptr, "%d", &array[i]);
    }
    fclose(fptr);
    return 0;
}

void menu(void) {
    printf("\n1. Wyswietl tabele\n");
    printf("2. Wprowadz wartosci do tabeli\n");
    printf("3. Zdefiniuj najmniejsza wartosc\n");
    printf("4. Zdefiniuj najwieksza wartosc\n");
    printf("5. Zdefiniuj srednia wartosc\n");
    printf("6. Zapisz do pliku\n");
    printf("7. Wczytaj z pliku\n");
    printf("0. Wyjscie\n");
    printf("Wybierz wlasciwa opcje: ");
}

int main() {
    int array[Size] = {1,2,3,4,5,6,7,8,9,10};
    int option = 0;
    int errorCode = 0;

    do {
        menu();
        scanf("%d", &option);

        switch(option) {
            case 0:
                printf("Koniec programu.\n");
                break;
            case 1:
                printArray(array);
                break;
            case 2:
                for (int i = 0; i < Size; i++) {
                    printf("array[%d] = ", i);
                    scanf("%d", &array[i]);
                }
                break;
            case 3:
                printf("Najmniejsza wartosc: %d\n", findminimum(array));
                break;
            case 4:
                printf("Najwieksza wartosc: %d\n", findmaximum(array));
                break;
            case 5:
                printf("Srednia wartosc: %.2f\n", findaverage(array));
                break;
            case 6:
                errorCode = save(array);
                if (errorCode) {
                    printf("Blad zapisu do pliku!\n");
                } else {
                    printf("Zapisano do pliku.\n");
                }
                break;
            case 7:
                errorCode = load(array);
                if (errorCode) {
                    printf("Blad wczytywania z pliku!\n");
                } else {
                    printf("Dane wczytane z pliku.\n");
                }
                break;
            default:
                printf("Niepoprawna opcja. Wprowadz ponownie.\n");
                break;
        }

    } while (option != 0);

    return 0;
}
