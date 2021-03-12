/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:16:17 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/12 15:17:20 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void triFusion(int tab[], int i, int j)
{
    int tmp[100];

    if (j <= i)
        return ;
  
    int m = (i + j) / 2;
    
    //triFusion(tab, i, m);             //trier la moitié gauche récursivement
    triFusion(tab, m + 1, j);         //trier la moitié droite récursivement

    int debut1 = i;                   //pg pointe au début du sous-tableau de gauche
    int debut2 = m + 1;               //pd pointe au début du sous-tableau de droite
    int compt;                        //compteur

    printf("i == |%d|\n", i);
    compt = i;
    // on boucle de i à j pour remplir chaque élément du tableau final fusionné
    while(compt <= j)
    {
        if (debut1 == m + 1)             //le pointeur du sous-tableau de gauche a atteint la limite
        {
            tmp[compt] = tab[debut2];
            debut2++;
        }
        else if (debut2 == j + 1)        //le pointeur du sous-tableau de droite a atteint la limite
        {
            tmp[compt] = tab[debut1];
            debut1++;
        }
        else if (tab[debut1] < tab[debut2]) //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
        {
            tmp[compt] = tab[debut1];
            debut1++;
        }
        else                        //le pointeur du sous-tableau de droite pointe vers un élément plus petit
        {
            tmp[compt] = tab[debut2];
            debut2++;
        }
        compt++;
    }
    
    
    //copier les éléments de tmp[] à tab[]
    compt = i;
    while (compt <= j)
    {
        tab[compt] = tmp[compt];
        compt++;
    }
}


int main()
{
    int nbr; 
    int i;
    int tab[100];
    
    printf("Entrez le nombre d'éléments dans le tableau: ");
    scanf("%d", &nbr);
    
    printf("Entrez %d entiers : ", nbr);
    for (i = 0; i < nbr; i++)
        scanf("%d", &tab[i]);
    

    printf("\nTableau pas trié : ");
    for (i = 0; i < nbr; i++)
        printf("%4d", tab[i]);
    printf("\n");
        

    triFusion(tab, 0, nbr - 1);
    

    
    printf("\nTableau     trié : ");
    for (i = 0; i < nbr; i++)
        printf("%4d", tab[i]);
    printf("\n");
    
    return 0;
}