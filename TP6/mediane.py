from os import system

import matplotlib.pyplot as plt

system("gcc base.c rapide.c -O3 && ./a.out")
system("gcc base.c mediane.c -O3 && ./a.out")

rapide = [float(x) for x in open("sortie/rapide.txt")]
mediane = [float(x) for x in open("sortie/mediane.txt")]
x = [100 * (i + 1) for i in range(40)]

plt.plot(x, rapide, label="Pivot premier élement")
plt.plot(x, mediane, label="Pivot médiane")
plt.title("Comparaison du temps d'exécution")
plt.xlabel("n")
plt.ylabel("s")
plt.legend()
plt.grid(True)
plt.show()
