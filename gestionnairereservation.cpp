#include "gestionnairereservation.h"
#include <QDebug>

void gestionnairereservation::ajouterReservation(const QString& nom, const QString& prenom, const QString& email, const QString& num_reserv, const QString& cin)
{
    Reservation reservation(nom,prenom,email, num_reserv , cin);

}

void gestionnairereservation::afficherReservations() {
    if (listeReservations.isEmpty()) {
        qDebug() << "Aucune réservation n'a été effectuée.";
    } else {
        qDebug() << "Liste des réservations :";
        for (const Reservation& res : listeReservations) {
            qDebug() << "Nom : " << res.getnom();
            qDebug() << "Prénom : " << res.getprenom();
            qDebug() << "Email : " << res.getemail();
            qDebug() << "Référence : " << res.getnum_reserv();
            qDebug() << "CIN : " << res.getcin();
            qDebug() << "------------------------";
        }
    }
}

void gestionnairereservation::supprimerReservation(const QString& num_reserv) {
    for (int i = 0; i < listeReservations.size(); ++i) {
        if (listeReservations[i].getnum_reserv() == num_reserv) {
            listeReservations.removeAt(i);
            qDebug() << "Réservation avec référence " << num_reserv << " supprimée.";
            return;
        }
    }
    qDebug() << "Réservation avec référence " << num_reserv << " non trouvée.";
}
