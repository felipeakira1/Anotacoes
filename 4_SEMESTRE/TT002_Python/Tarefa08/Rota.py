from Coordenada import Coordenada
import random

class Rota:
    def __init__(self):
        self.coordenadas = list()
    
    def addCoord(self, coordenada):
        if not isinstance(coordenada, Coordenada):
            raise TypeError("Parametro deve ser uma coordenada")
        self.coordenadas.append(coordenada)
    
    def __str__(self):
        result = ""
        for coord in self.coordenadas:
            result += f"{coord}->"
        return result + f"{self.coordenadas[0]}"

    def comprimento(self):
        soma = 0
        for i in range(len(self.coordenadas) - 1):
            soma += self.coordenadas[i].distancia(self.coordenadas[i+1])
        soma += self.coordenadas[-1].distancia(self.coordenadas[0])
        return soma
    
    def clone(self):
        rota = Rota()
        for coord in self.coordenadas:
            rota.addCoord(coord)
        return rota
    
    def shuffle(self):
        random.shuffle(self.coordenadas)

rota = Rota()
try:
    rota.addCoord(Coordenada((0,0)))
    rota.addCoord(Coordenada((0,4)))
    rota.addCoord(Coordenada((3,4)))
    print(rota)
    print(rota.comprimento())
    rota2 = rota.clone()
    rota2.shuffle()
    print(rota2)
    print(rota2.comprimento())
except Exception as e:
    print(e)
