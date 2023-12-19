/*
Explicación del programa:
El programa trata de una "aplicación de mensajería", donde un cliente desea saber
el tiempo que demora un mensaje en llegar a otro cliente. Para ello, se tienen dos
tipos de nodos: clientes y routers. Los clientes son los nodos que envían y reciben
mensajes, mientras que los routers son los nodos que se encargan de enrutar los
mensajes entre los clientes. Cada conexión (arista) tiene una velocidad de conexión y una
distancia de conexión. La velocidad de conexión es la velocidad de transmisión de
datos que tiene el nodo, mientras que la distancia es la cantidad de segundos
que tarda un "paquete" en enviarse a destino. El usuario de la plataforma debe entregar
el peso del archivo que desea enviar (lo que afecta a la velocidad de conexión). Por ejemplo,
si desde el cliente con id 0 (300 mb de velocidad) deseo enviar un archivo de 1200 mb, 
entonces el archivo debe ser particionado en 4 partes, debido a que la 
conexión solo acepta 300 mb como máximo.
La distancia también afecta el tiempo de conexión, ya que entrega la 
información de cuantos segundos se demora en enviar un archivo. 
Siguiendo con el ejemplo anterior, si la misma persona desea enviar el 
archivo de 1200 mb, entonces debe dividirse en 4 partes, cada parte se 
demora 1 segundo en generar la conexión con el router con id 10, por lo 
tanto, solo para que el archivo completo llegue al router, se demorara un 
tiempo total de 4 segundos.
Usuario además tiene que ser capaz de conocer la ruta que esta tomando el 
archivo y conocer los tiempos entre cada nodo que se comunica.

Para lograr esto, se deben leer 2 archivos csv. El primer archivo llamado servidores.csv,
establece la información de los clientes y servidores y el tipo con el 
siguiente formato:
id,nombre,tipo
0,Servidor0,cliente
1,Servidor1,cliente
2,Servidor2,cliente
3,Servidor3,cliente
4,Servidor4,router
5,Servidor5,cliente
6,Servidor6,cliente
7,Servidor7,router
8,Servidor8,cliente
9,Servidor9,cliente
10,Servidor10,cliente

El segundo archivo llamado conexiones.csv establece las conexiones de 
cliente con servidor y de servidor con servidor (cliente vendría a ser un pc 
de casa y servidor vendría a ser routers que generan la conexión wan), el 
archivo establece la información de la conexión con el siguiente formato:
idCliente,idServidor,velocidad,distancia
0,4,300,3
1,4,300,2
2,4,600,5
3,4,300,4
5,7,300,4
6,7,900,4
8,13,900,1
9,13,600,4
10,13,300,8

El programa debe leer ambos archivos y generar un grafo con la información
entregada. Luego, el usuario debe ingresar el id del cliente que desea enviar
el archivo, el id del cliente que desea recibir el archivo y el peso del archivo
en mb. El programa debe entregar la ruta que toma el archivo y el tiempo que
demora en llegar a destino. En caso de que el archivo no pueda ser enviado,
el programa debe entregar un mensaje de error.

Para recorrer el grafo y entregar el mejor camino, se debe utilizar el algoritmo de Bellman-Ford
*/

// Incluir las librerías necesarias
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

// Definir las estructuras para el grafo
struct Nodo { // Nodos
    int id; // Identificador del nodo
    string nombre; // Nombre del nodo
    string tipo; // Tipo del nodo (cliente o router)
};

struct Arista { // Conexiones
    int origen; // Identificador del nodo de origen
    int destino; // Identificador del nodo de destino
    int velocidad; // Velocidad de conexión
    int distancia; // Distancia de conexión
    int peso; // Peso de la arista
};

// Definimos la función que calcula la ruta más corta entre dos nodos usando Bellman-Ford.
// Recibe como parámetros el grafo, el nodo de origen y el nodo de destino.
// Retorna un vector con los nodos que forman la ruta más corta.
vector<int> bellmanFord(vector<Nodo>& nodos, vector<Arista>& aristas, int origen, int destino) {
    // Creamos el vector que almacenará la ruta más corta
    vector<int> ruta;

    // Implementar...
    
    // Retornar la ruta más corta
    return ruta;
}

// Función principal
int main() {
    // Creamos los vectores que almacenarán la información del grafo
    vector<Nodo> nodos;
    vector<Arista> aristas;
    // Creamos las variables que almacenarán la información de los archivos
    string id, nombre, tipo, origen, destino, velocidad, distancia;
    // Creamos las variables que almacenarán la información del usuario
    int idOrigen, idDestino, peso;
    // Creamos las variables que almacenarán la información del grafo
    int cantidadNodos, cantidadAristas;
    // Creamos las variables que almacenarán la información del algoritmo
    int distanciaMinima, nodoAnterior;
    // Creamos las variables que almacenarán la información de la ruta
    string ruta, rutaFinal;
    // Creamos las variables que almacenarán la información del tiempo
    int tiempo, tiempoFinal;

    // Abrimos el archivo servidores.csv
    ifstream archivoServidores("servidores.csv");
    // Abrimos el archivo conexiones.csv
    ifstream archivoConexiones("conexiones.csv");

    // Leemos la primera línea del archivo servidores.csv
    getline(archivoServidores, id, ',');
    getline(archivoServidores, nombre, ',');
    getline(archivoServidores, tipo, '\n');

    // Leemos la primera línea del archivo conexiones.csv
    getline(archivoConexiones, origen, ',');
    getline(archivoConexiones, destino, ',');
    getline(archivoConexiones, velocidad, ',');
    getline(archivoConexiones, distancia, '\n');

    // Leemos el resto del archivo servidores.csv
    while (getline(archivoServidores, id, ',')) {
        getline(archivoServidores, nombre, ',');
        getline(archivoServidores, tipo, '\n');
        // Creamos un nodo con la información leída
        Nodo nodo;
        nodo.id = stoi(id);
        nodo.nombre = nombre;
        nodo.tipo = tipo;
        // Agregamos el nodo al vector de nodos
        nodos.push_back(nodo);
    }

    // Leemos el resto del archivo conexiones.csv
    while (getline(archivoConexiones, origen, ',')) {
        getline(archivoConexiones, destino, ',');
        getline(archivoConexiones, velocidad, ',');
        getline(archivoConexiones, distancia, '\n');
        // Creamos una arista con la información leída
        Arista arista;
        arista.origen = stoi(origen);
        arista.destino = stoi(destino);
        arista.velocidad = stoi(velocidad);
        arista.distancia = stoi(distancia);
        arista.peso = stoi(distancia) / stoi(velocidad);
        // Agregamos la arista al vector de aristas
        aristas.push_back(arista);
    }

    // Cerramos el archivo servidores.csv
    archivoServidores.close();
    // Cerramos el archivo conexiones.csv
    archivoConexiones.close();

    /*
    // Para verificar que la información carga correctamente, mostramos los primeros
    // 10 nodos y las primeras 10 aristas
    cout << "Nodos:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << nodos[i].id << " " << nodos[i].nombre << " " << nodos[i].tipo << endl;
    }
    cout << endl;
    cout << "Aristas:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << aristas[i].origen << " " << aristas[i].destino << " " << aristas[i].velocidad << " " << aristas[i].distancia << " " << aristas[i].peso << endl;
    }
    cout << endl;
    */

    // Calculamos la cantidad de nodos
    cantidadNodos = nodos.size();
    // Calculamos la cantidad de aristas
    cantidadAristas = aristas.size();

    // Creamos las matrices que almacenarán la información del grafo
    int matrizAdyacencia[cantidadNodos][cantidadNodos];
    int matrizPesos[cantidadNodos][cantidadNodos];
    int matrizRuta[cantidadNodos][cantidadNodos];

    // Inicializamos las matrices
    for (int i = 0; i < cantidadNodos; i++) {
        for (int j = 0; j < cantidadNodos; j++) {
            matrizAdyacencia[i][j] = 0;
            matrizPesos[i][j] = 0;
            matrizRuta[i][j] = 0;
        }
    }

    // Llenamos las matrices con la información de los nodos y aristas
    for (int i = 0; i < cantidadAristas; i++) {
        matrizAdyacencia[aristas[i].origen][aristas[i].destino] = 1;
        matrizPesos[aristas[i].origen][aristas[i].destino] = aristas[i].peso;
        matrizRuta[aristas[i].origen][aristas[i].destino] = aristas[i].destino;
    }

    // Pedimos al usuario el id del cliente de origen
    cout << "Ingrese el id del cliente de origen: ";
    cin >> idOrigen;
    // Pedimos al usuario el id del cliente de destino
    cout << "Ingrese el id del cliente de destino: ";
    cin >> idDestino;
    // Pedimos al usuario el peso del archivo en mb
    cout << "Ingrese el peso del archivo en mb: ";
    cin >> peso;

    // Calculamos la ruta más corta entre el cliente de origen y el cliente de destino
    vector<int> rutaCorta = bellmanFord(nodos, aristas, idOrigen, idDestino);

    // Mostramos la ruta más corta
    cout << "La ruta más corta es: ";
    for (int i = 0; i < rutaCorta.size(); i++) {
        cout << rutaCorta[i] << " ";
    }
    cout << endl;

    // Terminamos el programa
    return 0;
}