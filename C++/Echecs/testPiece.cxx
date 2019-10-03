/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool
compare( const Piece & p, const Piece & q )
{
    return ( p.x() == q.x() ) && ( p.y() == q.y() );
}

Piece *
allouerPiece(int x, int y, bool white)
{
    Piece *ptr = new Piece( x, y, white );
    return ptr;

    /* FAUX : allocation statique sur la pile
    Piece tmp = Piece( x, y, white );
    return &tmp;
    */
}

/**
 * Programme principal
 */
int
main( int argc, char **argv )
{
    // instancie un objet p1 de type Piece
    Piece p1;
    // p1 est une piece blanche de coordonnees (3,3)
    p1.init( 3, 3, true );
    // constructeur special pour p2
    Piece p2( 4, 4, false );
    Piece p3 = p2;

    if ( p2.isBlack() )
        cout << "Une piece noire" << endl;
    p1.affiche();
    p2.affiche();

    p1 = p2;
    cout << ( compare( p1, p2 ) ? "memes coordonnees" : "coordonnees differentes" ) << endl;

    //Piece *ptr = new Piece( p2 );
    Piece * ptr = allouerPiece( 1, 1, false );

    delete ptr;
    /*
    Joueur jb(true);
    Joueur jn(false);
    jb.affiche();
    jn.affiche();
    */

    // les objets definis dans cette fonction sont automatiquement detruits.
    // Ex : p1
}
