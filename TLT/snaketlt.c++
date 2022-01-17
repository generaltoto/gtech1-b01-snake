#include <stdio.h>
#include <iostream>
using namespace std;

class MClasse {
  private:
    int a;

  public:
    MClasse() {     // <- Constructeur, ici initialise le membre =a=
      this->a = 0;
    }

    ~MClasse() {     // <- Destructeur, ici ne fait rien...
    }

    int add(int b) {  // méthode publique car définie dans le bloc 'public:'
      return this-> a + b; // "this" est un pointeur sur l'objet lui-même, "->" permet d'accéder à ses membres
    }          // membre privé car défini dans le bloc 'private:'
}; // Ne pas oublier le ';' final !

int main(void){
  MClasse ABC ;
  ABC.add(5);
  cout << "OUI\n";

  return 0;
}