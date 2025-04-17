#include <iostream>
using namespace std;

int arr[20], B[];   // Ukuran array maksimum 20
int n;           // Variabel untuk panjang array
void input() {
    while (true) {
        cout << "Masukkan panjang elemen array: ";
        cin >> n;

        if (n <= 20) {
            break;
        } else {
            cout << "\nMaksimal panjang array adalah 20\n";
        }
    }
    cout << "\n=====================";
    cout << "\nInputkan isi elemen array";
    cout << "\n=====================\n";

    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << " : ";
        cin >> arr[i];
    }
}
void mergeSort(int low, int high) {
    if (low < high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);  

    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }
    while(j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }
    while(i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
}
void output(){
    cout << "\nData setelah diurutkan (MargeSort): ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << "";
    }
    cout << endl;
}

int main(){
    input();
    mergeSort(0,n-1);
    output();
}

