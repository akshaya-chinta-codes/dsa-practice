 #include <stdio.h>

int binarysearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid + 1;   // position (1-based)

        else if (a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;   // search unsuccessful
}

int main()
{
    int n, key, a[10], i;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    if (n > 10)
    {
        printf("Array size exceeds limit\n");
        return 0;
    }

    printf("Enter array elements in sorted order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the element to be searched:\n");
    scanf("%d", &key);

    int res = binarysearch(a, n, key);

    if (res != -1)
    {
        printf("Search is successful\n");
        printf("Key is found at %d position\n", res);
    }
    else
        printf("Search is unsuccessful\n");

    return 0;
}
