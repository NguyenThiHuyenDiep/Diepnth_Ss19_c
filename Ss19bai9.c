#include<stdio.h>
#include<string.h>
struct Student{
    int id;
    char name[20];
    int age;
    char number[15];
};
void printfMenu(struct Student *menu, int member);// case 1
int addMenu(struct Student *menu, int *member, int *index); // case 2
void deleteEnter(struct Student *menu, int *member, int *index); // xoa enter khi in
void fixMenu(struct Student *menu, int *member, int *index);// case3
void deleteMenu(struct Student *menu, int *member, int *index);// case 4
void increaseMenu(struct Student *menu, int *member); // sx tang
int linearSearch(struct Student *menu, int *member);// tim kiem tuyen tinh
int main(void){
    struct Student menu[100]={
        {1, "Nguyen Van B", 20,"0987654325"},
        {2, "Nguyen Van A", 18,"0987654345"},
        {3,"Le Thi H", 19,"0324567543"},
        {4,"Nguyen Tran T", 18,"0543217658"},
        {5, "Phi Thi L", 21,"0732645891"},
    };
    int choose=0, member=5, index=0;
    printf("\tMENU \n 1. Hien thi danh sach sinh vien \n 2. Them sinh vien \n 3. Sua thong tin sinh vien \n 4. Xoa sinh vien \n 5. Tim kiem sinh vien( theo age) \n 6. Sap xep danh sach sinh vien( theo age) \n 7. Thoat \n");
    do{
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printfMenu(menu, member);
                break;
            case 2:
                addMenu(menu, &member, &index);
                break;
            case 3:
                fixMenu(menu, &member, &index);
                break;
            case 4:
                deleteMenu(menu, &member, &index);
                break;
            case 5:
                linearSearch(menu,&member);
                break;
            case 6:
                increaseMenu(menu, &member);
                break;
            case 7:
                printf("Ban da chon thoat \n");
                break;
            default:
                printf("Lua chon cua ban khong co trong MENU \n");
        }
    }while(choose!=7);
    
    return 0;
}
// case 1
void printfMenu(struct Student *menu, int member){
    for(int i=0; i<member; i++){
        printf("%d\t %s\t %d\t %s \n", menu[i].id, menu[i].name, menu[i].age,menu[i].number);
    }
}
void deleteEnter(struct Student *menu, int *member, int *index){ // xoa enter khi in
    for(int k=0; k< 50; k++){
        if(menu[*index].name[k] =='\n'){
            menu[*index].name[k]='\0';
        }
    }
}
// case2
int addMenu(struct Student *menu, int *member, int *index){
    printf("Moi ban nhap vi tri muon them: ");
    scanf("%d", index);
    if(*index <0 || *index >=100){ // vi tri sai
        printf("Vi tri ban nhap khong hop le \n");
        return 1;
    }else if(*index>=0 && *index< (*member)){   // 0<=index<member
        if(strcmp("**********", menu[*index].name)==0){// neu chua co ten
            printf("Moi ban nhap ten mon moi: ");
            getchar();
            fgets(menu[*index].name, 50, stdin);
            deleteEnter(menu, member, index);
            printf("Moi ban nhap tuoi mon moi: ");
            scanf("%d", &menu[*index].age);
            menu[*index].id=*index+1;
            printf("Moi ban nhap sdt mon moi: ");
            getchar();
            fgets(menu[*index].number, 50, stdin);
            for(int k=0; k< 50; k++){
                if(menu[*index].number[k] =='\n'){
                    menu[*index].number[k]='\0';
                }
            }
            return 1;
        }else{ // vi tri chen
            for(int i= *member; i>= *index; i--){
                menu[i].id=i+1;
                strcpy(menu[i].name, menu[i-1].name);
                menu[i].age=menu[i-1].age;
                strcpy(menu[i].number, menu[i-1].number);
            }
            *member=*member+1;
        }
        
    }else{ // ngoai co san
        for(int i=(*index); i>=(*member); i--){
            menu[i].id=0;
            strcpy(menu[i].name,"**********");
            menu[i].age=0;
            strcpy(menu[i].number,"**********");
        }
        *member=*index+1;
       
    }
    printf("Moi ban nhap ten mon moi: ");
    getchar();
    fgets(menu[*index].name, 50, stdin);
    deleteEnter(menu, member, index);
    printf("Moi ban nhap tuoi mon moi: ");
    scanf("%d", &menu[*index].age);
    menu[*index].id=*index+1;
    printf("Moi ban nhap sdt mon moi: ");
    getchar();
    fgets(menu[*index].number, 50, stdin);
    for(int k=0; k< 50; k++){
        if(menu[*index].number[k] =='\n'){
            menu[*index].number[k]='\0';
        }
    }
        return 0;
}
// case 3
void fixMenu(struct Student *menu, int *member, int *index){
    printf("Nhap vi tri ban muon sua: ");
    scanf("%d", index);
    if(0<= *index && *index<= *member){
        printf("Moi ban nhap ten muon doi: ");
        getchar();
        fgets(menu[*index].name, 50, stdin);
        deleteEnter(menu, member, index);
        printf("Moi ban nhap tuoi muon doi: ");
        scanf("%d", &menu[*index].age);
        printf("Moi ban nhap sdt mon moi: ");
        getchar();
        fgets(menu[*index].number, 50, stdin);
        for(int k=0; k< 50; k++){
            if(menu[*index].number[k] =='\n'){
                menu[*index].number[k]='\0';
            }
        }
    }else{
        printf("Vi tri muon sua khong hop le \n");
    }
}
// case 4
void deleteMenu(struct Student *menu, int *member, int *index){
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", index);
    if(0<= *index && *index<=*member){
        for(int i= *index; i<=*member; i++){
            strcpy(menu[i].name, menu[i+1].name);
            menu[i].age=menu[i+1].age;
            strcpy(menu[i].number, menu[i+1].number);
        }
        *member=*member-1;
    }else{
        printf("Vi tri muon xoa khong hop le \n");
    }
}
 
// case 6
void increaseMenu(struct Student *menu, int *member){ // sx tang
    for(int i=0; i< *member -1; i++){
        for(int j=0; j< *member-i-1; j++){
            if(menu[j].age > menu[j+1]. age ){
                // sx gia tuoi
                int count= menu[j].age;
                menu[j].age= menu[j+1].age;
                menu[j+1].age= count;
                // sx id
                int flag= menu[j].id;
                menu[j].id= menu[j+1].id;
                menu[j+1].id= flag;
                // sx ten
                char arr[50];
                strcpy(arr,menu[j].name);
                strcpy(menu[j].name, menu[j+1].name);
                strcpy(menu[j+1].name, arr);
                char num[50];
                strcpy(num,menu[j].number);
                strcpy(menu[j].number, menu[j+1].number);
                strcpy(menu[j+1].number, num);
            }
        }
    }
}
// case 5
// tuyen tinh
int linearSearch(struct Student *menu, int *member){
    int temp=0;
    printf("Moi ban nhap tuoi muon tim: ");
    getchar();
    scanf("%d", &temp);
    
    for(int i=0; i<*member; i++){
        if(temp==menu[i].age){
            printf("%d\t %s\t %d\t %s \n", menu[i].id, menu[i].name, menu[i].age,menu[i].number);

        }
    }
    return 0;
}