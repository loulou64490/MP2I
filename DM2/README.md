### Compiler

```bash
cd src/
clang main.c sound.c wav.c waveform.c melody.c test.c -o wav_writer -lm -O3
```

### Exécuter

```
usage: wav_writer input.txt output.wav [ATTACK DECAY RELEASE]
```
Par défaut, ATTACK = 0.01, DECAY = 0.05 et RELEASE = 0.005

Exemple d'utilisation:

```bash
# avec l'enveloppe par défaut
./wav_writer input/test.txt output/test.wav 

# avec une enveloppe personnalisée
./wav_writer input/test.txt output/test.wav 0.02 0.01 0.01

# pour exécuter les tests
./wav_writer
```
