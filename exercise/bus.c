#include <stdio.h>
#include <stdlib.h>


struct passenger{
    char gender ;
    int check ;
};

struct bus{
    struct passenger pas[40];
};

void again(struct bus bus);
void check(struct bus bus);

void genderTwo(){
    printf("Erkek icin E(e) tusuna basiniz. \n");
    printf("Kadin icin K(k) tusuna basiniz. \n");
}

void rightWindow(struct bus bus){
    for (int i = 0; i < 10; ++i) {
        if(bus.pas[(4*i)+2].gender == 'e' || bus.pas[(4*i)+2].gender == 'E'){
            printf("|%i E|",(4*i)+3);
        } else if(bus.pas[(4*i)+2].gender == 'k' || bus.pas[(4*i)+2].gender == 'K'){
            printf("|%i K|",(4*i)+3);
        } else{
            printf("|%i X|",(4*i)+3);
        }
    }
}
void rightCorridor(struct bus bus){
    for (int i = 0; i < 10; ++i) {
        if(bus.pas[(4*i)+3].gender == 'e' || bus.pas[(4*i)+3].gender == 'E'){
            printf("|%i E|",(4*i)+4);
        } else if(bus.pas[(4*i)+3].gender == 'k' || bus.pas[(4*i)+3].gender == 'K'){
            printf("|%i K|",(4*i)+4);
        } else{
            printf("|%i X|",(4*i)+4);
        }
    }
}
void leftCorridor(struct bus bus){
    for (int i = 0; i < 10; ++i) {
        if(bus.pas[(4*i)+1].gender == 'e' || bus.pas[(4*i)+1].gender == 'E'){
            printf("|%i E|",(4*i)+2);
        } else if(bus.pas[(4*i)+1].gender == 'k' || bus.pas[(4*i)+1].gender == 'K'){
            printf("|%i K|",(4*i)+2);
        } else{
            printf("|%i X|",(4*i)+2);
        }
    }
}
void leftWindow(struct bus bus){
    for (int i = 0; i < 10; ++i) {
        if (((4*i)) == 8){
            if(bus.pas[(4*i)].gender == 'e' || bus.pas[(4*i)+1].gender == 'E'){
                printf("|9  E|");
            } else if(bus.pas[(4*i)].gender == 'k' || bus.pas[(4*i)+1].gender == 'K'){
                printf("|9  K|");
            } else{
                printf("|9  X|");
            }
        }else if(bus.pas[(4*i)].gender == 'e'){
            printf("|%i E|",(4*i)+1);
        } else if(bus.pas[(4*i)].gender == 'k'){
            printf("|%i K|",(4*i)+1);
        } else{
            printf("|%i X|",(4*i)+1);
        }
    }
}

void genderCheck(struct bus bus,int chair,int b,char gender){
    if(gender == 'e' || gender == 'E'|| gender == 'k' ||gender == 'K'){
        if (gender == bus.pas[(chair+b)].gender || bus.pas[(chair+b)].gender == 'X' ){
            char a;
            printf("\n======================================\n");
            printf("Bu koltuga kayit yaptirmak istiyor musunuz\n");
            printf("Evet ise E(e) tusuna basiniz\n");
            printf("Hayir ise H(h) tusuna basiniz\n");
            printf("======================================\n");
            scanf("\n%c",&a);
            if(a == 'e' || a == 'E'){
                printf("Kayit Basararili sekilde kaydedildi. iyi Yolculuklar\n");
                bus.pas[chair-1].check = 1;
                bus.pas[chair-1].gender = gender;
                check(bus);
                again(bus);
            }else if(a == 'h' || a == 'H'){
                printf("Yine Bekleriz.");
            } else{
                printf("Yanlis tuslama.");
            }
        }
        else{
            printf("Farkli cinsiyetler yan yana oturamaz");
        }

    } else{
        printf("\nYanlis tuslama.");
    }
}

void check(struct bus bus){
    printf("\n======================================\n");
    printf("sag  "); rightWindow(bus);
    printf("\n");
    printf("     "); rightCorridor(bus);
    printf("\n                         KORIDOR    Emre Turizm");
    printf("\n");
    printf("sol  "); leftCorridor(bus);
    printf("\n");
    printf("     "); leftWindow(bus);
    printf("\n======================================\n");
}

void chairYesNo(){
    printf("\n======================================\n");
    printf("Bu koltuk doludur yan kolduga bakmak ister misiniz?\n");
    printf("Evet ise E(e) tusuna basiniz.\n");
    printf("hayir ise H(h) tusuna basiniz.\n");
    printf("======================================\n");
}

void checkGender(struct bus bus, int chair, char gender, int b){
    if(bus.pas[chair-1].check == 0){
        genderTwo();
        printf("\nLutfen cinsiyetini giriniz! = ");
        scanf("\n%c",&gender);
        genderCheck(bus,chair,b,gender);
    }else if(bus.pas[(chair+b)].check == 0) {
        char x = 0;
        printf("\n======================================\n");
        chairYesNo();
        scanf("\n%c",&x);
        if(x == 'e' || x == 'E'){
            genderTwo();
            printf("\nLutfen cinsiyetini giriniz! = ");
            scanf("\n%c",&gender);
            if(bus.pas[chair-1].gender == gender){
                char a;
                printf("\n======================================\n");
                printf("Bu koltukga kayit yaptirmak istiyor musunuz\n");
                printf("Evet ise E(e) tusuna basiniz\n");
                printf("hayir ise H(h) tusuna basiniz\n");
                printf("======================================\n");
                scanf("\n%c",&a);
                if(a == 'e' || a == 'E'){
                    printf("Kayit Basararili sekilde kaydedildi. iyi Yolculuklar\n");
                    bus.pas[chair-b].check = 1;
                    bus.pas[chair-b].gender = gender;
                    check(bus);
                    again(bus);
                }else if(a == 'h' || a == 'H'){
                    printf("Yine Bekleriz.");
                } else{
                    printf("Yanlis tuslama.");
                }
            } else{
                printf("Farkli cinsiyetler yanyana oturamaz !");
                exit(0);
            }
        }else if(x == 'h' || x == 'H'){
            printf("Yine Bekleriz.");
        } else{
            printf("Yanlis tuslama.");
        }
    }
}

void line(struct bus bus){
    char gender = 0;
    char number = 0;
    int  chair  = 0;
    int  check  = 0;
    printf("\n======================================\n");
    printf("Sag cam kenarı için 1 tuşuna basınız.\n");
    printf("Sag koridor için 2 tuşuna basınız.\n");
    printf("Sol koridor için 3 tuşuna basınız.\n");
    printf("sol cam kenarı için 4 tuşuna basınız.\n");
    printf("Programdan çıkmak için 5 tuşuna basınız.\n");
    printf("======================================\n");
    scanf("\n%c",&number);
    if(number == '1'){
        rightWindow(bus);
        printf("\nLutfen koltuk numarasi seciniz! = ");
        scanf("\n%d", &chair);
        for (int i = 0; i < 10; ++i) {
            if( ((4*i)+3) == chair){
                int b = 0;
                checkGender(bus, chair, gender, b);
                check = 1;
            }
        }
        if(check == 0){
            printf("Yanlis tuslama girdiniz");
            exit(0);
        }
    }else if (number == '2'){
        rightCorridor(bus);
        printf("\nLutfen koltuk numarasi seciniz! = ");
        scanf("\n%d", &chair);
        for (int i = 0; i < 10; ++i) {
            if( ((4*i)+4) == chair){
                int b = -2;
                checkGender(bus, chair, gender, b);
                check = 1;
            }
        }
        if(check == 0){
            printf("Yanlis tuslama");
            exit(0);
        }

    }else if (number == '3'){
        leftCorridor(bus);
        printf("\nLutfen koltuk numarasi seciniz! = ");
        scanf("\n%d", &chair);
        for (int i = 0; i < 10; ++i) {
            if( ((4*i)+2) == chair){
                int b = -2;
                checkGender(bus, chair, gender, b);
                check = 1;
            }
        }
        if(check == 0){
            printf("Yanlis tuslama2");
            exit(0);
        }

    }else if (number == '4'){
        leftWindow(bus);
        printf("\nLutfen koltuk numarasi seciniz! = ");
        scanf("\n%d", &chair);
        for (int i = 0; i < 10; ++i) {
            if( ((4*i)+1) == chair){
                int b = 0;
                checkGender(bus, chair, gender, b);
                check = 1;
            }
        }
        if(check == 0){
            printf("Yanlis tuslama");
            exit(0);
        }
    }else if(number == '5'){
        printf("Program kapatiliyor...");
        exit(0);
    }else{
        printf("YANLIS TUSLAMA");
        exit(0);
    }
}
void again(struct bus bus){
    char a;
    printf("\n======================================\n");
    printf("Tekrar Koltuk almak ister misiniz\n");
    printf("Evet ise E(e) tusuna basiniz\n");
    printf("hayir ise H(h) tusuna basiniz\n");
    printf("======================================\n");
    scanf("\n%c",&a);
    if(a == 'e' || a == 'E'){
        line(bus);
    }else if(a == 'h' || a == 'H'){
        printf("Yine Bekleriz\n");
    } else{
        printf("Yanlis tuslama yaptiniz lutfen tekrar deneyinzi");
    }
}
void welcome(){
    struct bus bus;
    char yesNo;
    printf("\n======================================\n");
    printf("Merhaba! Rezervasyon yapmak ister misiniz?\n");
    printf("Evet ise E(e) tusuna basiniz\n");
    printf("hayir ise H(h) tusuna basiniz\n");
    printf("======================================\n");
    scanf("%c",&yesNo);
    if(yesNo == 'e' || yesNo == 'E'){
        for (int i = 0; i < 40; i++) {
            bus.pas[i].gender = 'X';
            bus.pas[i].check = 0;
        }
        check(bus);
        line(bus);
    }else if(yesNo == 'h' || yesNo == 'H'){
        printf("Program kapatiliyor...");
    } else{
        printf("Yanlis tuslama yaptiniz lutfen tekrar deneyinzi");
    }
}
int main() {
    welcome();
}
