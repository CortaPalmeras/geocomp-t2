
## Tarea 1 de Geometría Computacional

#### Requisitos para ejecutar la tarea:

- Un compilador de C++, puede ser `g++` o `clang++`.
- `make` para ejecutar los comandos.
- Alguna distribución de Linux, yo hice y probé la tarea en Debian.

#### Instrucciones de ejecución:

El archivo makefile tiene targets para ejecutar los tests compilando con `g++` y con `clang++`:
- `g++`: Ejecutar `make` o `make test`.
- `clang++`: Ejecutar `make test-clang`.

#### Layout de la tarea:

```
./
├── makefile
├── README.md
├── bin/
├── include/
│   ├── poligono.hpp
│   ├── punto.hpp
│   └── vector.hpp
├── src/
│   ├── poligono.cpp
│   ├── punto.cpp
│   └── vector.cpp
└── test/
    ├── main_test.cpp
    ├── poligono_test.cpp
    ├── punto_test.cpp
    └── vector_test.cpp
```
