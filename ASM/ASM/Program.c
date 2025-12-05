// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 100

// ===== CHUC NANG 1 =====
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

void chucNang1() {
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

// ===== CHUC NANG 2 =====
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
void chucNang2() {
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

// ===== CHUC NANG 3 =====
void chucNang3() {
    float start, end;
    int tieptuc = 1;
    do {
        printf("Nhap gio bat dau (12 - 23): ");
        scanf_s("%f", &start);
        printf("Nhap gio ket thuc (12 - 23): ");
        scanf_s("%f", &end);

        if (start < 12 || end > 23 || start >= end) {
            printf("Khung gio khong hop le!\n");
            return;
        }

        float gio = end - start;
        float tien = 0;

        if (gio <= 3)
            tien = gio * 150000;
        else
            tien = 3 * 150000 + (gio - 3) * 150000 * 0.7;

        // Giam 10% neu trong khung 14–17
        if (start >= 14 && start <= 17)
            tien *= 0.9;

        printf("Tong tien can thanh toan: %.0f VND\n", tien);
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 4 =====
void chucNang4() {
    int kwh;
    int tieptuc = 1;
    double tien = 0;
    do {
        printf("Nhap so dien (kWh): ");
        scanf_s("%d", &kwh);

        if (kwh <= 50)
            tien = kwh * 1678;
        else if (kwh <= 100)
            tien = 50 * 1678 + (kwh - 50) * 1734;
        else if (kwh <= 200)
            tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
        else if (kwh <= 300)
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
        else if (kwh <= 400)
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
        else
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

        printf("Tien dien phai tra: %.0f VND\n", tien);
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 5 =====
void chucNang5() {
    int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int tien, i;
    int tieptuc = 1;
    do {
        printf("Nhap so tien can doi: ");
        scanf_s("%d", &tien);

        printf("So tien %d duoc doi ra:\n", tien);
        for (i = 0; i < 9; i++) {
            int soTo = tien / menhGia[i];
            if (soTo > 0) {
                printf("%d to menh gia %d\n", soTo, menhGia[i]);
                tien -= soTo * menhGia[i];
            }
        }
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}
// ===== CHUC NANG 6 =====
void chucNang6() {
    long tienVay;
    float laiSuat = 0.05;   // 5% / thang
    int kyHan = 12;
    int tieptuc = 1;
    do {

        printf("Nhap so tien muon vay: ");
        scanf_s("%ld", &tienVay);

        long gocPhaiTra = tienVay / kyHan;   // Tra goc co dinh moi thang
        long soTienConLai = tienVay;

        printf("\n%-7s %-12s %-12s %-15s %-15s\n",
            "Ky han", "Lai phai tra", "Goc phai tra", "Tong phai tra", "So tien con lai");

        for (int i = 1; i <= kyHan; i++) {
            long laiPhaiTra = soTienConLai * laiSuat;
            long tongPhaiTra = laiPhaiTra + gocPhaiTra;
            soTienConLai -= gocPhaiTra;

            printf("%-7d %-12ld %-12ld %-15ld %-15ld\n",
                i, laiPhaiTra, gocPhaiTra, tongPhaiTra, soTienConLai < 0 ? 0 : soTienConLai);
        }
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 7 =====
void chucNang7() {
    float phanTramVay;
    const float giaTriXe = 500000000;
    const int namVay = 24;
    const float laiSuatNam = 0.072;
    int tieptuc = 1;
    do {

        printf("Nhap phan tram vay toi da : ");
        scanf_s("%f", &phanTramVay);

        float soTienVay = giaTriXe * phanTramVay / 100;
        float traTruoc = giaTriXe - soTienVay;
        int thang = namVay * 12;
        float laiThang = laiSuatNam / 12;
        float traHangThang = (soTienVay * laiThang) / (1 - pow(1 + laiThang, -thang));

        printf("So tien phai tra lan dau: %.0f VND\n", traTruoc);
        printf("So tien phai tra hang thang trong %d thang: %.0f VND\n", thang, traHangThang);
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 8 =====
typedef struct {
    char ten[50];
    float diem;
    char hocLuc[20];
} SinhVien;

void xepLoai(SinhVien* sv) {
    if (sv->diem >= 9.0) strcpy(sv->hocLuc, "Xuat sac");
    else if (sv->diem >= 8.0) strcpy(sv->hocLuc, "Gioi");
    else if (sv->diem >= 6.5) strcpy(sv->hocLuc, "Kha");
    else if (sv->diem >= 5.0) strcpy(sv->hocLuc, "Trung binh");
    else strcpy(sv->hocLuc, "Yeu");
}

void chucNang8() {
    int n;
    int tieptuc = 1;
    do {
        SinhVien sv[MAX];
        printf("Nhap so luong sinh vien: ");
        scanf_s("%d", &n);
        getchar(); // bo ky tu Enter

        for (int i = 0; i < n; i++) {
            printf("Nhap ten SV %d: ", i + 1);
            fgets(sv[i].ten, 50, stdin);
            sv[i].ten[strcspn(sv[i].ten, "\n")] = '\0';
            printf("Nhap diem: ");
            scanf_s("%f", &sv[i].diem);
            getchar();
            xepLoai(&sv[i]);
        }

        // Sap xep theo diem giam dan
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sv[i].diem < sv[j].diem) {
                    SinhVien temp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = temp;
                }
            }
        }

        printf("\n--- DANH SACH SINH VIEN ---\n");
        for (int i = 0; i < n; i++) {
            printf("%d. %s - %.2f - %s\n", i + 1, sv[i].ten, sv[i].diem, sv[i].hocLuc);
        }
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 9 =====
void chucNang9() {
    int so1, so2;
    int tieptuc = 1;
    do {
        printf("Nhap 2 so (01-15): ");
        scanf_s("%d%d", &so1, &so2);

        srand(time(NULL));
        int may1 = rand() % 15 + 1;
        int may2 = rand() % 15 + 1;

        printf("So cua ban: %d - %d\n", so1, so2);
        printf("So cua he thong: %d - %d\n", may1, may2);

        int trung = 0;
        if (so1 == may1 || so1 == may2) trung++;
        if (so2 == may1 || so2 == may2) trung++;

        if (trung == 0) printf("Chuc ban may man lan sau!\n");
        else if (trung == 1) printf("Chuc mung ban da trung giai NHI!\n");
        else printf("Chuc mung ban da trung giai NHAT!\n");
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== CHUC NANG 10 =====
typedef struct {
    int tu;
    int mau;
} PhanSo;

PhanSo rutGon(PhanSo ps) {
    int ucln = UCLN(abs(ps.tu), abs(ps.mau));
    ps.tu /= ucln;
    ps.mau /= ucln;
    return ps;
}

void inPhanSo(PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

void chucNang10() {
    int tieptuc = 1;
    do {
        PhanSo a, b, tong, hieu, tich, thuong;
        printf("Nhap phan so 1 (tu mau): ");
        scanf_s("%d%d", &a.tu, &a.mau);
        printf("Nhap phan so 2 (tu mau): ");
        scanf_s("%d%d", &b.tu, &b.mau);

        tong.tu = a.tu * b.mau + b.tu * a.mau;
        tong.mau = a.mau * b.mau;

        hieu.tu = a.tu * b.mau - b.tu * a.mau;
        hieu.mau = a.mau * b.mau;

        tich.tu = a.tu * b.tu;
        tich.mau = a.mau * b.mau;

        thuong.tu = a.tu * b.mau;
        thuong.mau = a.mau * b.tu;

        tong = rutGon(tong);
        hieu = rutGon(hieu);
        tich = rutGon(tich);
        thuong = rutGon(thuong);

        printf("\nTong: "); inPhanSo(tong);
        printf("\nHieu: "); inPhanSo(hieu);
        printf("\nTich: "); inPhanSo(tich);
        printf("\nThuong: "); inPhanSo(thuong);
        printf("\n");
        printf("\nTiep tuc chuc nang 1? (1 = co, 0 = khong):");
        scanf_s("%d", &tieptuc);
    } while (tieptuc == 1);
}

// ===== MENU CHÍNH =====
int main() {
    int chon;
    do {
        printf("\n===== MENU CHUONG TRINH =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. lai suat vay tien\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &chon);

        switch (chon) {
        case 1: chucNang1(); break;
        case 2: chucNang2(); break;
        case 3: chucNang3(); break;
        case 4: chucNang4(); break;
        case 5: chucNang5(); break;
        case 6: chucNang6(); break;
        case 7: chucNang7(); break;
        case 8: chucNang8(); break;
        case 9: chucNang9(); break;
        case 10: chucNang10(); break;
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