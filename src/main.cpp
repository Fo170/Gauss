#include "Type.h"
#include "Gauss.h"

int main(void)
{
    int c, l, n, nl, nc;
    Ldbl MT[80][80], MTy[80], coeffs[80];
    Ldbl y, MTV[80][80], MTVy[80];
    Ldbl *aug;
    char txt = 'D';

    while (txt != 'S')
    {
        printf(" NOMBRES DE LIGNES ? ");
        scanf("%d", &nl);
        printf(" NOMBRES DE COLONNES ? ");
        scanf("%d", &nc);

        if (nl < nc)
        {
            printf(" IL Y A PLUSIEURS SOLUTIONS !\n");
            printf(" JE CHOISI LA SOLUTION AVEC LES COEFFICIENTS INCONNUS NUL\n");
            n = nc;
        }
        if (nc < nl)
        {
            printf(" IL Y A MOINS DE COLONNES QUE DE LIGNES,\n");
            printf(" DES IMPOSSIBILITEES PEUVENT APPARAITRE !\n");
            n = nl;
        }

        if (nc == nl) n = nl;
        printf(" N = %d\n", n);

        for (l = 0; l < n; l++)
        {
            for (c = 0; c < n; c++)
            {
                printf(" MT( %d ,%d ) ? ", l, c);
                scanf("%le", &MT[l][c]);
                MTV[l][c] = MT[l][c];
            }
            printf(" MTy( %d ) ? ", l);
            scanf("%le", &MTy[l]);
            printf("\n");
            MTVy[l] = MTy[l];
        }

        printf("**********************************************\n");
        for (l = 0; l < n; l++)
        {
            for (c = 0; c < n; c++)
                printf(" MT( %d , %d ) = %lg\n", l, c, MT[l][c]);
            printf(" MTy( %d ) = %lg\n", l, MTy[l]);
            printf("**********************************************\n");
            GETCH();
        }

        printf("********** Debut Calculs ************************************\n");

        aug = (Ldbl*)calloc(n * (n + 1), sizeof(Ldbl));
        if (!aug)
        {
            printf("Memoire insuffisante !\n");
            exit(1);
        }

        for (l = 0; l < n; l++)
        {
            for (c = 0; c < n; c++)
                aug[l * (n + 1) + c] = MT[l][c];
            aug[l * (n + 1) + n] = MTy[l];
        }

        if (GSolve(aug, coeffs, n))
        {
            printf("**********  Fin Calculs  ************************************\n");
        }
        else
        {
            printf("**********  Matrice Singuliere !  ***************************\n");
        }

        for (l = 0; l < n; l++)
        {
            for (c = 0; c < n; c++)
            {
                MT[l][c] = aug[l * (n + 1) + c];
                printf(" MT( %d , %d ) = %lg\n", l, c, MT[l][c]);
            }
            MTy[l] = aug[l * (n + 1) + n];
            printf(" MTy( %d ) = %lg\n", l, MTy[l]);
            printf("**********************************************\n");
            GETCH();
        }

        free(aug);

        for (c = 0; c < n; c++)
            printf(" K( %d ) = %lg\n", c, coeffs[c]);
        printf("**********************************************\n");
        GETCH();

        for (l = 0; l < n; l++)
        {
            y = 0;
            for (c = 0; c < n; c++)
                y += coeffs[c] * MTV[l][c];
            printf(" Y( %d ) = %lg ,Y'( %d ) = %lg\n", l, MTVy[l], l, y);
        }

        txt = GETCH();
    }

    return 0;
}
