#include <stdio.h>
#define oo __INT_MAX__
#define forl(i,a,b) for(int i=0;i<a;i+=b)// define sẵn tý đỡ viết lại
int main(){
   int n,x;//số phần tử của mảng
   printf("Nhập số phần tử: "); scanf("%d",&n);
   printf("Nhập số cần xét: "); scanf("%d",&x);
   int a[n];//khai báo mảng có n phần tử
   printf("Nhập các phần tử: ");
   forl(i,n,1) scanf("%d",&a[i]);
   printf("Mảng là: ");
   int dem = 0, dem_duong = 0, dem_am = 0;
   int max = -oo, min = oo;
   forl(i,n,1){
      printf("%d ",a[i]);
      if (a[i] == x) dem ++;
      if (a[i]>0) dem_duong++;
      if (a[i]<0) dem_am++;
      if (a[i]>max) max = a[i];
      if (a[i]<min) min = a[i];
   }
   printf("\nCác phần tử chia hết cho %d là: ",x);
   forl(i,n,1){
    if (a[i] %x ==0) printf("%d ",a[i]);
   }
   printf("\nCác phần tử không chia hết cho %d là: ",x);
   forl(i,n,1){
    if (a[i] %x !=0) printf("%d ",a[i]);
   }
   printf("\nSố phần tử dương là: %d",dem_duong);
   printf("\nSố phần tử âm là: %d",dem_am);
   printf("\nVị trí max là: ");
   forl(i,n,1){
      if (a[i] == max) printf("%d, ",i);
   }
   printf("\nVị trí min là: ");
   forl(i,n,1){
      if (a[i] == min) printf("%d, ",i);
   }
}