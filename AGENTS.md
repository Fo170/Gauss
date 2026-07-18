# AGENTS.md - Projet Gauss

## Structure du projet

```
./
├── src/                    # Code source partagé (Windows + Linux)
│   ├── main.cpp            # Point d'entrée console
│   ├── Gauss.h             # Élimination de Gauss (GSolve)
│   └── Type.h              # Types, macros, GETCH cross-platform
├── Windows/                # Projet QT pour Windows
│   └── CMakeLists.txt      # Build CMake Windows
├── linux/                  # Projet QT pour Linux
│   └── CMakeLists.txt      # Build CMake Linux
├── plus_necessaire/        # Anciens fichiers (VS2003, Old_includes)
├── AGENTS.md               # Ce fichier
└── README.md               # Documentation
```

## Dépendances analysées

GAUSS.CPP original incluait `Type.h` (introuvable) et `Gauss.h`.
- `Type.h` a été reconstruit à partir de `Old_includes/DEF_HL.h` (18/01/97), version la plus récente des définitions de types (Ldbl, uint, ulong, macros _(), _L(), swap, GETCH)
- `Gauss.h` a été corrigé : GSolve réécrit pour tableau 1D (flat array) avec pivotage de lignes, l'original utilisait un passage `Ldbl*` vers `Ldbl**` invalide

## Commandes de build

### Windows (VS2022+ ou MinGW)
```powershell
cd Windows
cmake -B build -G "Visual Studio 17 2022"
cmake --build build
```

### Linux
```bash
cd linux
cmake -B build
cmake --build build
```

## Fichiers déplacés dans plus_necessaire/

- `Old_includes/` : toutes les anciennes bibliothèques (graphisme, souris, son, EMS, hyperlink, etc.) non nécessaires au calcul de Gauss
- `GAUSS.CPP`, `Gauss.h` : originaux VS2003
- `Gauss.vcproj`, `Gauss.sln`, `Gauss.suo`, `UpgradeLog.XML`, `_UpgradeReport_Files/`, `Release/`

## Corrections appliquées

1. **GSolve** : paramètre `Ldbl *aug` (tableau 1D de taille `n*(n+1)`) au lieu de `Ldbl **a` incompatible avec l'appel
2. **getch()** : remplacé par `GETCH()` cross-platform (termios sur Linux, `_getch` sur Windows)
3. **TRUE/FALSE** : définis localement dans Gauss.h
4. **Math constants** : réduits à `PI` uniquement (le reste n'étant pas utilisé)
