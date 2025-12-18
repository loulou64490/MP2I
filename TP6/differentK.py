from os import system

import matplotlib.pyplot as plt

system("gcc base.c hybride.c -O3 -march=native")

x = [10000 * (i + 1) for i in range(10)]
for i in range(1, 9):
    system(f"./a.out {2**i}")
    plt.plot(x, [float(x) for x in open("sortie/hybride.txt")], label=f"K = {2**i}")

plt.title("Comparaison du temps d'exécution")
plt.xlabel("n")
plt.ylabel("s")
plt.legend()
plt.grid(True)
plt.show()
