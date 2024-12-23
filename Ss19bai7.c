#include<stdio.h>
#include<string.h>
struct SinhVien{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
typedef struct SinhVien sv;
int delete(struct SinhVien *arrSv, int *temp, int *flag);
int main(void){
    sv arrSv[5]={
        {1,"Nguyen Van A",18,"0987654320"},
        {2,"Nguyen Van B",19,"0987654321"},
        {3,"Nguyen Van C",20,"0987654322"},
        {4,"Nguyen Van D",21,"0987654323"},
        {5,"Nguyen Van E",22,"0987654324"},
    };
    int temp=5;
    int flag=0;
        printf("Moi ban nhap id SV can xoa: ");
        scanf("%d", &flag);
        
    delete(arrSv, &temp, &flag);
    
        for(int i=0;i<temp; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }

    return 0;
}
int delete(struct SinhVien *arrSv, int *temp, int *flag){
    int count=0;
    for(int i=0; i<*temp; i++){
        if(*flag== i+1 ){
            count=1;
            *temp= *temp-1;
            for(int j=i; j< *temp; j++){
                strcpy(arrSv[j].name, arrSv[j+1].name);
                strcpy(arrSv[j].phoneNumber, arrSv[j+1].phoneNumber);
                arrSv[j].id=arrSv[j+1].id;
                arrSv[j].age=arrSv[j+1].age;
            }
        }
    }
    if(count!=1){
        printf("SV khong ton tai \n");
        return 1;
    }
    return 0;
}