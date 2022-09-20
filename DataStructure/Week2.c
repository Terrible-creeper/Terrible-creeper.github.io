#include <stdio.h>
void strcat_(char S1[],char S2[]) {
    int i = 0,j = 0;
    char data[200];
    while(S1[i] != '\0') {
        data[i] = S1[i];
        i++;
    }
    while(S2[j] != '\0') {
        data[i] = S2[j++];
        i++;
    }
    data[i] = '\0';
    printf("%s",data);
}

int main() {
    char data[100],data2[100];
    printf("Input first string: ");
    gets(data);
    printf("Input second string: ");
    gets(data2);
    strcat_(data,data2);
}
