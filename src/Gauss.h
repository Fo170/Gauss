#ifndef GAUSS_H
#define GAUSS_H

#define EPS 1e-308
#define TRUE 1
#define FALSE 0

int GSolve(Ldbl *aug, Ldbl *c, int n)
{
    int i, j, k, maxrow;
    Ldbl tmp;

    for (i = 0; i < n; i++)
    {
        maxrow = i;
        for (j = i + 1; j < n; j++)
            if (fabsl(aug[j * (n + 1) + i]) > fabsl(aug[maxrow * (n + 1) + i]))
                maxrow = j;

        if (maxrow != i)
            for (k = i; k <= n; k++)
            {
                tmp = aug[i * (n + 1) + k];
                aug[i * (n + 1) + k] = aug[maxrow * (n + 1) + k];
                aug[maxrow * (n + 1) + k] = tmp;
            }

        if (fabsl(aug[i * (n + 1) + i]) < EPS)
            return FALSE;

        for (j = i + 1; j < n; j++)
        {
            tmp = aug[j * (n + 1) + i] / aug[i * (n + 1) + i];
            for (k = i; k <= n; k++)
                aug[j * (n + 1) + k] -= tmp * aug[i * (n + 1) + k];
        }
    }

    for (j = n - 1; j >= 0; j--)
    {
        c[j] = aug[j * (n + 1) + n];
        for (k = j + 1; k < n; k++)
            c[j] -= aug[j * (n + 1) + k] * c[k];
        c[j] /= aug[j * (n + 1) + j];
    }

    return TRUE;
}

#endif
