
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct SinhVien {
	int MSSV;
	char Ten[100];
	float LTC;
	float DTCB;
	float NMKT;
	float DTB;
}SV ;
void Nhap(int &n,SV a[]) {

	printf("Nhap so sinh vien: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Nhap ma so sinh vien: ");
		scanf_s("%d",&a[i].MSSV);
		
		getchar();
		printf("Nhap ho va ten: ");
		gets_s(a[i].Ten);

		printf("Nhap diem mon lap trinh C: ");
		scanf_s("%f",&a[i].LTC);
		printf("Nhap diem mon dien tu can ban: ");
		scanf_s("%f", &a[i].DTCB);
		printf("Nhap diem mon nhap mon ki thuat: ");
		scanf_s("%f", &a[i].NMKT);
		a[i].DTB = (a[i].LTC + a[i].DTCB + a[i].NMKT) / 3;
	}
}
void ThemSV(int &n, SV a[]) {
	int tsv, temp;
	printf("Nhap so sinh vien muon them: ");
	scanf_s("%d", &tsv);
	temp = n;
	n = n + tsv;
	for (int i = temp; i < n; i++) {
		printf("Nhap ma so sinh vien: ");
		scanf_s("%d", &a[i].MSSV);

		getchar();
		printf("Nhap ho va ten: ");
		gets_s(a[i].Ten);

		printf("Nhap diem mon lap trinh C: ");
		scanf_s("%f", &a[i].LTC);
		printf("Nhap diem mon dien tu can ban: ");
		scanf_s("%f", &a[i].DTCB);
		printf("Nhap diem mon nhap mon ki thuat: ");
		scanf_s("%f", &a[i].NMKT);
		a[i].DTB = (a[i].LTC + a[i].DTCB + a[i].NMKT) / 3;
	}
}
void Xuat(int n, SV a[]) {
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s","MSSV","Ho va ten","Diem lap trinh C","Diem dien tu can ban","Diem nhap mon ki thuat","Diem trung binh");
	for (int i = 0; i < n; i++) {
		printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f",a[i].MSSV,a[i].Ten, a[i].LTC, a[i].DTCB, a[i].NMKT, a[i].DTB);
	}
}

void ChinhSua(int n, SV a[]) {
	int mssv_cs;
	printf("Nhap MSSV cua sinh vien can chinh sua: ");
	scanf_s("%d",&mssv_cs);
	for (int i = 0; i < n; i++) {
		if (mssv_cs == a[i].MSSV) {
			printf("Nhap ma so sinh vien: ");
			scanf_s("%d", &a[i].MSSV);

			getchar();
			printf("Nhap ho va ten: ");
			gets_s(a[i].Ten);

			printf("Nhap diem mon lap trinh C: ");
			scanf_s("%f", &a[i].LTC);
			printf("Nhap diem mon dien tu can ban: ");
			scanf_s("%f", &a[i].DTCB);
			printf("Nhap diem mon nhap mon ki thuat: ");
			scanf_s("%f", &a[i].NMKT);
			a[i].DTB = (a[i].LTC + a[i].DTCB + a[i].NMKT) / 3;
		}
	}
}
void XoaSV(int n, SV a[]) {
	int mssv_xoa;
	printf("Nhap MSSV cua sinh vien can xoa: ");
	scanf_s("%d",&mssv_xoa);
	for (int i = 0; i < n; i++) {
		if (mssv_xoa == a[i].MSSV) {
			a[i] = a[i + 1];
			n--;
		}
	}
}
void TimDTB(int n, SV a[]) {
	int DTBLN, DTBNN;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i].DTB > a[j].DTB) {
				DTBLN = i;
				DTBNN = j;
			}
			else {
				DTBLN = j;
				DTBNN = i;
			}
		}	
	}
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	printf("Thong tin sinh vien co diem trung binh lon nhat la:\n");
	printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[DTBLN].MSSV, a[DTBLN].Ten, a[DTBLN].LTC, a[DTBLN].DTCB, a[DTBLN].NMKT, a[DTBLN].DTB);
	printf("\nThong tin sinh vien co diem trung binh nho nhat la:\n");
	printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[DTBNN].MSSV, a[DTBNN].Ten, a[DTBNN].LTC, a[DTBNN].DTCB, a[DTBNN].NMKT, a[DTBNN].DTB);
}

void TimThongTinSV(int n, SV a[]) {
	int mssv_tim;
	int stt;
	printf("Nhap MSSV cua sinh vien can tim: ");
	scanf_s("%d", &mssv_tim);
	for (int i = 0; i < n; i++) {
		if (mssv_tim == a[i].MSSV) {
			stt = i;
		}
	}
	printf("\nThong tin sinh vien :\n");
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[stt].MSSV, a[stt].Ten, a[stt].LTC, a[stt].DTCB, a[stt].NMKT, a[stt].DTB);
}
void DTB_NAM(int n, SV a[]) {
	int DTB_L[100];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].DTB > 5) {
			DTB_L[j] = i;
			j++;
		}
	}
	printf("\nThong tin sinh vien co diem trung binh tren 5:\n");
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	for (int k = 0; k < j; k++) {
		printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[DTB_L[k]].MSSV, a[DTB_L[k]].Ten, a[DTB_L[k]].LTC, a[DTB_L[k]].DTCB, a[DTB_L[k]].NMKT, a[DTB_L[k]].DTB);
	}
}
void TimDiemTong(int n, SV a[]) {
	// Tong diem = LTC*2 + ĐTCB + NMKT
	float TongDiem;
	int temp[100];
	int j = 0;
	for (int i = 0; i < n; i++) {
		TongDiem = a[i].LTC * 2 + a[i].DTCB + a[i].NMKT;
		if (TongDiem > 20) {
			temp[j] = i;
			j++;
		}
	}
	printf("\nThong tin sinh vien co tong diem lon hon 20:\n");
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	for (int k = 0; k < j; k++) {
		printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[temp[k]].MSSV, a[temp[k]].Ten, a[temp[k]].LTC, a[temp[k]].DTCB, a[temp[k]].NMKT, a[temp[k]].DTB);
	}
}
void SapXepTheoMSSV(int n, SV a[]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].MSSV > a[j].MSSV) {
				SV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Sinh vien tang dan theo MSSV");
	Xuat(n, a);
}
void SapXepTheoDTBGiamDan(int n, SV a[]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].DTB < a[j].DTB) {
				SV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Sinh vien gian dan theo diem trung binh");
	Xuat(n, a);
}
void GhiFile(int n, SV a[]) {
	FILE* f;
	fopen_s(&f,"danhsach.txt","wt");
	fprintf(f,"\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	for (int i = 0; i < n;i++) {
		fprintf(f, "\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[i].MSSV, a[i].Ten, a[i].LTC, a[i].DTCB, a[i].NMKT, a[i].DTB);
	}
	printf("Ghi danh sach vao file thanh cong");
	fclose(f);
}
void DocFile(int n,SV a[]) {
	FILE* f;
	fopen_s(&f, "danhsach.txt", "wt");
	printf("\n%-7s %-25s %-20s %-25s %-25s %-25s", "MSSV", "Ho va ten", "Diem lap trinh C", "Diem dien tu can ban", "Diem nhap mon ki thuat", "Diem trung binh");
	for (int i = 0; i < n; i++) {
		fscanf_s(f, "%d %s %f %f %f %f", a[i].MSSV, a[i].Ten, a[i].LTC, a[i].DTCB, a[i].NMKT, a[i].DTB);
		printf("\n%-7d %-25s %-20.1f %-25.1f %-25.1f %-25.1f", a[i].MSSV, a[i].Ten, a[i].LTC, a[i].DTCB, a[i].NMKT, a[i].DTB);
	}
	printf("\nDoc file thanh cong");
	fclose(f);
}
int main() {
	int n;
	int x = 1;
	SV a[100];
	while(x != 0) {
		printf("\n1. Nhap danh sach sinh vien\n");
		printf("2. Xuat danh sach sinh vien\n");
		printf("3. Chinh sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien trong danh sach\n");
		printf("5. Them sinh vien vao danh sach\n");
		printf("6. Tim thong tin sinh vien co diem trung binh cao va thap nhat\n");
		printf("7. Tim thong tin sinh vien bang MSSV\n");
		printf("8. Liet ke sinh vien co diem trung binh tren 5\n");
		printf("9. Liet ke sinh vien co tong diem lon hon 20\n");
		printf("10. Sap xep danh sach theo MSSV tang dan\n");
		printf("11. Sap xep danh sach theo diem trung binh giam dan\n");
		printf("12. Ghi danh sach vao file danhsach.txt\n");
		printf("13. Doc danh sach tu file danhsach.txt\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &x);

		switch (x){
			case 1:
				Nhap(n, a);
				break;
			case 2:
				Xuat(n, a);
				break;
			case 3:
				ChinhSua(n, a);
				break;
			case 4:
				XoaSV(n, a);
				break;
			case 5:
				ThemSV(n, a);
				break;
			case 6:
				TimDTB(n, a);
				break;
			case 7:
				TimThongTinSV(n, a);
				break;
			case 8:
				DTB_NAM(n, a);
				break;
			case 9:
				TimDiemTong(n, a);
				break;
			case 10:
				SapXepTheoMSSV(n, a);
				break;
			case 11:
				SapXepTheoDTBGiamDan(n, a);
				break;
			case 12:
				GhiFile(n, a);
				break;
			case 13:
				DocFile(n, a);
				break;
		}
	}
}
