/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include <memory>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

class Joueur : public NonCopyable
{
protected:
  // Piece m_pieces[16];
  vector< shared_ptr<Piece> > m_pieces;

public:
  explicit Joueur(const Color &white);
  virtual ~Joueur();
  virtual bool isWhite() = 0; // methode virtuelle pure
  void affiche() const;
  void placerPieces(Echiquier &e);
};

class JoueurBlanc : public Joueur
{
public:
  JoueurBlanc();
  bool isWhite();
};

class JoueurNoir : public Joueur
{
public:
  JoueurNoir();
  bool isWhite();
};

#endif /* Joueur_h */
