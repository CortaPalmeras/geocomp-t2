
# Tarea 2 de Geometría Computacional

La prataforma que utilicé principalmente para probar esta tarea y en la
que ejecuté la experimentacion fue Debian usando el compilador gcc, tambien
ejecuté los tests en Windows 10 y pasaron, pero no realicé la experimentacion.

### Instrucciones de ejecución en Linux

- Desde el directorio raiz de la tarea, crear un directorio llamado build y ejecutar Cmake desde ahí:
```bash
mkdir build
cd build
cmake ..
```

- Compilar la tarea con make y correr los tests:
```bash
make
./test/convex_hull/convex_hull_test 
```

### Instrucciones de ejecución en Windows

Para compilar en Windows corrí los comandos en "Developer PowerShell for VS", esto es necesario para 
que cmake sepa que compilador usar, pero no es necesario usar el IDE completo.

- Desde el directorio raiz de la tarea, crear un directorio llamado build y ejecutar Cmake desde ahí:
```bash
mkdir build
cd build
cmake ..
```

- Compilar la tarea y correr los tests:
```bash
cmake --build . --config Release
./test/convex_hull/Release/convex_hull_test.exe
```

## Instrucciones para generar los graficos

Al ejecutar los tests, la parte de experimentacion va a crear archivos csv con los tiempos de distintas
ejecuxiones de las funciones, en el directorio raiz de la tarea hay un script de python que genera 
graficos usando los datos de la experimentacion, también están los archivos csv con los datos generados
cuando yo ejecuté la experimentacion.

Para generar los gráficos se debe cambiar al directorio raiz de la tarea, instalar
las dependencias y ejecutar el script, el primer argumento del script es el directorio
en el que buscar los archivos, especificar `build` para utilizar los generados localmente
y `.` para usar los generados en mi computador:

```bash
cd ..
pip3 install -r requirements.txt
python3 graficos.py build
```

