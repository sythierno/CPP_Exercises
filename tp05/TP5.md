# TP5 - Copie et déplacement

## Objectifs

- Identifier les l-values et les r-values
- Comprendre le mécanisme du déplacement
- Définir un constructeur de copie
- Définir un constructeur de déplacement
- Définir un opérateur d'assignation par copie
- Définir un opérateur d'assignation par déplacement

## Exercice 1 - l-value ou r-value ? (30 min)

1. Identifiez si les expressions ci-dessous sont des l-values ou des r-values et justifiez.  

a. `i` est un `int`  
```cpp
4
4 + i
i
i = 4
i == 4
```

b. `vec` est un `std::vector<char>`
```cpp
vec[5]
vec
vec.pop_back()
std::vector { 'a', 'b', 'c' }
vec.emplace_back('d')
std::move(vec)
```

c. `ptr` est un pointeur de `int`
```cpp
ptr + 3
*(ptr + 3)
*ptr + 3
```

d. `str` est une `std::string`
```cpp
std::string { "aaaa" }
str
str + "aaaa"
str += "aaaa"
```

2. Supposons que vous ayiez l'instruction : `auto inst = Class { expr };`.  
Quelles sont les deux conditions pour que le constructeur de copie soit appelé ?  
Même question pour le constructeur de déplacement ?

## Exercice 2 - Minimisons les copies dans le tp02 (30 min)

Cet exercice est simple. Nous avons repris la solution du tp02 et le but est de faire passer le main que nous avons écrit.

Tracker

Vous pouvez reprendre votre code pour les fichiers `Card.{cpp,hpp}` et `Player.{cpp,hpp}` si vous préférez.

1. Ouvrez le fichier `Tracker.hpp` et lisez le.  

2. Pour chacun des 6 premiers constructeurs/opérateurs de `Tracker, écrivez leur nom en commentaire au dessus.

3. Quelle est la règle des `0/3/5` et est-ce que `Tracker` la suit?

4.

## Exercice 3 - Implémentations de listes chaînées 