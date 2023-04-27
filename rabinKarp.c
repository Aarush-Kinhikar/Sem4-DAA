#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define d 256
void search(char pat[], char str[], int q)
{
    int M = strlen(pat);
    int N = strlen(str);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + str[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (str[i + j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M) {
            t = (d * (t - str[i] * h) + str[i + M]) % q;
            if (t < 0){
                t = (t + q);
            }
        }
    }
}
int main(){
    char *str;
    char *pat;
    char ch;
    int l1,l2;
    printf("Enter Length of String: ");
    scanf("%d",&l1);
    str = (char*)malloc(l1 * sizeof(char));
    printf("Enter String: ");
    scanf("%c",&ch);
    scanf("%[^\n]%*c",str);
    printf("\n");
    printf("Enter Length of Pattern: ");
    scanf("%d",&l2);
    pat = (char*)malloc(l2 * sizeof(char));
    printf("Enter Pattern: ");
   	scanf("%c",&ch);
   	scanf("%[^\n]%*c",pat);
    int q = 101;
    search(pat, str, q);
    return 0;
}
