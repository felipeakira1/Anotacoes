class Linha:
    def __init__(self):
        self.dados = list()
    
    def append(self, valor):
        if not isinstance(valor, list):
            self.dados.append(valor)
        else:
            self.dados.extend(valor)
    
    def __len__(self):
        return len(self.dados)
    
    def __str__(self):
        return f"{self.dados}({len(self.dados)})\n"