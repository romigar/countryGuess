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

//    result("iran","irna");
//    result("iran","ir");
/*
    std::srand ( unsigned ( std::time(0) ) );
    std::list<std::string> list = { "blue", "red", "green" };
    std::cout<<list;
    std::random_shuffle(list.begin(),list.end(),myrandom);
    */
/*
    std::vector<int> list {1,2,3,4,5,6,7,8,9,10};

    std::cout<< list.size() << std::endl;
    std::random_shuffle(list.begin(),list.end(),myrandom);
    std::cout<< list << std::endl;
    list.erase(list.begin()+2);
    list.erase(list.begin()+2);
    list.erase(list.begin()+2);
    list.erase(list.begin()+2);
    list.erase(list.begin()+2);
    std::cout<< list << std::endl;
    std::cout<< list.size() << std::endl;
    std::cout<< "end"<<std::endl;
    */

    std::srand(std::time(nullptr)); // use current time as seed for random generator




    city marseille(1,"Marseille",300000);
    city londres(2,"Londres",500000);
    city madrid(3,"Madrid",400000);
    country france(0,"France",70000000,"Europe",marseille);
    country espagne(0,"Espagne",50000000,"Europe",city(3,"Madrid",400000));
    country angleterre(0,"Angleterre",60000000,"Europe",marseille);
    std::vector<country> list {france,espagne,angleterre};
    continent europe("Europe",2,list);
    europe.display();
    europe.display_list_country_name();

    marseille = londres;
    france = espagne;

    std::random_shuffle(europe.list.begin(),europe.list.end());
    europe.display_list_country_name();
    return a.exec();
}

