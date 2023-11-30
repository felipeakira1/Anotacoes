from matplotlib import pyplot as plt
import numpy as np

anos = ['2018', '2019', '2020', '2021', '2022', '2023']
vendas_anuais_x = [120, 300, 200, 90, 50, 32]
vendas_anuais_y = [130, 400, 400, 30, 40, 50]

x = np.arange(len(anos))
largura = 0.35

plt.bar(x - largura/2, vendas_anuais_x, largura, color='blue', label="Produto Y")
plt.bar(x + largura/2, vendas_anuais_y, largura, color='red', label="Produto X")
plt.legend()
plt.title("Comparação de vendas anuais")
plt.xlabel("Anos")
plt.ylabel("Vendas (unidades)")
plt.xticks(x, anos)
plt.show()