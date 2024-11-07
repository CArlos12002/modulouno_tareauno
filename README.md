# Simulación de Robots de Limpieza Reactivos

### Carlos Anaya Ruiz
### A01662464

## Descripción del Proyecto
Este proyecto implementa una simulación de robots de limpieza en una habitación representada como una matriz de celdas. Los robots pueden operar bajo distintos comportamientos, ya sea de forma reactiva (aleatoria) o siguiendo algoritmos de búsqueda para optimizar el proceso de limpieza. La simulación permite analizar cómo el número de robots y el tipo de comportamiento influyen en la eficiencia de limpieza.

## Funcionamiento del Código
La simulación utiliza una matriz para representar la habitación, donde cada celda puede estar limpia (0) o sucia (1). Los robots se mueven por la habitación y limpian las celdas sucias según un conjunto de reglas:
- **Comportamiento Reactivo (Aleatorio)**: Los robots se mueven aleatoriamente a celdas adyacentes cuando no encuentran suciedad.
- **Comportamientos con Razonamiento**: Los robots pueden usar algoritmos de búsqueda como BFS o DFS para mejorar su recorrido, identificando celdas sucias cercanas y reduciendo el número de movimientos aleatorios.

El programa recopila:
- Tiempo necesario para limpiar toda la habitación.
- Porcentaje de celdas limpias al final de la simulación.
- Número total de movimientos realizados por todos los agentes.

## Parámetros de Ejecución
El código permite configurar los siguientes parámetros:
- **Dimensiones de la habitación (MxN)**: Tamaño de la matriz.
- **Número de agentes**: Cantidad de robots que operarán en la simulación.
- **Porcentaje de celdas sucias**: Proporción de celdas que empiezan sucias al inicio.
- **Tiempo máximo de ejecución**: Número máximo de pasos de tiempo.

## Ejemplo
int filas = 20;
int columnas = 20;
double porcentaje_suciedad = 0.5;
int numero_agentes = 3;
int tiempo_maximo = 150;


## Instrucciones de Uso
Para ejecutar el programa, sigue estos pasos:

1. **Compilar el código**:
   Utiliza un compilador de C++ para compilar el archivo de la simulación:
   ```bash
   g++ -o simulacion_robot_limpieza simulacion_robot_limpieza.cpp
