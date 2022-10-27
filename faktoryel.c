#include <stdio.h>

int main() {
    int sayi;
    unsigned long long carpma = 1;
   printf("sayi gir : ");
   scanf("%i",&sayi);
   if(0<sayi){
       for (int i = 1; i <= sayi; ++i) {
           carpma *= i;
       }
       printf("%d sayisinin faktoryelli = %llu",sayi,carpma);
   }else{
       printf("Lutfen negatif ve sifir sayi girmeyiniz");
   }
}
