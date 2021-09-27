#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "productos.h"

int main(){

// MAPA CON CLAVE CARRITO //
Map* carrito = createMap(is_equal_string);
setSortFunction(carrito, lower_than_string);

 // MAPA CON CLAVE NOMBRE //
Map* producto_nombre = createMap(is_equal_string);
setSortFunction(producto_nombre, lower_than_string);

// MAPA CON CLAVE MARCA //
Map* producto_marca = createMap(is_equal_string);
setSortFunction(producto_marca, lower_than_string);

// MAPA CON CLAVE TIPO //
Map* producto_tipo = createMap(is_equal_string);
setSortFunction(producto_tipo, lower_than_string);

// MAPA INT CON CLAVE STOCK //
Map * producto_stock = createMap(is_equal_int);

// MAPA INT CON CLAVE STOCK //
Map * producto_precio = createMap(is_equal_int);
    
      

//p = crearProducto("Coca Cola 1 lt", "coca-cola", "bebida", 200, 1000);
      
  //    insertMap(producto_nombre, p->nombre, p);
    //  insertMap(producto_marca, p->marca, p);
      //insertMap(producto_tipo, p->tipo, p);
      //insertMap(producto_stock, &p->stock, p);
      //insertMap(producto_precio, &p->precio, p);


//--------------------------------------------------------
 


//------------------------------------------------------
      
int op=10;

    while (op!=0) 
    {   
    printf("\n");
    printf("--------------------------------------------\n");  
		printf("|        ✔  Bienvenido al Menú ✔           |\n");
    printf("--------------------------------------------\n");
		printf("| 1. Importar Productos                    |\n");
		printf("| 2. Exportar Productos                    |\n");
		printf("| 3. Agregar Producto                      |\n");
		printf("| 4. Buscar Productos por Tipo             |\n");
		printf("| 5. Buscar Productos por Marca            |\n");
		printf("| 6. Buscar Productos por Nombre           |\n");
		printf("| 7. Mostrar todos los Productos           |\n");
		printf("| 8. Agregar al Carrito                    |\n");
    printf("| 9. Concretar Compra                      |\n");
    printf("| 0. Salir                                 |\n");
    printf("--------------------------------------------\n");

    printf("| ⏬ Indica la opción ⏬ |\n");
    printf("--------------------------\n");
		printf("👉 "); scanf("%d", &op);
    printf("\n");

  //  FILE * lista = fopen("productos.csv","r");
  //  char linea[300];
  //  char *token;
  //  Producto *b=NULL;

  //AQUI!
  
    Carrito *c = NULL;
    int a=0;
    Carrito fila[50];
    Producto *b=NULL;
    char nombre_carrito[30];
    int i=0,magnitud=50;

  // char busca_tipo[10];
  //  char busca_Marca[10];
  // char busca_Nombre[10];


    
    
		
		switch (op) 
    {

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖-➖//
    case 1:

     importarProductos(producto_nombre,producto_marca,producto_tipo,producto_stock,producto_precio);

    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
      
    case 2: printf("EXPORTAR PRODUCTOS\n");

    exportarProductos(producto_nombre, producto_marca, producto_tipo, producto_stock, producto_precio);

    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
    case 3:
      
    agregarProducto(producto_nombre,producto_marca, producto_tipo,producto_stock,producto_precio);
      
    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
    case 4:

    buscarProductoTipo(producto_nombre, producto_marca, producto_tipo,producto_stock, producto_precio);

    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//

    case 5:

    buscarProductoMarca(producto_nombre, producto_marca, producto_tipo, producto_stock, producto_precio);
      
    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//

    case 6:

     buscarProductoNombre(producto_nombre, producto_marca, producto_tipo, producto_stock, producto_precio);

    break;
//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//

    case 7:

    mostrarProductos(producto_nombre, producto_marca, producto_tipo,producto_stock, producto_precio);

    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//

/*
 Agrega un producto al carrito de compras, dicho carrito tendrá su nombre propio. Pirmero se le pregunta cual es el producto que desea agregar, luego cuanta es la cantidad que quiere añadir, por ultimo se le preguntará si quiere agregar otro produto más.
*/
      case 8:
    
      printf("Ingrese nombre carrito: ");
      scanf(" %[^\n]",nombre_carrito);

      for(i=0;i<magnitud;i++){
        if (strcmp(nombre_carrito,fila[i].nombre_de_carrito)==0)
        {  
          break;
        }else if( strlen (fila[i].nombre_de_carrito)==0){
          strcpy(fila[i].nombre_de_carrito,nombre_carrito);
          break;
        } 
      }
/* */

///////////////////////////////////////////////////////////////

      int indice=0;
      while(1){

        b = firstMap(producto_nombre);
     
        int terminar=1;
        char nombre_c[20];
        int cosas_al_carro=0;

       printf("Ingrese producto: ");
       scanf(" %[^\n]",nombre_c);

       printf("Ingrese cuantos: ");
       scanf("%d",&cosas_al_carro);

        while (b!=NULL){

          if (strcmp(nombre_c,b->nombre)==0){

          strcpy(fila[i].chek[indice].nombre_producto,b->nombre);
          fila[i].chek[indice].cantidad = cosas_al_carro;
          fila[i].chek[indice].precios = b->precio;
          break;
        }
      
        else b=nextMap(producto_nombre);
        }

        indice++;
        printf("\n");

        printf("¿Desea agregar otro producto?\n");
        printf("\n");
        printf("Si = 1 ; No = 0\n");

        scanf("%d",&terminar);

        if (terminar==0) break;
      
      }

      break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
       case 9:

       /*Concreta la compra de los productos seleccionados en el caso 8. Se pide ingresar el nombre de carro, luego la funcion buesa el carro en el arreglo fila. De encontrarlo,imprime los datos de la sigugiente manera:
       -Imprime el titulo "Nombre de carro" y Lista de compras" con los nombres de productos por orden de ingreso, junto con la cantidad y precio del producto.
       - Finalmente imprime el total a pagar junto con eliminar el carro ya usado */

       while(1){
          char pagar[30];
          int indice,j;
          int suma=0;

       printf("Ingrese nombre de carrito \n");
       scanf(" %[^\n]",pagar);

       for (indice=0 ; indice < 50 ; indice++){
         if (strcmp(pagar,fila[indice].nombre_de_carrito)==0){
           break;
         }
       }
       if(indice == 50){
         printf("Carro no encontrado\n");
         break;
       }
       printf("\n");

       printf("Carro: %s\n",pagar);

       printf("Lista de compras\n");
       printf("--------------------------\n");

       
      ////////////////////////////////////////////////////////
       for(j=0 ; j<100; j++){     

         printf("%s %d x %d \n",fila[indice].chek[j].nombre_producto,fila[indice].chek[j].cantidad,fila[indice].chek[j].precios);

         suma+=(fila[indice].chek[j].cantidad)* (fila[indice].chek[j].precios); 

         if(strlen(fila[indice].chek[j+1].nombre_producto)==0) break;
       }
       printf("--------------------------\n");
       printf("Total a pagar: %d \n",suma);


       strcpy(fila[indice].nombre_de_carrito,"Borrado");
       printf("\n");
       
       printf("CARRO ELIMINADO");
       break;

       }
       break;

    }
    }
    
}
