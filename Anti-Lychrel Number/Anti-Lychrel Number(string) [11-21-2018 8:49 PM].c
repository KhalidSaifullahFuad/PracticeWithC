#include<stdio.h>

char number[1000], rev[1000], temp[1000], sum[1000];

int length(char ch[]);
void stringCopy(char str1[], char str2[]);
int stringCmp(char str1[], char str2[]);
void reverse(char str[]);
void printString(char str[]);
void fixingString(char str[], int len1, int len2);
void summation();

int main()
{
    printf("\n Enter  a Number : ");
    //Try 103972734991273489392710475699173. It will BLOOOOW!! your mind
    gets(number);

    int count = 0;

    while(1)
    {
        stringCopy(rev,number);
        reverse(rev);

        summation();

        printf(" %-2d. ",++count);
        printString(rev);
        printf(" + ");
        printString(number);
        printf(" = ");
        printString(sum);
        printf("\n");
//        printf("%s + %s = %s\n",number, rev, sum);

        stringCopy(temp,sum);
        reverse(temp);

        if(stringCmp(sum, temp)==1)
            break;

        stringCopy(number ,sum);
    }
    return 0;
}

int length(char ch[])
{
    int i=0;
    while(ch[i])
        i++;
    return i;
}

void stringCopy(char str1[], char str2[])
{
    int i = -1;
    while(str2[++i])
        str1[i] = str2[i];
}

int stringCmp(char str1[], char str2[])
{
    int i = -1;
    while(str1[++i] && str2[i])
        if(str1[i] != str2[i])
            return 0;
    return 1;
}

void reverse(char str[])
{
    int len = length(str);
    char rev[len+1];

    ///Copy String
    int i = -1;
    while(str[++i])
        rev[i] = str[i];
    rev[i] = '\0';

    ///start reversing
    int j = -1;
    while(len>=0)
        str[++j] = rev[--len];
    str[j]='\0';
    ///end;
}

void printString(char str[])
{
    int i=-1;

    while(str[++i])
    {
        if(i==0)
            while(str[i]=='0')
                i++;
        printf("%c",str[i]);
    }
}

void fixingString(char str[], int len1, int len2)
{
    while(len1<len2)
        str[len1++]='0';
    str[len1]=='\0';
}

void summation()
{
    int len, len1, len2, i, j, total, carray=0;

    len1 = length(number);
    len2 = length(rev);


    ///reversing two string. it's helpful
    reverse(number);
    reverse(rev);

    if(len1>len2)
        fixingString(rev, len2, len1);
    else if(len2>len1)
        fixingString(number, len1, len2);

    len = length(number);
    for(i=0; i<len; i++)
    {
        total = number[i] + rev[i] + carray - '0'; /// add two index and convert to number;

        if(total>'9'){
            sum[i] = total - 10;
            carray = (total-48)/10;
        }else{
            sum[i] = total;
            carray = 0;
        }
    }

    if(carray>0)
    {
        sum[i] = carray + '0';
        sum[i+1] = '\0';
    }else{
        sum[i]='\0';
    }

    reverse(sum);
}
