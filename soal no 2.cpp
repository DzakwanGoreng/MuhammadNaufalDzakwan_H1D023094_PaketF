#include <iostream>
using namespace std;

void swap(int *asep, int *pesa) {
    int temp = *asep;
    *asep = *pesa;
    *pesa = temp;
}

void bubbleSort(int arr[], int n){
    for (int i=0;i < n-1;i++){
        for (int j=0;j<n-i-1; j++){
            if (arr[j]<arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size){
    for (int i=0;i<size; i++){
        cout << arr[i]<< " ";
    }
    cout<<endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan elemen-elemen (nominal uang):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Array dari terbesar: ";
    printArray(arr, n);

    return 0;
}
