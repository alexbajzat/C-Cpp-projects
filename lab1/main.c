#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
    //functia primeste un numar si verifica daca este prim
    // n - de tipul int , trebuie sa fie mai mare ca 0
    // returneaza true in cazul in care numarul este prim , false in caz  contrar

    if(n<=1)
        return 0;
    int i=2;
    for(i=2;i<=n/2;i++)
    {

        if (n%i==0)
        return 0;

    }
    return 1;
}

void printAllPrimes(unsigned n)
{   /*
    functia verifica numere succesive pana gaseste n numere prime
    n este de tipul int , n>0
    functia nu returneaza nimic
    */


    int number=2;
    while(n>0)
    {
        if (prime(number))
        {   printf("%d",number);
            printf("\n");
            n--;
        }
    number++;

    }
}

int main()
{
    int optiune=1;

    while(optiune){
            optiune=0;
    unsigned count;
    printf("introduceti numarul:");
    scanf("%d",&count);
    printAllPrimes(count);

    printf(" Continue-1 , Exit-0 \n");
    scanf("%d",&optiune);
    if(!optiune)
        break;
    }

    return 0;
}
