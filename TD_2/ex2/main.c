#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#define MAX_SIZE 1000

int main(void)
{
    int list[MAX_SIZE];
    int expected[MAX_SIZE];
    int size = 0;
    int expected_size = 0;


    FILE *input = fopen("text/input.txt", "r");
    if (!input) {
        fprintf(stderr, "Erreur\n");
        return 1;
    }

    while (fscanf(input, "%d", &list[size]) == 1 && size < MAX_SIZE)
        size++;
    fclose(input);

    if (size == 0) {
        fprintf(stderr, "Erreur\n");
        return 1;
    }


    FILE *expected_file = fopen("text/expected_output.txt", "r");
    if (!expected_file) {
        fprintf(stderr, "Erreur\n");
        return 1;
    }

    while (fscanf(expected_file, "%d", &expected[expected_size]) == 1 && expected_size < MAX_SIZE)
        expected_size++;
    fclose(expected_file);

    if (expected_size != size) {
        fprintf(stderr, "Erreur : tailles différentes entre input.txt (%d) et expected_output.txt (%d)\n",
                size, expected_size);
        return 1;
    }



    clock_t begin, end;
    double time;


    int list_selection[size];
    copy_array(list, list_selection, size);

    begin = clock();
    selection_sort(list_selection, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Selection sort time: %lf seconds\n ~Result: ", time);
    arrays_equal(list_selection, expected, size);


    int list_insertion[size];
    copy_array(list, list_insertion, size);

    begin = clock();
    insertion_sort(list_insertion, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Insertion sort time: %lf seconds\n ~Result: ", time);
    arrays_equal(list_insertion, expected, size);


    int list_bubble[size];
    copy_array(list, list_bubble, size);

    begin = clock();
    bubble_sort(list_bubble, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Bubble sort time: %lf seconds\n ~Result: ", time);
    arrays_equal(list_bubble, expected, size);


    
    int list_merge[size];
    copy_array(list, list_merge, size);

    begin = clock();
    merge_sort(list_merge, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Merge sort time: %lf seconds\n ~Result: ", time);
    arrays_equal(list_merge, expected, size);



    int list_quick[size];
    copy_array(list, list_quick, size);

    begin = clock();
    quick_sort(list_quick, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Quick sort time: %lf seconds\n ~Result: ", time);
    arrays_equal(list_quick, expected, size);

    return 0;
}