
import os
import sys
import pandas as pd
import matplotlib.pyplot as plt

directorio_datos = './'
if len(sys.argv) == 2:
    directorio_datos = sys.argv[1]
    if directorio_datos[-1] != '/':
        directorio_datos += '/'

directorio_salida = 'out/'

os.makedirs(directorio_salida, exist_ok = True)

def graficar_radial(caso: str):
    nombre = 'radial_' + caso

    csv_radial = pd.read_csv(directorio_datos + nombre + '.csv')
    csv_radial['proporcion'] = csv_radial['n_puntos_cupula'] / csv_radial['numero_puntos']

    directorio_caso = directorio_salida + nombre +'/'
    os.makedirs(directorio_caso, exist_ok = True)

    directorio_proporcion = directorio_caso + 'tiempo_sobre_proporcion/'
    os.makedirs(directorio_proporcion, exist_ok = True)

    for n_puntos in csv_radial['numero_puntos'].unique():
        df_filtrado_n_puntos = csv_radial[csv_radial['numero_puntos'] == n_puntos]

        plt.figure(figsize=(10, 6))
        plt.grid(True)

        x = df_filtrado_n_puntos['proporcion']

        y = df_filtrado_n_puntos['t_gift_wrapping']
        plt.scatter(x, y, alpha=0.5, label='Gift Wrapping')

        y = df_filtrado_n_puntos['t_incremental']
        plt.scatter(x, y, alpha=0.5, label='Incremental')

        plt.legend()
        plt.title('Cantidad de puntos total:' + str(n_puntos))
        plt.xlabel('Proporción de puntos que están dentro de la cúpula')
        plt.ylabel('Tiempo de ejecución (s)')

        plt.savefig(directorio_proporcion+ str(n_puntos) + '.png')
        plt.close()

    directorio_cantidades = directorio_caso + 'tiempo_sobre_cantidad/'
    os.makedirs(directorio_cantidades, exist_ok = True)

    for n_puntos_cupula in csv_radial['n_puntos_cupula'].unique():
        df_filtrado_n_puntos = csv_radial[csv_radial['n_puntos_cupula'] == n_puntos_cupula]

        plt.figure(figsize=(10, 6))
        plt.grid(True)

        x = df_filtrado_n_puntos['numero_puntos']

        y = df_filtrado_n_puntos['t_gift_wrapping']
        plt.scatter(x, y, alpha=0.5, label='Gift Wrapping')

        y = df_filtrado_n_puntos['t_incremental']
        plt.scatter(x, y, alpha=0.5, label='Incremental')

        y = df_filtrado_n_puntos['t_incremental_nosort']
        plt.scatter(x, y, alpha=0.5, label='Incremental sin sort')

        plt.legend()
        plt.title('Cantidad de puntos en la cúpula: ' + str(n_puntos_cupula))
        plt.xlabel('Cantidad de puntos en total')
        plt.ylabel('Tiempo de ejecución (s)')

        plt.savefig(directorio_cantidades + str(n_puntos_cupula) + '.png')
        plt.close()


def graficar_random():
    csv_random= pd.read_csv(directorio_datos + 'random.csv')

    promedios_random = csv_random.groupby('numero_puntos').mean().reset_index()
    x = promedios_random['numero_puntos']
    plt.figure(figsize=(10, 6))
    plt.grid(True)

    y = promedios_random['t_gift_wrapping']
    plt.scatter(x, y, alpha=0.5, label='Gift Wrapping')

    y = promedios_random['t_incremental']
    plt.scatter(x, y, alpha=0.5, label='Incremental')

    y = promedios_random['t_incremental_nosort']
    plt.scatter(x, y, alpha=0.5, label='Incremental sin sort')

    plt.legend()
    plt.title('Tiempo sobre numero de puntos')
    plt.xlabel('Numero de puntos')
    plt.ylabel('Tiempo de ejecución (s)')
    plt.savefig(directorio_salida + 'random.png')
    plt.close()

graficar_random()
graficar_radial('grande')
graficar_radial('pequeno')
graficar_radial('cupulas_pequenas')

