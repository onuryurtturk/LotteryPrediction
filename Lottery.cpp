#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define Temizle system("cls")

void Sirala(int[]);

int main()
{
    int KolonSay,*Kolon,i,j,k,Collon;

    printf("Kac Kolon Oynamak Istersiniz?");
    scanf("%d",&KolonSay);

    Temizle;

    srand(time(NULL));

    for (i=1;i<=KolonSay;i++)
    {
        Kolon=(int *)malloc(6*sizeof(int));

        for (j=0;j<6;j++)
        {
KolonOlustur:
            *(Kolon+j) = rand()%49+1;

            for (k=j-1;k>=0;k--)
                if (Kolon[k]==Kolon[j]) goto KolonOlustur;
        }

        Sirala(Kolon); /*Kolon Elemanlarý Küçükten Büyüðe Siralanir */

        /* i. kolon ekrana yazdirilir */
        printf("\n\t%2d. Kolon: ",i);
        for (k=0;k<6;k++)
        {
            printf("%3d ",Kolon[k]);
            if (k!=5) printf("-");
        }

        free(Kolon);
    }

    printf("\n\n\t%d Kolon Fiyati %d TLdir. Bol Sanslar.",KolonSay,KolonSay);
    getch();
    return 0;
}


void Sirala(int Kolon[])
{
    char kontrol=0;
    int i;

    while (!kontrol)
    {
        kontrol=1;
        for (i=0;i<5;i++)
            if (Kolon[i]>=Kolon[i+1])
            {
                int temp=Kolon[i];
                Kolon[i]=Kolon[i+1];
                Kolon[i+1]=temp;
                kontrol=0;
            }
    }

}