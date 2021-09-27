#ifndef Productos_h
#define Productos_h
#include "Map.h"



int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

Producto* crearProducto(char* nombre, char *marca, char * tipo, int stock, int precio);

void importarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void exportarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void agregarProducto(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void buscarProductoTipo(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void buscarProductoMarca(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void buscarProductoNombre(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void mostrarProductos(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

#endif /* Productos_h */