#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int* arr = malloc(5000000*sizeof(int));  // Allocate memory for 5 integers (initialized to zero)

 for (int i = 0; i < 5000000; i++) {
        printf("%d ", arr[i]);  // May print unpredictable or garbage values
    }



    free(arr);  // Deallocate the memory correctly

    return 0;
}