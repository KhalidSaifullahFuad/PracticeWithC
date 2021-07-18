#include<stdio.h>

long long reverse(long long num)
{
    long long rev=0;

    while(num)
    {
        rev = rev*10 + num%10;
        num/=10;
    }

    return rev;
}

int main()
{
    long long num;
    printf("Enter a number: ");
    scanf("%lld",&num);

    long long sum=0, rev, count=0;

    while(count++<130)
    {
        rev = reverse(num);
        sum = num + rev;
        printf("%lld + %lld = %lld\n",num, rev, sum);
        if(sum==reverse(sum))
            break;
        num = sum;
    }

    if(count<30)
        printf("Anti-Lychrel Number\n");
    else
        printf("Not Anti-Lychrel Number\n");
    return 0;
}
