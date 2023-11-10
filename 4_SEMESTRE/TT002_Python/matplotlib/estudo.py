import matplotlib.pyplot as plt
from matplotlib.patches import Circle

# Crie uma figura e um eixo
fig, ax = plt.subplots()

# Crie um círculo
circle = Circle((0.5, 0.5), 0.2, fill=True, color='blue')

# Adicione o círculo ao eixo
ax.add_patch(circle)

# Defina os limites do eixo para garantir que o círculo seja totalmente visível
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)

# Exiba o gráfico
plt.show()
