from Rota import Rota
from matplotlib import pyplot as plt
import random
import time

class Otimizador:
    def __init__(self):
        self.plt = plt
    
    def swap(self, rota: Rota, pos1: int, pos2: int):
        aux = rota.coordenadas[pos1]
        rota.coordenadas[pos1] = rota.coordenadas[pos2]
        rota.coordenadas[pos2] = aux

    def singleSwap(self, rota: Rota, time_ms: int):
        rota.shuffle()
        tin = round(time.time() * 1000)

        delta_ms = round(time.time() * 1000) - tin
        minComprimento = rota.comprimento()

        tempos = []
        comprimentos = []
        
        while delta_ms < time_ms:
            delta_ms = round(time.time() * 1000) - tin
            if delta_ms % 1000 == 0:
                print(f"Esperando: {delta_ms} ms")
            size_rota = len(rota.coordenadas)
            pos1 = random.randrange(0, size_rota)
            pos2 = random.randrange(0, size_rota)
            self.swap(rota, pos1, pos2)
            if rota.comprimento() < minComprimento:
                minComprimento = rota.comprimento()
            else:
                self.swap(rota, pos1, pos2)

            tempos.append(delta_ms)
            comprimentos.append(rota.comprimento())
        
        self.plt.plot(tempos, comprimentos, color='k', label='SingleSwap')
    
    def aleatorio(self, rota: Rota(), time_ms: int):
        # Inicia a partir de uma rota nao otimizada
        rota.shuffle()
        tempo_atual = round(time.time() * 1000)
        delta_ms = round(time.time() * 1000) - tempo_atual

        tempos = list()
        comprimentos = list()

        min_comprimento = rota.comprimento()
        while delta_ms < time_ms:
            delta_ms = round(time.time() * 1000) - tempo_atual
            if delta_ms % 1000 == 0:
                print(f"Esperando: {delta_ms} ms")

            rotaAux = rota.clone()
            rotaAux.shuffle()

            if rotaAux.comprimento() < min_comprimento:
                rota.coordenadas = rotaAux.coordenadas
                min_comprimento = rota.comprimento()
            
            tempos.append(delta_ms)
            comprimentos.append(min_comprimento)
        
        self.plt.plot(tempos, comprimentos, color='green', label='Aleatorio')
    
    def otimizadorGrupo1(self, rota: Rota, time_ms: int):
        rota.shuffle()
        tin = round(time.time() * 1000)
        delta_ms = round(time.time() * 1000) - tin

        min_comprimento = rota.comprimento()
        tempos = []
        comprimentos = []

        while delta_ms < time_ms:
            delta_ms = round(time.time() * 1000) - tin

            if delta_ms % 1000 == 0:
                print(f"Esperando: {delta_ms} ms")
            
            pos1 = random.randrange(len(rota.coordenadas))
            pos2 = (pos1 + 1) % len(rota.coordenadas)
            # Escolhe aleatoriamente um ponto para inserção
            ponto_insercao = random.randrange(len(rota.coordenadas))
            # Move o ponto adjacente para o local de inserção
            rota_temp = rota.clone()
            rota_temp.coordenadas.insert(ponto_insercao, rota_temp.coordenadas.pop(pos2))
            novo_comprimento = rota_temp.comprimento()

            if novo_comprimento < min_comprimento:
                rota.coordenadas = rota_temp.coordenadas
                min_comprimento = novo_comprimento

            tempos.append(delta_ms)
            comprimentos.append(rota.comprimento())
        
        self.plt.plot(tempos, comprimentos, color='b', label='Ana_Catarina_Felipe', linewidth=3)
    def salvaFigura(self, filename):
        plt.xlabel('Tempo (ms)')
        plt.ylabel('Comprimento (pixel)')
        plt.title('Comprimento versus Tempo (ms)')
        self.plt.legend()
        self.plt.savefig(filename)

# Cria uma rota vazia.
r = Rota()

# Solicita o numero de coordenadas da rota
size = int(input("Digite o numero de vertices: "))

# Popula a rota com coordenadas entre 1 e 400
r.randomCoords(size, 400)

# Cria um novo otimizador
opt = Otimizador()

# Solicita o tempo de otimizacao
time_ms = int(input("Digite o tempo em ms: "))

# Otimiza por single swap
opt.singleSwap(r, time_ms)

# Otimização aleatorio
opt.aleatorio(r, time_ms)


opt.otimizadorGrupo1(r, time_ms)

# Otimizacao do grupo
opt.salvaFigura("Resultado_" + str(size) + ".png")