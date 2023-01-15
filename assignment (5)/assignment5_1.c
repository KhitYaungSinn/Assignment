// Jump Search ==> linear Search ==> Tree
#include <stdlib.h>
#include <stdio.h>
int jumpsearch(int array[], int key, int size)
{
    int step = 10;
    int previous = 0;
    while (array[step - 1] < key)
    {
        previous = step;
        step += step;
        if (previous >= size)
        {
            return -1;
        }
    }

    int center = step / 2;
    if (array[center] == key) // check root
    {
        return center;
    }
    else if (array[center] < key) // if key is greater than center,go right
    {
        for (int k = center + 1; k < step; k++)
        {
            if (array[k] == key)
            {
                return k;
            }
        }
    }
    else // if key is less than center, go left
    {
        for (int l = previous; l < center; l++)
        {
            if (array[l] == key)
            {
                return l;
            }
        }
    }
    return -1;
}
int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 220;
    int index_number = jumpsearch(array, key, size);
    if (index_number != -1)
    {
        printf("at index %d, we found %d", index_number, array[index_number]);
    }
    else
    {
        printf("Not found. may be the data is not in array");
    }

    return 0;
}