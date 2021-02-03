#include <iostream>

using namespace std;

// definimos dos constantes
#define MAXN 105
#define INF 100000

// Arreglo a de dos dimensiones
int a[MAXN][MAXN], n, m;

int Trace[3][MAXN];

// Funcion para ingresar el input
void ingresoDatos() {
    int i,j,u,v,cost;
    cin >> n >> m; // ingresamos las escuelas con sus conexiones
    // rellenamos las conexiones en dento de la matriz de dos dimensiones
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            a[i][j] = a[j][i] = INF;
      
    for (i=1;i<=m;i++) {
        cin >> u >> v >> cost;
        a[u][v] = a[v][u] = cost;
    }
}


// Algortimo de prim
int Prim(int ace) {
    // Delcaramos variables
    int u,v,k, d[n+2], min, sum;
    bool comprobacion[n+2], conectado= true;
    
    
    // Recorremos para rellenar
    for (v=1;v<=n;v++) {
        d[v]=INF; comprobacion[v]=true;
    }
    d[1] = 0;
    // recorremos n numero de veces
    for (k=1;k<=n;k++) {
        u = 0; min = INF;
        for (v=1;v<=n;v++)
            if (comprobacion[v] && d[v]<min) {
                u = v; min = d[v];
            }
        if (u==0) {
            conectado = false; break;
        }
        comprobacion[u] = false;
        for (v=1;v<=n;v++)
        if (comprobacion[v] && d[v]>a[u][v]) {
                d[v] = a[u][v];
                Trace[ace][v] = u;
            }
    }
    
    if (!conectado) return -1;
    sum = 0;
    for (v=2;v<=n;v++)
        sum += a[v][Trace[ace][v]];
    return sum;
}

//main
int main() {
    
    cout<<"ACM Contest and Blackout"<<endl;
    
    int kase, i, primero, segundo, k;
    cin >> kase;
    // Bucle que funciona el numero de casos que sean necesarios
    while (kase--) {
        ingresoDatos();
        primero = Prim(0);
        segundo = INF;
        for (i=2;i<=n;i++) {
            int temp = a[i][Trace[0][i]];
            a[i][Trace[0][i]] = a[Trace[0][i]][i] = INF;
            
            k = Prim(1);
            if (k>=0 && k<segundo)segundo = k;
            a[i][Trace[0][i]] = a[Trace[0][i]][i] = temp;
        }
        if (segundo == INF) segundo = primero;
        printf("%d %d\n",primero,segundo);
    }
}
