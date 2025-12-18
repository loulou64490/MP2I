from os import system

import matplotlib.pyplot as plt

system("gcc base.c rapide.c -O3 && ./a.out")  # pour exécuter le programme
system("gcc base.c insertion.c -O3 && ./a.out")

insertion = [float(x) for x in open("sortie/insertion.txt")]  # plus simple...
rapide = [float(x) for x in open("sortie/rapide.txt")]
x = [100 * (i + 1) for i in range(40)]

plt.plot(x, insertion, label="Tri par insertion")
plt.plot(x, rapide, label="Tri rapide")
plt.title("Comparaison du temps d'exécution")
plt.xlabel("n")
plt.ylabel("s")
plt.legend()
plt.grid(True)
plt.show()
