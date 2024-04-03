#include<iostream>
#include<math.h>
using namespace std;
const long MIN = -1000000000;
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}
bool checkNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
}
int Fun(int a[], int n) {
    long max = MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max && checkNT(a[i]) )
            max = a[i];
    }
    if( max == MIN )
        return 0;
    else
        return max;
}
int main() {
    int a[100];
    int n;
    cout << "Nhap vao n: ";
    cin >> n;
    NhapMang(a, n);
    if (Fun(a, n) == 0)
        cout << "Mang khong ton tai so nguyen to";
    else
        cout << "So nguyen to lon nhat trong mang la: "  << Fun(a, n);
    system("pause");
    return 0;
}
