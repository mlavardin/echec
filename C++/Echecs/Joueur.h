/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"

class Joueur {
private:
    Piece m_pieces[16];

public:
    Joueur(bool white);
    void affiche();
    bool isWhite();
};

#endif