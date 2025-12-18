from os import system

import matplotlib.pyplot as plt

system("gcc base.c hybride.c -O3 && ./a.out")

rapide = [float(x) for x in open("sortie/rapide.txt")]
hybride = [float(x) for x in open("sortie/hybride.txt")]
x = [10000 * (i + 1) for i in range(10)]

plt.plot(x, rapide, label="Tri rapide")
plt.plot(x, hybride, label="Tri hybride")
plt.title("Comparaison du temps d'exécution")
plt.xlabel("n")
plt.ylabel("s")
plt.legend()
plt.grid(True)
plt.show()
