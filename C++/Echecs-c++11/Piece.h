/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

//#include "Echiquier.h"
class Echiquier;

#include "Commun.h"

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Piece : public NonCopyable
{
protected:
  Coordinate m_c;
  Color m_white;

public:
  Piece();
  virtual ~Piece();
  Piece(const Coordinate &c, const Color &white);
  //Piece (const Piece & autre);
  //Piece & operator=(const Piece & autre);
  void move(const Coordinate &c);
  Coordinate c() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  virtual bool mouvementValide(const Echiquier &e, const Coordinate &c) = 0;
  virtual char getChar() const;
};

class Roi : public Piece
{
public:
  explicit Roi(const Color &white);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
  void roque();
};

class Pion : public Piece
{
public:
  Pion(const Color &white, const int pos);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
};

class Cavalier : public Piece
{
public:
  Cavalier(const Color &white, const bool left);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
};

class Fou : virtual public Piece
{
public:
  Fou(const Color &white, const bool left);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
};

class Tour : virtual public Piece
{
public:
  Tour(const Color &white, bool left);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
};

class Reine : public Fou, public Tour
{
public:
  explicit Reine(const Color &white);
  bool mouvementValide(const Echiquier &e, const Coordinate &c);
  char getChar() const;
};

#endif // !defined Piece_h
