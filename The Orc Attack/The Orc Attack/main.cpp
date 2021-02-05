#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

using namespace std;


// Floyd Warshall

void floyd_warshall(vector < vector <int> > & Graph)
{
    int n = Graph.size(); // Tamaño del array
    
    // Tres bucles
    for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
        Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
    
    //if(Graph[i][j]>Graph[i][k]+Graph[k][j])
    // Graph[i][j]=Graph[i][k]+Graph[k][j];
    return ;
}


int main(void)
{
    
    cout<<"The Orc Attack"<<endl;
    
    int T = 0, map_counter = 0;
    cin >> T; // Ingresa el numero de veces a ser usado
    while(T--){
        ++map_counter; // Se aumenta contador de cual es la matriz
        
        int l, d;
        cin >> l >> d; // Ingresamos el numero de nodos y de vertices
        vector < vector <int> > Graph(l, vector <int> (l, INT_MAX)); // Inicializamos la matriz de pesos
        
        for(int i = 0; i < l; ++i)
        Graph[i][i] = 0;  // toda la diagonal se llena de 0
        
        for(int i = 0; i < d; ++i){
            int u, v, c;
            cin >> u >> v >> c; // Se ingresa el los nodos a conectar con su peso
            
            --u;
            --v;
            
            Graph[u][v] = Graph[v][u] = min(Graph[u][v], c); // se almacena en el casillero
        }
        
        floyd_warshall(Graph); // Llamado de la funcion
        
        int result_node = -2;
        int min_distance = INT_MAX;
        
        for(int i = 0; i < l; ++i){ // se recorre la cantidad de nodos
            bool valid_node = 1;
            for(int j = 0; j < 5; ++j) // Los 5 edificios
            if(Graph[j][i] != Graph[0][i])
                valid_node = 0;
            
            if(valid_node){
                int far_dist = *std::max_element(Graph[i].begin(), Graph[i].end());
                // distancia mas larga
                
                if(far_dist < min_distance){ // comparacion
                    result_node = i;
                    min_distance = far_dist;
                }
            }
        }
        cout << "Map " << map_counter<< ": " << (result_node != -2 ? min_distance : -1) << endl;
    }
    return 0;
}


/*
 1 7 2
 2 7 2
 3 7 2
 5 7 2
 6 7 1
 1 6 1
 2 6 1
 3 6 1
 4 6 1
 5 6 1
 7 6 1
 */
