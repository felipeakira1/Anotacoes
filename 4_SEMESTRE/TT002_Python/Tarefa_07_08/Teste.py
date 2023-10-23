import random
import math 

class Coordenada:
    def __init__(self, *args):
        if len(args) > 1:
            raise TypeError("Numero de parametros errado")
        
        cord = args[0] if args else None

        if not isinstance(cord, tuple):
            raise Exception("O parametro deve ser uma tupla")
        if len(cord) != 2:
            raise Exception("Numero de coordenadas invalido: " + str(len(cord)))
        if not all(isinstance(i, (int, float)) for i in cord):
            raise Exception("Os elementos da tupla devem ser numeros")
        self.x = cord[0]
        self.y = cord[1]

    def distancia(self, cord2):
        if not isinstance(cord2, Coordenada):
            raise Exception("O parametro deve ser uma instância de Coordenada")

        dx = self.x - cord2.x
        dy = self.y - cord2.y
        return math.sqrt(dx**2 + dy**2)

    def __str__(self):
        return f"({self.x}, {self.y})"

class Rota:
    def __init__(self): 
        self.coordenadas = []

    def addCoord(self, coordenada):
        if isinstance(coordenada, Coordenada):
            self.coordenadas.append(coordenada)
        else:
            raise Exception("O parametro deve ser uma instancia de Coordenada")

    def comprimento(self): 
        if len(self.coordenadas) < 2: 
            return 0

        comprimento_total = 0
        for i in range(len(self.coordenadas) - 1): 
            comprimento_total += self.coordenadas[i].distancia(self.coordenadas[i + 1])

        comprimento_total += self.coordenadas[-1].distancia(self.coordenadas[0])
        return comprimento_total

    def copy(self):
        nova_rota = Rota()
        for coordenada in self.coordenadas:
            nova_rota.addCoord(Coordenada((coordenada.x, coordenada.y)))
        return nova_rota 
    
    def shuffle(self):
        random.shuffle(self.coordenadas)
    
    def otimiza(self):
        melhor_comprimento = self.comprimento()
        mudou = True

        while mudou:
            mudou = False
            for i in range(len(self.coordenadas) - 1):
                for j in range(i + 1, len(self.coordenadas)):
                    # Criar uma nova rota trocando as arestas (i, i+1) e (j, j+1)
                    nova_rota = self.copy()
                    nova_rota.coordenadas[i + 1:j + 1] = reversed(self.coordenadas[i + 1:j + 1])

                    # Calcular o comprimento da nova rota
                    novo_comprimento = nova_rota.comprimento()

                    # Se o novo comprimento for menor, atualizar a rota atual
                    if novo_comprimento < melhor_comprimento:
                        self.coordenadas = nova_rota.coordenadas
                        melhor_comprimento = novo_comprimento
                        mudou = True

    def __str__(self):
        output = str(self.coordenadas[0])
        for i in range(1, len(self.coordenadas)):
            output += f" -> {str(self.coordenadas[i])}"
        
        output +=f" -> {str(self.coordenadas[0])}"
        return output

rota1: Rota = Rota()
for i in range(50):
   x = random.randrange(1, 100)
   y = random.randrange(1, 100)
   cord = Coordenada((x, y))
   rota1.addCoord(cord)

# Otimizando a rota usando Simulated Annealing
print("\nRota ANTS DE SER OTIMIZADA:")
print(rota1)
print("Comprimento da rota otimizada:", rota1.comprimento())
rota1.otimiza()
print("\nRota otimizada:")
print(rota1)
print("Comprimento da rota otimizada:", rota1.comprimento())