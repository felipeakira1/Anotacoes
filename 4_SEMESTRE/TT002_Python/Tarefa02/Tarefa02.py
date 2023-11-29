import random
from matplotlib import pyplot as plt

carro = dict()
carro["placa"] = "BBB2B99"
carro["ano"] = 2022
carro["marca"] = "chevrolet"
carro["modelo"] = "onix"

filename = "carros.txt"
def addCarro(carro):
    file = open(filename, "a")
    file.write(str(carro) + "\n")
    file.close()

def carregaCarros():
    lista = list()
    file = open(filename, "r")
    for linha in file:
        lista.append(eval(linha))
    file.close()
    return lista

def contemPlaca(placa):
    carros = carregaCarros()
    for carro in carros:
        if placa == carro["placa"]:
            return True
    return False

def placaAleatoria():
    letras = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U", "V", "W", "X", "Y","Z"]
    numeros = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    while True:
        placa = list()
        placa.append(random.choice(letras))
        placa.append(random.choice(letras))
        placa.append(random.choice(letras))
        placa.append(random.choice(numeros))
        placa.append(random.choice(letras))
        placa.append(random.choice(numeros))
        placa.append(random.choice(numeros))
        if not contemPlaca(placa):
            return "".join(placa)

def carroAleatorio():
    marcas = ["chevrolet", "volkswagem", "fiat"]
    modelosChevrolet = ["onix", "cruze", "camaro"]
    modelosVolkswagem = ["polo", "jetta", "gol"]
    modelosFiat = ["pulse", "argo", "moby"]
    carro = dict()
    carro["placa"] = placaAleatoria()
    carro["ano"] = random.randint(2000, 2023)
    carro["marca"] = random.choice(marcas)
    if(carro["marca"] == "chevrolet"):
        carro["modelo"] = random.choice(modelosChevrolet)
    elif(carro["marca"] == "volkswagem"):
        carro["modelo"] = random.choice(modelosVolkswagem)
    elif(carro["marca"] == "fiat"):
        carro["modelo"] = random.choice(modelosFiat)
    return carro

def popula_dados():
    file = open(filename, "w")
    for i in range(200):
        addCarro(carroAleatorio())

def calculaEstatistica(chave):
    carros = carregaCarros()
    print(f"-- Numero de carros por {chave} --")
    estatistica = dict()
    for carro in carros:
        valorChave = carro[f"{chave}"]
        if valorChave in estatistica.keys():
            estatistica[valorChave] += 1
        else:
            estatistica[valorChave] = 1

    for valorChave in sorted(estatistica.keys()):
        quantidade = estatistica[valorChave]
        print(f"{chave} {valorChave}: {quantidade} carro(s)")
    print()
    

def geraEstatistica():
    calculaEstatistica("ano")
    calculaEstatistica("marca")
    calculaEstatistica("modelo")

geraEstatistica()