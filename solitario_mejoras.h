//JUEGO DEL SOLITARIO

//Incluir librerias

#include<stdio.h>
#include<stdlib.h> //rand(), system()
#include<time.h> //time()
#include<ctype.h> //tolower()


//Definir variables

//Definir variables

//Numero de cartas de la baraja
#define NUM_CARTAS_BARAJA 48  
//Atributo si la carta esta visible
#define VISIBLE 1
//Atributo si la carta no esta visible
#define NOVISIBLE 2
//Numero para identificar una pila vacia
#define VACIA 0
//Numero para identificar una carta que ha sdo quitada del descarte
#define NUM_SIGUIENTE -1


//Definir gotoxy para imprimir el tablero

#define gotoxy(x,y) printf("\x1b[%d;%dH",(y),(x));


/*Definir la estructura carta con un campo para el numero de la carta, otro para el palo y otro para la visibilidad de la carta*/

typedef struct Carta{
  char palo; // 'O', 'C', 'E' y 'B'
  int num; // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 y 12
  int vis; //VISIBLE o NOVISIBLE
}carta;


//Declaracion de funciones

//Imprimir el tablero basico del juego
void pantallaInicial();

/*Menu principal con las elecciones basicas (iniciar juego, guardar juego, cargar juego y salir del juego*/
void eleccion (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Genera las doce cartas de cada palo con su correspendiente letra
void generar  ();

//Baraja las cartas generadas de forma aleatoria
void barajar (carta[]);

//Reparte las cartas generadas en el tablero
void repartir (carta[]);

/*Identifica la carta que mas abajo este y devuelve su posicion para imprimir las indicaciones inferiores*/
int num_mayor (int, int, int, int, int, int, int);

//Comprueba si el movimiento es valido o si se pide ir al menu
void movimiento (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Comprueba si el movimieno es imcorrecto o si se puede realizar
void realizarMovimiento (int, int, int, int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Comprueba si hay algun error y realiza el movimiento entre columnas
void cambioCartasColumnas (int, int, carta[], carta[]);

//Comprueba si hay algun error y realiza el movimiento entre salidas
void cambioCartasSalidas (int, int, carta[], carta[]);

/*Imprime el tablero, contador, indicaciones inferiores, cartas de las columnas y cartas de las salidas*/
int imprimir (int,carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Imprime el descarte cuando se ha quitado una carta de el
void imprimirDescarte (carta[]);

//Funcion que imprime el tablero cuando las salidas estan llenas o el contador es 3
void JuegoCompleto (int, carta[], carta[], carta[], carta[]);

//Se llama cuando se ha introducido un caracter o conjunto que no es m o M
void Solo_m_o_M (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Imprime las reglas del juego
int Reglas (char[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Guarda el juego en su transcurso
void guardarJuego(int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);

//Carga el ultimo juego guardado
void cargarJuego(int*, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
