#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void decryption(int d,int N);

int calculateGCD(int x, int y)
{
    int i,gcd;

    if(x==y)
    {
        return x;
    }
    else
    {
        for(i=1;x>=i,y>=i;i++)
        {
            if(x%i==0&&y%i==0)
            {
                gcd=i;
            }
        }
    }
    return gcd;

}

int main()
{
    int primeNum1,primeNum2,N,Qn,a,e,b,d;

    printf("Enter any two prime number: ");

    scanf("%d %d",&primeNum1,&primeNum2);

    N=primeNum1*primeNum2;

    Qn=(primeNum1-1)*(primeNum2-1);

    for(a=2; a<Qn; ++a)
    {
        if(calculateGCD(a,N)==1 && calculateGCD(a,Qn)==1)
        {
            e=a;
            break;
        }
    }

    for(b=1;;++b)
    {
        if((e*b)%Qn==1 && e!=b)
        {
            d=b;
            break;
        }
    }
    printf("The keys are N=%d Qn=%d e=%d d=%d",N,Qn,e,d);
    decryption(d,N);

}

void decryption(int d, int N)
{
    int i,x;
    long double pw;
    char str[500],str2[500];

    printf("\nEnter your encrypted message: ");
    fflush(stdin);
    gets(str);

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            str2[i]=str[i];
        }

        else if(str[i]>=97&&str[i]<=122)
        {
            x=(int)str[i];
            x=x-96;
            pw=pow((double)x,(double)d);
            str2[i]=(((int)pw%N)+96);
            //str2[i]=(((x)^d)%N)+96;
        }
        else if(str[i]>=65&&str[i]<=90)
        {
            x=(int)str[i];
            x=x-64;
            pw=pow((double)x,(double)d);
            str2[i]=(((int)pw%N)+64);
            //str2[i]=(((x)^d)%N)+64;
        }
    }
    str2[i]='\0';
    printf("The decrypted message is: ");
    puts(str2);
}
