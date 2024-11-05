#include <stdio.h>
#include <string.h>
void addParityBit(char data[], char parityData[]) 
{
    int i, count = 0;
    int n = strlen(data);
    for (i = 0; i < n; i++) 
    {
        parityData[i] = data[i];
        if (data[i] == '1') 
        {
            count++;
        }
    }
    if (count % 2 == 0) 
    {
        parityData[n] = '0';
    } 
    else 
    {
        parityData[n] = '1'; 
    }
    parityData[n + 1] = '\0'; 
}
int main() 
{
    char data[100], parityData[101];
    printf("Enter binary data: ");
    scanf("%s", data);
    addParityBit(data, parityData);
    printf("Data with parity bit: %s\n", parityData);
    return 0;
}
