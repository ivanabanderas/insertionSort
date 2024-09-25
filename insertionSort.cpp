#include <iostream>
#include <vector>

using namespace std;

bool verificar(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i * i <= num; i++) { 
        if (num % i == 0) return false; 
    }
    return true;
}

void instertionSort(vector <int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i -1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j -1;
        }

        arr[j + 1] = key;
    }
}


vector <int> filtrar(vector <int>& numeros) {
    vector <int> primos;

    for (int num : numeros) {
        if (verificar(num)) {
            primos.push_back(num);
        }
    }


    instertionSort(primos);
    return primos;
}

int main(){
    vector <int> arr = {12, 5, 3, 7, 11, 4, 8, 13};

    vector <int> primosOrd = filtrar(arr);

    for (int num:primosOrd){
        cout << num << "" << endl;
    }
    return 0;
}