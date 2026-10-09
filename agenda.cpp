#include <iostream>
#include <string>
using namespace std;

// ================== Clase Fecha ==================
class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha() {
        dia = 0;
        mes = 0;
        anio = 0;
    }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAnio(int a) { anio = a; }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }

    void imprimir() {
        cout << dia << "/" << mes << "/" << anio;
    }
};

// ================== Clase Contacto ==================
class Contacto {
private:
    string numeros[3];
    int cantNumeros;
    string nombre;
    string correo;
    string direccion;
    bool estaBloqueado;
    bool eliminado;
    Fecha fechaNacimiento;

public:
    Contacto() {
        cantNumeros = 0;
        estaBloqueado = false;
        eliminado = false;
    }

    // ---- Setters ----
    void setNumero(int pos, string n) { numeros[pos] = n; }
    void setCantNumeros(int c) { cantNumeros = c; }
    void setNombre(string n) { nombre = n; }
    void setCorreo(string c) { correo = c; }
    void setDireccion(string d) { direccion = d; }
    void setEstaBloqueado(bool b) { estaBloqueado = b; }
    void setEliminado(bool e) { eliminado = e; }
    void setFechaNacimiento(Fecha f) { fechaNacimiento = f; }

    // ---- Getters ----
    string getNumero(int pos) { return numeros[pos]; }
    int getCantNumeros() { return cantNumeros; }
    string getNombre() { return nombre; }
    string getCorreo() { return correo; }
    string getDireccion() { return direccion; }
    bool getEstaBloqueado() { return estaBloqueado; }
    bool getEliminado() { return eliminado; }
    Fecha getFechaNacimiento() { return fechaNacimiento; }

    // ---- Metodos ----
    void registrar() {
        string texto;

        cout << "Nombre: ";
        cin >> texto;
        nombre = texto;

        cout << "Cuantos numeros tiene (maximo 3): ";
        cin >> cantNumeros;
        if (cantNumeros > 3) {
            cantNumeros = 3;
        }
        for (int i = 0; i < cantNumeros; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> numeros[i];
        }

        cout << "Correo electronico: ";
        cin >> correo;

        cout << "Direccion: ";
        cin >> direccion;

        int d, m, a;
        cout << "Fecha de nacimiento" << endl;
        cout << "Dia: ";
        cin >> d;
        cout << "Mes: ";
        cin >> m;
        cout << "Anio: ";
        cin >> a;
        fechaNacimiento.setDia(d);
        fechaNacimiento.setMes(m);
        fechaNacimiento.setAnio(a);
    }

    void eliminar() {
        eliminado = true;
    }

    void bloquear() {
        estaBloqueado = true;
    }

    void desbloquear() {
        estaBloqueado = false;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        for (int i = 0; i < cantNumeros; i++) {
            cout << "Numero " << i + 1 << ": " << numeros[i] << endl;
        }
        cout << "Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Fecha de nacimiento: ";
        fechaNacimiento.imprimir();
        cout << endl;
        if (estaBloqueado) {
            cout << "Estado: BLOQUEADO" << endl;
        } else {
            cout << "Estado: Activo" << endl;
        }
    }

    // Devuelve true si el texto esta en el nombre
    bool buscar(string texto) {
        if (nombre.find(texto) != string::npos) {
            return true;
        }
        return false;
    }

    int calcularEdad(int diaHoy, int mesHoy, int anioHoy) {
        int edad = anioHoy - fechaNacimiento.getAnio();
        if (mesHoy < fechaNacimiento.getMes()) {
            edad = edad - 1;
        } else if (mesHoy == fechaNacimiento.getMes() && diaHoy < fechaNacimiento.getDia()) {
            edad = edad - 1;
        }
        return edad;
    }

    void listar() {
        cout << nombre;
        if (cantNumeros > 0) {
            cout << " - " << numeros[0];
        }
        if (estaBloqueado) {
            cout << " (bloqueado)";
        }
        cout << endl;
    }

    bool cumpleHoy(int diaHoy, int mesHoy) {
        if (fechaNacimiento.getDia() == diaHoy && fechaNacimiento.getMes() == mesHoy) {
            return true;
        }
        return false;
    }
};

// ================== Programa principal ==================
int main() {
    Contacto agenda[100];
    int total = 0;
    int opcion;

    do {
        cout << endl;
        cout << "===== AGENDA =====" << endl;
        cout << "1) Registrar nuevo contacto" << endl;
        cout << "2) Editar contacto" << endl;
        cout << "3) Listar contacto" << endl;
        cout << "4) Eliminar contacto" << endl;
        cout << "5) Bloquear contacto" << endl;
        cout << "6) Buscar contacto" << endl;
        cout << "7) Cumpleanios de hoy" << endl;
        cout << "8) Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (total < 100) {
                    agenda[total].registrar();
                    total++;
                    cout << "Contacto registrado." << endl;
                } else {
                    cout << "La agenda esta llena." << endl;
                }
                break;
            }

            case 2: {
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado()) {
                        cout << i + 1 << ") ";
                        agenda[i].listar();
                    }
                }
                int pos;
                cout << "Numero del contacto a editar: ";
                cin >> pos;
                pos = pos - 1;
                if (pos >= 0 && pos < total && !agenda[pos].getEliminado()) {
                    string texto;
                    cout << "Nuevo nombre: ";
                    cin >> texto;
                    agenda[pos].setNombre(texto);
                    cout << "Nuevo correo: ";
                    cin >> texto;
                    agenda[pos].setCorreo(texto);
                    cout << "Nueva direccion: ";
                    cin >> texto;
                    agenda[pos].setDireccion(texto);
                    cout << "Contacto editado." << endl;
                } else {
                    cout << "Contacto no valido." << endl;
                }
                break;
            }

            case 3: {
                int cantidad = 0;
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado()) {
                        agenda[i].listar();
                        cantidad++;
                    }
                }
                if (cantidad == 0) {
                    cout << "No hay contactos." << endl;
                }
                break;
            }

            case 4: {
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado()) {
                        cout << i + 1 << ") ";
                        agenda[i].listar();
                    }
                }
                int pos;
                cout << "Numero del contacto a eliminar: ";
                cin >> pos;
                pos = pos - 1;
                if (pos >= 0 && pos < total && !agenda[pos].getEliminado()) {
                    agenda[pos].eliminar();
                    cout << "Contacto eliminado." << endl;
                } else {
                    cout << "Contacto no valido." << endl;
                }
                break;
            }

            case 5: {
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado()) {
                        cout << i + 1 << ") ";
                        agenda[i].listar();
                    }
                }
                int pos;
                cout << "Numero del contacto: ";
                cin >> pos;
                pos = pos - 1;
                if (pos >= 0 && pos < total && !agenda[pos].getEliminado()) {
                    if (agenda[pos].getEstaBloqueado()) {
                        agenda[pos].desbloquear();
                        cout << "Contacto desbloqueado." << endl;
                    } else {
                        agenda[pos].bloquear();
                        cout << "Contacto bloqueado." << endl;
                    }
                } else {
                    cout << "Contacto no valido." << endl;
                }
                break;
            }

            case 6: {
                string texto;
                cout << "Nombre a buscar: ";
                cin >> texto;
                bool encontrado = false;
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado() && agenda[i].buscar(texto)) {
                        agenda[i].mostrar();
                        cout << "-----------------" << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "No se encontro ningun contacto." << endl;
                }
                break;
            }

            case 7: {
                int d, m, a;
                cout << "Ingrese la fecha de hoy" << endl;
                cout << "Dia: ";
                cin >> d;
                cout << "Mes: ";
                cin >> m;
                cout << "Anio: ";
                cin >> a;
                bool hay = false;
                for (int i = 0; i < total; i++) {
                    if (!agenda[i].getEliminado() && agenda[i].cumpleHoy(d, m)) {
                        cout << agenda[i].getNombre() << " cumple "
                             << agenda[i].calcularEdad(d, m, a) << " anios hoy" << endl;
                        hay = true;
                    }
                }
                if (!hay) {
                    cout << "Nadie cumple anios hoy." << endl;
                }
                break;
            }

            case 8:
                cout << "Hasta luego." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 8);

    return 0;
}