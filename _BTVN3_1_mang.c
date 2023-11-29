#include <stdio.h>
#define oo  __INT_MAX__
#define forl(i,a,b) for(int i=0;i<a;i+=b)// define sẵn tý đỡ viết lại
int main(){
   int n;//số phần tử của mảng
   printf("Nhập số phần tử: "); scanf("%d",&n);
   int a[n];//khai báo mảng có n phần tử
   printf("Nhập các phần tử: ");
   forl(i,n,1) scanf("%d",&a[i]);
   int tong = 0, max = a[0], min = a[0]; 
   printf("Mảng là: ");
   forl(i,n,1) {
    printf("%d ",a[i]); // In ra mảng
    tong += a[i];
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
   }
   printf("\nTổng, max, min của mảng là: %d %d %d",tong,max,min);
   int tong_le = 0, max_le = -oo, min_le = oo;
   int tong_chan = 0, max_chan = -oo, min_chan = oo;
   forl(i,n,1){
    if (i%2==0){
        tong_chan += a[i];
        if (a[i]>max_chan) max_chan = a[i];
        if (a[i]<min_chan) min_chan = a[i];   
       }
    else {
        tong_le += a[i];
        if (a[i]>max_le) max_le = a[i];
        if (a[i]<min_le) min_le = a[i];
    }
   }
   printf("\nTổng, min, max của các phần tử vị trí chẵn là: %d, %d, %d",tong_chan,min_chan,max_chan);
   printf("\nTổng, min, max của các phần tử vị trí lẻ là: %d, %d, %d",tong_le,min_le,max_le);
   int tong_gtchan = 0, min_gtchan = oo, max_gtchan = -oo;
   int tong_gtle = 0, min_gtle = oo, max_gtle = -oo;
   printf("\nCác phần tử chẵn là: ");
   forl(i,n,1){
      if (a[i] %2 ==0) printf("%d ",a[i]);
   }
   printf("\nCác phần tử lẻ là: ");
   forl(i,n,1){
      if (a[i] %2 != 0) printf("%d ",a[i]);
   }
   forl(i,n,1){
     if (a[i] %2 ==0){
        tong_gtchan += a[i];
        if (a[i]>max_gtchan) max_gtchan = a[i];
        if (a[i]<min_gtchan) min_gtchan = a[i];
     }
     if (a[i] %2 !=0){
        tong_gtle += a[i];
        if (a[i]>max_gtle) max_gtle = a[i];
        if (a[i]<min_gtle) min_gtle = a[i];
     }
   }
   if (min_gtchan == oo){
      min_gtchan = 0;
   }
   if (max_gtchan == -oo){
      max_gtchan = 0;
   }
   if (min_gtle == oo){
      min_gtle = 0;
   }
   if (max_gtle == -oo){
      max_gtle = 0;
   }
   printf("\nTổng, min, max của các phần tử có giá trị chẵn là: %d, %d, %d",tong_gtchan,min_gtchan,max_gtchan);
   printf("\nTổng, min, max của các phần tử có giá trị lẻ là: %d, %d, %d",tong_gtle,min_gtle,max_gtle);
}