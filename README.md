
# Tarea 2 de Geometría Computacional

Esta tarea fue probada solo en Debian, no en otros sistemas operativos
por lo que no puedo asegurar que funcione en windows o mac.

### Instrucciones de ejecución

- Crear una carpeta llamada build y en ella crear el cache de cmake:
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

Los resultados de los tests quedarán en archivos csv, estos se puedenutilizar 
para generar gráficos usando un script the python que está en el directorio raíz
de la tarea, ahí también están los archivos csv generados en mi computador.

Para generar los gráficos se debe cambiar al directorio raiz de la tarea, instalar
las dependencias y ejecutar el script, el primer argumento del script es el directorio
en el que buscar los archivos, especificar `build` para utilizar los generados localmente
y `.` para los generados por mí:

```bash
cd ..
pip3 install -r requirements.txt
python3 graficos.py build
```

