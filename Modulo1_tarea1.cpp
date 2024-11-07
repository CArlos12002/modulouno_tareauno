#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Clase que representa la habitación
class Habitacion {
public:
    Habitacion(int filas, int columnas, double porcentaje_suciedad)
        : filas(filas), columnas(columnas), matriz(filas, std::vector<int>(columnas, 0)) {
        inicializar_suciedad(porcentaje_suciedad);
    }

    bool esta_sucia(int fila, int columna) const {
        return matriz[fila][columna] == 1;
    }

    void limpiar(int fila, int columna) {
        matriz[fila][columna] = 0;
    }

    int obtener_filas() const {
        return filas;
    }

    int obtener_columnas() const {
        return columnas;
    }

    bool todas_limpias() const {
        for (const auto& fila : matriz) {
            for (int celda : fila) {
                if (celda == 1) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int filas;
    int columnas;
    std::vector<std::vector<int>> matriz;

    void inicializar_suciedad(double porcentaje) {
        int total_celdas = filas * columnas;
        int celdas_sucias = static_cast<int>(total_celdas * porcentaje);
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < celdas_sucias; ++i) {
            int fila = rand() % filas;
            int columna = rand() % columnas;
            matriz[fila][columna] = 1; // 1 representa suciedad
        }
    }
};

// Clase que representa al robot de limpieza
class RobotLimpieza {
public:
    RobotLimpieza(Habitacion& habitacion, int fila_inicial, int columna_inicial)
        : habitacion(habitacion), fila(fila_inicial), columna(columna_inicial), movimientos(0) {}

    void actuar() {
        if (habitacion.esta_sucia(fila, columna)) {
            habitacion.limpiar(fila, columna);
        } else {
            mover();
        }
    }

    int obtener_movimientos() const {
        return movimientos;
    }

private:
    Habitacion& habitacion;
    int fila;
    int columna;
    int movimientos;

    void mover() {
        static const int movimientos_posibles[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        while (true) {
            int indice = rand() % 8;
            int nueva_fila = fila + movimientos_posibles[indice][0];
            int nueva_columna = columna + movimientos_posibles[indice][1];
            if (nueva_fila >= 0 && nueva_fila < habitacion.obtener_filas() &&
                nueva_columna >= 0 && nueva_columna < habitacion.obtener_columnas()) {
                fila = nueva_fila;
                columna = nueva_columna;
                ++movimientos;
                break;
            }
        }
    }
};

int main() {
    // Parámetros de la simulación
    int filas = 10;
    int columnas = 10;
    double porcentaje_suciedad = 0.3;
    int numero_agentes = 2;
    int tiempo_maximo = 100;

    // Inicializar entorno y agentes
    Habitacion habitacion(filas, columnas, porcentaje_suciedad);
    std::vector<RobotLimpieza> agentes;
    for (int i = 0; i < numero_agentes; ++i) {
        agentes.emplace_back(habitacion, 0, 0);
    }

    // Ejecutar simulación
    int tiempo;
    for (tiempo = 0; tiempo < tiempo_maximo; ++tiempo) {
        for (auto& agente : agentes) {
            agente.actuar();
        }
        if (habitacion.todas_limpias()) {
            std::cout << "Todas las celdas están limpias en el tiempo " << tiempo << ".\n";
            break;
        }
    }
    if (tiempo == tiempo_maximo) {
        std::cout << "Se alcanzó el tiempo máximo de simulación.\n";
    }

    // Resultados
    int movimientos_totales = 0;
    for (const auto& agente : agentes) {
        movimientos_totales += agente.obtener_movimientos();
    }
    int celdas_limpias = filas * columnas;
    double porcentaje_limpias = 100.0;

    std::cout << "Movimientos totales: " << movimientos_totales << "\n";
    std::cout << "Porcentaje de celdas limpias: " << porcentaje_limpias << "%\n";

    return 0;
}
