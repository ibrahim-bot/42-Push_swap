/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:45:24 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/12 16:39:13 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void fusion(int tab[], int debut, int milieu, int fin)
{
	for (int i = 0; i < 6; i++)
			printf("%d ", tab[i]);
		printf("\n");
	int n1 = milieu - debut + 1;
	int n2 = fin - milieu;
	
	int G[n1], D[n2];
	
	for (int i = 0; i < n1; i++)
		G[i] = tab[debut + i];
	for (int j = 0; j < n2; j++)
		D[j] = tab[milieu + 1 + j];
	
	// maintient trois pointeurs, un pour chacun des deux tableaux et un pour
	// maintenir l'index actuel du tableau trié final
	int i, j, k;
	i = 0;
	j = 0;
	k = debut;
	
	while (i < n1 && j < n2)
	{
		if (G[i] <= D[j])
		{
			tab[k] = G[i];
			i++;
		}
		else
		{
			tab[k] = D[j];
			j++;
		}
		k++;
	}
	
	// Copiez tous les éléments restants du tableau non vide
	while (i < n1)
	{
		tab[k] = G[i];
		i++;
		k++;
	}
	
	while (j < n2)
	{
		tab[k] = D[j];
		j++;
		k++;
	}
}
	
// Tri par fusion
void triFusion(int tab[], int debut, int fin)
{
	if (debut < fin)
	{        
		// Trouvez le point milieu pour diviser le tableau en deux moitiés
		int m = (debut + fin) / 2;
	
		printf("m = %d\n", m);

		triFusion(tab, debut, m);
		triFusion(tab, m + 1, fin);
		// // Fusionnez les deux moitiés triées
		fusion(tab, debut, m, fin);
	}
}
	
void afficher(int tab[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	printf("\n");
}
	
	
int main()
{
	int tab[] = {6, 5, 4, 3, 2, 1};
	int n = 6;
	
	triFusion(tab, 0, n - 1);
	
	//printf("Tableau trié: \n");
	//afficher(tab, n);
}