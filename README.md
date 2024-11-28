
   
			BIENVENUE SUR MON README.TXT

Compilation des différents exécutables :

	Compiler le programme principal : make
	Compiler le PDF Doxygene : DoxLatex/make
	Compiler le Diaporama Beamer : Beamer/make
	Compiler la génération de fichiers tests : generation_fichier_test/make


			Création des fichiers tests

-> Aller dans le dossier generation_fichier_test

Utilisation : ./creation_logs.sh <nom_du_dossier_a_creer> <nombre_de_points> <nombre_de_classe>

Exemple : ./creation_logs.sh 10pts 10 2


		VOICI LES RÈGLES DU JEU ET LES DIFFÉRENTS MODES :

    1.MODE KPPV :

    Permet de faire les Kppv de plusieurs manières différentes (LE CHOIX DU KPPV EST MODIFIABLE).
    	1.1 Mode voisinage qui nous donne les Kppv avec la rapidité d'une liste utilisant le Tri Fusion.
    	1.2 Mode voisinage avec prise de décision qui nous donne les Kppv avec la classe majoritaire avec l'option de rajouter le point qu'on vient de mettre.
    	1.3 Mode voisinage Arbre qui nous donne les Kppv avec la rapidité d'un arbre KD.
    	1.4 Mode voisinage Arbre avec prise de décision qui nous donne les Kppv avec la classe majoritaire avec l'option de rajouter le point qu'on vient de mettre.

    2.MODE CRÉATION :

    	2.1 Permet de rajouter des points sur l'écran de la classe choisie.
    	2.2 Permet de charger un fichier contenant des Kppv.
    	2.3 Donne la possibilité de supprimer le dernier point ajouté.
    	2.4 Permet de sauvegarder sa configuration de points dans un fichier nommé : save.txt
