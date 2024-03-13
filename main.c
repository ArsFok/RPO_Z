#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Неверное количество аргументов\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int a = atoi(argv[2]);

    if (n <= 0 || a <= 0) {
        printf("Неверные значения n или a\n");
        return 1;
    }

    srand(time(NULL));

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Не удалось выделить память\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (2 * a + 1) - a;
    }

    int sign_changes = 0;
    int prev_sign = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] * prev_sign < 0) {
            sign_changes++;
        }
        prev_sign = arr[i];
    }

    FILE *file = fopen("out.txt", "w");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }
	
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
	printf("\n%d", sign_changes);
	
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n%d", sign_changes);
    fclose(file);

    free(arr);
    return 0;
}
