file = open("carros.txt", "r")
linhas = file.readlines()
for linha in linhas:
    print(linha)