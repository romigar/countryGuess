#include <QObject>
#include <QString>
#include "tools.h"




uint32_t DistanceDeDamerauLevenshtein(QString reference, QString candidat)
{
    int i = 0;
    int j = 0;
    int cout = 0;
    int sum = 0;
    int d[reference.size()][candidat.size()];

    for (i = 0; i < reference.size() ; i++)
    {
        for ( j = 0 ; j < candidat.size() ; j++)
        {
            if (reference.at(i) == candidat.at(j)){

            }
            else {
                cout++;
            }
            if ( (i>1) && (j>1) ) {                     // transposition
                if ( (reference.at(i) == candidat.at(j-1))
                     && (reference.at(i-1) == candidat.at(j)) ) {

                }
            }
        }
    }
    return 0;
}

/*
entier DistanceDeDamerauLevenshtein(caractere chaine1[1..longueurChaine1],
                                    caractere chaine2[1..longueurChaine2])
   // d est un tableau de longueurChaine1+1 rangées et longueurChaine2+1 colonnes
   // d est indexé à partir de 0, les chaînes à partir de 1
   déclarer entier d[0..longueurChaine1, 0..longueurChaine2]
   // i et j itèrent sur chaine1 et chaine2
   déclarer entier i, j, coûtSubstitution

   pour i de 0 à longueurChaine1
       d[i, 0] := i
   pour j de 0 à longueurChaine2
       d[0, j] := j

   pour i de 1 à longueurChaine1
      pour j de 1 à longueurChaine2
          si chaine1[i] = chaine2[j] alors coûtSubstitution := 0
                                     sinon coûtSubstitution := 1
           d[i, j] := minimum(
                                d[i-1, j  ] + 1,                 // effacement du nouveau caractère de chaine1
                                d[i,   j-1] + 1,                 // insertion dans chaine1 du nouveau caractère de chaine2
                                d[i-1, j-1] + coûtSubstitution   // substitution
                             )
           si(i > 1 et j > 1 et chaine1[i] = chaine2[j-1] et chaine1[i-1] = chaine2[j]) alors
               d[i, j] := minimum(
                                d[i, j],
                                d[i-2, j-2] + coûtSubstitution   // transposition
                             )

   renvoyer d[longueurChaine1, longueurChaine2]
*/


