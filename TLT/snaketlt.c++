class MClasse {
  private:
  int a;

  public:
    int add(int b) {  // méthode publique car définie dans le bloc 'public:'
      return this-> a + b; // "this" est un pointeur sur l'objet lui-même, "->" permet d'accéder à ses membres
    }          // membre privé car défini dans le bloc 'private:'
}; // Ne pas oublier le ';' final !

MClasse ABC ;

void main(){
  ABC.add(5);
}