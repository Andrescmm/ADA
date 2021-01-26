
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


float Distancia (int x1 , int x2, int y1, int y2){
    
    float  dis = sqrt((x1- x2)*(x1 - x2 ) + (y1 - y2)*(y1 - y2));
    
    return dis;
}




void Problema1( vector<vector<int> > array){
    
    int tam = array.size();
    
    float distancia =0;
    
    float temp= Distancia(array[0][0],array[1][0],array[0][1],array[1][1]);

    
    int temp_i [2];
    int temp_j [2];
    
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-2;j++){

               
        //distancia = Distancia(array[i][j],array[i+1],array[i][j+1],array[i+1][j+1] );
       distancia = sqrt((array[i][j] - array[i+1][j])*(array[i][j] - array[i+1][j] ) + (array[i][j+1] - array[i+1][j+1])*(array[i][j+1] - array[i+1][j+1]));
        
            
        if(distancia<=temp){
            temp= distancia;
            temp_i[0]=array[i][j] ; temp_i[1]=array[i][j+1];
            temp_j[0]=array[i+1][j] ; temp_j[1]=array[i+1][j+1];
        }
                //cout<<"La distam{"<<array[i][j]<<","<<array[i][j+1]<<"}"<<" y {"<<array[i+1][j] <<","<<array[i+1][j+1]<<"}" << " y es = "<<distancia<<endl;
      
    }
  }
    cout<<"La menor distancia esta entre el punto {"<<temp_i[0]<<","<<temp_i[1]<<"}"<<" y {"<<temp_j[0]<<","<<temp_j[1]<<"}" << " y es = "<<temp<<endl;
}





int main() {
    
    vector<vector<int> > array ={{8,9},{1,2},{7,9}};
    
    Problema1(array);
}

