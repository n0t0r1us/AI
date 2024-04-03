#include <stdio.h>
int check_bosong(int A[]){
int t=0;
if(A[1]==2&&A[2]==3&&A[0]!=1){
printf("Chet! Ho an thit trau rui!");
t=1;
}else if(A[2]==3&&A[3]==4&&A[0]!=1){
printf("Chet! Trau an co rui!");
t=1;
}else if(A[1]==-2&&A[2]==-3&&A[0]!=-1){
printf("Chet! Ho an thit trau rui!");
t=1;
}else if(A[2]==-3&&A[3]==-4&&A[0]!=-1){
printf("Chet! Trau an co rui!");
t=1;
}
return t;
}
void swap_vat(int i, int A[], int B[]){
int temp;
temp=A[i];
A[i]=B[i];
B[i]=temp;
}
void swap_nguoi(int A[], int B[]){
int temp;
temp=A[0];
A[0]=B[0];
B[0]=temp;
}
void dichuyen(int i, int A[], int B[]){
swap_nguoi(A,B);
swap_vat(i,A,B);
if(check_bosong(A)==1){
printf("\nGame over!\n");

}
if(A[0]==-1&&A[1]==-2&&A[2]==-3&&A[3]==-4){
printf("\nHoan tat viec chuyen do!\n");
printf("\nBan that la gioi!\n");
}
}

void main(){
printf("\t\t-----Nguoi Nong Dan Qua Song-----\n");
int i, A[]={1,2,3,4}, B[]={-1,-2,-3,-4};
int t=0;
while(t>=0){
printf("\n\t0.Nguoi\t 1.Ho\t2.Trau\t3.Bo co\n");
printf("Hay chon so tuong ung voi luot di: ");
scanf("%d",&i);
if(i==0){
swap_nguoi(A,B);
if(check_bosong(A)==1){
printf("\nGame over!\n");
exit(0);
}
}
else if((A[0]==1&&A[i]>0)||(A[0]==-1&&A[i]<0))
dichuyen(i,A,B);
else{
printf("Chac la ban quen thu gi do rui!");
printf("\nLai nhe!\n");
}
}
}
