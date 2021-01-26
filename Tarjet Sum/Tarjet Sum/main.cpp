#include <iostream>
#include <vector>
using namespace std;

// 0
bool TargetSum(vector<int> arr, int T){
    
    int tam= arr.size();
    
    for(int i = 0; i<tam-1 ; i++){
        for( int j =0 ; j<tam;j++){
            if(arr[i]+arr[j] == T && i!= j)return 1;
        }
    }
    return 0;
}



// 1
bool TargetSum1(vector<int> arr, int T){
    int cabeza = 0;
    int cola = arr.size() - 1;
    int sum;
        while (cabeza != cola)
        {
            sum = arr[cabeza] + arr[cola];
            if (sum < T)
                cabeza++;
            else if (sum > T)
                cola--;
            else return 1;
        }
        return 0;
}

// 2

void Target_sum(int A[],int tam, int N, int& cont1, int& cont2) {

    int M = N / 2;
    cont1 = 0;

    // Encontrar M
    for (; A[cont1] < M; cont1++);
    if (A[cont1] > M) cont1--;

    // Suma

    cont2 = cont1 + 1;
    int resultado = A[cont1] + A[cont2];
    while (resultado != N && cont1 != 0 && cont2 != tam ) {
        if (resultado > N) cont1--;
        else if (resultado < N) cont2++;
        resultado = A[cont1] + A[cont2];
    }
}


int main() {
   
    vector<int> arr = {-20,10,20,30,35,40,60,70};
    int T = 60;
    
   bool result = TargetSum(arr, T);
    
    cout<< result<<endl;
    
    bool result1 = TargetSum1(arr, T);
    
    cout<< result1 <<endl;
    
}
