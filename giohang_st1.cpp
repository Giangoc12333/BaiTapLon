#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct giohang_st{
	char TenKhachHang[30];
	char DiaChi[50];
	char STT[30];
	int sosanpham;
	typedef struct ds_sp dssp [30];
		char TenSP[30];
		int gia;
		int soluong;

}giohang_st;
void taogiohang(giohang_st *a,int n);
void chonhang(giohang_st *a,int n);
void xuatgiohang(giohang_st*a, int n);
void hienthi(giohang_st *a,int n);
void sapxep(giohang_st *a,int n);
void xemgiohang(giohang_st *a,int n);
void loaiMH(giohang_st *a,int n);
void ghifile(giohang_st *a, int n);
void docfile(giohang_st *a, int n);
void menu(giohang_st *a,int n){
	int chon;
	bool daNhap = false;
	while(true){
		system("cls");
        printf("**    		CHUONG TRINH QUAN LY GIO HANG	            **\n");
        printf("**        	1. Tao gio hang                             **\n");
        printf("**      	2. Chon hang                                **\n");
        printf("**      	3. xem chi tiet gio hang                    **\n");
        printf("**      	4. Loai bo mot mang hang                    **\n");
        printf("**      	5. Luu gio hang vao tep nhi phan cart.dat   **\n");
        printf("**        	6. Thoat      	                            **\n");
        printf("nhap su lua chon cua ban:");
        scanf("%d",&chon);
        switch(chon){
			case 1: 
        	printf("\nBan da chon muc chon tao gio hang hang");
			taogiohang(a,n);
            daNhap = true;
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
  			case 2:if(daNhap){
			printf("\nban da chon muc chon hang");
			chonhang(a,n);
			}
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
  			case 3:if(daNhap ){
			printf("\nban da chon muc xem gio hang");
			xemgiohang(a,n);
			}
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
  			case 4:if(daNhap){
			printf("\nban da chon muc loat mat hang");
			loaiMH(a,n);
		
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
			case 5:if(daNhap){
			printf("\nban da chon muc luu file");
			ghifile(a,n);
			printf("\nBan da Luu file thanh cong");
			docfile(a,n);
			}
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
  			case 6: 
			printf("\nBan da thoat chuong trinh");
			getch();
			return;
            default:
            printf("\nKhong co chuc nang nay!");
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
			}	
		}
	}
} 
// tao gio hang    		       	
void taogiohang(giohang_st *a,int n)
{
	printf("\n____________________________________\n");
		printf("\nMoi ban nhap Khach hang");
	for(int i=0; i<n;i++){
		printf("\nnhap ten khach hang %d: ",i+1);fflush(stdin);
		gets((a+i)->TenKhachHang);fflush(stdin);
		printf("\nnhap dia chi: ");
		gets((a+i)->DiaChi);fflush(stdin);
	}
}
//xuat gio hang
void xuatgiohang(giohang_st*a, int n){
	for(int i=0; i<n;i++){
		printf("\nDon Hang cua toi\n");
		printf("\nTen khach hang %d: ",i+1);
		puts((a+i)->TenKhachHang);
		printf("\nDia chi: ");
		puts((a+i)->DiaChi);
		printf("\nSan Pham: ");
		puts((a+i)->TenSP);
		if((a+i)->soluong==0){
		printf("\n Gio hang hien dang trong");
		}
	else {
	printf("\nSoluong:%d\n",(a+i)->soluong);
	printf("\nGia:%d\n",(a+i)->gia);
		}
	}
	printf("\n____________________________________\n"); 	
}
//tao danh sach san pham
void chonhang(giohang_st *a,int n)

{
	printf("\nMoi ban nhap san pham");
	for(int i=0; i<n;i++){
		printf("\nSTT:",i+1);fflush(stdin);
		gets((a+i)->STT);
		fflush(stdin);
		printf("\nNhap Ten San Pham %d: ",i+1);fflush(stdin);
		gets((a+i)->TenSP);
	    fflush(stdin);
	    printf("\nNhap so luong: ");
	    scanf("%d",&(a+i)->soluong);fflush(stdin);
		printf("\nNhap gia: ");
		scanf("%d",&(a+i)->gia);fflush(stdin);
	}	
	n++;
}
//sap xep them A-Z
void sapxep(giohang_st *a,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
		if(strcmp(a[i].TenSP,a[j].TenSP)==1){
		giohang_st c=a[i];
		a[i]=a[j];
		a[j]=c;
		}
	}
}
//hien thi DSSP 1.1
void hienthi(giohang_st *a,int n){
	for(int i= 0;i<n;i++){
	printf("\n%-10s %-10s %22d %20d ",(a+i)->STT,(a+i)->TenSP,(a+i)->gia,(a+i)->soluong);}
	
}
//hien thi DSSP 1.2
void hienthicot(){	
	printf("\n%-10s %-10s %20s %20s \n","STT","Ten San Pham", "gia", "soluong");
}
//tao muc xem gio hang(sap xep,xuat DSSP,xuat gio hang).
void xemgiohang(giohang_st *a,int n)
{
	sapxep(a,n);
	hienthicot();
	hienthi(a,n);
	xuatgiohang(a,n);
}
//loai bo mat hang.
void loaiMH(giohang_st *a, int n)
{
	int x, i;
	printf("\nnhap vi tri can xoa: ");
	scanf("%d", &x);
	printf("can loai bo san pham thu %d la: \n", x);

	for(i=x; i<n; i++)
	{
		a[i]=a[i+1];
	}
	n--;
	xuatgiohang(a,n);
	printf("\n____________________________________\n");
}
void ghifile(giohang_st *a, int n){
	getchar();
	char fname[26];
	printf("\nnhap ten file:");
	gets(fname);
	FILE* fOut=fopen(fname,"a");
	for(int i=0;i<n;i++){
		giohang_st cart=a[i];
		fprintf(fOut,"%20s %20s %20s %10d %10d ",cart.TenKhachHang,cart.DiaChi,cart.TenSP,cart.soluong,cart.gia);
		
	}
	fclose(fOut);
}
void docfile(giohang_st *a, int n){
	FILE* fOut=fopen("cart.dat","r");
	int i=0;
	if(fOut){
	for(;;){
		giohang_st cart=a[i];
		fprintf(fOut,"\n%-10s %-10s %-10s %20s %20s \n","Ten KhacH Hang","Dia Chi","Ten San Pham", "gia", "soluong");
		fprintf(fOut,"%20s %20s %20s %10d %10d \n",cart.TenKhachHang,cart.DiaChi,cart.TenSP,&cart.soluong,&cart.gia);
		if(feof(fOut)){
			break;
		}
		a[i++]=cart;
		
	}
	fclose(fOut);
	n=i;
}
}
int main()
{
	int n;
	giohang_st *b;
  	b=(giohang_st*)calloc(n+1,sizeof(giohang_st));
  	printf("\nNhap so luong khach hang: "); scanf("%d", &n);
	menu(b,n);
}	
