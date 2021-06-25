#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

static inline void
print_arr (int a[], uint64_t size_of_arr)
{
    printf("\n");
    for (int i = 0; i < size_of_arr; i++) {
        printf("%d, ", a[i]);
    }
}

static void
merge_sort (int a[], int start_idx, int end_idx)
{
    int32_t arr_size = (end_idx - start_idx + 1);
    if (end_idx < start_idx) {
        //Nothing to do.
        return;
    } else if (end_idx == start_idx) {
        //One element is always sorted.
        printf("\nBase case");
        print_arr(a+start_idx, arr_size);
        return;
    } else {
        int median;

        median = (end_idx + start_idx) / 2;
        merge_sort(a, start_idx, median);
        merge_sort(a, median + 1, end_idx);
        
        //Merge
 
        int *new_arr = (int *) malloc (sizeof(int) * arr_size);
        int first_arr_iter, second_arr_iter, new_arr_iter;
        first_arr_iter = start_idx;
        second_arr_iter = median + 1;
        new_arr_iter = 0;

        while (first_arr_iter <= median && second_arr_iter <= end_idx) {
            if (a[first_arr_iter] < a[second_arr_iter]) {
                new_arr[new_arr_iter] = a[first_arr_iter];
                first_arr_iter++;
            } else {
                new_arr[new_arr_iter] = a[second_arr_iter];
                second_arr_iter++;
            }
            new_arr_iter++;
        }
        if (first_arr_iter <= median) {
            while (first_arr_iter <= median) {
                new_arr[new_arr_iter] = a[first_arr_iter];
                new_arr_iter++;
                first_arr_iter++;
            }
        } else {
            while (second_arr_iter <= end_idx) {
                new_arr[new_arr_iter] = a[second_arr_iter];
                new_arr_iter++;
                second_arr_iter++;
            }
        }

        //Move new_iter elements back to a.
        memcpy((a+start_idx), new_arr, sizeof(int) * arr_size);//This probably doesn't work.
        printf("\nMerge");
        print_arr(a+start_idx, arr_size);
        free(new_arr);
    }
}

static void
sort_arr (int a[], uint64_t size_of_arr)
{
   merge_sort(a, 0, size_of_arr - 1);
}

int
main() {
    int a[] = {1, 11, 93, -3, 72, 4, 11, 23, 300, 21, 31};

    uint64_t size_of_arr =  sizeof(a)/sizeof(int);

    print_arr(a, size_of_arr);

    sort_arr(a, size_of_arr);

    print_arr(a, size_of_arr);

}

