#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

	//Variable
    int pvMonstre = 100;
	int pvJoueur = 100;
	int pmMonstre = 50;
	int pmJoueur = 50;
	int actionJoueur;
	int actionMonstre;
	int tamponJoueur = 0;
	int tamponMonstre = 0;
	int tamponPoisonJoueur = 0;
	int tamponPoisonMonstre = 0;

	
	//Fonction pour l'aléatoire
	int a = 0;
	int b = 100;
	int rand_a_b(int a, int b){
		return rand()%(b-a) +a;
	}

	//DEBUT

	printf("\n Bienvenu cher aventurier ! Il s'agira ici de prendre des decisions d'actions qui vous seront proposees lors de la rencontre d'un monstre \n");
	
	//Affichage des points de vie et des manas du joueur
	printf("\n Au depart vous avez: %d Points de vie \n",pvJoueur);
	printf("Ainsi que: %d points de manas \n",pmJoueur);
	printf("\n Attention ! Un monstre vous attaque !\n");
	
	while (pvMonstre > 0 && pvJoueur > 0){
		
		//TOUR DU JOUEUR
		
		//dégats infligés
		if (tamponPoisonJoueur == 1){
			pvJoueur -= 10;
		}
		
		//Affichage de la vie et des manas du joueur
		printf("\n Il VOUS reste %d/100 de points de vie \n",pvJoueur);
		printf(" Il VOUS reste %d/50 de manas \n",pmJoueur);
		
		// Réinitialisation du tampon joueur
		tamponJoueur = 0;
		
		// Régénération du Mana
		if (pmJoueur < 50){
			pmJoueur = pmJoueur + 1;
		}
		
		//Choix des actions disonibles
		printf("\nC'est a vous ! Faites le bon choix ! Saisissez votre action : \n");
		printf("\n /1/ Attaquer  /2/ Se Defendre /3/ Empoisonner /4/ Se soigner\n");
		scanf("%d", &actionJoueur);
		
		//Attaque
		if (actionJoueur == 1){
			printf("\n Vous le touchez dans une attaque au corps a corps \n");
			if (tamponMonstre == 1){
				//degats divisés par 4 si action de defense au dernier tour
				printf ("\n Vous lui faites moins de degats a cause de son bouclier, malin le nain !\n");
				pvMonstre -= 10/4;
			}	else { 
				pvMonstre -= 10;
			}
		}
		
		//Défense
		if (actionJoueur == 2){
			tamponJoueur = 1;
			printf("Vous vous munissez de votre bouclier\n");
			}
		
		//Poison
		if (actionJoueur == 3){
			if(pmJoueur > 4){
				printf("Une hora se forme autour du monstre vous l'avez empoisonne\n");
				tamponPoisonMonstre = 1;
				pmJoueur -= 5;
			}else{
				printf("\n Oh mince ! Le sort echoue  \n");
			}
		
		}
		
		//Antidote
		if (actionJoueur == 4){
			if(pmJoueur > 4){
				printf("Vous vous soignez : ah ! ca va mieux !\n");
				tamponPoisonJoueur = 0;
				pmJoueur -= 5;
			}else{
				printf("\nVous ne parvenez pas a vous soigner\n");
			}
		}
		
		
		printf("\n          PROCHAIN TOUR              \n");
		
		//TOUR DU MONSTRE
		
		//DEGATS DU POISON
		if (tamponPoisonMonstre == 1){
			pvMonstre -= 10;
		}
		
		
		//Affichage des points de vie du monstre
		printf("\n Le MONSTRE est a %d/100 de points de vie ",pvMonstre);
		printf ("  et il lui reste %d/50 de manas",pmMonstre);
		
		
		// Reinitialisation du tampon Monstre
		tamponMonstre = 0;
		
		// régénération du mana
		if (pmMonstre < 50){
			pmMonstre = pmMonstre + 1;
		}
		
		// action aleatoire du monstre
		actionMonstre = rand_a_b(a, b);
	
		// Attaque
		if (actionMonstre < 44){
			printf("\nLe Monstre vous attaque!\n");
			if (tamponJoueur == 1){
				//degats divisés par 4 si action de defense au dernier tour
				printf ("\n Il vous inflige moins de degats : on ne joue pas avec le danger ,vous l'avez compris avec votre bouclier\n");
				pvJoueur -= 10/4;
			}else{
				pvJoueur -= 10;
			}
		}
		
		//defense
		if (actionMonstre > 45 && actionMonstre < 79){
			tamponMonstre = 1;
			printf("\nLe monstre ne se laisse pas faire, il se defend !\n");
		}
		
		//Sort
		if(actionMonstre > 80 && pmMonstre >= 5){
			if (tamponPoisonMonstre != 1){
				//poison
				if(tamponPoisonJoueur == 0){
					printf("Vous etes empoisonne!\n");
					tamponPoisonJoueur = 1;
					pmMonstre -= 5;
				}else{
					printf("\nLe monstre a tente de vous empoisonner");
				}
			}else{
				//antidote
				printf("Le monstre se soigne: votre poison ne l'a pas atteint\n");
				tamponPoisonMonstre = 0;
				pmMonstre -= 5;
			}
		}else{
			if(actionMonstre > 80 && pmMonstre < 5){
				printf("\n Le monstre attend le bon moment pour effectuer une action, vous vous sentez traque");
			}
		}
		
		
		printf("\n          PROCHAIN TOUR              \n");
	}
		printf("\n FIN DU JEU \n");
	//Fin
}
