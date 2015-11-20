#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int cases, temp_mov, temp_sum, temp_indice;
    cin >> cases;

    vector<int> inicial; // Vector con las posiciones inciciales
    vector<int> movimiento; // Vector con las direcciones
    vector<int> sumado; // Vector con las posiciones finales
    vector<int> indiceOrdenado; // Vector de indices

    int L, T, N;

    for (int cas=0; cas<cases; cas++) {
        // Entrada de datos
        cin >> L >> T >> N;
        int temp;
        char c;
        for (int i=0; i<N; i++) {
            cin >> temp >> c;
            if (c=='R')
                movimiento.push_back(1);
            if (c=='L')
                movimiento.push_back(-1);
            inicial.push_back(temp);
        }

        // Hago todos los movimientos para todas las hormigas
        for (int i=0; i<N; i++) {
            sumado.push_back(inicial.at(i) + T*movimiento.at(i));
        }

        // Genero el vector de indices
        for (int i=0; i<N; i++) {
            indiceOrdenado.push_back(i);
        }

        // Ordeno el array de posiciones finales, modificando tambien movimientos e indices
        int i, j;
        for (i = 1; i < N-1; i++) {
            j = i-1;
            temp_sum = sumado[i];
            temp_mov = movimiento[i];
            temp_indice = indiceOrdenado[i];
            while (j>=0 && sumado[j] > temp_sum) {
                sumado[j+1] = sumado[j];
                movimiento[j+1] = movimiento[j];
                indiceOrdenado[j+1] = indiceOrdenado[j];
                j--;
            }
            sumado[j+1] = temp_sum;
            indiceOrdenado[j+1] = temp_indice;
            movimiento[j+1] = temp_mov;

            if(sumado[j+1] == sumado[j]){
                movimiento[j+1] = 0;
                movimiento[j] = 0;
            }
        }

        // Ordeno el array de indices y modifico tambien el de direcciones y posiciones finales
        for (i = 1; i < N-1; i++) {
            j = i-1;
            temp_indice = indiceOrdenado[i];
            temp_mov = movimiento[i];
            temp_sum = sumado[i];
            while (j>=0 && indiceOrdenado[j] < temp_indice) {
                indiceOrdenado[j+1] = indiceOrdenado[j];
                sumado[j+1] = sumado[j];
                movimiento[j+1] = movimiento[j];
                j = j-1;
            }
            indiceOrdenado[j+1] = temp_indice;
            sumado[j+1] = temp_sum;
            movimiento[j+1] = temp_mov;
        }

        cout << "Case #" << cas+1 << ":" << endl;
        for (int a=0; a<N; a++) {
            if(sumado[a] > 0 && sumado[a]<= L){
                cout << sumado[a] << " ";
                if(movimiento[a] == 1)          cout << "R" << endl;
                else if(movimiento[a] == -1)    cout << "L" << endl;
                else                            cout << "Turning" << endl;
            }
            else cout << "Fell off" << endl;
        }

        // Limpieza de vectores
        inicial.clear();
        movimiento.clear();
        sumado.clear();
        indiceOrdenado.clear();

        cout << endl;
    }
    return 0;
}
