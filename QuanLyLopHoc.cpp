#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char Ten[20];
    float DTB;
} SV;

typedef struct Lop {
    char TenLop[10];
    SV* DSSV;
    int SiSo;
} L;

// Ham nhap thong tin sinh vien cua lop hoc do
void NhapSV(SV* sv) {
    getchar();
    printf("\nNhap ten sinh vien: ");
    gets_s(sv->Ten);

    printf("\nNhap diem trung binh cua sinh vien: ");
    scanf_s("%f", &sv->DTB);
}

//Ham nhap ten lop va si so lop hoc
void NhapLop(L *DSLop) {
        getchar();
        printf("\nNhap ten lop: ");
        gets_s(DSLop->TenLop);

        printf("\nNhap si so sinh vien: ");
        scanf_s("%d", &DSLop->SiSo);

        DSLop->DSSV = (SV*)malloc(DSLop->SiSo * sizeof(SV));
        if (DSLop->DSSV == NULL) {
            printf("LOI!");
            return;
        }
        for (int j = 0; j < DSLop->SiSo; j++) {
            NhapSV(&DSLop->DSSV[j]);
        }
}

//Tim lop co hon 5 sinh vien va co diem trung binh dat loai gioi
void XuatSVGioi(L* DSLop, int n) {
        printf("\nTen sinh vien\t\t\t Diem trung binh");
        for (int j = 0; j < DSLop->SiSo; j++) {
            if (DSLop->DSSV[j].DTB >= 8) {
                printf("\n%-15s\t\t\t%.2f", DSLop->DSSV[j].Ten, DSLop->DSSV[j].DTB);
            }
        }
}

//Tim va in ra lop lop co nhieu sinh vien nhat
void LopNhieuSV(L* DSLop, int n) {
    if (n == 1) {
        printf("\nLop co nhieu sinh vien nhat là lop: %s, si so: %d", DSLop[0].TenLop,DSLop[0].SiSo);
    }
    else if (n == 2) {
            if (DSLop[0].SiSo > DSLop[1].SiSo) {
                printf("\nLop co nhieu sinh vien nhat la lop: %s, si so:%d", DSLop[0].TenLop, DSLop[0].SiSo);
            }
            else {
                printf("\nLop co nhieu sinh vien nhat la lop: %s, si so:%d", DSLop[1].TenLop, DSLop[1].SiSo);
            }
    }
    else {
        int max = DSLop[0].SiSo;
        for (int i = 1; i < n; i++) {
            if (DSLop[i].SiSo > max) {
                max = i;
            }
        }
        printf("\nLop co nhieu sinh vien nhat la lop: %s, si so:%d", DSLop[max].TenLop, DSLop[max].SiSo);
    }
}

//Tim va in ra lop lop co it sinh vien nhat
void LopItSV(L* DSLop, int n) {
    if (n == 1) {
        printf("\nLop co it sinh vien nhat là lop: %s, si so: %d", DSLop[0].TenLop, DSLop[0].SiSo);
    }
    else if (n == 2) {
        if (DSLop[0].SiSo > DSLop[1].SiSo) {
            printf("\nLop co it sinh vien nhat la lop: %s, si so:%d", DSLop[1].TenLop, DSLop[1].SiSo);
        }
        else {
            printf("\nLop co nhieu sinh vien nhat la lop: %s, si so:%d", DSLop[0].TenLop, DSLop[0].SiSo);
        }
    }
    else {
        int min = DSLop[0].SiSo;
        for (int i = 1; i < n; i++) {
            if (DSLop[i].SiSo < min) {
                min = i;
            }
        }
        printf("\nLop co it sinh vien nhat la lop: %s, si so:%d", DSLop[min].TenLop, DSLop[min].SiSo);
    }
}

//Ham tim va xuat ra sinh vien co diem trung binh cao nhat
void SV_DTB_Cao(L* DSLop, int n) {
    int temp1, temp2;
    float DTBMax = DSLop[0].DSSV[0].DTB;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DSLop[i].SiSo; j++) {
            if (DSLop[i].DSSV[j].DTB > DTBMax) {
                DTBMax = DSLop[i].DSSV[j].DTB;
                temp1 = i;
                temp2 = j;

            }
        }
    }
    printf("\nSinh vien co diem trung binh cao nhat:");
    printf("\nLop: %s\t\tTen: %s\t\tDiem trung binh: %.2f", DSLop[temp1].TenLop, DSLop[temp1].DSSV[temp2].Ten, DTBMax);
}

//Ham tim va xuat ra lop co so luong sinh vien dat diem trung binh loai gioi nhieu nhat
void Lop_DTBGioi_NhieuNhat(L* DSLop, int n){
    int dem = 0;
    int max; //Luu so so luong SV co DTB >= 8
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DSLop[i].SiSo; j++) {
            if (DSLop[i].DSSV[j].DTB < 8) {
                DSLop[i].SiSo = DSLop[i].SiSo - 1;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int l = k+1; l < n; l++) {
            if (DSLop[k].SiSo > DSLop[l].SiSo) {
                max = k;
            }
            else { max = l; }
        }
    } 
    /*Đầu tiên lấy DTB của sinh viên trong lớp đó so sánh nếu nhỏ hơn điểm loại giỏi thì giảm sỉ số của lớp đó xuống, cứ như vậy cho đến khi hết 
    tất cả các lớp học. Sau đó, so sánh sỉ số của từng lớp cho nhau, lớp nào có sỉ số cao nhất lớp đó có nhiều sinh viên đạt DTB loại giỏi nhất*/
    printf("Lop co nhieu sinh vien co diem trung binh loai gioi nhat la lop: %s",DSLop[max].TenLop);
}

//Xuat toan bo lop hoc va tat ca sinh vien trong lop hoc đó
void Xuat(L* DSLop, int n) {
    printf("\nLop: %s\t Si so: %d", DSLop->TenLop, DSLop->SiSo);
    printf("\nTen sinh vien\t\t Diem trung binh");
    for (int i = 0; i < DSLop->SiSo; i++) {
        printf("\n%-15s\t\t DTB: %.2f",DSLop->DSSV[i].Ten, DSLop->DSSV[i].DTB);
    }
}

//Ham MAIN
int main() {
    int n;
    int x = 1;
    L* DSLop = NULL;
    while (x != 0) {
        //Cac chuc nang
        printf("\n\n1. Nhap danh sach cac lop");
        printf("\n2. In danh sach cac lop hoc");
        printf("\n3. In danh sach cac lop co tren 5 sinh vien co diem trung binh loai gioi");
        printf("\n4. Lop co nhieu sinh vien nhat");
        printf("\n5. Lop co it sinh vien nhat");
        printf("\n6. Sinh vien co diem trung binh cao nhat");
        printf("\n7. Lop co so luong sinh vien dat diem trung binh loai gioi nhieu nhat");
        printf("\nNhap lua chon: ");
        scanf_s("%d", &x);

        switch (x) {
        case 1:
            printf("\nNhap so lop hoc: ");  // Nhap so lop hoc sau do cap phat bo nho dong
            scanf_s("%d", &n);
            DSLop = (L*)malloc(n * sizeof(L));
            for (int i = 0; i < n; i++) {
                NhapLop(&DSLop[i]);
            }
            break;
        case 2:
            printf("\n\t\t=== DANH SACH CAC LOP HOC===\t\t");
            for (int i = 0; i < n; i++) {
                Xuat(&DSLop[i], n);
            }
                break;
        case 3:
            printf("\n\t\t=== DANH SACH CAC LOP HOC CO NHIEU HON 5 SV VA CO DTB GIOI===\t\t");
            for (int i = 0; i < n; i++) {
                if (DSLop[i].SiSo > 5) {
                    printf("\nLop: %s\t Si so: %d", DSLop[i].TenLop, DSLop[i].SiSo);
                    XuatSVGioi(&DSLop[i], n);
                }
            }
            break;
        case 4:
            LopNhieuSV(DSLop,n);
            break;
        case 5:
            LopItSV(DSLop, n);
            break;
        case 6:
            SV_DTB_Cao(DSLop, n);
            break;
        case 7:
            Lop_DTBGioi_NhieuNhat(DSLop,n);
            break;

        }
        }
    for (int i = 0; i < n; i++) {
        free(DSLop[i].DSSV);
    }
    free(DSLop);
    return 0;
}
