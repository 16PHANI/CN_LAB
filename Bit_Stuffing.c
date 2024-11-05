#include <stdio.h>
int main() 
{ 
    int a[20], b[40], i, j = 0, k, count = 1, n;  
    printf("Enter the frame size: "); 
    scanf("%d", &n); 
    printf("Enter the frame in the form of 0's and 1's: "); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%d", &a[i]); 
    } 
    i = 0; 
    while (i < n) 
    { 
        if (a[i] == 1) 
        { 
            b[j++] = a[i]; 
            count = 1; 
            for (k = i + 1; k < n && a[k] == 1 && count < 5; k++) 
            { 
                b[j++] = a[k]; 
                count++; 
            } 
            if (count == 5) 
            { 
                b[j++] = 0; 
            }
            i = k;
        } 
        else 
        { 
            b[j++] = a[i]; 
            i++;
        }
    }  
    printf("After bit stuffing: "); 
    for (i = 0; i < j; i++) 
    {
        printf("%d", b[i]); 
    } 
    printf("\n"); 
    
    return 0;
}
