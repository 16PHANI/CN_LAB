#include <stdio.h>
#include <string.h>
int main() 
{
    int i, n;
    char d[100];
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    printf("Enter the characters: ");
    scanf("%s", d);
    printf("The original data: %s\n", d);
    printf("The transmitted data: dlestx");
    for (i = 0; i < n; i++) 
    {
        if (d[i] == 'd' && d[i+1] == 'l' && d[i+2] == 'e') 
        {
            printf("dle");  
        }
        printf("%c", d[i]);
    }
    printf("dleetx\n");
    printf("The received data: %s\n", d);
    return 0;
}



