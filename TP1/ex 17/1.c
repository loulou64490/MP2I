#include<stdio.h>

int main(){
    int x=1;
    printf("Entrez un entier : ");
    scanf("%d",&x);
    if (x==0){
        printf("C'est un zero");
    } else{
        printf("C'est pas un zero");
    }
    return 0;
}