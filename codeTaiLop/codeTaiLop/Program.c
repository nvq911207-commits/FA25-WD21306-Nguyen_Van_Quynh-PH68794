// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#define ROWS 2 // Số hàng
#define COLS 3 // Số cột
 // ===== CHUC NANG KIEMTRASO =====
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int laSoChinhPhuong(int n) {
    int can = sqrt(n);
    return can * can == n;
}
void KTRSoNguyen() {
    int x;
    int tieptuc = 1;
    do {
        printf("Nhap so nguyen x: ");
        scanf_s("%d", &x);
        printf("-> %d la so nguyen\n", x);
        if (laSoNguyenTo(x)) printf("-> %d la so nguyen to\n", x);
        else printf("-> %d khong phai so nguyen to\n", x);
        if (laSoChinhPhuong(x)) printf("-> %d la so chinh phuong\n", x);
        else printf("-> %d khong phai so chinh phuong\n", x);
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}
// ===== CHUC NANG UCLNBCNN =====
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
void UCllBCNN() {
    int x, y;
    int tieptuc = 1;
    do {
        printf("Nhap 2 so nguyen x, y: ");
        scanf_s("%d%d", &x, &y);
        printf("Uoc so chung lon nhat: %d\n", UCLN(x, y));
        printf("Boi so chung nho nhat: %d\n", BCNN(x, y));
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}
// ===== CHUC NANG Mang =====
void Mang2Chieu() {
    int array[ROWS][COLS];
    int tieptuc = 1;
    do {
        printf("--- NHAP GIA TRI CHO MANG 2 CHIEU (%dx%d) ---\n", ROWS, COLS);
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("Nhap phan tu A[%d][%d]: ", i, j);
                scanf_s("%d", &array[i][j]);
            }
        }
        printf("\n--- MANG 2 CHIEU VUA NHAP ---\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%4d", array[i][j]);
            }
            printf("\n"); 
        }
        printf("\nTiep tuc chuc nang Mang 2 chieu? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1); 
// ===== MENU CHÍNH =====
int main() {
    int chon;
    do {
        printf("\n===== MENU CHUONG TRINH =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Mang 2 chieu\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &chon);
        switch (chon) {
        case 1: KTRSoNguyen(); break;
        case 2: UCllBCNN(); break;
        case 3: Mang2Chieu(); break;
        case 0: printf("Tam biet!\n"); break;
        default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}


// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Mo "View" > "Solution Explorer"
//          de them/quan ly cac files
//   2. Mo "View" > "Output"
//          de kiem tra "build output" va "cac thong bao khac"
//   3. Mo "View" > "Error List"
//          de xem loi
//   4. Chon Project > "Add" > "New Item"
//          de tao moi file code,
//      hoac Project > "Add" > "Existing Item"
//          de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//          chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//          trong cua so "Solution Explorer"
//          bam chuot phai vao "Solution"
//          chon "Open Folder in File Explorer"

// GV: AnhTT184