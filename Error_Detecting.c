#include <stdio.h>
#include <string.h>
int main() 
{
    char data[100], parityData[101];
    int count = 0;
    int n;
    printf("Enter binary data: ");
    scanf("%s", data);
    n = strlen(data);
    for (int i = 0; i < n; i++) 
    {
        parityData[i] = data[i];
        if (data[i] == '1') 
        {
            count++;
        }
    }
    parityData[n] = (count % 2 == 0) ? '0' : '1';
    parityData[n + 1] = '\0';
    printf("Data with parity bit: %s\n", parityData);
    return 0;
}
