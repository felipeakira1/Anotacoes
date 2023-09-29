# NOMES
# Felipe Akira Nozaki 172885
# Catarina Lima Mendes 172787
# Ana Clara Silva Sartori 172682

# Tarefa em grupo de 3 pessoas. Apenas um submete, porém com o nome
# dos três integrantes.

# Neste projeto, você deve inicialmente abrir o arquivo de coordenadas.
# Em seguida, você deve fazer a varredura nas coordenadas.
#
# Depois disso, você deve criar uma imagem em branco, 1001x1001.
# Cada coordenada do arquivo deve ser desenhada na imagem que foi
# criada.
#
# Você deve fazer um processo de normalização de modo que a menor latitude
# esteja associada à posição zero e a maior latitude esteja associada à posição
# 1000. Uma latitude intermediaria vai estar em um ponto intemediario entre
# 0 e 1000. Este é um processo chamado normalização.
# O mesmo deve ser feito para longitude.
# Após desenhar as coordenadas na imagem, deve rotacioná-la de maneira
# que o norte esteja para cima e o leste para a direita.
#
# Uma melhoria que deve ser feita é a seguinte: Cada estado
# deve ser pintado com uma cor entre (preto, azul, amarelo, cinza).
# Além disso, estados que possuem fronteira maior que zero
# devem ter cores diferentes.
#
# Ao final, você deve salvar o resulado em Brasil.png
#
# Você deve submeter o arquivo Brasil.png e o arquivo python com o programa.

cores_estados = {
    'AC': 'yellow',
    'AM': 'gray',
    'RR': 'blue',
    'PA': 'black',
    'AP': 'yellow',
    'MT': 'yellow',
    'RO': 'blue',
    'TO': 'blue',
    'MA': 'yellow',
    'PI': 'gray',
    'CE': 'black',
    'RN': 'blue',
    'PB': 'yellow',
    'PE': 'blue',
    'AL': 'gray',
    'SE': 'blue',
    'BA': 'yellow',
    'MT': 'yellow',
    'GO': 'gray',
    'MS': 'black',
    'MG': 'blue',
    'ES': 'gray',
    'RJ': 'black',
    'SP': 'yellow',
    'PR': 'blue',
    'SC': 'black',
    'RS': 'blue',
    'DF': 'black'
}

from PIL import Image, ImageDraw
import random

def normalizar_coordenada(coordenada, coordenada_minima, coordenada_maxima):
    return int(((coordenada - coordenada_minima) / (coordenada_maxima - coordenada_minima)) * 1000)

def ler_coordenadas(nome_arquivo):
    coordenadas = []
    file = open(nome_arquivo, 'r')
    for linha in file:
        lista_linha = linha.strip().split(';')
        estado = lista_linha[2]
        latitude = float(lista_linha[3])
        longitude = float(lista_linha[4])
        coordenadas.append((latitude, longitude, estado))
    return coordenadas

def desenhar_ponto():
    for latitude, longitude, estado in coordenadas:
        latitude_normalizada = normalizar_coordenada(latitude, latitude_minima, latitude_maxima)
        longitude_normalizada = normalizar_coordenada(longitude, longitude_minima, longitude_maxima)
        cor=cores_estados[estado]
        draw.point((latitude_normalizada, longitude_normalizada), fill=cor)
        

coordenadas = ler_coordenadas("coordenadas.txt")
latitude_minima = min(coordenadas, key=lambda x: x[0])[0]
latitude_maxima = max(coordenadas, key=lambda x: x[0])[0]

longitude_minima = min(coordenadas, key=lambda x: x[1])[1]
longitude_maxima = max(coordenadas, key=lambda x: x[1])[1]

largura = 1001
altura = 1001
cor_fundo = 'white'
imagem = Image.new('RGB', (largura, altura), color=cor_fundo)
draw = ImageDraw.Draw(imagem)

desenhar_ponto()
imagem_rotacionada = imagem.rotate(90, expand=True)
imagem_rotacionada.show()
imagem_rotacionada.save("Brasil.png")