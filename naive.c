#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void search(char* pat, char* str)
{
    int M = strlen(pat);
    int N = strlen(str);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++){
            if (str[i + j] != pat[j]){
                break;
            }
 		}
        if (j == M){
            printf("Pattern found at index %d \n", (i+1));
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
    search(pat, str);
    printf("\n");
    return 0;
}
