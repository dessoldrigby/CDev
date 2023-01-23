// #define _UALL
#include <string.h>
#define _USTRSTACK
#include "utils.h"
//#include "stack.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define BUFF_SIZE 1024

void fun(char* s, int sz) 
{
    printf("[%s]\n", s);
}

typedef struct _array_elem_t {
    void* element;
    size_t element_size;

} array_elem_t;

int main(int argc, char* argv[]) 
{
    char string[] = "abcd";
    int arr[] = {1, 2, 3, 4};
    double* doubles = malloc(3 * sizeof(double));
    doubles = memcpy(doubles, (double[]){1.0, 3.0, 5.0}, sizeof(double) * 3);

    array_elem_t arr_elem[] = {
        {(void*)string, sizeof(string)}, 
        {(void*)arr, sizeof(arr)},
        {(void*)doubles, malloc_usable_size(doubles)}
    };

    printf("%s\n", (char*)arr_elem[0].element);

    for(int i = 0; i < arr_elem[1].element_size / sizeof(int); i++) {
        printf("%d\t", ((int*)arr_elem[1].element)[i]);
    }
    printf("\n");

    for(int i = 0; i < arr_elem[2].element_size / sizeof(double); i++) {
        printf("%f\t", ((double*)arr_elem[2].element)[i]);
    }
    printf("\n");

    free(doubles);

    // strstack_t s = strstack_create_from_array(argv, argc);

    // strstack_for(&s, fun);

    // strstack_clear(&s);

    // char* ss[] = {
    //     "AAA",
    //     "BBB",
    //     "CCC"
    // };

    // strstack_t s = strstack_create();
    // strstack_push(&s, ss[0], 0);
    // strstack_push(&s, ss[1], 1);
    // strstack_push(&s, ss[2], 2);
    // strstack_push(&s, ss[0], -1);
    // strstack_push(&s, ss[1], 3);
    // strstack_push(&s, ss[2], -1);
    // strstack_push(&s, ss[0], 4);

    // strstack_for(&s, fun);

    // strstack_clear(&s);

    return EXIT_SUCCESS;
}