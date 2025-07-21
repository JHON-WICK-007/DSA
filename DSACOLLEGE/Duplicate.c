#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1];   
    int count[n + 1]; 

    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    int found = 0;

    for (int i = 1; i <= n; i++)
    {
        if (count[i] == 2)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("-1");
    }

    return 0;
}