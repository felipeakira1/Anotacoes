from matplotlib import pyplot as plt

meses = ["Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]
vendas = [120, 135, 150, 145, 160, 155, 170, 165, 180, 175, 190, 200]

plt.plot(meses, vendas, color='black', marker='o')
plt.xlabel("Meses")
plt.ylabel("Vendas (unidades)")
plt.title("Vendas mensais em 2023")
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()