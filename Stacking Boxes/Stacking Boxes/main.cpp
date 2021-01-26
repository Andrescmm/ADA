
#include <iostream>
#include <algorithm>
using namespace std;


// Estructura de una caja
struct box {
int num; // numero
int d; // dimensiones
int dimensions[10]; // aray que almacena las dimensiones
};


// Resultados
struct result {
int len;
int pos;
};

// Funcion para comprobar si un caja A entra en una caja B
bool boxFits(const box &a, const box &b) {
for (int i = 0; i < a.d; i++) {
  if (a.dimensions[i] >= b.dimensions[i])
    return false;
}
return true;
}

// regresa el orden mas apropiado para la caja y hacer que sus dimensiones encajen
bool correctOrder(const box &a, const box &b) {
for (int i = 0; i < a.d; i++) {
  if (a.dimensions[i] >= b.dimensions[i]) {
    if (boxFits(b, a))
      return true;
    else
      return a.num > b.num;
  }
}

return false;
}

int main(void) {
int n, k;  // n = cantidad de cajas y k = dimensiones de la caja
box boxes[30]; // array de cajas
int dp[30];
result best;
result tmp;

cout<< "Stacking Boxes"<<endl;
    
while (cin >> n >> k) {
  for (int i = 0; i < 30; i++)
    dp[i] = 1;

  best.pos = 0;
  best.len = 1;

    // Se recorre basado en las cjas y sus dimensiones
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> boxes[i].dimensions[j]; // Se llena los valores de las dimensiones de cada caja
    }
    boxes[i].d = k; // Se le asigna su dimension
    boxes[i].num = i + 1; // Se le asigna su numero
    sort(boxes[i].dimensions, boxes[i].dimensions + k); // ordena las dinemsiones
  }

  sort(boxes, boxes + n, correctOrder ); // ordena las dimensiones en accedente o descendente dependiendo de la funcion

  for (int i = 0; i < n; i++) {
    if (boxes[i].num == 1)
      best.pos = i;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (boxFits(boxes[i], boxes[j])) { // Comprueba si las cajas encajan
        dp[i] = max(dp[i], dp[j] + 1);  // se devuelve el maximo de los elemntos de la lista dp
        if (dp[i] > best.len) { // si dp[i] es mayor que best.len
          best.len = dp[i]; // se iguala a dp[i]
          best.pos = i;     // la pos se iguala a i
        }
      }
    }
  }

  

  cout << boxes[best.pos].num; // Caja mas pequeña
  best.len--; // se reduce la cnatidad de cajas
  while (best.len) {
    cout << " ";

    tmp.len = 2000000;
    tmp.pos = 0;
    for (int i = 0; i < best.pos; i++) { // se recorre el numero de cajas
      if (dp[i] == best.len && boxFits(boxes[best.pos], boxes[i])) { //
        tmp.len = min(tmp.len, boxes[i].num);
        if (tmp.len == boxes[i].num)
          tmp.pos = i;
      }
    }

    cout << boxes[tmp.pos].num; // Devuelve la cajas mas grande y luego la siguiente
    best.pos = tmp.pos;

    best.len--;// se resta el espacio entre la cajas
  }
  cout << endl; // Espacio entre cajas
}

return 0; // fin
}
