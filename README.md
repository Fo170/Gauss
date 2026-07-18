# Gauss - Solveur d'équations linéaires par élimination de Gauss

Projet porté de Visual Studio 2003 vers CMake multiplateforme.

## Description

Programme console qui résout un système d'équations linéaires `A · x = b` par la méthode
d'élimination de Gauss avec pivotage partiel.

Soit le système :

```
A[0][0]·x0 + A[0][1]·x1 + ... + A[0][n-1]·xn-1 = b0
A[1][0]·x0 + A[1][1]·x1 + ... + A[1][n-1]·xn-1 = b1
  ⋮            ⋮                      ⋮           ⋮
A[n-1][0]·x0 + A[n-1][1]·x1 + ... + A[n-1][n-1]·xn-1 = bn-1
```

Le programme calcule les coefficients `x0 ... xn-1` et affiche la vérification :
pour chaque ligne, `Y' = Σ coeffs[c]·MTV[l][c]` est comparé à `MTVy[l]` (la valeur
originale attendue).

## Utilisation

Lancez l'exécutable :
```powershell
.\Gauss.exe
```

### Saisie des données

1. **Nombre de lignes** (`nl`) et **nombre de colonnes** (`nc`) de la matrice
2. Si `nl ≠ nc`, le programme ajuste automatiquement la dimension `n` :
   - `nl < nc` → plusieurs solutions possibles (coefficients inconnus mis à zéro)
   - `nc < nl` → système surdéterminé (des impossibilités peuvent apparaître)
3. Saisie des éléments de la matrice **A** un par un : `MT(ligne, colonne) ?`
4. Saisie du second membre **b** pour chaque ligne : `MTy(ligne) ?`

### Calcul

Le programme :
- Construit la matrice augmentée `[A | b]` au format 1D
- Applique l'élimination de Gauss avec pivotage de lignes (tolérance `EPS = 1e-308`)
- Effectue la remontée (back-substitution) pour trouver les coefficients `coeffs[0..n-1]`
- Affiche la matrice transformée après élimination
- Affiche les coefficients `K(0) ... K(n-1)`
- Affiche la vérification : `Y(ligne) = valeur originale` vs `Y'(ligne) = Σ(coeffs · Aoriginale)`

### Exemple

Saisie d'un système 2×2 :
```
 NOMBRES DE LIGNES ? 2
 NOMBRES DE COLONNES ? 2
 MT( 0 ,0 ) ? 3
 MT( 0 ,1 ) ? 1
 MTy( 0 ) ? 5
 MT( 1 ,0 ) ? 1
 MT( 1 ,1 ) ? -2
 MTy( 1 ) ? 4
```

Résultat attendu : `K(0) = 2, K(1) = -1`
Vérification : `3·2 + 1·(-1) = 5` et `1·2 + (-2)·(-1) = 4` ✓

### Contrôles

- Appuyez sur une touche après chaque affichage pour continuer
- Tapez `S` (ou `s`) à la fin d'un calcul pour quitter l'application
- Tapez n'importe quelle autre touche pour recommencer avec une nouvelle matrice

## Prérequis

- CMake >= 3.16
- Compilateur C++17 (GCC, Clang, MSVC, MinGW)

## Build

### Windows
```powershell
cd Windows
cmake -B C:\temp\Gauss_build -G "Visual Studio 16 2019" -A x64
cmake --build C:\temp\Gauss_build --config Release
```

### Linux
```bash
cd linux
cmake -B build
cmake --build build
```

## Structure des répertoires

| Dossier | Description |
|---------|-------------|
| `src/` | Code source partagé (main.cpp, Gauss.h, Type.h) |
| `Windows/` | Projet de build Windows (CMakeLists.txt) |
| `linux/` | Projet de build Linux (CMakeLists.txt) |
| `plus_necessaire/` | Archives du projet original VS2003 |

## Licence

Projet interne.
