/*
 * ============================================================================
 *  SISTEMA DE GENERACION Y ORDENAMIENTO DE NUMEROS ALEATORIOS
 * ============================================================================
 *
 *  Este programa permite generar una cantidad determinada de numeros
 *  aleatorios y ordenarlos utilizando distintos algoritmos de ordenamiento,
 *  midiendo y comparando el tiempo que tarda cada uno en ejecutarse.
 *
 *  Algoritmos incluidos:
 *      1) Bubble Sort      (Ordenamiento burbuja)
 *      2) Insertion Sort    (Ordenamiento por insercion)
 *      3) Selection Sort    (Ordenamiento por seleccion)
 *      4) Merge Sort        (Ordenamiento por mezcla)
 *      5) Quick Sort        (Ordenamiento rapido)
 *      6) Counting Sort     (Ordenamiento por conteo)
 *
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
using namespace std::chrono;

// ============================================================================
// VARIABLES GLOBALES
// ============================================================================

// Vector que almacena los numeros generados aleatoriamente.
vector<int> numeros;

// Arreglo con el tiempo (en milisegundos) que tardo cada algoritmo.
// Indice 0 = Bubble Sort, 1 = Insertion Sort, 2 = Selection Sort,
// 3 = Merge Sort, 4 = Quick Sort, 5 = Counting Sort.
double tiempos[6] = {0, 0, 0, 0, 0, 0};

// Indica si un algoritmo ya fue ejecutado al menos una vez.
bool ejecutado[6] = {false, false, false, false, false, false};

// Nombres de los algoritmos, en el mismo orden que los arreglos anteriores.
string nombres[6] = {
    "Bubble Sort",
    "Insertion Sort",
    "Selection Sort",
    "Merge Sort",
    "Quick Sort",
    "Counting Sort"
};


// ============================================================================
// ALGORITMOS DE ORDENAMIENTO
// ============================================================================
// Cada funcion recibe el arreglo por referencia y lo ordena "in place".
// Quien llama a estas funciones siempre les pasa una COPIA del vector
// original, para que los numeros generados nunca se pierdan.
// ============================================================================

// ----------------------------------------------------------------------------
// Bubble Sort (Burbuja)
// Complejidad: O(n^2) en el peor caso.
// Idea: recorre el arreglo varias veces intercambiando elementos adyacentes
// que estan en el orden incorrecto, "burbujeando" el mayor hacia el final.
// ----------------------------------------------------------------------------
void bubbleSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ----------------------------------------------------------------------------
// Insertion Sort (Insercion)
// Complejidad: O(n^2) en el peor caso.
// Idea: toma cada elemento y lo inserta en la posicion correcta dentro de
// la parte ya ordenada del arreglo, como cuando se ordenan cartas en la mano.
// ----------------------------------------------------------------------------
void insertionSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

// ----------------------------------------------------------------------------
// Selection Sort (Seleccion)
// Complejidad: O(n^2) en el peor caso.
// Idea: en cada vuelta busca el elemento mas pequeno del resto del arreglo
// y lo coloca en su posicion definitiva.
// ----------------------------------------------------------------------------
void selectionSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idxMin]) {
                idxMin = j;
            }
        }
        if (idxMin != i) {
            swap(arr[i], arr[idxMin]);
        }
    }
}

// ----------------------------------------------------------------------------
// Funcion auxiliar de Merge Sort: mezcla dos sub-arreglos ya ordenados
// (arr[izq..medio] y arr[medio+1..der]) en un solo bloque ordenado.
// ----------------------------------------------------------------------------
void mezclar(vector<int>& arr, int izq, int medio, int der) {
    vector<int> temp;
    temp.reserve(der - izq + 1);

    int i = izq;
    int j = medio + 1;

    while (i <= medio && j <= der) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= medio) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= der) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++) {
        arr[izq + k] = temp[k];
    }
}

// ----------------------------------------------------------------------------
// Funcion recursiva de Merge Sort: divide el arreglo por la mitad, ordena
// cada mitad de forma recursiva y luego las mezcla con mezclar().
// ----------------------------------------------------------------------------
void mergeSortRec(vector<int>& arr, int izq, int der) {
    if (izq >= der) {
        return; // sub-arreglo de 0 o 1 elementos, ya esta "ordenado"
    }
    int medio = izq + (der - izq) / 2;
    mergeSortRec(arr, izq, medio);
    mergeSortRec(arr, medio + 1, der);
    mezclar(arr, izq, medio, der);
}

// ----------------------------------------------------------------------------
// Merge Sort (Mezcla)
// Complejidad: O(n log n) siempre, incluso en el peor caso.
// ----------------------------------------------------------------------------
void mergeSort(vector<int>& arr) {
    if (!arr.empty()) {
        mergeSortRec(arr, 0, (int)arr.size() - 1);
    }
}

// ----------------------------------------------------------------------------
// Funcion auxiliar de Quick Sort: particion tipo Lomuto.
// Toma el ultimo elemento como pivote y reordena el sub-arreglo de forma
// que los menores queden a la izquierda y los mayores a la derecha.
// Devuelve la posicion final del pivote.
// ----------------------------------------------------------------------------
int particion(vector<int>& arr, int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[alto]);
    return i + 1;
}

// ----------------------------------------------------------------------------
// Funcion recursiva de Quick Sort.
// ----------------------------------------------------------------------------
void quickSortRec(vector<int>& arr, int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        quickSortRec(arr, bajo, pi - 1);
        quickSortRec(arr, pi + 1, alto);
    }
}

// ----------------------------------------------------------------------------
// Quick Sort (Rapido)
// Complejidad: O(n log n) en promedio, O(n^2) en el peor caso.
// ----------------------------------------------------------------------------
void quickSort(vector<int>& arr) {
    if (!arr.empty()) {
        quickSortRec(arr, 0, (int)arr.size() - 1);
    }
}

// ----------------------------------------------------------------------------
// Counting Sort (Conteo)
// Complejidad: O(n + k), donde k es el rango de valores (max - min).
// Idea: cuenta cuantas veces aparece cada valor y luego reconstruye el
// arreglo ya ordenado usando ese conteo. Solo funciona bien con enteros
// dentro de un rango razonable.
// ----------------------------------------------------------------------------
void countingSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int maxVal = arr[0];
    int minVal = arr[0];
    for (int n : arr) {
        if (n > maxVal) maxVal = n;
        if (n < minVal) minVal = n;
    }

    int rango = maxVal - minVal + 1;
    vector<int> conteo(rango, 0);

    for (int n : arr) {
        conteo[n - minVal]++;
    }

    int idx = 0;
    for (int i = 0; i < rango; i++) {
        for (int c = 0; c < conteo[i]; c++) {
            arr[idx] = i + minVal;
            idx++;
        }
    }
}


// ============================================================================
// FUNCIONES DE UTILIDAD (entrada/salida)
// ============================================================================

// ----------------------------------------------------------------------------
// Lee un numero entero desde el teclado, validando que la entrada sea
// realmente un numero. Si el usuario escribe texto invalido, se vuelve a
// pedir el dato.
// ----------------------------------------------------------------------------
int leerEntero(const string& mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor)) {
        cout << "Entrada invalida. Por favor ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

// ----------------------------------------------------------------------------
// Imprime todos los elementos de un vector separados por espacios,
// en una sola linea, igual que en los ejemplos de salida del sistema.
// ----------------------------------------------------------------------------
void imprimirArreglo(const vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i != (int)arr.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

// ----------------------------------------------------------------------------
// Imprime un encabezado decorado con lineas de "=" arriba y abajo del
// titulo indicado, para separar visualmente las secciones del programa.
// ----------------------------------------------------------------------------
void encabezado(const string& titulo) {
    cout << "\n========================================\n";
    cout << "          " << titulo << "\n";
    cout << "========================================\n";
}


// ============================================================================
// FUNCIONES DEL MENU
// ============================================================================

// ----------------------------------------------------------------------------
// Opcion 1: Generar numeros aleatorios.
// Pide al usuario la cantidad de numeros y el rango [minimo, maximo],
// y llena el vector global "numeros" con valores aleatorios dentro de
// ese rango. Ademas reinicia los resultados anteriores, ya que los
// numeros cambiaron.
// ----------------------------------------------------------------------------
void generarNumeros() {
    int cantidad = leerEntero("Cantidad de numeros: ");
    if (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que cero.\n";
        return;
    }

    int minVal = leerEntero("Valor minimo: ");
    int maxVal = leerEntero("Valor maximo: ");

    if (minVal > maxVal) {
        swap(minVal, maxVal);
    }

    numeros.clear();
    numeros.reserve(cantidad);

    for (int i = 0; i < cantidad; i++) {
        int aleatorio = minVal + rand() % (maxVal - minVal + 1);
        numeros.push_back(aleatorio);
    }

    // Como cambiaron los numeros, cualquier resultado anterior queda
    // invalido y se debe reiniciar.
    for (int i = 0; i < 6; i++) {
        ejecutado[i] = false;
        tiempos[i] = 0;
    }

    cout << cantidad << " numeros generados.\n";
}

// ----------------------------------------------------------------------------
// Opcion 2: Mostrar numeros generados.
// Simplemente imprime el contenido actual del vector "numeros".
// ----------------------------------------------------------------------------
void mostrarNumeros() {
    if (numeros.empty()) {
        cout << "Primero genere numeros (opcion 1).\n";
        return;
    }
    imprimirArreglo(numeros);
}

// ----------------------------------------------------------------------------
// Ejecuta un algoritmo especifico (segun "idx", de 0 a 5), mostrando:
//   - El arreglo original.
//   - El arreglo ya ordenado.
//   - El tiempo que tardo el algoritmo, en milisegundos.
// El arreglo original (variable global "numeros") nunca se modifica,
// ya que el ordenamiento se hace sobre una copia local.
// ----------------------------------------------------------------------------
void ejecutarAlgoritmo(int idx) {
    vector<int> copia = numeros;

    cout << "\nArreglo original:\n";
    imprimirArreglo(numeros);

    auto inicio = high_resolution_clock::now();

    switch (idx) {
        case 0:
            bubbleSort(copia);
            break;
        case 1:
            insertionSort(copia);
            break;
        case 2:
            selectionSort(copia);
            break;
        case 3:
            mergeSort(copia);
            break;
        case 4:
            quickSort(copia);
            break;
        case 5:
            countingSort(copia);
            break;
        default:
            cout << "Indice de algoritmo invalido.\n";
            return;
    }

    auto fin = high_resolution_clock::now();
    double duracionMs = duration<double, milli>(fin - inicio).count();

    tiempos[idx] = duracionMs;
    ejecutado[idx] = true;

    cout << "\nArreglo ordenado con " << nombres[idx] << ":\n";
    imprimirArreglo(copia);

    cout << "Tiempo: " << fixed << setprecision(4) << duracionMs << " ms\n";
}

// ----------------------------------------------------------------------------
// Opcion 3: Ordenar con un metodo.
// Muestra un submenu con los 6 algoritmos, una opcion para ejecutarlos
// todos seguidos, y una opcion para regresar al menu principal.
// ----------------------------------------------------------------------------
void ordenarConMetodo() {
    if (numeros.empty()) {
        cout << "Primero genere numeros (opcion 1).\n";
        return;
    }

    int op;
    do {
        encabezado("METODOS DE ORDENAMIENTO");
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Counting Sort\n";
        cout << "7. Todos los metodos\n";
        cout << "8. Regresar\n";

        op = leerEntero("Seleccione una opcion: ");

        if (op >= 1 && op <= 6) {
            // Ejecutar unicamente el algoritmo elegido.
            ejecutarAlgoritmo(op - 1);
        } else if (op == 7) {
            // Ejecutar los 6 algoritmos, uno despues del otro.
            for (int i = 0; i < 6; i++) {
                ejecutarAlgoritmo(i);
            }
        } else if (op != 8) {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (op != 8);
}

// ----------------------------------------------------------------------------
// Opcion 4: Comparar todos los metodos.
// Ejecuta los 6 algoritmos en orden y guarda sus tiempos, para luego
// poder revisarlos con la opcion 5 (Mostrar resultados).
// ----------------------------------------------------------------------------
void compararTodos() {
    if (numeros.empty()) {
        cout << "Primero genere numeros (opcion 1).\n";
        return;
    }

    for (int i = 0; i < 6; i++) {
        ejecutarAlgoritmo(i);
    }
}

// ----------------------------------------------------------------------------
// Opcion 5: Mostrar resultados.
// Imprime una tabla con el tiempo obtenido por cada algoritmo que ya
// haya sido ejecutado al menos una vez.
// ----------------------------------------------------------------------------
void mostrarResultados() {
    bool hayAlguno = false;
    for (int i = 0; i < 6; i++) {
        if (ejecutado[i]) {
            hayAlguno = true;
            break;
        }
    }

    if (!hayAlguno) {
        cout << "Aun no hay resultados. Use la opcion 3 o 4 primero.\n";
        return;
    }

    cout << "\nAlgoritmo            Tiempo (ms)\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < 6; i++) {
        cout << left << setw(20) << nombres[i];
        if (ejecutado[i]) {
            cout << fixed << setprecision(4) << tiempos[i] << "\n";
        } else {
            cout << "--\n";
        }
    }
}


// ============================================================================
// FUNCION PRINCIPAL (MENU)
// ============================================================================
int main() {
    // Se inicializa la semilla de numeros aleatorios una sola vez,
    // usando la hora actual del sistema.
    srand((unsigned int)time(0));

    int opcion;

    do {
        encabezado("MENU PRINCIPAL");
        cout << "1. Generar numeros aleatorios\n";
        cout << "2. Mostrar numeros generados\n";
        cout << "3. Ordenar con un metodo\n";
        cout << "4. Comparar todos los metodos\n";
        cout << "5. Mostrar resultados\n";
        cout << "6. Salir\n";

        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                generarNumeros();
                break;
            case 2:
                mostrarNumeros();
                break;
            case 3:
                ordenarConMetodo();
                break;
            case 4:
                compararTodos();
                break;
            case 5:
                mostrarResultados();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 6);

    return 0;
}