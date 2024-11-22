#include <stdio.h>
int main() 
{
    int a[20], b[40], n, count = 0, j = 0;
    printf("Enter the frame size: ");
    scanf("%d", &n);
    printf("Enter the frame in the form of 0's and 1's: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) 
    {
        b[j++] = a[i]; 
        if (a[i] == 1) 
        {
            count++;
            if (count == 5) 
            {
                b[j++] = 0; 
                count = 0;
            }
        } 
        else 
        {
            count = 0; 
        }
    }
    printf("After bit stuffing: ");
    for (int i = 0; i < j; i++) 
    {
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
