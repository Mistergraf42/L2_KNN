#!/bin/bash

mkdir $1
echo "dossier $1 créé."

for i in {1..20};
 do
    nom="$1_$i.txt"
    touch "$1/$nom"
    ./generation "$1/$nom" $2 $3 2 > "$1/$nom"
    echo "Nous avons créer le fichier $nom"
done
