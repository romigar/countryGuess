#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

#include "city.h"
#include "country.h"
#include "continent.h"



uint32_t DistanceDeDamerauLevenshtein(QByteArray reference, QByteArray candidat)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int a = reference.size()+1;
    int b = candidat.size()+1;
    int d[a][b];

    std::cout<<std::endl;

    std::cout<<"L"<<i<<"\t| ";
    for (i = 0; i < a ; i++) {
        d[i][0] = i;
        std::cout<<d[i][j]<<" ";
    }
    std::cout<<" |"<<std::endl;
    for (j = 0; j < b ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j < b ; j++)
    {
        std::cout<<"L"<<j<<"\t| ";
        std::cout<<d[0][j]<<" ";

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

            std::cout<<d[i][j]<<" ";
        }
        std::cout<<" |"<<std::endl;
    }
    return d[a-1][b-1];
}



static uint32_t distanceDamerauLevenshtein(const char* str1,const int size1,const char* str2,const int size2)
{
    std::cout<< "size1 : " << size1 << std::endl;
    std::cout<< "size2 : " << size2 << std::endl;
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int d[size1+1][size2+1];



    std::cout<<"_ | _ ";
    for (i = 0; i < size1 ; i++) {
        std::cout<<str1[i]<<" ";
    }
    std::cout<<" |"<<std::endl;
    std::cout<<"_ | ";
    i=0;

    for (i = 0; i <= size1 ; i++) {
        d[i][0] = i;
        std::cout<<d[i][j]<<" ";

    }
    std::cout<<" |"<<std::endl;

    for (j = 0; j <= size2 ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j <= size2 ; j++)
    {
        std::cout<<str2[j-1]<<" | ";
        std::cout<<d[0][j]<<" ";
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
            std::cout<<d[i][j]<<" ";
        }
        std::cout<<" |"<<std::endl;
    }
    std::cout<<d[size1][size2]<<std::endl;
    return d[size1][size2];
}



bool result(QByteArray word1, QByteArray word2)
{
    std::cout<< word1.constData() << "|" << word2.constData() << std::endl;

    float tolerance = 0.2;
    float result;
    int distance = DistanceDeDamerauLevenshtein(word1,word2);
    result = (float)distance/qMin(word1.size(),word2.size());

    if (result >= tolerance)
        std::cout<< "refused " << result << std::endl;
    else {
        std::cout<< "accepted " << result << std::endl;
    }
}

bool result(std::string word1, std::string word2)
{
    std::cout<< word1 << "|" << word2 << std::endl;

    float tolerance = 0.2;
    float result;
    int distance = distanceDamerauLevenshtein(word1.data(),word1.size(),word2.data(),word2.size());
    result = (float)distance/qMin(sizeof(word1),sizeof(word2));

    if (result >= tolerance)
        std::cout<< "refused " << result << std::endl;
    else {
        std::cout<< "accepted " << result << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const std::list<std::string> &list)
{
    for (auto const &i: list) {
        os << i << std::endl;
    }
    return os;
}

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int myrandom (int i) { return std::rand()%i;}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<< "start"<<std::endl;

    std::string str1 = "salutations";
    std::string str2 = "salutatoins";
    std::string str3 = "salutatoin";
    std::string str4 = "salutatain";


    result(str1,str1);
    result(str1,str2);
    result(str1,str3);
    result(str1,str4);


    return 0;
}

