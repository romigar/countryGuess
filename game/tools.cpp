#include <QObject>
#include <QString>
#include <iostream>
#include "tools.h"

/* ***************************************************************** */

static uint32_t distanceDamerauLevenshtein(QByteArray reference, QByteArray candidat)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int a = reference.size()+1;
    int b = candidat.size()+1;
    int d[a][b];

    for (i = 0; i < a ; i++) {
        d[i][0] = i;
    }
    for (j = 0; j < b ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j < b ; j++)
    {
        for (i = 1; i < a; i++)
        {
            if (reference.at(i) == candidat.at(j)){
                coutSubstitution = 0;
            }
            else {
                coutSubstitution = 1;
            }

            d[i][j] = qMin(
                        d[i-1][j] + 1 ,
                  qMin( d[i][j-1] + 1 ,
                        d[i-1][j-1] + coutSubstitution ));


            // transposition
            if ( (i > 1 && j > 1)
                 && (reference.at(i) == candidat.at(j-1))
                 && (reference.at(i-1) == candidat.at(j)) ) {
                d[i][j] = qMin( d[i][j] , d[i-2][j-2] + coutSubstitution);
            }
        }
    }
    return d[a-1][b-1];
}

/* ***************************************************************** */

static uint32_t distanceDamerauLevenshtein(char* str1, int size1, char* str2, int size2)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int d[size1][size2];

    for (i = 0; i < size1 ; i++) {
        d[i][0] = i;
    }
    for (j = 0; j < size2 ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j < size2 ; j++)
    {
        for (i = 1; i < size1 ; i++)
        {
            if (str1[i] == str2[j]){
                coutSubstitution = 0;
            }
            else {
                coutSubstitution = 1;
            }

            d[i][j] = qMin(
                        d[i-1][j] + 1 ,
                  qMin( d[i][j-1] + 1 ,
                        d[i-1][j-1] + coutSubstitution ));


            // transposition
            if ( (i > 1 && j > 1)
                 && (str1[i] == str2[j-1])
                 && (str1[i-1] == str2[j]) ) {
                d[i][j] = qMin( d[i][j] , d[i-2][j-2] + coutSubstitution);
            }
        }
    }
    return d[size1][size2];
}

/* ***************************************************************** */

static double relativeDistance(QByteArray reference, QByteArray candidat)
{
    return (double)distanceDamerauLevenshtein(reference,candidat)/(double)reference.size();
}

/* ***************************************************************** */

bool validDistance(QByteArray reference, QByteArray candidat, double tolerance)
{
    return (relativeDistance(reference,candidat) <= tolerance);
}

/* ***************************************************************** */

static uint32_t distanceDamerauLevenshtein(const char* str1,const int size1,const char* str2,const int size2)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int d[size1+1][size2+1];


    for (i = 0; i <= size1 ; i++) {
        d[i][0] = i;
    }

    for (j = 0; j <= size2 ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j <= size2 ; j++)
    {
        for (i = 1; i <= size1 ; i++)
        {
            if (str1[i-1] == str2[j-1]){
                coutSubstitution = 0;
            }
            else {
                coutSubstitution = 1;
            }

            d[i][j] = std::min( d[i-1][j] + 1 ,
                      std::min( d[i][j-1] + 1 ,
                        d[i-1][j-1] + coutSubstitution ));


            // transposition
            if ( (i > 1 && j > 1)
                 && (str1[i-1] == str2[j-2])
                 && (str1[i-2] == str2[j-1]) ) {
                d[i][j] = std::min( d[i][j] , d[i-2][j-2] + coutSubstitution);
            }
        }
    }
    return d[size1][size2];
}

/* ***************************************************************** */

static double relativeDistance(std::string reference, std::string candidat)
{

    std::cout<< "distance" << (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())<<std::endl;
    std::cout<< "distance relative" << (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())/(double)reference.size()<<std::endl;

    return (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())/(double)reference.size();
}

/* ***************************************************************** */

bool validDistance(std::string reference, std::string candidat, double tolerance)
{
    return (relativeDistance(reference,candidat) <= tolerance);
}

