#include<stdio.h>
#include<string.h>
struct Ten{
    char ho[10];
    char tenDem[10];
    char ten[10];
};
struct SinhVien{
    int id;
    struct Ten sv;
    int age;
    char phoneNumber[15];
};
typedef struct SinhVien sv;
void sortName( sv *arrSv);
int main(void){
    sv arrSv[5]={
        {1,"Nguyen"," Van"," B",18,"0987654320"},
        {2,"Nguyen"," Van"," E",19,"0987654321"},
        {3,"Nguyen"," Van"," C",20,"0987654322"},
        {4,"Nguyen"," Van"," D",21,"0987654323"},
        {5,"Nguyen"," Van"," A",22,"0987654324"},
    };
    sortName(arrSv);
    for(int i=0;i<5; i++){
        printf("%d \t", arrSv[i].id);
        printf("%s", arrSv[i].sv.ho);
        printf("%s", arrSv[i].sv.tenDem);
        printf("%s \t", arrSv[i].sv.ten);
        printf("%d \t", arrSv[i].age);
        printf("%s \t", arrSv[i].phoneNumber);
        printf("\n");
    }
    return 0;
}
void sortName(sv *arrSv){
    for(int i=0; i<4; i++){
        for(int j=0; j<5-i-1; j++){
            if(strcmp(arrSv[j].sv.ten,arrSv[j+1].sv.ten )>0){
                char arr[10];
                strcpy(arr, arrSv[j].sv.ten);
                strcpy( arrSv[j].sv.ten, arrSv[j+1].sv.ten);
                strcpy( arrSv[j+1].sv.ten, arr);
            }
        }
    }
}