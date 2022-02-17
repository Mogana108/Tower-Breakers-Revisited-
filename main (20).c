#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int countPrimeFactors(long long num, int sum);
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int towers,sum=0, xor=0;
        scanf("%d",&towers);
        long long heights[towers];
        int i;
        for(i=0;i<towers;i++){
            scanf("%lld",&heights[i]);
        }
        for(i=0;i<towers;i++){
            xor ^= countPrimeFactors(heights[i],sum);
        }
        if(xor==0){
            printf("2 \n");
        }else{
            printf("1 \n");
        }
    }
    return 0;
}

int countPrimeFactors(long long num, int sum){
    int i=0;
    while(num%2 ==0){
        num=num/2;
        sum += 1;
    }
    for(i=3;i<=sqrt(num);i+=2){
        while(num%i==0){
            num /=i;
            sum +=1;
        }
    }
    if(num>2){
        sum+=1;
    }
    return sum;
}
