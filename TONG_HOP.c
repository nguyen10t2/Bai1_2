#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define oo __INT_MAX__
#define forl(i,a,b) for(int i=0;i<a;i+=b)
long long c[50][50];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void np(long n){
    // trả về 0 nếu n =0
    if (n==0){
        printf("0");
        return;
    }
    // khởi tạo xâu có 32 ký tự
    int str[32]; // dem_so kiểm tra số lượng chữ số còn lại của n
    int dem_so = 0; // chia 2 dư bao nhiêu thêm vào mảng
    while (n>0){
        str[dem_so] = n % 2;
        n = n / 2;
        dem_so ++;
    } // input mảng theo chiều ngược lại
    printf("\nĐổi nhị phân là: ");
    for (int i=dem_so-1;i>=0;i--){
        printf("%d",str[i]);
    }
}
int min2(int a,int b){
    if (a>b) return b;
    else return a;
}
int minpath(int m, int n, int a[m][n]){
    // khởi tạo 1 ma trận mới update liên tục
    int dx[m][n];
    // giữ nguyên cột đầu tiên
    for (int i=0;i<m;i++) dx[i][0] = a[i][0];
    for (int j=1;j<n;j++)
      for (int i=0;i<m;i++){
        // hàng trên cùng thì chỉ được 2 ô chiếu tới bằng min của 2 ô nguồn trong dx + chính ô đang xét trong a
        if (i==0) dx[i][j] = min2(dx[i][j-1], dx[i+1][j-1]) + a[i][j];
        //tương tự nhưng có 3 ô nguồn
        if (i !=0 && i !=m-1) dx[i][j] = min2(min2(dx[i-1][j-1], dx[i][j-1]), dx[i+1][j-1]) + a[i][j];
        // có 2 ô nguồn
        if (i == m-1) dx[i][j] = min2(dx[i-1][j-1], dx[i][j-1]) + a[i][j];
      }
    // tìm min ở cột cuối cùng
    int min = dx[0][n-1];
    for (int i=1;i<m;i++){
        if (dx[i][n-1]<min) min = dx[i][n-1];
    }
    //trả về min
    return min;
}
long C(int k, int n){
    // khởi tạo 2 nguồn nhỏ nhất của đệ qui
    if (k==0 || k==n) return 1;
    if (k==1 || k==n-1) return n;
    // theo công thức truy hồi của c(k,n)
    return C(k-1,n-1) + C(k,n-1);
}
long giai_thua(int n){
   long x=1;
   for (int i=2;i<=n;i++){
      x = x * i;
   }
   return x;
}
long to_hop(int k, int n){
   if (k==0 || k==n) return 1;
   return giai_thua(n)/(giai_thua(k)*giai_thua(n-k));
}
void dao_nguoc(char str[], int do_dai){
   int bat_dau = 0;
   int ket_thuc = do_dai - 1;
   // đổi chỗ 2 phần tử đối xứng nhau
   do {
    char ki_tu_phu = str[bat_dau];
    str[bat_dau] = str[ket_thuc];
    str[ket_thuc] = ki_tu_phu;
    bat_dau ++;
    ket_thuc --;
   }while (bat_dau<ket_thuc);
   // xóa ký tự 0 đầu chuỗi
   // nếu ký tự đầu tiên là 0 thì dịch nó sang trái 1 lần (độ dài khi dịch chuyển = độ dài xâu cũ )
   // độ dài xâu sẽ được cập nhật mỗi khi dịch chuyển
   while (str[0] == '0'){
    memmove(str, str+1, strlen(str));
   }
   // đề phòng chuỗi có đúng 1 ký tự 0 thì trả về 0
   if(strlen(str) == 0) {
    str[0] = '0';
    str[1] = '\0';// Ký tự kết thúc mà ko chiếm bộ nhớ
   }
}
void to_hop_qhd(){
   // Ma trận tam giác trên
   // C(0,n) = c(n,n) = 1
   for (int i=0;i<50;i++){
      c[i][i] = 1;
      c[0][i] = 1;
   }
   // C(k,n) thì k<=n mới có nghĩa nên j chạy từ i+1
   for (int i=1;i<50;i++){
      for (int j=i+1;j<50;j++){
         // Truy hồi của C(k,n)
          c[i][j] = c[i][j-1] + c[i-1][j-1];
      }
   }
}
void bai1(){
    //số phần tử
   int n;
   printf("Nhập số phần tử: ");
   scanf("%d",&n);
   //khởi tạo mảng có n phần tử
   long a[n];
   printf("Nhập các phần tử: ");
   //đọc tham trị của mảng
   for (int i=0;i<n;i++) scanf("%ld",&a[i]);
   //Sắp xếp mảng bằng hàm qsort() trong thư viện stdlib.h
   qsort(a,n,sizeof(long),cmp);
   //sau khi sắp xếp nếu phần tử đầu tiên = cuối => dãy hằng
   if (a[n-1] == a[0]) printf("NOT FOUND");
   else {
    // duyệt từ cuối mảng lên nếu thấy bất kì phần tử nào khác max thì in ra và kết thúc
    printf("\nPhần tử lớn thứ 2 là: ");
      for (int i=n-2;i>=0;i--){
         if (a[n-1] > a[i])
         {
             printf("%ld",a[i]);
             return ;
         }
      }       
   }
}
void bai2(){
   int n;
   printf("Nhập n: ");
   scanf("%d",&n);
   // kiểm tra điều kiện đầu vào
   if (n>=65536) printf("TOO BIG");
   // đúng điều kiện mới gọi hàm
   else np(n);
   return ;
}
void bai3(){
    //khai báo số phần tử của mảng
    long n;
    printf("Nhập số phần tử: ");
    scanf("%ld",&n);
    //khai báo mảng có n phần tử
    long a[n];
    // nhập phần tử từ bàn phím
    printf("Nhập các phần tử: ");
    for (long i=0;i<n;i++) scanf ("%ld",&a[i]);
    // sử dụng qsort() có sắn trong stdlib.h
    qsort(a,n,sizeof(long),cmp);
    // in ra mảng mới đã được sắp xếp
    printf("Mảng sau khi sắp xếp: ");
    for (long i=0;i<n;i++) printf("%ld ",a[i]);
    return ;
}
void bai4(){
   int m,n;
    // nhập số hàng, cột
    printf("Nhập số hàng, số cột: ");
    scanf("%d%d",&m,&n);
    int a[m][n];
    // đọc hàng trước, cột sau
    printf("Nhập mảng:\n");
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    //in ra ô min tìm đc
    printf("Tổng số trên đường đi ngắn nhất là: %d",minpath(m,n,a));
    return ;
}
void bai5(){
   //Khai báo số phần tử của mảng và số cần tìm
    long so_pt,so_can_tim;
    // đọc từ bàn phím
    printf("Nhập số phần tử và số cần tìm: ");
    scanf("%ld%ld",&so_pt,&so_can_tim);
    //Khai báo mảng có số phần tử +1 và chèn phần tử cuối là số cần tìm
    long mang[so_pt+1];
    mang[so_pt] = so_can_tim;
    // đọc từ bàn phím mảng 
    printf("Nhập mảng: ");
    for (long i=0;i<so_pt;i++) scanf("%ld",&mang[i]);
    // chạy mảng theo 2 chiều
    long bat_dau = 0,ket_thuc = so_pt - 1;
    // tiếp tục cộng cho biến bat_dau nếu phần tử tại đó còn khác số cần tìm
    while (mang[bat_dau] != so_can_tim){
        bat_dau++;
    }
    // nó sẽ chạy đến phần tử cuối cùng được gán ở trên và in ra điều kiện
    if (bat_dau == so_pt) printf("NO");
    else{
    printf("Vị trí tìm thấy: ");
    printf("%ld",bat_dau);
    //tương tự với chiều kia
    while (mang[ket_thuc] != so_can_tim){
        ket_thuc--;
      } printf(" %ld",ket_thuc);
    }
    return;
}
void bai6(){
   int k,n;
   //đọc k,n từ bàn phím
   printf("Nhập k và n: ");
   scanf("%d%d",&k,&n);
   // hàm trả về long nên cứ in ra thôi !
   printf("C(%d,%d) = ",k,n);
   printf("%ld",C(k,n));
   return;
}
void bai7(){
  int k,n;
   //đọc k,n từ bàn phím
   printf("Nhập k và n: ");
   scanf("%d%d",&k,&n);
   //hàm to_hop trả về giá trị long nên ouput thôi!
   printf("C(%d,%d) = ",k,n);
   printf("%ld",to_hop(k,n));
   return ;
}
void bai8(){
  long n;
  printf("Nhập n: ");
    scanf("%ld",&n);
    //Kiểm tra điều kiện
    if (n > 10000000000) printf("TOO BIG");
    else {
    char str[1001];
    //đọc str bằng n
    sprintf(str,"%ld", n);
    // Gọi hàm dao_nguoc
    dao_nguoc(str,strlen(str));
    //output chuỗi str sau khi được đảo
    printf("Số sau khi đảo ngược: %s",str);
    }
    return;
}
void bai9(){
   int k,n;
   // Đọc k,n từ bàn phím
   printf("Nhập k và n: ");
   scanf("%d%d",&k,&n);
   // Gọi hàm
   to_hop_qhd();
   // In ra giá trị nào cũng được mà ko cần chạy bất cứ cái gì nữa vì mảng a toàn cục
   printf("C(%d,%d) = %lld",k,n,c[k][n]);
   return ;
}
void bai10(){
  int n;
    // biến giá trị (num dec 10)
    long so_thap_phan =0;
    // đọc số phần tử của mảng
    printf("Nhập số phần tử: ");
    scanf("%ld",&n);
    //khai báo mảng có n phần tử
    int a[n];
    //đọc các giá trị của a từ bàn phím
    printf("Nhập mảng bit 01: ");
    for (long i=0;i<n;i++) scanf("%d",&a[i]);
    // 100 = 4 = 0*2^0 + 0*2^1 + 0*2^1
    for (long i=0;i<n;i++){
        // theo công thức trên
       so_thap_phan += a[n-1-i] * pow(2,i);
    }
    //output ra dec 10
    printf("Sau khi đổi sang thập phân: %ld",so_thap_phan);
    return ;
}
void bai11(){
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
void bai12(){
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
void main(){
    int n;
    printf("Nhập bài cần tìm: "); scanf("%d",&n);
    switch (n){
        case 1:
           printf("Bài 3_1: Phần tử lớn thứ 2 của mảng!\n");
           bai1();
            break;  
        case 2:
           printf("Bài 3_2: Đổi số Nhị Phân!\n");
           bai2();
           break;
        case 3:
           printf("Bài 3_3: Sắp xếp dãy số!\n");
           bai3();
           break;
        case 4:
           printf("Bài 3_4: MinPath!\n");
           bai4();
           break;
        case 5:
           printf("Bài 3_5: Tìm kiếm trong mảng!\n");
           bai5();
           break;
        case 6:
           printf("Bài 3_6: Tính tổ hợp chập k của n (đệ quy)!\n");
           bai6();
           break;
        case 7:
           printf("Bài 3_7: Tính tổ hợp chập k của n bằng vòng lặp!\n");
           bai7();
           break;
        case 8:
           printf("Bài 3_8: Tìm số đảo ngược!\n");
           bai8();
           break;
        case 9:
           printf("Bài 3_9: Tính tổ hợp chập k của n bằng qui hoạch động!\n");
           bai9();
           break;
        case 10:
           printf("Bài 3_10: Tính giá trị số nhị phân!\n");
           bai10();
           break;
        case 11:
           printf("Bài tập về nhà 1!\n");
           bai11();
           break;
        case 12:
           printf("Bài tập về nhà 2!\n");
           bai12();
           break;
        default: 
           printf("Nhập lại!");
           main();
    }
}