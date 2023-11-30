from Coordenada import Coordenada
from PIL import Image, ImageDraw, ImageFont
import random
import time

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

    def espera(self, time):
        tin = time.time()
        delta = time.time - tin;
        while delta < time:
            if delta == 1000:
                print(f"Esperando: {delta}")
            delta = time.time() - tin
    
    def randomCoords(self, n, max_coord):
        self.coordenadas = list()
        for _ in range(n):
            x = random.randint(1, max_coord)
            y = random.randint(1, max_coord)
            coordenada = Coordenada((x, y))
            self.addCoord(coordenada)
    
    def maximo(self):
        max_x = 0
        max_y = 0
        for i in range(len(self.coordenadas)):
            if self.coordenadas[i].x > max_x:
                max_x = self.coordenadas[i].x
            if self.coordenadas[i].y > max_y:
                max_y = self.coordenadas[i].y
        return (max_x, max_y)

    def desenha(self, filename):
      max_x, max_y = self.maximo()
      margin = 20  # Margem em pixels

      img = Image.new("RGB", (max_x + margin * 2, max_y + margin * 2), (255, 255, 255))
      draw = ImageDraw.Draw(img)

      for i in range(len(self.coordenadas)):
        x1, y1 = self.coordenadas[i].x + margin, self.coordenadas[i].y + margin
        x2, y2 = self.coordenadas[(i + 1) % len(self.coordenadas)].x + margin, self.coordenadas[(i + 1) % len(self.coordenadas)].y + margin
        draw.line((x1, y1, x2, y2), fill=(0, 0, 0), width=2)

      draw.text((10, max_y + margin), f"Comprimento: {self.comprimento()}", fill=(0, 0, 0))

      img.save(filename)
      return img

    def otimiza(self):
        melhor_comprimento = self.comprimento()
        mudou = True

        while mudou:
            mudou = False
            for i in range(len(self.coordenadas) - 1):
                for j in range(i + 1, len(self.coordenadas)):
                    # Criar uma nova rota trocando as arestas (i, i+1) e (j, j+1)
                    nova_rota = self.clone()
                    nova_rota.coordenadas[i + 1:j + 1] = reversed(self.coordenadas[i + 1:j + 1])

                    # Calcular o comprimento da nova rota
                    novo_comprimento = nova_rota.comprimento()

                    # Se o novo comprimento for menor, atualizar a rota atual
                    if novo_comprimento < melhor_comprimento:
                        self.coordenadas = nova_rota.coordenadas
                        melhor_comprimento = novo_comprimento
                        mudou = True