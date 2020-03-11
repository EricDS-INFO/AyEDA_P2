# ESTE REPOSITORIO CONTIENE LA SEGUNDA PRÁCTICA DE AyEDA.
*( - Conaway's Game of life - )*
***

## Contenido:

- [cabecera de la clase célula](./include/cell_t.hpp)
- [cabecera de la clase tablero](./include/board_t.hpp)
- [implementación de la clase célula](./src/cell_t.cpp)
- [implementación de la clase tablero](./src/board_t.cpp)
- [fichero de programa principal](./src/game_of_life_NG.cpp)
 > (tenga en cuenta que NG es de "Non Graphic. Existe una versión gráfica del programa")


## Dependencias

- [OpenGL](https://www.opengl.org/)
> (si pretende probar la versión gráfica debe instalar la librería GLUT, la cual es una colección de herramientas de open gl)

Para adquirirla:
  ```
    sudo apt-get install freeglut3 freeglut3-dev
  ```

## funciones del makefile 

- make  -> compila el fichero fuente básico solicitado

- make graphic  -> compila la versión gráfica del programa
> debe tener en cuenta que para que esto funcione la macro
> INFINITE debe retener un valor 1 (true), ya que debido 
> a la implementación que se ha hecho es necesario.

- make clean -> eliminar ejecutables


## Respecto a ideas futuras:
 - otorgar a las células varios puntos de vida
  > esto podría emplearse con OpenGL para otorgar un color 
  > distinto a cada estado y asi generar un mapa de calor.
