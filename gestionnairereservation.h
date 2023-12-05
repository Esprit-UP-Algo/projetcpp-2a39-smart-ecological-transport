<<<<<<< HEAD
#ifndef GESTIONNAIRERESERVATIONS_H
#define GESTIONNAIRERESERVATIONS_H

#include <QList>
#include "reservation.h"

class gestionnairereservation {
public:
    void ajouterReservation(const QString& nom, const QString& prenom,const QString& num_reserv,int date_de_debut,const QString& email,  const QString& cin);
    void afficherReservations();
    void supprimerReservation(const QString& num_reserv);


private:
    QList<Reservation> listeReservations;
};

#endif // GESTIONNAIRERESERVATIONS_H
=======
#ifndef GESTIONNAIRERESERVATIONS_H
#define GESTIONNAIRERESERVATIONS_H

#include <QList>
#include "reservation.h"

class gestionnairereservation {
public:
    void ajouterReservation(const QString& nom, const QString& prenom,const QString& num_reserv,int date_de_debut,const QString& email,  const QString& cin);
    void afficherReservations();
    void supprimerReservation(const QString& num_reserv);


private:
    QList<Reservation> listeReservations;
};

#endif // GESTIONNAIRERESERVATIONS_H
>>>>>>> d8e75cc0f0e315cdd085192fe209afe4a45db9f0
