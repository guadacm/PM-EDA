#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#define DIM 170
typedef struct Articulo
{
	char codigo[8];
	char articulo[52];
	char marca[62];
	float valor;
	int cantidad;
	char club[72];
} Articulo;

/* PROTOTIPOS */
void encabezado();
void borrar_salto(Articulo *art);

// -- LSD
int localizar_LSD(char codigo[], int *i);
Articulo evocar_LSD (char codigo[],int *exito);

// -- LSO
int alta_LSO(Articulo nuevo, int entrada);
int baja_LSO(char codArt[], int entrada);
Articulo consultar_LSO(char codArt[8]);

// -- LVO
/* FIN PROTOTIPOS */


/* VARIABLES */
// -- LSD
Articulo LSD[DIM];
int cant_LSD = 0;

// -- LSO
Articulo LSO[DIM];
int cant_LSO;

// -- LVO
/* FIN VARIABLES */

void imprimirArt(Articulo Art){
        printf("\n Codigo: \t%s",Art.codigo);
        printf("\n Articulo: \t%s",Art.articulo);
        printf("\n Marca: \t%s",Art.marca);
        printf("\n Valor: \t$%.2f",Art.valor);
        printf("\n Cantidad: \t%i",Art.cantidad);
        printf("\n Club: \t\t%s",Art.club);
        printf("\n");
}

void mostrar_LS (Articulo LS[], int cant)             // Muestra la lista de articulos para LSD � LSO
{
    int i;
    if(cant == 0)
    {
        printf("\n\tLa lista esta vacia\n");
        return;
    }
    else
    {
        printf("\n\t----------LISTA DE ARTICULOS----------\n");
        for(i = 0; i < cant; i++)
        {
            imprimirArt(LS[i]);
        }
        printf("\n\tTotal de articulos: %d \n\n",cant);
    }

}

void memorizacion_previa(int lista) // lista: 1.LSD - 2.LSO - 3.LVO
{
    Articulo nuevo;
    FILE *fp;

    if ((fp = fopen("PruebaArticulos.txt", "r")) == NULL)
        printf("\n\nERROR: no se pudo abrir el archivo\n\n");
    else
    {
        while(!(feof(fp)))
        {
            fgets(nuevo.codigo, 8, fp);
            strupr(nuevo.codigo);
            fgets(nuevo.articulo, 52, fp);
            fgets(nuevo.marca, 62, fp);
            fscanf(fp, "%f\n", &nuevo.valor);
            fscanf(fp, "%i\n", &nuevo.cantidad);
            fgets(nuevo.club, 72, fp);
            borrar_salto(&nuevo);

            switch(lista)
            {
                case 1:
                    alta_LSD(nuevo, 1);
                    break;
                case 2:
                    alta_LSO(nuevo, 1);
                    break;
                case 3:
                    break;

            }
        }
        printf("\n\nLa memorizacion se ha llevado a cabo\n\n");
    }
    fclose(fp);
}

 char confirmacion_baja_LS(Articulo baja)
{
    char c;
    //printf("\n Codigo: \t%s",LS[i].codigo);
    printf("\n Articulo: \t%s", baja.articulo);
    printf("\n Marca: \t%s", baja.marca);
    printf("\n Valor: \t$%.2f", baja.valor);
    printf("\n Cantidad: \t%i", baja.cantidad);
    printf("\n Club: \t\t%s", baja.club);

    printf("\n\nEsta seguro que quiere eliminar este articulo? S/N: ");
    fflush(stdin);
    scanf("%c", &c);
    //strupr(&c);
    return c;
}

void borrar_salto(Articulo *art) {//Borra en '\n' que almacena fgets.
    int i = 0;
    for (i = 0; i < 8; i++) { //Codigo
        if ((*art).codigo[i] == '\n') {
            (*art).codigo[i] = '\0';
        }
    }
    for (i = 0; i < 52; i++) { //Articulo
        if ((*art).articulo[i] == '\n') {
            (*art).articulo[i] = '\0';
        }
    }
    for (i = 0; i < 62; i++) { //Marca
        if ((*art).marca[i] == '\n') {
            (*art).marca[i] = '\0';
        }
    }
    for (i = 0; i < 72; i++) { //Club
        if ((*art).club[i] == '\n') {
            (*art).club[i] = '\0';
        }
    }
}
#endif // LISTAS_H_INCLUDED
