#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>



using namespace std;

class lab
{

	char Mon_Laby[10][20];

	int Xbot,Ybot;
	int Xobjet,Yobjet;
	int Xrobot, Yrobot;
	int ecriture;
	char Nombre_fichiers;

	string nom_fichier;
	string level;
	string lvl;
	string chemin;


	public:

		void test();
		
		void logo();
		void affichage();
		void deplacement();
		void boucle();
	
};

void lab::test(){

	ifstream Mon_fichier("./Niveau/Niveau.lvl", ios::in);
	Mon_fichier.get(Nombre_fichiers);
	Mon_fichier.close();

	level = "Level";
	lvl = ".lvl";
	chemin = "./Niveau/";
	nom_fichier = chemin + level + Nombre_fichiers + lvl;

	//cout << Nombre_fichiers;
	ifstream fichier(nom_fichier.c_str(), ios::in);

	

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				fichier.get(Mon_Laby[i][j]);

				if(Mon_Laby[i][j] == 'a'){
					Mon_Laby[i][j] = ' ';
				}
			}
		}
	





	Xbot = 3;
	Ybot = 3;

	Xobjet = 8;
	Yobjet = 17;

	Xrobot = 7;
	Yrobot = 16;

	Mon_Laby[Xbot][Ybot] = 'x';
	Mon_Laby[Xobjet][Yobjet] = 'O'; 
	Mon_Laby[Xrobot][Yrobot] = 'm';


}

void lab::logo(){

	cout << "\t\t.___  _________   _____ _____________________" << "\n" << "\t\t|   |/   _____/  /  _  \\______   \\__    ___/" << "\n";
	cout << "\t\t|   |\\_____  \\  /  /_\\  \\|       _/ |    |" << "\n" << "\t\t|   |/        \\/    |    \\    |   \\ |    |" << "\n";
	cout << "\t\t|___/_______  /\\____|__  /____|_  / |____|" << "\n" << "\t\t            \\/         \\/       \\/           ";
	cout << "\n";


}

void lab::affichage(){

	logo();

	for(int i = 0; i < 10 ; ++i)
	{
		for(int j = 0; j < 20;++j)
		{
			cout << Mon_Laby[i][j];
		}

		
	}

	Mon_Laby[Xobjet][Yobjet] = 'O';



}

void lab::deplacement(){

	char deplacement;

	cout << "\n";
	cout << "deplacement" << endl;

	cin >> deplacement;


	if(deplacement == 'a'){

		if(Mon_Laby[Xbot+1][Ybot] != '&'){

			Mon_Laby[Xbot][Ybot] = ' ';
			Xbot++;
			Mon_Laby[Xbot][Ybot] = 'x';
		}

		if(Mon_Laby[Xrobot+1][Yrobot] != '&'){

			Mon_Laby[Xrobot][Yrobot] = ' ';
			Xrobot++;
			Mon_Laby[Xrobot][Yrobot] = 'm';
		}

	}else if(deplacement == 'z'){

		if(Mon_Laby[Xbot-1][Ybot] != '&'){

			Mon_Laby[Xbot][Ybot] = ' ';
			Xbot--;
			Mon_Laby[Xbot][Ybot] = 'x';
		}

		if(Mon_Laby[Xrobot-1][Yrobot] != '&'){

			Mon_Laby[Xrobot][Yrobot] = ' ';
			Xrobot--;
			Mon_Laby[Xrobot][Yrobot] = 'm';
		}

	}else if(deplacement == 'e'){

		if(Mon_Laby[Xbot][Ybot+1] != '&'){

			Mon_Laby[Xbot][Ybot] = ' ';
			Ybot++;
			Mon_Laby[Xbot][Ybot] = 'x';
		}

		if(Mon_Laby[Xrobot][Yrobot+1] != '&'){

			Mon_Laby[Xrobot][Yrobot] = ' ';
			Yrobot++;
			Mon_Laby[Xrobot][Yrobot] = 'm';
		}

	}else if(deplacement == 'r'){

		if(Mon_Laby[Xbot][Ybot-1] != '&'){

			Mon_Laby[Xbot][Ybot] = ' ';
			Ybot--;
			Mon_Laby[Xbot][Ybot] = 'x';
		}

		if(Mon_Laby[Xrobot][Yrobot-1] != '&'){

			Mon_Laby[Xrobot][Yrobot] = ' ';
			Yrobot--;
			Mon_Laby[Xrobot][Yrobot] = 'm';
		}

	}else{

		cout << "Valeur interdite" << endl;

	}
}

void lab::boucle(){

	while(1){

		
		deplacement();
		system("cls");
		affichage();

		if(Xbot == Xrobot and Yrobot == Ybot){

			cout << "\n" "Vous-avez perdus" << endl;
			break;
		}

		else if(Xbot == Xobjet and Ybot == Yobjet){

			cout << "\n" << "Vous-avez gagner" << endl;


			ofstream Mon_fichier("Niveau.lvl");

			Mon_fichier << char(Nombre_fichiers+1);
			Mon_fichier.close();
			
			break;
		}

	}

	cout << "fin" << endl;


		

}

int main(){

	system("cls");
	lab Mon_Laby;
	bool jouer = true;
	char rejouer;


	while(jouer){


		Mon_Laby.test();
		Mon_Laby.affichage();
		Mon_Laby.boucle();

		cout << "Voulez-vous continuer?" << endl;
		cin >> rejouer;

		if(rejouer == 'O' or rejouer == 'o'){

			cout << "on continue" << endl;
		}

		else if(rejouer == 'N' or rejouer == 'n'){

			cout << "sauvegarde.." << "\n" << "liaison terminer" << endl; 

		}

		system("cls");


	}




}