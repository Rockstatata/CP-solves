#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<strings.h>
 
int main(){
    int a, b, l,c;
    scanf("%d%d%d", &a, &b, &l);
    int count=0;
    for(int x=0; x<=20 && pow(a,x)<=l; x++)
    {
        for(int y=0; y<=20 && pow(b,y)<=l; y++)
        {
            c=pow(a,x)*pow(b,y);
            // printf("c==%d\n",c);
            if(c<=l && l%c==0)
            {
                printf("y==%d\n",y);
                //printf("c==%d\n",c);
                count++;
            }
        }
    }
    printf("%d\n",count);
}