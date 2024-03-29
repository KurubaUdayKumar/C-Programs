#include <stdio.h>
#include <string.h>
 
int findLength(char *str)
{
    int n = strlen(str);
    int maxlen = 0; 
 
    
    int sum[n][n];
 
    
    for (int i =0; i<n; i++)
        sum[i][i] = str[i]-'0';
 
    
    for (int len=2; len<=n; len++)
    {
       
        for (int i=0; i<n-len+1; i++)
        {
            int j = i+len-1;
            int k = len/2;
 
            
            sum[i][j] = sum[i][j-k] + sum[j-k+1][j];
             if (len%2 == 0 && sum[i][j-k] == sum[(j-k+1)][j]
                           && len > maxlen)
                 maxlen = len;
        }
    }
    return maxlen;
}
 

int main(void)
{
    char str[] = "000000";
    printf("Length of the substring is %d", findLength(str));
    return 0;
}
