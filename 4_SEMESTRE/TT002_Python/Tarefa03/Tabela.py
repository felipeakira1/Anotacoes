from Linha import Linha

class Tabela:
    def __init__(self, nomeArquivo = None):
        self.cabecalho = Linha()
        self.dados = list()

        if nomeArquivo:
            self.carregarTabela(nomeArquivo)

    def add_cabecalho(self, valor):
        if isinstance(valor, list):
            self.cabecalho.append(valor)
        else:
            raise TypeError("O parametro deve ser um objeto do tipo lista.")
    
    def add_linha(self, valor):
        if isinstance(valor, Linha):
            if len(valor) == len(self.cabecalho):
                self.dados.append(valor)
            else:
                raise ValueError("O tamanho da linha eh diferente do tamanho do cabecalho.")
        else:
            raise TypeError("O parametro deve ser um objeto do tipo Linha.")

    def __str__(self):
        resultado = f"{str(self.cabecalho)}\n"
        resultado += "-----------------------------------------\n"
        for linha in self.dados:
            resultado += f"{str(linha)}"
        return resultado

    def ordena_por(self, valor):
        # Verificar se o valor está presente no cabeçalho
        if valor in self.cabecalho.dados:
            posicaoCabecalho = self.cabecalho.dados.index(valor)
            self.dados.sort(key = lambda linha : linha.dados[posicaoCabecalho])
        else:
            raise ValueError("O valor nao esta presente no cabecalho.")
        
    def carregarTabela(self, nomeArquivo):
        try:
            file = open(nomeArquivo, "r")
            linhas = file.readlines()
            cabecalho = Linha()
            cabecalho.append(eval(linhas[0]))
            self.add_cabecalho(eval(linhas[0]))
            for linha in linhas[1:]:
                carro = Linha()
                carro.append(eval(linha))
                self.add_linha(carro)
            file.close()
        except FileNotFoundError:
            print("Erro: O arquivo nao existe")

    def writeFile(self, nomeArquivo):
        file = open(nomeArquivo, "r")
tabela = Tabela("carro.txt")
tabela.ordena_por("ano")
print(tabela)