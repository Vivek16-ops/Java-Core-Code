#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size; // memory to be reserved
    int used_size;  // memory to be used
    int *ptr;       // pointer for pointing base address
};

void createarray(struct myArray *a, int tsize, int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr  = (int *)malloc(tsize*sizeof(int));

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setval(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d:", i);
        scanf("%d", &(a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    createarray(&marks, 100, 20);

    printf("We are running setVal:\n");
    setval(&marks);

    printf("We are running show function:\n");
    show(&marks);
    return 0;
}
// & -> help to provide address
// * -> help to content in that address