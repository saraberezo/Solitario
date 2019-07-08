//JUEGO DEL SOLITARIO

#include "solitario_mejoras.h"

//Declaracion de funciones

void pantallaInicial();
void eleccion (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void generar  ();
void barajar (carta[]);
void repartir (carta[]);
int num_mayor (int, int, int, int, int, int, int);
void movimiento (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void realizarMovimiento (int, int, int, int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void cambioCartasColumnas (int, int, carta[], carta[]);
void cambioCartasSalidas (int, int, carta[], carta[]);
int imprimir (int,carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void imprimirDescarte (carta[]);
void JuegoCompleto (int, carta[], carta[], carta[], carta[]);
void Solo_m_o_M (int, int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
int Reglas (char[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void guardarJuego(int, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);
void cargarJuego(int*, carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[], carta[]);


//Menu principal

int main (){

  int contVueltas=0;
  carta descarte[21], columna1[12], columna2[13], columna3[14], columna4[15], columna5[16], columna6[17], columna7[18], salida8[13], salida9[13], salida10[13], salida11[13];
 int  k=19;

  srand(time(NULL));
  pantallaInicial();
  eleccion (k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);

  return 0;
}


//Desarrollo de funciones

void pantallaInicial (){

  int contVueltas=0;
  /*La componente 0 sera el contador de vueltas del mazo, la componente 1 sera el contador de movimientos validos y la componente 2 sera el contador de movimientos no validos"*/

  system("clear");
  gotoxy(0,0); printf("**************************** JUEGO DEL SOLITARIO *******************************");
  gotoxy(0,3);  printf("MAZO\t");
  gotoxy(10,3);  printf("CONT\t"); 
  gotoxy(30,3); printf("Salida8\t"); 
  gotoxy(40,3);  printf("Salida9\t"); 
  gotoxy(50,3);  printf("Salida10\t"); 
  gotoxy(60,3);  printf("Salida11\t"); 
  gotoxy(0,7);  printf("DESCARTE:\t");
  gotoxy(0,10);  printf("Columna1\t"); 
  gotoxy(10,10); printf("Columna2\t");
  gotoxy(20,10);  printf("Columna3\t"); 
  gotoxy(30,10); printf("Columna4\t");
  gotoxy(40,10);  printf("Columna5\t"); 
  gotoxy(50,10);  printf("Columna6\t"); 
  gotoxy(60,10);  printf("Columna7\t"); 
  gotoxy(0,5);  printf("???\t");
  gotoxy(11,5); printf("%d\t",contVueltas);
  gotoxy(31,5); printf("vacia\t");
  gotoxy(41,5); printf("vacia\t");
  gotoxy(51,5); printf("vacia\t");
  gotoxy(61,5); printf("vacia\t");
  gotoxy(11,7); printf("vacia\t");
  gotoxy(2,12); printf("vacia\t");
  gotoxy(12,12); printf("vacia\t");
  gotoxy(22,12); printf("vacia\t");
  gotoxy(32,12); printf("vacia\t");
  gotoxy(42,12); printf("vacia\t");
  gotoxy(52,12); printf("vacia\t");
  gotoxy(62,12); printf("vacia\t");
  
  return;
}


//Menu

void eleccion (int k, int contVueltas, carta descarte[],carta columna1[],carta columna2[],carta columna3[],carta columna4[],carta columna5[],carta columna6[],carta columna7[],carta salida8[],carta salida9[],carta salida10[],carta salida11[]){

  int var_eleccion;
  
  do{
    if(k>=19){
      gotoxy(0,k+8); printf("\t1.Iniciar nuevo juego.\n\t2.Recuperar juego guardado.\n\t3.Guardar juego.\n\t4.Salir del juego.\n\t(Elegir una opcion pulsando 1,2,3 o 4).");
      gotoxy (24,k+14); printf ("             ");
      gotoxy(0,k+14); printf ("Introduzca su eleccion: ");
    }
    else{  
      gotoxy(0,27); printf("\t1.Iniciar nuevo juego.\n\t2.Recuperar juego guardado.\n\t3.Guardar juego.\n\t4.Salir del juego.\n\t(Elegir una opcion pulsando 1,2,3 o 4).");
      gotoxy (24,33); printf ("             ");
      gotoxy(0,33); printf ("Introduzca su eleccion: ");
    }
    scanf(" %d",&var_eleccion);

    switch (var_eleccion){

    case 1: generar(); //Inicar juego
      break;

    case 2: //Recuperar juego guardado
      cargarJuego(&contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;

    case 3:
      if(contVueltas==0){
	printf("%c[%d;%dmERROR: No se puede guardar el juego porque no ha empezado todavia.%c[%dm", 27,1,34,27,0);
      }
      else{
	guardarJuego(contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      }      
      var_eleccion=0;
      break;

    case 4://Salir del juego
      printf("%c[%d;%dm\n\n               USTED HA SALIDO DEL JUEGO.    \n\n\n%c[%dm", 27,1,35,27, 0); 
      exit (1);

    default: printf("%c[%d;%dmERROR: ELECCION INCORRECTA, PULSAR 1,2,3 Ó 4.%c[%dm", 27,1,34,27,0);
      break;
    }
    
  }while(var_eleccion<1 || var_eleccion>4);
  
  return;
}


//Generar las cartas de la baraja española

void generar (){ 

  int k;
  int pal;
  carta m[NUM_CARTAS_BARAJA];
  
  for(k=0;k<48;k++){
    m[k].num=k%12+1;
    pal=k/12;
    switch(pal){
    case 0:
      m[k].palo='B';
      break;
    case 1:
      m[k].palo='C';
      break;
    case 2:
      m[k].palo='E';
      break;
    case 3:
      m[k].palo='O';
      break;
    }
  }
  barajar(m);
  repartir (m);
  
  return;
}


//Barajar aleatoriamente las carta ya generadas e incluidas en un mazo

void barajar (carta v[]){

  int i,j,k;
  carta temp;

  for (i=0;i<3000;i++){
    j=rand()%48;
    k=rand()%48;
    temp=v[j];v[j]=v[k];v[k]=temp;
  }

  return;
}


//Repartir las cartas en las diferentes pilas

void repartir (carta m[]){
  
  int i, j, k=0;
  int contVueltas=1;
  carta columna1[12], columna2[13], columna3[14], columna4[15], columna5[16], columna6[17], columna7[18];
  carta salida8[1], salida9[1], salida10[1], salida11[1];
  carta descarte[21];

  //SALIDA 8
  salida8[0].num=VACIA;
  gotoxy(31,3); printf("vacia\t");
  
  //SALIDA 9
  salida9[0].num=VACIA;
  gotoxy(41,3); printf("vacia\t");
  
  //SALIDA 10
  salida10[0].num=VACIA;
  gotoxy(51,3); printf("vacia\t");
  
  //SALIDA 11
  salida11[0].num=VACIA;
  gotoxy(61,3); printf("vacia\t");
  
  //COLUMNA 1
  columna1[0].num=1;
  for (i=1; i<2; i++){
    columna1[i].num=m[k].num;
    columna1[i].palo=m[k].palo;
    columna1[i].vis=VISIBLE;
    k++;
  }
  
  //COLUMNA 2
  columna2[0].num=2;
  for (i=1; i<3; i++){
    columna2[i].num=m[k].num;
    columna2[i].palo=m[k].palo;
    
    if (i==columna2[0].num){
      columna2[i].vis=VISIBLE;
    }
    else{
      columna2[i].vis=NOVISIBLE;
    }
    k++;
  }
  
  //COLUMNA 3
  columna3[0].num=3;
  for (i=1; i<4; i++){
    columna3[i].num=m[k].num;
    columna3[i].palo=m[k].palo;
    
    if (i==columna3[0].num){
      columna3[i].vis=VISIBLE;
    }
    else{
      columna3[i].vis=NOVISIBLE;
    }
    k++;
  }
  
  //COLUMNA 4
  columna4[0].num=4;
  for (i=1; i<5; i++){
    columna4[i].num=m[k].num;
    columna4[i].palo=m[k].palo;
    
    if (i==columna4[0].num){
      columna4[i].vis=VISIBLE;
    }
    else{
      columna4[i].vis=NOVISIBLE;
    }
    k++;
  }
  
  //COLUMNA 5
  columna5[0].num=5;
  for (i=1; i<6; i++){
    columna5[i].num=m[k].num;
    columna5[i].palo=m[k].palo;
    
    if (i==columna5[0].num){
      columna5[i].vis=VISIBLE;
    }
    else{
      columna5[i].vis=NOVISIBLE;
    }
    k++;
  }
  
  //COLUMNA 6
  columna6[0].num=6;
  for (i=1; i<7; i++){
    columna6[i].num=m[k].num;
    columna6[i].palo=m[k].palo;
    
    if (i==columna6[0].num){
      columna6[i].vis=VISIBLE;
    }
    else{
      columna6[i].vis=NOVISIBLE;
    }
    k++;
  }
  
  //COLUMNA 7
  columna7[0].num=7;
  for (i=1; i<8; i++){
    columna7[i].num=m[k].num;
    columna7[i].palo=m[k].palo;
    
    if (i==columna7[0].num){
      columna7[i].vis=VISIBLE;
    }
    else{
      columna7[i].vis=NOVISIBLE;
    }
    k++;
  }
  
//La cartas quedan repartidas y posicionadas boca abajo y la ulima boca arriba

/*El mazo se queda de forma que la proxima posicion para ser usada es la 28 del mazo, es decir, m[28].num y m[28].palo*/
  
  
  //MAZO Y DESCARTE
  /*En la funcion repartir se han quedado desde la posicion 28 hasta la 47 sin usar, por lo que ahora metemos esas cartas en un nuevo array de tamaño 19 para usarlo como el nuevo mazo. Sin embargo, como el mazo no se muestra, solo hace falta volcar las cartas restantes en el descarte.*/
  j=28;
  descarte[0].num=VACIA; //Nuemero de cartas que han pasado en el descarte
  descarte[21].num=VACIA; //Numero de cartas que se han quitado
  for (i=1; i<21; i++){
    descarte[i].num=m[j].num;
    descarte[i].palo=m[j].palo;
    j++;
  }

  //Numero de cartas que contiene cada columna
  columna1[0].num=1; columna2[0].num=2; columna3[0].num=3; columna4[0].num=4; columna5[0].num=5; columna6[0].num=6; columna7[0].num=7;

  //Llamada a la funcion para imprimir las cartas
  k=imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);
    
  //Llamada a la funcion para realizar los movimientos
  movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
  
  return;
}


//Imprimir las pilas

int imprimir (int contVueltas,carta columna1[], carta columna2[], carta columna3[], carta columna4[], carta columna5[], carta columna6[], carta columna7[], carta salida8[], carta salida9[], carta salida10[], carta salida11[], carta descarte[]){
  
  int i, j; 
  int k1, k2, k3, k4, k5, k6, k7, k; 
  //Para imprimir la indicaciones inferiores
  
  //TABLERO
  system("clear");
  gotoxy(0,0); printf("**************************** JUEGO DEL SOLITARIO *******************************");
  gotoxy(0,3);  printf("MAZO\t");
  gotoxy(10,3);  printf("CONT\t"); 
  gotoxy(30,3); printf("Salida8\t"); 
  gotoxy(40,3);  printf("Salida9\t"); 
  gotoxy(50,3);  printf("Salida10\t"); 
  gotoxy(60,3);  printf("Salida11\t"); 
  gotoxy(0,7);  printf("DESCARTE:\t");
  gotoxy(0,10);  printf("Columna1\t"); 
  gotoxy(10,10); printf("Columna2\t");
  gotoxy(20,10);  printf("Columna3\t"); 
  gotoxy(30,10); printf("Columna4\t");
  gotoxy(40,10);  printf("Columna5\t"); 
  gotoxy(50,10);  printf("Columna6\t"); 
  gotoxy(60,10);  printf("Columna7\t"); 
  gotoxy(0,5); printf ("???  ");
  gotoxy(11,5); printf("%d\t",contVueltas);
  
  
  //DESCARTE
  i=descarte[0].num;
  j=descarte[0].num;

 /*La carta siguiente a la que imprimirmos es la que hemos quitado por eso la ponemos como vacia*/
  while(descarte[j].num==NUM_SIGUIENTE){ 
    descarte[0].num=(descarte[0].num)-1;
    j=descarte[0].num;
  }
  
  if (descarte[0].num==VACIA){
    gotoxy(11,7); printf("vacia");
  }
  else{
     if(descarte[j].palo=='C'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, descarte[j].num, descarte[j].palo, 27, 0);
    }
    if(descarte[j].palo=='O'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, descarte[j].num, descarte[j].palo, 27, 0);
    }
    if(descarte[j].palo=='B'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, descarte[j].num, descarte[j].palo, 27, 0);
    }
    if(descarte[j].palo=='E'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, descarte[j].num, descarte[j].palo, 27, 0);
    }
  }

  //Se comprueba si el mazo esta lleno o vacio
  if((descarte[21].palo)=='V'){
    gotoxy(0,5); printf("vacia");
  }
  if((descarte[21].palo)=='L'){
    gotoxy(0,5); printf("???  ");
  }

  //Se comprueba si se han quitado todas las cartas
  if ((descarte[21].num)==20){
    gotoxy(11,7); printf("vacia");
    gotoxy(0,5); printf("vacia");
  }

  //Volvemos a dejar el descarte en su posicion anterior
  descarte[0].num=i;
  

  //COLUMNA 1
  k1=12;
  if ((columna1[0].num)==VACIA){
    gotoxy(2,12); printf ("vacia");
  }
  for (j=1; j<=columna1[0].num; j++){
    if(columna1[j].vis==VISIBLE){
      if(columna1[j].palo=='C'){
	gotoxy(3,k1); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna1[j].num, columna1[j].palo, 27, 0);
      }
      if(columna1[j].palo=='O'){
	gotoxy(3,k1); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna1[j].num, columna1[j].palo, 27, 0);
      }
      if(columna1[j].palo=='B'){
	gotoxy(3,k1); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna1[j].num, columna1[j].palo, 27, 0);
      }
      if(columna1[j].palo=='E'){
	gotoxy(3,k1); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna1[j].num, columna1[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(3,k1); printf ("??? ");
    }
    k1++;
  }
  
  //COLUMNA 2
  k2=12;
  if ((columna2[0].num)==VACIA){
    gotoxy(12,12); printf ("vacia");
  }
  for (j=1; j<=columna2[0].num; j++){
    if (columna2[j].vis==VISIBLE){
      if(columna2[j].palo=='C'){
	gotoxy(13,k2); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna2[j].num, columna2[j].palo, 27, 0);
      }
      if(columna2[j].palo=='O'){
	gotoxy(13,k2); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna2[j].num, columna2[j].palo, 27, 0);
      }
      if(columna2[j].palo=='B'){
	gotoxy(13,k2); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna2[j].num, columna2[j].palo, 27, 0);
      }
      if(columna2[j].palo=='E'){
	gotoxy(13,k2); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna2[j].num, columna2[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(13,k2); printf ("??? ");
    }
    k2++;
  }

  //COLUMNA 3
  k3=12;
  if ((columna3[0].num)==VACIA){
    gotoxy(22,12); printf ("vacia");
  }
  for (j=1; j<=columna3[0].num; j++){
    if (columna3[j].vis==VISIBLE){
      if(columna3[j].palo=='C'){
	gotoxy(23,k3); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna3[j].num, columna3[j].palo, 27, 0);
      }
      if(columna3[j].palo=='O'){
	gotoxy(23,k3); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna3[j].num, columna3[j].palo, 27, 0);
      }
      if(columna3[j].palo=='B'){
	gotoxy(23,k3); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna3[j].num, columna3[j].palo, 27, 0);
      }
      if(columna3[j].palo=='E'){
	gotoxy(23,k3); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna3[j].num, columna3[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(23,k3); printf ("??? ");
    }
    k3++;
  }  

  //COLUMNA 4
  k4=12;
  if ((columna4[0].num)==VACIA){
    gotoxy(32,12); printf ("vacia");
  }
  for (j=1; j<=columna4[0].num; j++){
    if (columna4[j].vis==VISIBLE){
      if(columna4[j].palo=='C'){
	gotoxy(33,k4); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna4[j].num, columna4[j].palo, 27, 0);
      }
      if(columna4[j].palo=='O'){
	gotoxy(33,k4); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna4[j].num, columna4[j].palo, 27, 0);
      }
      if(columna4[j].palo=='B'){
	gotoxy(33,k4); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna4[j].num, columna4[j].palo, 27, 0);
      }
      if(columna4[j].palo=='E'){
	gotoxy(33,k4); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna4[j].num, columna4[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(33,k4); printf ("??? ");
    }
    k4++;
  }
  
  //COLUMNA 5
  k5=12;
  if ((columna5[0].num)==VACIA){
    gotoxy(42,12); printf ("vacia");
  }
  for (j=1; j<=columna5[0].num; j++){
    if (columna5[j].vis==VISIBLE){
      if(columna5[j].palo=='C'){
	gotoxy(43,k5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna5[j].num, columna5[j].palo, 27, 0);
      }
      if(columna5[j].palo=='O'){
	gotoxy(43,k5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna5[j].num, columna5[j].palo, 27, 0);
      }
      if(columna5[j].palo=='B'){
	gotoxy(43,k5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna5[j].num, columna5[j].palo, 27, 0);
      }
      if(columna5[j].palo=='E'){
	gotoxy(43,k5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna5[j].num, columna5[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(43,k5); printf ("??? ");
    }
    k5++;
  }
  
  //COLUMNA 6
  k6=12;
  if ((columna6[0].num)==VACIA){
    gotoxy(52,12); printf ("vacia");
  }
  for (j=1; j<=columna6[0].num; j++){
    if (columna6[j].vis==VISIBLE){
      if(columna6[j].palo=='C'){
	gotoxy(53,k6); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna6[j].num, columna6[j].palo, 27, 0);
      }
      if(columna6[j].palo=='O'){
	gotoxy(53,k6); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna6[j].num, columna6[j].palo, 27, 0);
      }
      if(columna6[j].palo=='B'){
	gotoxy(53,k6); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna6[j].num, columna6[j].palo, 27, 0);
      }
      if(columna6[j].palo=='E'){
	gotoxy(53,k6); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna6[j].num, columna6[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(53,k6); printf ("??? ");
    }
    k6++;
  }

  //COLUMNA 7
  k7=12;
  if ((columna7[0].num)==VACIA){
    gotoxy(62,12); printf ("vacia");
  }
  for (j=1; j<=columna7[0].num; j++){
    if (columna7[j].vis==VISIBLE){
      if(columna7[j].palo=='C'){
	gotoxy(63,k7); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, columna7[j].num, columna7[j].palo, 27, 0);
      }
      if(columna7[j].palo=='O'){
	gotoxy(63,k7); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, columna7[j].num, columna7[j].palo, 27, 0);
      }
      if(columna7[j].palo=='B'){
	gotoxy(63,k7); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, columna7[j].num, columna7[j].palo, 27, 0);
      }
      if(columna7[j].palo=='E'){
	gotoxy(63,k7); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, columna7[j].num, columna7[j].palo, 27, 0);
      }
    }
    else{
      gotoxy(63,k7); printf ("??? ");
    }
    k7++;
  }
  
  k=num_mayor(k1, k2, k3, k4, k5, k6, k7);

  //INDICACIONES INFERIORES
  if (k>=19){
    gotoxy(0,k+2); printf("INDICAR MOVIMIENTO ENTRE LAS PILAS DE CARTAS:<nro_pila_origen> <nro_pila_destino> <num_cartas>");
    gotoxy(0,k+5); printf("(Para volver al menu pulsar m o M. Para ver las reglas escriba 'reglas').");
    gotoxy(0,k+4); printf("Movimiento: ");
  }
  else{
    gotoxy(0,21); printf("INDICAR MOVIMIENTO ENTRE LAS PILAS DE CARTAS:<nro_pila_origen> <nro_pila_destino> <num_cartas>");
    gotoxy(0,24); printf("(Para volver al menu pulsar m o M. Para ver las reglas escriba 'reglas').");
    gotoxy(0,23); printf("Movimiento: ");
  }

  //SALIDA 8
  if ((salida8[0].num)!=VACIA){
    if(salida8[1].palo=='C'){
      gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida8[1].num, salida8[1].palo, 27, 0);
    }
    if(salida8[1].palo=='O'){
      gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida8[1].num, salida8[1].palo, 27, 0);
    }
    if(salida8[1].palo=='B'){
      gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida8[1].num, salida8[1].palo, 27, 0);
    }
    if(salida8[1].palo=='E'){
      gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida8[1].num, salida8[1].palo, 27, 0);
    }
  }
  else{
    gotoxy(31,5); printf("vacia");
  }
  
  //SALIDA 9
  if ((salida9[0].num)!=VACIA){
    if(salida9[1].palo=='C'){
      gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida9[1].num, salida9[1].palo, 27, 0);
    }
    if(salida9[1].palo=='O'){
      gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida9[1].num, salida9[1].palo, 27, 0);
    }
    if(salida9[1].palo=='B'){
      gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida9[1].num, salida9[1].palo, 27, 0);
    }
    if(salida9[1].palo=='E'){
      gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida9[1].num, salida9[1].palo, 27, 0);
    }
  }
  else{
    gotoxy(41,5); printf("vacia");
  }
  
  //SALIDA 10
  if ((salida10[0].num)!=VACIA){
    if(salida10[1].palo=='C'){
      gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida10[1].num, salida10[1].palo, 27, 0);
    }
    if(salida10[1].palo=='O'){
      gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida10[1].num, salida10[1].palo, 27, 0);
    }
    if(salida10[1].palo=='B'){
      gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida10[1].num, salida10[1].palo, 27, 0);
    }
    if(salida10[1].palo=='E'){
      gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida10[1].num, salida10[1].palo, 27, 0);
    }
  }
  else{
    gotoxy(51,5); printf("vacia");
  }
  
  //SALIDA 11
  if ((salida11[0].num)!=VACIA){
    if(salida11[1].palo=='C'){
      gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida11[1].num, salida11[1].palo, 27, 0);
    }
    if(salida11[1].palo=='O'){
      gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida11[1].num, salida11[1].palo, 27, 0);
    }
    if(salida11[1].palo=='B'){
      gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida11[1].num, salida11[1].palo, 27, 0);
    }
    if(salida11[1].palo=='E'){
      gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida11[1].num, salida11[1].palo, 27, 0);
    }
  }
  else{
    gotoxy(61,5); printf("vacia");
  }
  
  return k; /*Devuelve la fila donde se encuntra la carta que esta mas abajo comparada con las del resto de columnas*/
}


/*Funcion que sirve para devolver la fila en la que se encuentra la carta que esta mas abajo comparada con el resto*/

int num_mayor (int k1, int k2, int k3, int k4, int k5, int k6, int k7){

  int k;

  k=(k1>k2) ? k1 : k2;
  k=(k>k3) ? k : k3;
  k=(k>k4) ? k : k4;
  k=(k>k5) ? k : k5;
  k=(k>k6) ? k : k6;
  k=(k>k7) ? k : k7;

  return k;
}



/*Cuando se llama a esta funcion significa que una carta ha sido quitada del descarte y en esta funcion se elimina*/

void imprimirDescarte (carta descarte []){
  
  int i, j;
int cont=0;
  
  i=descarte[0].num;
  
  descarte[i+1].num=NUM_SIGUIENTE;
  descarte[21].num=((descarte[21].num)+1);

  /*La carta siguiente a la que imprimirmos es la que hemos quitado por eso la ponemos como vacia*/
  while(descarte[i].num==NUM_SIGUIENTE){   
    descarte[0].num=(descarte[0].num)-1;
    i=descarte[0].num;
  }
  
  //Se comprueba si el descarte esta vacio
  if (descarte[0].num==VACIA){
    gotoxy(11,7); printf("vacia");
  }
  else{
     if(descarte[i].palo=='C'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, descarte[i].num, descarte[i].palo, 27, 0);
    }
    if(descarte[i].palo=='O'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, descarte[i].num, descarte[i].palo, 27, 0);
    }
    if(descarte[i].palo=='B'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, descarte[i].num, descarte[i].palo, 27, 0);
    }
    if(descarte[i].palo=='E'){
      gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, descarte[i].num, descarte[i].palo, 27, 0);
    }
  }

  //Se comprueba si el mazo esta vacio
  if((descarte[0].num)==20){
    gotoxy(0,5); printf("vacia");
  }
  else{
    gotoxy(0,5); printf("???  ");
  }
  for(j=i+1; j<=20; j++){
    if (descarte[j].num==NUM_SIGUIENTE){
      cont++;
    }
  }
  if (cont==20-i){
    gotoxy(0,5); printf("vacia");
    descarte[21].palo='V';
  }  
  else{
    descarte[21].palo='L';
  }

  //Se comprueba si se han quitado todas las cartas
  if ((descarte[21].num)==20){
    gotoxy(11,7); printf("vacia");
    gotoxy(0,5); printf("vacia");
  }

  return;
}


/*Introducir movimiento y validar si es correcto. Si lo es se llama a otra funcion para hacer los movimientos. Sino es correcta la entrada se llama otra vez a esta funcion*/

void movimiento (int k, int contVueltas, carta descarte[], carta columna1[], carta columna2[], carta columna3[], carta columna4[], carta columna5[], carta columna6[], carta columna7[], carta salida8[], carta salida9[], carta salida10[], carta salida11[]){
  
  char linea[10];
  char enter;
  int  retorno;
  int origen, destino, cartas;
  int nro_variables;

  //Comprobar si se ha acabado el juego
  if ((salida8[1].num==12) && (salida9[1].num==12) && (salida10[1].num==12) && (salida11[1].num==12)){
    do{
      gotoxy(0,28); printf("%c[%d;%dmHa completado con exito el juego. Pulse enter para continuar...%c[%dm", 27, 1, 35, 27, 0);
    scanf("%c", &enter);
    }while (enter!='\n');
    system("clear");
    JuegoCompleto(contVueltas, salida8, salida9, salida10, salida11);
  }

  if (k>=19){
    gotoxy(13,k+4); printf("                                                 ");
    gotoxy(11,k+4); printf(": ");
  }
  else{
    gotoxy(13,23); printf("                                                  ");
    gotoxy(11,23); printf(": ");
 
  }
  
  fgets(linea,10,stdin);

  retorno=Reglas (linea, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);
  if(retorno==1){
    //Llamada a la funcion para imprimir las cartas
    k=imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);	    
    //Llamada a la funcion para realizar los movimientos
    movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
  }

  if (linea[0]=='\n'){
    movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
  }
  
  if(sscanf(linea, "%d %d %d", &origen, &destino, &cartas)>3){
    nro_variables=4;
  }
  
  if(sscanf(linea, "%d %d %d", &origen, &destino, &cartas)==3){
    nro_variables=3;
  }
  else{
    if(sscanf(linea, "%d %d %d", &origen, &destino, &cartas)==2){
      cartas=1;
      nro_variables=3;
    }
    else{
      if((tolower(linea[0]=='m')) && (linea[1]=='\n')){
	nro_variables=1;
      }
      else{
	if((tolower(linea[0]>='a')) && (tolower(linea[0]<='z'))){
	  Solo_m_o_M(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
	}
      }
    }
  }
  
  /*Depende el numero de variables que le hayamos asignado antes hay una consecuencia*/
  switch (nro_variables){
  case 1: gotoxy(0,26); printf ("                                                                                                ");
    eleccion(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    break;

  case 3: 
    realizarMovimiento(k, contVueltas, origen, destino, cartas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    break;

   default:
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada no es valida.%c[%dm",27,1,34,27,0);
      }
      else{   
	gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada no es valida.%c[%dm",27,1,34,27,0);
      }

    //Se llama a la funcion movimiento porque la entrada no es valida    
    movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    break;
  }
  return;
}


//Funcion que hace el cambio de cartas de acuerdo a los datos introducidos

void realizarMovimiento (int k, int contVueltas, int origen, int destino, int cartas, carta descarte[], carta columna1[], carta columna2[], carta columna3[], carta columna4[], carta columna5[], carta columna6[], carta columna7[], carta salida8[], carta salida9[], carta salida10[], carta salida11[]){

   int i;

  //CASOS QUE PRODUCEN ERROR
 //Si el origen es igual al destino
    if (destino==origen){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: La columa%d no puede ser el origen y el destino a la vez.%c[%dm", 27, 1, 34, destino, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: La columa%d no puede ser el origen y el destino a la vez.%c[%dm", 27, 1, 34, destino, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Si se pasa mas de una carta a las salidas
    if((destino==8 || destino==9 || destino==10 || destino==11) && (cartas>1)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: A las salidas no se puede pasar mas de una carta y usted ha solicitado pasar %i cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: A las salidas no se puede pasar mas de una carta y usted ha solicitado pasar %i cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Si el destino es el descarte (12) y el origen no es el mazo (0)
    if((destino==12) && (origen>1)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: Si el destino es el descarte (12), el origen solo puede ser el mazo (0).%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: Si el destino es el descarte (12), el origen solo puede ser el mazo (0).%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Si el origen es el descarte (12) y se pasa mas de una carta
    if ((origen==12) && (cartas>1)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: Si el origen es el descarte (12) solo se puede pasar una carta y usted ha solicitado pasar %d cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: Si el origen es el descarte (12) solo se puede pasar una carta y usted ha solicitado pasar %d cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Si el destino es el descarte (12) y el origen no es el mazo (0)
    if ((destino==12) && (origen!=0)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: Si el destino es el descarte (12) solo se pueden pasar cartas del mazo.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: Si el destino es el descarte (12) solo se pueden pasar cartas del mazo.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Si el origen es el mazo (0) y el destino no es el descarte (12)
    if ((destino!=12) && (origen==0)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: Si el origen es el mazo (0), el destino solo puede ser el descarte (12).%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: Si el origen es el mazo (0), el destino solo puede ser el descarte (12).%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    /*Si el destino es el descarte (12), el origen el mazo (0) y se pasa mas de una carta*/
    if(((destino==12) && (origen==0)) && (cartas>1)){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: Si el destino es el descarte (12) y el origen el mazo (0) solo se puede pasar una carta y usted ha solicitado pasar %d cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: Si el destino es el descarte (12) y el origen el mazo (0) solo se puede pasar una carta y usted ha solicitado pasar %d cartas.%c[%dm", 27, 1, 34, cartas, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }

    //Comprobar si se han quitado todas las cartas del mazo (0) y descarte (12)
    if ((((descarte[21].num)==20)) && (origen==0) && (destino==12)){
      gotoxy(11,7); printf("vacia");
      gotoxy(0,5); printf("vacia");
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: El descarte (12) y el mazo (0) estas vacios por lo que no se puede pasar ningua carta.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: El descarte (12) y el mazo (0) estas vacios por lo que no se puede pasar ningua carta.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
    }


    switch(origen){
      
      //SI EL ORIGEN ES EL MAZO
      
    case 0:
      
      k=imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);

      //Imprimir la carta en el descarte si viene del mazo
      descarte[0].num=((descarte[0].num)+1);
      i=descarte[0].num;

      /*Comprueba si la carta que viene a continuacion ya la hemos usado antes y si es asi pasa a imprimir la siguiente*/
      while (descarte[i].num==NUM_SIGUIENTE){
	descarte[0].num=((descarte[0].num)+1);
	i=descarte[0].num;
      }
      
      if(descarte[i].palo=='C'){
	gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, descarte[i].num, descarte[i].palo, 27, 0);
      }
      if(descarte[i].palo=='O'){
	gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, descarte[i].num, descarte[i].palo, 27, 0);
      }
      if(descarte[i].palo=='B'){
	gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, descarte[i].num, descarte[i].palo, 27, 0);
      }
      if(descarte[i].palo=='E'){
	gotoxy(11,7); printf("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, descarte[i].num, descarte[i].palo, 27, 0);
      }
      
      //Comprobar si la pila esta llena
      if((descarte[0].num)==20){
	gotoxy(0,5); printf("vacia");
      }
      else{
	gotoxy(0,5); printf("???  ");
      }
      
      //Comprobar el contador
      if(((descarte[0].num)==21) && (contVueltas==1)){
	contVueltas=2;
	gotoxy(11,5); printf("%d", contVueltas);
	descarte[0].num=0;
	gotoxy(11,7); printf ("vacia");
      }
      
      //El mazo ya ha dado tres vueltas por lo que se ha acabado el juego
      if(((descarte[0].num)==21) && (contVueltas==2)){
	contVueltas=3;
	system("clear");
	JuegoCompleto(contVueltas, salida8, salida9, salida10, salida11);
      }
      
      //Llamada a la funcion para poder introducir un nuevo movimiento
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      
      break;

      //SI EL ORIGEN ES UNA COLUMNA
    case 1:
      switch (destino){
      case 2: cambioCartasColumnas(k, cartas, columna1, columna2); break;
      case 3: cambioCartasColumnas(k, cartas, columna1, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, columna1, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, columna1, columna5); break;
      case 6: cambioCartasColumnas(k, cartas, columna1, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, columna1, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna1, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna1, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna1, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna1, salida11); break;
      default: 
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }      
      break;
      
    case 2:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna2, columna1); break;	
      case 3: cambioCartasColumnas(k, cartas, columna2, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, columna2, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, columna2, columna5); break;
      case 6: cambioCartasColumnas(k, cartas, columna2, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, columna2, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna2, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna2, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna2, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna2, salida11); break;
      default:
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	} 
	break;
      }    
      break;
      
    case 3:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna3, columna1); break;  
      case 2: cambioCartasColumnas(k, cartas, columna3, columna2); break;
      case 4: cambioCartasColumnas(k, cartas, columna3, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, columna3, columna5); break;   
      case 6: cambioCartasColumnas(k, cartas, columna3, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, columna3, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna3, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna3, salida9); break;   
      case 10: cambioCartasSalidas(k, cartas, columna3, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna3, salida11); break;
      default: 
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }
      break;
      
    case 4:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna4, columna1); break;
      case 2: cambioCartasColumnas(k, cartas, columna4, columna2); break;
      case 3: cambioCartasColumnas(k, cartas, columna4, columna3); break;
      case 5: cambioCartasColumnas(k, cartas, columna4, columna5); break;
      case 6: cambioCartasColumnas(k, cartas, columna4, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, columna4, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna4, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna4, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna4, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna4, salida11); break;
      default: 
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }
      break;
 
    case 5:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna5, columna1); break; 
      case 2: cambioCartasColumnas(k, cartas, columna5, columna2); break;
      case 3: cambioCartasColumnas(k, cartas, columna5, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, columna5, columna4); break;
      case 6: cambioCartasColumnas(k, cartas, columna5, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, columna5, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna5, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna5, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna5, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna5, salida11); break;
      default: 
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }
      break;
      
    case 6:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna6, columna1); break;
      case 2: cambioCartasColumnas(k, cartas, columna6, columna2); break;	
      case 3: cambioCartasColumnas(k, cartas, columna6, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, columna6, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, columna6, columna5); break;
      case 7: cambioCartasColumnas(k, cartas, columna6, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, columna6, salida8); break;   
      case 9: cambioCartasSalidas(k, cartas, columna6, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna6, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna6, salida11); break;    
      default: 
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }
      break;
      
    case 7:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, columna7, columna1); break;
      case 2: cambioCartasColumnas(k, cartas, columna7, columna2); break;
      case 3: cambioCartasColumnas(k, cartas, columna7, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, columna7, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, columna7, columna5); break;
      case 6: cambioCartasColumnas(k, cartas, columna7, columna6); break;
      case 8: cambioCartasSalidas(k, cartas, columna7, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, columna7, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, columna7, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, columna7, salida11); break;
      default:
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0);
	}
	break;
      }
      break;
      
      
      //SI EL ORIGEN  ES UNA SALIDA

    case 8: 
      if(k>=19){
	gotoxy (0,k+7); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy (0,26); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;
      
    case 9:
      if(k>=19){
	gotoxy (0,k+7); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy (0,26); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;
      
    case 10: 
      if(k>=19){
	gotoxy (0,k+7); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy (0,26); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;

    case 11: 
      if(k>=19){
	gotoxy (0,k+7); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      else{
	gotoxy (0,26); printf ("%c[%d;%dmERROR: La carta de origen no puede pertenecer a ninguna salida.%c[%dm", 27, 1, 34, 27, 0);
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;
      
      //SI EL ORIGEN ES EL DESCARTE
      
    case 12:
      switch (destino){
      case 1: cambioCartasColumnas(k, cartas, descarte, columna1); break;
      case 2: cambioCartasColumnas(k, cartas, descarte, columna2); break;
      case 3: cambioCartasColumnas(k, cartas, descarte, columna3); break;
      case 4: cambioCartasColumnas(k, cartas, descarte, columna4); break;
      case 5: cambioCartasColumnas(k, cartas, descarte, columna5); break;
      case 6: cambioCartasColumnas(k, cartas, descarte, columna6); break;
      case 7: cambioCartasColumnas(k, cartas, descarte, columna7); break;
      case 8: cambioCartasSalidas(k, cartas, descarte, salida8); break;
      case 9: cambioCartasSalidas(k, cartas, descarte, salida9); break;
      case 10: cambioCartasSalidas(k, cartas, descarte, salida10); break;
      case 11: cambioCartasSalidas(k, cartas, descarte, salida11); break;
      default:
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0); 
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de destino no es la correcta.%c[%dm", 27, 1, 34, 27, 0); 
	}
	break;	
      }
      break;
      
    default:
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: La entrada de la pila de origen no es la correcta.%c[%dm", 27, 1, 34, 27, 0); 
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: La entrada de la pila de origen no es la correcta.%c[%dm", 27, 1, 34, 27, 0); 
      }
      movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
      break;
    
    }

    //Imprimir las cartas
    k=imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);

    //Impimir nuevo descarte
    if(origen==12){
      imprimirDescarte(descarte);
    }

    //Hacer otro movimientos
    movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);

    return;
  }


  //Si el movimiento es de cartas hacia una columna

  void cambioCartasColumnas (int k, int cartas, carta arrayOrigen[], carta arrayDestino[]){
  
    int i, j, h;
  
    //Si se pasa una sola carta
    if (cartas==1){ 
      i=arrayOrigen[0].num;
      j=arrayDestino[0].num;
    
      if ((arrayOrigen[0].num)==VACIA){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
	}
	return;
      }

      if (((arrayDestino[0].num)==VACIA) && (arrayOrigen[i].num!=12)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: En la pila de destino no hay cartas y la carta de la pila de origen no es un Rey (12).%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: En la pila de destino no hay cartas y la carta de la pila de origen no es un Rey (12).%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    
      if (cartas>(arrayOrigen[0].num)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: Ha solicitado mover mas cartas de las que hay en la pila de origen.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: Ha solicitado mover mas cartas de las que hay en la pila de origen.%c[%dm",27,1,34,27,0);
	}
	return;
      }
    
      if ((arrayOrigen[i].palo)==(arrayDestino[j].palo)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: El palo de la pila de origen y de destino es el mismo y debe de ser diferente.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: El palo de la pila de origen y de destino es el mismo y debe de ser diferente.%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    
    
      if( ((arrayOrigen[i].num)==((arrayDestino[j].num)-1)) || (((arrayDestino[0].num)==VACIA) && (arrayOrigen[i].num==12))){
            
	j++;
	arrayDestino[j].num=arrayOrigen[i].num;
	arrayDestino[j].palo=arrayOrigen[i].palo;
	arrayDestino[j].vis=VISIBLE;
      
	i--;
	arrayOrigen[i].vis=VISIBLE;
      
	arrayOrigen[0].num=((arrayOrigen[0].num)-1);
	arrayDestino[0].num=((arrayDestino[0].num)+1);
      }
    
      else{
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destino debe ser una unidad mas que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destino debe ser una unidad mas que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    }
  
    //Si se pasa mas de una carta
    else{
      h=(arrayOrigen[0].num)-cartas;
      i=(arrayOrigen[0].num)-cartas+1;
      j=arrayDestino[0].num;
    
      if ((arrayOrigen[0].num)==VACIA){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
	}     
	return;
      }
    
      if (cartas>(arrayOrigen[0].num)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: Ha solicitado mover mas cartas de las que hay en la pila de origen.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: Ha solicitado mover mas cartas de las que hay en la pila de origen.%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    
      if (((arrayDestino[0].num)==VACIA) && (arrayOrigen[i].num!=12)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: En la pila de destino no hay cartas y la carta de la pila de origen no es un Rey (12).%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: En la pila de destino no hay cartas y la carta de la pila de origen no es un Rey (12).%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    
      if ((arrayOrigen[i].palo)==(arrayDestino[j].palo)){
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: El palo de la pila de origen y de destino es el mismo y debe de ser diferente.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: El palo de la pila de origen y de destino es el mismo y debe de ser diferente.%c[%dm",27,1,34,27,0);
	}      
	return;
      }
    
      if (((arrayOrigen[i].num)==((arrayDestino[j].num)-1)) || (((arrayDestino[0].num)==VACIA) && (arrayOrigen[i].num==12))){   

	do{
	
	  j++;
	  arrayDestino[j].num=arrayOrigen[i].num;
	  arrayDestino[j].palo=arrayOrigen[i].palo;
	  arrayDestino[j].vis=VISIBLE;
	  i++;      
	
	  arrayOrigen[0].num=((arrayOrigen[0].num)-1);
	  arrayDestino[0].num=((arrayDestino[0].num)+1);
	  cartas--;
	
	}while (cartas>0);
      
	arrayOrigen[h].vis=VISIBLE;
	arrayOrigen[0].num=h;   
      
      }
      else{
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destino debe ser una unidad mas que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destino debe ser una unidad mas que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}     
	return;
      }
    
    }
  
    return;
  }


  //Si el movimiento es de cartas hacia una salida

  void cambioCartasSalidas (int k, int cartas, carta arrayOrigen[], carta arrayDestino[]){
  
    int i;
  
    if ((arrayOrigen[0].num)==VACIA){
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: En la pila de origen no hay cartas.%c[%dm",27,1,34,27,0);
      }    
      return;
    }
  
    i=(arrayOrigen[0].num);
  
    //Si la salida esta vacia
    if ((arrayDestino[0].num)==VACIA){
      if ((arrayOrigen[i].num)==1){
      
	arrayDestino[1].num=arrayOrigen[i].num;
	arrayDestino[1].palo=arrayOrigen[i].palo;
      
	i--;
	arrayOrigen[i].vis=VISIBLE;
      
	arrayOrigen[0].num=((arrayOrigen[0].num)-1);
	arrayDestino[0].num=((arrayDestino[0].num)+1);
      }
      else{
	if(k>=19){
	  gotoxy (0,k+7); printf("%c[%d;%dmERROR: Como la salida esta vacia, la carta de la pila de origen solo puede ser un AS (1).%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy (0,26); printf("%c[%d;%dmERROR: Como la salida esta vacia, la carta de la pila de origen solo puede ser un AS (1).%c[%dm",27,1,34,27,0);
	}
      }
      return;
    }
  
    //Si en la salida ya hay una carta
    if ((arrayOrigen[i].palo)==(arrayDestino[1].palo)){
      if ((arrayOrigen[i].num)==(arrayDestino[1].num)+1){

	arrayDestino[1].num=arrayOrigen[i].num;
	arrayDestino[1].palo=arrayOrigen[i].palo;
      
	i--;
	arrayOrigen[i].vis=VISIBLE;
      
	arrayOrigen[0].num=((arrayOrigen[0].num)-1);
      }
      else{
	if(k>=19){
	  gotoxy(0,k+7); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destinosalida debe ser una unidad menos que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}
	else{
	  gotoxy(0,26); printf("%c[%d;%dmERROR: El numero de la carta de la pila de destinosalida debe ser una unidad menos que el numero de la carta de la pila de origen.%c[%dm",27,1,34,27,0);
	}
	return;
      }
    }
    else{
      if(k>=19){
	gotoxy(0,k+7); printf("%c[%d;%dmERROR: El palo de la pila de origen y de salida es diferente y debe ser el mismo.%c[%dm",27,1,34,27,0);
      }
      else{
	gotoxy(0,26); printf("%c[%d;%dmERROR: El palo de la pila de origen y de salida es diferente y debe ser el mismo.%c[%dm",27,1,34,27,0);
      }
    }
  
    return;
  }


  //Funcion cuando se completan las salidas o cuando el contador llega a 3

  void JuegoCompleto (int contVueltas, carta salida8[], carta salida9[], carta salida10[], carta salida11[]){
  
    char linea[10];
  
    //TABLERO
    system("clear");
    gotoxy(0,0); printf("**************************** JUEGO DEL SOLITARIO *******************************");
    gotoxy(0,3);  printf("MAZO\t");
    gotoxy(10,3);  printf("CONT\t"); 
    gotoxy(30,3); printf("Salida8\t"); 
    gotoxy(40,3);  printf("Salida9\t"); 
    gotoxy(50,3);  printf("Salida10\t"); 
    gotoxy(60,3);  printf("Salida11\t"); 
    gotoxy(0,7);  printf("DESCARTE:\t");
    gotoxy(0,10);  printf("Columna1\t"); 
    gotoxy(10,10); printf("Columna2\t");
    gotoxy(20,10);  printf("Columna3\t"); 
    gotoxy(30,10); printf("Columna4\t");
    gotoxy(40,10);  printf("Columna5\t"); 
    gotoxy(50,10);  printf("Columna6\t"); 
    gotoxy(60,10);  printf("Columna7\t"); 
    gotoxy(0,5);  printf("???\t");
    gotoxy(11,5); printf("%d\t",contVueltas);
    gotoxy(11,7); printf("vacia\t");
    gotoxy(2,12); printf("vacia\t");
    gotoxy(12,12); printf("vacia\t");
    gotoxy(22,12); printf("vacia\t");
    gotoxy(32,12); printf("vacia\t");
    gotoxy(42,12); printf("vacia\t");
    gotoxy(52,12); printf("vacia\t");
    gotoxy(62,12); printf("vacia\t");
  
    //Si el contador es 1
    if (contVueltas==1){
      //salida 8
      if(salida8[1].palo=='C'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='O'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='B'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='E'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida8[1].num, salida8[1].palo, 27, 0);
      }  
      //salida 9
      if(salida9[1].palo=='C'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='O'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='B'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='E'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida9[1].num, salida9[1].palo, 27, 0);
      }
      //salida 10
      if(salida10[1].palo=='C'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='O'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='B'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='E'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida10[1].num, salida10[1].palo, 27, 0);
      }
      //salida 11
      if(salida11[1].palo=='C'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='O'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='B'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='E'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida11[1].num, salida11[1].palo, 27, 0);
      }
      gotoxy(0,21); printf("%c[%d;%dmt\tAVISO: JUEGO CARTAS SOLITARIO COMPLETADO\n\n\t\tPUNTUACION: 100 puntos, maxima puntuacion.%c[%dm", 27, 1, 35, 27, 0);
    }
  
    //Si el contador es 2
    if (contVueltas==2){
      //salida 8
      if(salida8[1].palo=='C'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='O'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='B'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida8[1].num, salida8[1].palo, 27, 0);
      }
      if(salida8[1].palo=='E'){
	gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida8[1].num, salida8[1].palo, 27, 0);
      }  
      //salida 9
      if(salida9[1].palo=='C'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='O'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='B'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida9[1].num, salida9[1].palo, 27, 0);
      }
      if(salida9[1].palo=='E'){
	gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida9[1].num, salida9[1].palo, 27, 0);
      }
      //salida 10
      if(salida10[1].palo=='C'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='O'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='B'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida10[1].num, salida10[1].palo, 27, 0);
      }
      if(salida10[1].palo=='E'){
	gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida10[1].num, salida10[1].palo, 27, 0);
      }
      //salida 11
      if(salida11[1].palo=='C'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='O'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='B'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida11[1].num, salida11[1].palo, 27, 0);
      }
      if(salida11[1].palo=='E'){
	gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida11[1].num, salida11[1].palo, 27, 0);
      }
      gotoxy(0,21); printf("%c[%d;%dm\t\tAVISO: JUEGO CARTAS SOLITARIO COMPLETADO\n\n\t\tPUNTUACION: 50 puntos sobre 100.%c[%dm", 27, 1, 35, 27, 0);
    }
  
    //Si el contador es 3
    if (contVueltas==3){
      system ("clear");
      //Imprimir las salidas
      if(salida8[0].num==VACIA){
	gotoxy(31,5); printf("vacia");
      }
      else{
	if(salida8[1].palo=='C'){
	  gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida8[1].num, salida8[1].palo, 27, 0);
	}
	if(salida8[1].palo=='O'){
	  gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida8[1].num, salida8[1].palo, 27, 0);
	}
	if(salida8[1].palo=='B'){
	  gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida8[1].num, salida8[1].palo, 27, 0);
	}
	if(salida8[1].palo=='E'){
	  gotoxy(31,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida8[1].num, salida8[1].palo, 27, 0);
	}  
      }
      if(salida9[0].num==VACIA){
	gotoxy(41,5); printf("vacia");
      }
      else{
	if(salida9[1].palo=='C'){
	  gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida9[1].num, salida9[1].palo, 27, 0);
	}
	if(salida9[1].palo=='O'){
	  gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida9[1].num, salida9[1].palo, 27, 0);
	}
	if(salida9[1].palo=='B'){
	  gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida9[1].num, salida9[1].palo, 27, 0);
	}
	if(salida9[1].palo=='E'){
	  gotoxy(41,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida9[1].num, salida9[1].palo, 27, 0);
	}
      }
      if(salida10[0].num==VACIA){
	gotoxy(51,5); printf("vacia");
      }
      else{
	if(salida10[1].palo=='C'){
	  gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida10[1].num, salida10[1].palo, 27, 0);
	}
	if(salida10[1].palo=='O'){
	  gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida10[1].num, salida10[1].palo, 27, 0);
	}
	if(salida10[1].palo=='B'){
	  gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida10[1].num, salida10[1].palo, 27, 0);
	}
	if(salida10[1].palo=='E'){
	  gotoxy(51,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida10[1].num, salida10[1].palo, 27, 0);
	}
      }
      if(salida11[0].num==VACIA){
	gotoxy(61,5); printf("vacia");
      }
      else{
	if(salida11[1].palo=='C'){
	  gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 31, salida11[1].num, salida11[1].palo, 27, 0);
	}
	if(salida11[1].palo=='O'){
	  gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 33, salida11[1].num, salida11[1].palo, 27, 0);
	}
	if(salida11[1].palo=='B'){
	  gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 32, salida11[1].num, salida11[1].palo, 27, 0);
	}
	if(salida11[1].palo=='E'){
	  gotoxy(61,5); printf ("%c[%d;%dm%d %c  %c[%dm", 27, 1, 36, salida11[1].num, salida11[1].palo, 27, 0);
	}
      }
      gotoxy(0,21); printf("%c[%d;%dm\t\tAVISO: JUEGO CARTAS SOLITARIO SIN COMPLETAR.%c[%dm", 27, 1, 35, 27, 0);
    }
  
    do{
      //Para volver al menu principal tras terminar el juego
      gotoxy(114, 25); printf("                                              ");
      gotoxy(0,25); printf("Pulse m o M para volver a la pantalla inicial o introduzca la palabra 'creditos' para ver los creditos del juego: ");
      fgets(linea,10,stdin);
      
      //Comprobar si se ha introducido la palabra 'creditos'
      if ((linea[0]=='c') && (linea[1]=='r') && (linea[2]=='e') && (linea[3]=='d') && (linea[4]=='i') && (linea[5]=='t') && (linea[6]=='o') && (linea[7]=='s') && (linea[8]=='\n')){
	gotoxy(0,28); printf("Este solitario ha sido creado por:\n\tCristina Gonzalez Escudeiro\n\tAlismar Hernandez Muiños\n\tSara Berezo Loza");
      }
      else{  
	//Comprobar si se ha pulsado algun caracter que no es m o M
	if((tolower(linea[0]=='m')) && (linea[1]=='\n')){
	  main();
	}
	else{
	  gotoxy(0,27); printf("%c[%d;%dmERROR: No ha pulsado 'm' o 'M' o la palabra 'creditos'.%c[%dm",27,1,34,27,0);
	}
      }
    }while((tolower(linea[0]!='m')) && (linea[1]!='\n'));

  }


  
//Funcion por la que solo se puede introducir m o M o se puede volver

void Solo_m_o_M (int k, int contVueltas, carta descarte[], carta columna1[], carta columna2[], carta columna3[], carta columna4[], carta columna5[], carta columna6[], carta columna7[], carta salida8[], carta salida9[], carta salida10[], carta salida11[]){

  char variable;
  
  do{
    if(k>=19){
      gotoxy (142,k+6); printf ("                                            ");
      gotoxy (0,k+6); printf("%c[%d;%dmHa introducido una letra o un conjunto de ellas incorrecto. Pulse m o M para ir al menu o pulse v o V para volver a introducir un movimiento:%c[%dm ", 27,1,35,27,0);
    }
    else{
      gotoxy (142,25); printf ("                                             ");
      gotoxy (0,25); printf("%c[%d;%dmHa introducido una letra o un conjunto de ellas incorrecto. Pulse m o M para ir al menu o pulse v o V para volver a introducir un movimiento:%c[%dm ", 27,1,35,27,0);
    }
    scanf ("%c", &variable);
  }while ((tolower(variable)!='m') && (tolower(variable)!='v'));
  gotoxy (0,27); printf("                                                                                                                                                                          ");
  if (tolower(variable)=='m'){
    eleccion(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
  }
  if (tolower(variable)=='v'){
    k=imprimir(contVueltas,columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11, descarte);
    movimiento(k, contVueltas, descarte, columna1, columna2, columna3, columna4, columna5, columna6, columna7, salida8, salida9, salida10, salida11);
  }

}

  void guardarJuego (int contVueltas, carta descarte[],carta columna1[],carta columna2[],carta columna3[],carta columna4[],carta columna5[],carta columna6[],carta columna7[],carta salida8[],carta salida9[],carta salida10[],carta salida11[]){
  
    FILE *fp;
    int i;
  
    if((fp=fopen("juego_guardado.txt","w"))==NULL){
      gotoxy(0,34); printf("%c[%d;%dmERROR: NO EXISTE O NO SE PUEDE ABRIR EL FICHERO juego_guardado.txt%c[%dm",27,1,34,27,0);
    }
    else{
      //Guarda el contador
      fprintf(fp,"%d",contVueltas);
    
      //Guarda las salidas
      fprintf(fp," %d",salida8[0].num);
      for(i=1;i<=salida8[0].num;i++)
	fprintf(fp," %d %c",salida8[i].num,salida8[i].palo);
      
      fprintf(fp," %d",salida9[0].num);
      for(i=1;i<=salida9[0].num;i++)
	fprintf(fp," %d %c",salida9[i].num,salida9[i].palo);
      
      fprintf(fp," %d",salida10[0].num);
      for(i=1;i<=salida10[0].num;i++)
	fprintf(fp," %d %c",salida10[i].num,salida10[i].palo);
      
      fprintf(fp," %d",salida11[0].num);
      for(i=1;i<=salida11[0].num;i++)
	fprintf(fp," %d %c",salida11[i].num,salida11[i].palo);
     
     
      //Guarda el descarte
      fprintf(fp," %d",descarte[0].num); fprintf(fp," %d",descarte[21].num);
      for (i=1; i<=20; i++)
	fprintf(fp," %d %c",descarte[i].num,descarte[i].palo);
       
      //Guarda las columnas y delante de ellas el numero de cartas que hay
      fprintf(fp," %d",columna1[0].num);
      for(i=1; i<=columna1[0].num; i++)
	fprintf(fp," %d %c %d",columna1[i].num,columna1[i].palo,columna1[i].vis);
 
      fprintf(fp," %d",columna2[0].num);
      for(i=1; i<=columna2[0].num; i++)
	fprintf(fp," %d %c %d",columna2[i].num,columna2[i].palo,columna2[i].vis);
   
      fprintf(fp," %d",columna3[0].num);
      for(i=1; i<=columna3[0].num; i++)
	fprintf(fp," %d %c %d",columna3[i].num,columna3[i].palo,columna3[i].vis);
    	
      fprintf(fp," %d",columna4[0].num);
      for(i=1; i<=columna4[0].num; i++)
	fprintf(fp," %d %c %d",columna4[i].num,columna4[i].palo,columna4[i].vis);
  	
      fprintf(fp," %d",columna5[0].num);
      for(i=1; i<=columna5[0].num; i++)
	fprintf(fp," %d %c %d",columna5[i].num,columna5[i].palo,columna5[i].vis);
  
      fprintf(fp," %d",columna6[0].num);
      for(i=1; i<=columna6[0].num; i++)
	fprintf(fp," %d %c %d",columna6[i].num,columna6[i].palo,columna6[i].vis);
   	
      fprintf(fp," %d",columna7[0].num);
      for(i=1; i<=columna7[0].num; i++)
	fprintf(fp," %d %c %d",columna7[i].num,columna7[i].palo,columna7[i].vis);
      
      printf("%c[%d;%dmAVISO: Juego guardado%c[%dm",27,1,35,27,0); 

      fclose (fp);
      
    }
    
    return;
  }


void cargarJuego (int *contVueltas, carta descarte[],carta columna1[],carta columna2[],carta columna3[],carta columna4[],carta columna5[],carta columna6[],carta columna7[],carta salida8[],carta salida9[],carta salida10[],carta salida11[]){
  
    FILE *fp;
    int i;
  
    if((fp=fopen("juego_guardado.txt","r"))==NULL){
      gotoxy(0,34); printf("%c[%d;%dmERROR: NO EXISTE O NO SE PUEDE ABRIR EL FICHERO juego_guardado.txt%c[%dm",27,1,34,27,0);
    }
    else{
    
      fscanf(fp,"%d",contVueltas);
         
      //Guarda las salidas
      fscanf(fp," %d",&salida8[0].num);
      if (salida8[0].num==1){
	fscanf(fp," %d",&salida8[1].num);
	fscanf(fp," %c",&salida8[1].palo);
  
      }

      fscanf(fp," %d",&salida9[0].num);
      if (salida9[0].num==1){
	fscanf(fp," %d",&salida9[1].num); 
	fscanf(fp," %c",&salida9[1].palo);
      }

      fscanf(fp," %d",&salida10[0].num);
      if (salida10[0].num==1){
	fscanf(fp," %d",&salida10[1].num);
	fscanf(fp," %c",&salida10[1].palo);
      }
    
      fscanf(fp," %d",&salida11[0].num);
      if (salida11[0].num==1){
	fscanf(fp," %d",&salida11[1].num);
	fscanf(fp," %c",&salida11[1].palo);
      }
    
      //Guarda el descarte
      fscanf(fp," %d",&descarte[0].num); fscanf(fp," %d",&descarte[21].num);
      for (i=1; i<=20; i++){
	fscanf(fp," %d %c",&descarte[i].num,&descarte[i].palo);
      }
    
      //Guarda las columnas y delante de ellas el numero de cartas que hay
      fscanf(fp," %d",&columna1[0].num);
      for(i=1; i<=columna1[0].num; i++){
	fscanf(fp," %d %c %d",&columna1[i].num,&columna1[i].palo,&columna1[i].vis);
      }
      fscanf(fp," %d",&columna2[0].num);
      for(i=1; i<=columna2[0].num; i++){
	fscanf(fp," %d %c %d",&columna2[i].num,&columna2[i].palo,&columna2[i].vis);
      }
      fscanf(fp," %d",&columna3[0].num);
      for(i=1; i<=columna3[0].num; i++){
	fscanf(fp," %d %c %d",&columna3[i].num,&columna3[i].palo,&columna3[i].vis);
      }
      fscanf(fp," %d",&columna4[0].num);
      for(i=1; i<=columna4[0].num; i++){
	fscanf(fp," %d %c %d",&columna4[i].num,&columna4[i].palo,&columna4[i].vis);
      }
      fscanf(fp," %d",&columna5[0].num);
      for(i=1; i<=columna5[0].num; i++){
	fscanf(fp," %d %c %d",&columna5[i].num,&columna5[i].palo,&columna5[i].vis);
      }
      fscanf(fp," %d",&columna6[0].num);
      for(i=1; i<=columna6[0].num; i++){
	fscanf(fp," %d %c %d",&columna6[i].num,&columna6[i].palo,&columna6[i].vis);
      }
      fscanf(fp," %d",&columna7[0].num);
      for(i=1; i<=columna7[0].num; i++){
	fscanf(fp," %d %c %d",&columna7[i].num,&columna7[i].palo,&columna7[i].vis);
      }
      
      fclose (fp);
      
    }
    
    return;
  }


//Funcion que imprime las reglas del juego

int Reglas (char mov[10], carta columna1[], carta columna2[], carta columna3[], carta columna4[], carta columna5[], carta columna6[], carta columna7[], carta salida8[], carta salida9[], carta salida10[], carta salida11[], carta descarte[]){

  char enter;

  if ((mov[0]=='r') && (mov[1]=='e') && (mov[2]=='g') && (mov[3]=='l') && (mov[4]=='a') && (mov[5]=='s') && (mov[6]=='\n')){
    do{
      system ("clear");
      printf("Las reglas del juegos del Solitario son las siguientes:\n\nLos movimientos constan de tres datos numericos: el primero corresponde con la pila de origen, el segundo con la pila de destino y el tercero con el numero de cartas que se desea pasar(si se obvia el tercero se asumira que es una carta).\nLas pilas estan numeradas tal que: 0=mazo, 1=columna1, 2=columna2, 3=columna3, 4=columna4, 5=columna5, 6=columna6, 7=columna7, 8=salida8, 9=salida9, 10=salida10, 11=salida11 y 12=descarte.\nCuando una salida este vacia solo pueden moverse ases (unos) a esa pila. Sin embargo, cuando una columna este vacia solo podran moverse reyes (doces) a esa pila.\nPara mover las cartas entre las columna o del descarte a una columna, la carta de origen y de destino deben de ser de palos diferente y el numero de la carta de origen debe ser una unidad menos que la de destino.\nDe la pila mazo solo se pueden pasar cartas a la pila descarte  y las cartas de la pila descarte solo pueden ser obtenidas del mazo.\nDe la pila descarte se podran sacar cartas hacia cualquier columna o salida (siempre y cuando cumpla las normas citadas anteriormente) y al quitar una carta se mostrara la anterior carta que habiamos pasado.\nPUNTUACION:\nExiste un contador que se incrementa cada vez que el mazo se acaba y se le da la vuelta. Las puntuaciones finales del juego iran en funcion del contador de forma que: si toda la baraja esta posicionada en las salidas (tal que solo se muestren los reyes) y el contador esta en 1, su puntuacion sera de 100 puntos y sera la maxima puntuacion. Igualmente, si toda la baraja ha sido transportada desde las columnas y el descarte a las salidas, y el contador esta en 2, su puntuacion sera de 50 puntos. Si usted no ha acabado el juego y el contador llega a 3 habra perdido.\nEn los tres casos anteriores el juego termina y tiene la opcion de ver los creditos y de regresar al menu.\n\n");

      printf("Pulse enter para volver...");
      scanf("%c", &enter);
      
    }while(enter!='\n');
   
    return 1;
  }

  return 2;
}
