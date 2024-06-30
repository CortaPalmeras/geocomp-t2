
import os
import pandas as pd
import matplotlib.pyplot as plt

directorio_datos = 'build/'
directorio_salida = "out/"

os.makedirs(directorio_salida, exist_ok = True)

def graficar_radial(caso: str):
    csv_radial = pd.read_csv(directorio_datos + 'radial_' + caso + '.csv')
    csv_radial['proporcion'] = csv_radial['n_puntos_cupula'] / csv_radial['numero_puntos']

    directorio_caso = directorio_salida + nombre +'/'
    os.makedirs(directorio_caso, exist_ok = True)

    directorio_proporcion = directorio_caso + "proporcion/"
    os.makedirs(directorio_proporcion, exist_ok = True)

    cantidades_puntos = csv_radial['numero_puntos'].unique()

    for n_puntos in cantidades_puntos[4:]:
        radial_n_puntos = csv_radial[csv_radial['numero_puntos'] == n_puntos]
        x = radial_n_puntos ['proporcion']
        plt.figure(figsize=(10, 6))
        plt.grid(True)

        y = radial_n_puntos ['t_gift_wrapping']
        plt.scatter(x, y, alpha=0.5, label="Gift Wrapping")

        y = radial_n_punto['t_incremental']
        plt.scatter(x, y, alpha=0.5, label="Incremental")

        plt.legend()
        plt.title("Tiempo sobre proporcion de puntos con " + str(n_puntos) + " puntos")
        plt.xlabel("Proporcion de puntos que están dentro de la cúpula")
        plt.ylabel("Tiempo de ejecución (s)")

        plt.savefig(directorio_proporcion + str(n_puntos) + '.png')

    x = csv_radial['proporcion']
    plt.figure(figsize=(10, 6))
    plt.grid(True)

    y = csv_radial['t_gift_wrapping']
    plt.scatter(x, y, alpha=0.5, label="Gift Wrapping")

    y = radial_n_punto['t_incremental']
    plt.scatter(x, y, alpha=0.5, label="Incremental")

    plt.legend()
    plt.title("Tiempo sobre proporcion de puntos con " + str(n_puntos) + " puntos")
    plt.xlabel("Proporcion de puntos que están dentro de la cúpula")
    plt.ylabel("Tiempo de ejecución (s)")

    plt.savefig(directorio_caso + 'todos.png')


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

graficar_random()


