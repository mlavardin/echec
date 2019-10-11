/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(const Piece &p1, const Piece &p2)
{
  return (p1.c().x() == p2.c().x()) && (p1.c().y() == p2.c().y());
}

/**
 * Programme principal
 */
int main(int argc, char **argv)
{
  /*
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );
  Piece p2( 4, 4, false);

  if (p1.isWhite())
    cout << "Piece blanche" << endl;
  else
    cout << "Piece noir" << endl;

  cout << "Piece " << ((p2.isBlack())?"noir":"blanche") << endl;

  p1.affiche();
  p2.affiche();

  if (compare(p1,p2))
    cout << "memes positions" << endl;
  else
    cout << "positions differentes" << endl;

  Piece p3=p1; // constructeur par copie
  p3=p2; // operateur d'affectation

  //Piece tbl[4];
  */

  //Joueur jb(true);
  //Joueur jn(false);
  //Joueur j; // interdit par la classe abstraite

  JoueurBlanc jb;
  JoueurNoir jn;
  jb.affiche();
  jn.affiche();

  Echiquier e;
  jb.placerPieces(e);
  jn.placerPieces(e);

  Roi rb(Color::colorWhite);
  Roi rn(Color::colorBlack);
  Reine qb(Color::colorWhite);
  Reine qn(Color::colorBlack);

  Coordinate c(6, 6);
  Piece *ptr;
  ptr = (Piece*) &rb;
  ptr->mouvementValide(e, c);
  //ptr->roque(); interdit
  Roi *rptr = dynamic_cast<Roi *>(ptr);
  if (rptr != nullptr)
    rptr->roque();
  qb.mouvementValide(e, c);

  /*
  e.enleverPiece(5,1);
  e.placer(ptr);
  ptr=&rn;
  e.enleverPiece(5,8);
  e.placer(ptr);
  e.enleverPiece(4,1);
  e.placer(&qb);
  e.enleverPiece(4,8);
  e.placer(&qn);
  */

  e.affiche();

  //Echiquier f=e; Echiquier non copyable
  //Echiquier f; f=e; Echiquier non affectable
  //idem pour JoueurBlanc, JoueurNoir
  //rb=rn; Piece non copiable (si on retire le constructeur par copie et l'operateur d'affectation)

  // les objets definis dans cette fonction sont automatiquement detruits.
  // Ex : p1
}
