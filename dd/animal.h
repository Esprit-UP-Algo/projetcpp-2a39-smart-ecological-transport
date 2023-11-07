#ifndef ANIMAL_H
#define ANIMAL_H
#include<QSqlQuery>
#include<QSqlQueryModel>

class Animal
{
    QString caracteristiques, sexe, reproduction,race,vaccination,sante;
    int identifiant,poids,age,date;
public:
    Animal(){}
    Animal(int,int,int,int,QString,QString,QString,QString,QString,QString);

    QString getcaracteristiques(){return caracteristiques;}
     QString getsexe(){return sexe;}
      QString getreproduction(){return reproduction;}
       QString getrace(){return race;}
        QString getvaccination(){return vaccination;}
         QString getsante(){return sante;}
         int getidentifiant(){return identifiant;}
         int getpoids(){return poids;}
         int getage(){return age;}
         int getdate(){return date;}

         void setcaracteristiques(QString c){caracteristiques=c;}
         void setsexe(QString s){sexe=s;}
         void setreoroduction(QString r){reproduction=r;}
         void setrace(QString rc){race=rc;}
         void setvaccination(QString v){vaccination=v;}
         void setidentifiant(int id){this->identifiant=id;}
         void setpoids(int p){this->poids=p;}
         void setage(int a){this->age=a;}
         void setdate(int d){this->date=d;}
         bool ajouter();
         QSqlQueryModel * afficher();
         bool supprimer(int identifiant);
         bool rechercher(int identifiant);
         bool modifier();
};

#endif // ANIMAL_H
