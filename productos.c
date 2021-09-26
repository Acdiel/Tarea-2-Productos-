#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Map.h"
#include"productos.h"


/*
  funciÃ³n para comparar claves de tipo string
  retorna 1 si son iguales
*/
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo string
  retorna 1 si son key1<key2
*/
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo int
  retorna 1 si son iguales
*/
int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo int
  retorna 1 si son key1<key2
*/
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}



Producto* crearProducto(char* nombre, char *marca, char * tipo, int stock, int precio) {
  Producto* p = (Producto*) malloc (sizeof(Producto));
	strcpy(p->nombre, nombre);
  strcpy(p->marca, marca);
  strcpy(p->tipo, tipo);
  p->stock = stock;
	p->precio = precio;
  return p;
}

void importarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  FILE * lista = fopen("productos.csv","r");
  char linea[300];
  char *token;

  
  while(fgets(linea,sizeof(linea), lista)!=NULL){

          Producto *vector = malloc(sizeof(Producto));
           
          token=strtok(linea,",");
          strcpy(vector->nombre,token);

      
          insertMap(producto_nombre,vector->nombre,vector);
          
////////////////////////////////////////////////

          token=strtok(NULL,",");
          strcpy(vector->marca,token);

          insertMap(producto_marca,vector->marca,vector);

////////////////////////////////////////////////////////////
          token=strtok(NULL,",");
          strcpy(vector->tipo,token);

          insertMap(producto_tipo, vector->tipo, vector);
          
         
//////////////////////////////////////////////////////////////
          token=strtok(NULL,",");
          vector->stock=atoi((const char*)token);

          insertMap(producto_stock, &vector->stock, vector);
              
//////////////////////////////////////////////////////////////
          token=strtok(NULL,"\n");
          vector->precio=atoi((const char*)token);

          insertMap(producto_precio, &vector->precio, vector);

        }

}

void exportarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  char stock1[20];
  char precio1[20];
  FILE *filePointer;

  b = firstMap(producto_nombre);
  int llave_exportar=0;
  
  sprintf(stock1, "%d", b->stock);
  sprintf(precio1, "%d", b->precio);
     
  while(b != NULL){
      
    char archivo[100000];    
 
    strcat(archivo,b->nombre);
    strcat(archivo,",");
    strcat(archivo,b->marca); //asi!
    strcat(archivo,",");
    strcat(archivo,b->tipo);
    strcat(archivo,",");
    strcat(archivo,stock1); // funcion itoa para pasar a string
    strcat(archivo,",");  
    strcat(archivo,precio1);
    strcat(archivo,"\n");
    
    filePointer = fopen("productos2.csv", "w+b") ;

    if ( filePointer == NULL )
    {
        printf( "El archivo productos2.csv no se pudo abrir." ) ;
    }
    else
    {
      if(llave_exportar==0)
      {
        printf("El archivo esta abierto.\n") ;
        llave_exportar=1;
      }
      if ( strlen ( archivo ) > 0 ){     
        fprintf(filePointer,"%s",archivo);
        b=nextMap(producto_nombre); 
      }
            
    }

  } 
    
    fclose(filePointer) ;

}

void agregarProducto(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  b = malloc(sizeof(Producto));

      printf("Nombre:\n");
      scanf(" %[^\n]", b->nombre);

      printf("Marca:\n");
      scanf(" %[^\n]", b->marca);

      printf("Tipo:\n");
      scanf(" %[^\n]", b->tipo);

      printf("Stock\n");
      scanf("%d", &b->stock);

      printf("Precio\n");
      scanf("%d", &b->precio);

      insertMap(producto_nombre, b->nombre, b);
      insertMap(producto_marca, b->marca, b);
      insertMap(producto_tipo, b->tipo, b);
      insertMap(producto_stock, &b->stock, b);
      insertMap(producto_precio, &b->precio, b);

}

void buscarProductoTipo(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  char busca_tipo[10];

  scanf("%s",busca_tipo);

      b = firstMap(producto_nombre);

      printf("---------------\n"); 

      while (b!=NULL){

        if (strcmp(busca_tipo,b->tipo)==0){

        printf("Nombre: %s\n",b->nombre);
        printf("Marca:  %s\n",b->marca);
        printf("Stock:  %d\n",b->stock);
        printf("Precio: %d\n",b->precio);
         printf("---------------\n"); 
        
        }
        b=nextMap(producto_nombre);
      }

}

void buscarProductoMarca(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  char busca_Marca[10];

  scanf("%s",busca_Marca);

      b = firstMap(producto_nombre);

      printf("---------------\n"); 

      while (b!=NULL){

        if (strcmp(busca_Marca,b->marca)==0){

        printf("Nombre: %s\n",b->nombre);
        printf("Tipo:   %s\n",b->tipo);
        printf("Stock:  %d\n",b->stock);
        printf("Precio: %d\n",b->precio);
        printf("---------------\n"); 
        
        }
        b=nextMap(producto_nombre);
      }
}

void buscarProductoNombre(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  char busca_Nombre[10];

 scanf(" %[^\n]",busca_Nombre);

      b = firstMap(producto_nombre);

      printf("---------------\n"); 

      while (b!=NULL){

        if (strcmp(busca_Nombre,b->nombre)==0){

        printf("Marca:  %s\n",b->marca);
        printf("Tipo:   %s\n",b->tipo);
        printf("Stock:  %d\n",b->stock);
        printf("Precio: %d\n",b->precio);
        printf("---------------\n"); 
        break;
        }
        b=nextMap(producto_nombre);
      }
}

void mostrarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

  Producto *b=NULL;

  b = firstMap(producto_nombre); 

      while (b!=NULL){

        printf("Nombre: %s\n",b->nombre);
        printf("Marca: %s\n",b->marca);
        printf("Tipo: %s\n",b->tipo);
        printf("Stock: %d\n",b->stock);
        printf("Precio: %d\n",b->precio);
        printf("---------------\n"); 

        b=nextMap(producto_nombre);
      }
      
}

/*void agregarCarrito(Map * producto_nombre, int cantidad, Map * carrito){

  Carrito * c = (Carrito*) malloc (sizeof(Carrito));

  printf("-----------------\n");
  printf("| 🛒 Carrito 🛒 |\n");
  printf("-----------------\n");
  printf("|               |\n");
    c = firstMap(producto_nombre);
    while (c) {
        printf("| %s (%d) |\n", c->nombre, c->cantidad);
        printf("-----------------\n");
        c = nextMap(producto_nombre);
    }
  
}*/