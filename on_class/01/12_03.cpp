#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string maSinhVien;
    string hoTen;
    double diemTrungBinh;

public:
    SinhVien* next;

    SinhVien(string maSinhVien, string hoTen, double diemTrungBinh) {
        this->maSinhVien = maSinhVien;
        this->hoTen = hoTen;
        this->diemTrungBinh = diemTrungBinh;
        this->next = nullptr;
    }

    string getMaSinhVien() {
        return maSinhVien;
    }

    string getHoTen() {
        return hoTen;
    }

    double getDiemTrungBinh() {
        return diemTrungBinh;
    }
};

class QuanLySinhVien {
private:
    SinhVien* head;

public:
    QuanLySinhVien() {
        head = nullptr;
    }

    void themSinhVien(string maSinhVien, string hoTen, double diemTrungBinh) {
        SinhVien* sinhVienMoi = new SinhVien(maSinhVien, hoTen, diemTrungBinh);
        if (head == nullptr) {
            head = sinhVienMoi;
        } else {
            SinhVien* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = sinhVienMoi;
        }
    }

    void hienThiDanhSach() {
        if (head == nullptr) return;
        SinhVien* current = head;
        while (current != nullptr) {
            cout << current->getMaSinhVien() << " " 
                 << current->getHoTen() << " "
                 << current->getDiemTrungBinh() << endl;
            current = current->next;
        }
        cout << endl << endl << endl;
    }

    SinhVien* timSinhVienTheoMa(string maSinhVien) {
        SinhVien* current = head;
        while (current != nullptr) {
            if (current->getMaSinhVien() == maSinhVien) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void xoaSinhVienTheoMa(string maSinhVien) {
        if (head == nullptr) return;
        if (head->getMaSinhVien() == maSinhVien) {
            SinhVien* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        SinhVien* current = head;
        while (current->next != nullptr && current->next->getMaSinhVien() != maSinhVien) {
            current = current->next;
        }
        if (current->next != nullptr) {
            SinhVien* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    ~QuanLySinhVien() {
        SinhVien* current = head;
        while (current != nullptr) {
            SinhVien* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
void menu() {
    cout << "1. Them sinh vien" << endl;
    cout << "2. Hien thi ds sinh vien" << endl;
    cout << "3. Tim sinh vien theo msv" << endl;
    cout << "4. Xoa sv theo ma" << endl;
    cout << "5. Exit" << endl;
}
int main() {
    QuanLySinhVien qlSinhVien;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string masv, hoten;
        double gpa;

        cin >> masv;
        cin.ignore();
        getline(cin, hoten);
        cin >> gpa;
        cin.ignore();
        qlSinhVien.themSinhVien(masv, hoten, gpa);
    }

    int luaChon;
    do {
        menu();
        cout << "Chon thao tac     ";
        cin >> luaChon;
        cin.ignore();

        string masv, hoten;
        double gpa;

        switch (luaChon) {
            case 1:
                cin >> masv;
                cin.ignore();
                getline(cin, hoten);
                cin >> gpa;
                qlSinhVien.themSinhVien(masv, hoten, gpa);
                break;
            case 2:
                qlSinhVien.hienThiDanhSach();
                break;
            case 3:
                cin >> masv;
                if (qlSinhVien.timSinhVienTheoMa(masv) != nullptr)
                    cout << "Co sinh vien " << masv << endl;
                else
                    cout << "Khong tim duoc sinh vien "<< masv << endl;
                break;
            case 4:
                cin >> masv;
                qlSinhVien.xoaSinhVienTheoMa(masv);
                break;
        }
    } while (luaChon != 5);

    return 0;
}