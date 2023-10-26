#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int write_to_file_input(FILE *f, int *n) {
    f = fopen("in.txt", "w");
    int current;
    for (int i = 0; i < (*n); i++) {
        current = rand() % 21 - 10;
        fprintf(f, "%d\n", current);
    }
    fclose(f);
    return 0;
}

int read_file_input(FILE *f, int *n, int *arr_in) {
    f = fopen("in.txt", "r");
    for (int i = 0; i < (*n); i++) {
        fscanf(f, "%d", &arr_in[i]);
    }
    fclose(f);
    return 0;
}

int insertion_sort(int *arr_in, int *arr_out_1, int *n) {

    int temp = 0;
    for (int i = 0; i < (*n); i++) {
        arr_out_1[i] = arr_in[i];
    }
    for (int i = 1; i < (*n); i++) {
        for (int j = i; j > 0; j--) {
            if (arr_out_1[j] < arr_out_1[j - 1]) {
                temp = arr_out_1[j - 1];
                arr_out_1[j - 1] = arr_out_1[j];
                arr_out_1[j] = temp;
                temp = 0;
            } else {
                break;
            }
        }
    }
    return 0;
}


int gnome_sort(int *arr_out_2, int *n) {
    size_t i = 1; 

	while (i < (*n)) {
		if (i == 0) {
			i = 1;
		}
		if (arr_out_2[i-1] <= arr_out_2[i]) {
			++i; 
		} else {
			
			long tmp = arr_out_2[i];
			arr_out_2[i] = arr_out_2[i-1];
			arr_out_2[i-1] = tmp;
			--i;
		}
	}

    return 0;

}

int write_to_out_2(FILE *f, int *arr_out_2, int *n) {
    f = fopen("out_merge.txt", "w");
    for (int i = 0; i < (*n); i++) {
        fprintf(f, " %d ", arr_out_2[i]);
    }
    fclose(f);
    return 0;
}

int write_to_out_1(FILE *f, int *arr_out_1, int *n) {
    f = fopen("out_insertion.txt", "w");
    for (int i = 0; i < (*n); i++) {
        fprintf(f, " %d ", arr_out_1[i]);
    }
    fclose(f);
    return 0;
}

int main() {

    srand(time(NULL));
    FILE *f = NULL;

    int n = 0;

    int temp = 0;
    int *arr_in = (int *) calloc((n), sizeof(int));
    int *arr_out_1 = (int *) calloc((n), sizeof(int));
    int *arr_out_2 = (int *) calloc((n), sizeof(int));


    printf("Write the digits number: ");
    scanf("%d", &n);

    if (!n) {
        printf("0");
        return 0;
    } else {
        write_to_file_input(f, &n);
        read_file_input(f, &n, arr_in);
        printf("Initial Array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr_in[i]);
        }
        printf("\n\nArray insertion sort result:\n\n");
        insertion_sort(arr_in, arr_out_1, &n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr_out_1[i]);
        }
        write_to_out_1(f, arr_out_1, &n);

        printf("\n\nArray gnome sort result:\n\n");
        for (int i = 0; i < n; i++) {
            arr_out_2[i] = arr_in[i];
        }
        gnome_sort(arr_out_2, &n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr_out_2[i]);
        }
        write_to_out_2(f, arr_out_2, &n);

    }
    free(arr_in);
    free(arr_out_1);
    free(arr_out_2);
    return 0;
}
