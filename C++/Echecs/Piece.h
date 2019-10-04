/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

//#include "Echiquier.h"
class Echiquier;

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Piece
{
   protected:
    int  m_x;
    int  m_y;
    bool m_white;

   public:
    Piece();
    virtual ~Piece();
    Piece( int x, int y, bool white );
    Piece( const Piece &autre );
    Piece & operator=( const Piece &autre );
    virtual bool mouvementValide( Echiquier &e, int x, int y );
    void    init( int x, int y, bool white );
    void    move( int x, int y );
    int     x() const;
    int     y() const;
    bool    isWhite() const;
    bool    isBlack() const;
    void    affiche() const;
    virtual char codechar() const;
};

class Roi : public Piece
{
    public:
     Roi( bool white );
     bool mouvementValide( Echiquier &e, int x, int y );
     char codechar() const;
};

class Fou : virtual public Piece
{
    public:
     Fou( bool white, bool left );
     bool mouvementValide( Echiquier &e, int x, int y );
     char codechar() const;
};

class Tour : virtual public Piece
{
    public:
     Tour( bool white, bool left );
     bool mouvementValide( Echiquier &e, int x, int y );
     char codechar() const;
};

class Reine : public Tour, public Fou
{
    public:
     Reine( bool white );
     bool mouvementValide( Echiquier &e, int x, int y );
     char codechar() const;
};

#endif  // !defined Piece_h
