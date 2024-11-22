#include <stdio.h>
#include <string.h>
void computeCRC(char msg[], char key[], char remainder[], int msg_len, int key_len) 
{
    for (int i = 0; i <= msg_len - key_len; i++) 
    {
        if (remainder[0] == '1') 
        { 
            for (int j = 0; j < key_len; j++) 
            {
                remainder[j] = (remainder[j] == key[j]) ? '0' : '1'; 
            }
        }
        memmove(remainder, remainder + 1, key_len - 1);
        remainder[key_len - 1] = msg[i + key_len];
    }
}
int main() 
{
    char key[20], msg[100], remainder[20];
    int msg_len, key_len;
    // Sender Side
    printf("\nSender Side\n");
    printf("Enter message: ");
    scanf("%s", msg);
    printf("Enter key (polynomial): ");
    scanf("%s", key);
    msg_len = strlen(msg);
    key_len = strlen(key);
    for (int i = 0; i < key_len - 1; i++) 
    {
        msg[msg_len + i] = '0';
    }
    msg[msg_len + key_len - 1] = '\0';
    strncpy(remainder, msg, key_len);
    remainder[key_len] = '\0';
    computeCRC(msg, key, remainder, strlen(msg), key_len);
    printf("CRC remainder: %s\n", remainder);
    strncpy(msg + msg_len, remainder, key_len - 1);
    msg[msg_len + key_len - 1] = '\0';
    printf("Transmitted message with CRC: %s\n", msg);
    printf("\nReceiver Side\n");
    printf("Enter received message: ");
    scanf("%s", msg);
    strncpy(remainder, msg, key_len);
    remainder[key_len] = '\0';
    computeCRC(msg, key, remainder, strlen(msg), key_len);
    int isError = 0;
    for (int i = 0; i < key_len - 1; i++) 
    {
        if (remainder[i] != '0') 
        {
            isError = 1;
            break;
        }
    }
    if (isError) 
    {
        printf("Error detected in received message.\n");
    } 
    else 
    {
        printf("No error detected in received message.\n");
    }
    return 0;
}
