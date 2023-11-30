import math

class Coordenada:
    def __init__(self, *args):
        if len(args) > 1:
            raise ValueError(f"Numero de argumentos errado: {len(args)}")
        coordenada = args[0]
        if not isinstance(coordenada, tuple):
            raise TypeError("Parametro nao eh uma tupla")
        if len(coordenada) != 2:
            raise ValueError("A tupla deve possuir dois elementos e os elementos devem ser numeros")
        if not all(isinstance(c, (int, float)) for c in coordenada):
            raise TypeError("Os elementos da tupla devem ser inteiros ou flutuantes. ")
        self.x, self.y = coordenada

    def distancia(self, coordenada):
        deltax = self.x - coordenada.x
        deltay = self.y - coordenada.y
        distancia = math.sqrt((deltax**2 + deltay**2))
        return distancia

    def __str__(self):
        return f"({self.x},{self.y})"