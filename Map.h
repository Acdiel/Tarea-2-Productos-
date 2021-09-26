#ifndef MAP_H
#define MAP_H

typedef struct Map Map;

typedef struct{
	char nombre[50];
  char marca[70];
	char tipo[20];
	int stock;
	int precio;
}Producto;

typedef struct{

  char nombre_producto[20];
  int cantidad;
  int precios;
}cosas;


typedef struct{
	char nombre_de_carrito[30];
  cosas chek[100];
}Carrito;


/*
typedef struct{
	char nombre[30];
  char carrito[40];
  int cantidad;
}Carrito;*/


Map * createMap(int (*is_equal)(void* key1, void* key2));

void insertMap(Map * map, void * key, void * value);

void * eraseMap(Map * map, void * key);

void * searchMap(Map * map, void * key);

void * firstMap(Map * map);

void * nextMap(Map * map);

void setSortFunction(Map* map, int (*lower_than)(void* key1, void* key2));



#endif /* MAP_h */