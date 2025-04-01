#include <iostream>
#include <string>

using namespace std;

class Etudiant {
private:
    int matricule;
    string nom;
    int nbrNots;
    float *tabNots;
    static int n;

public:
    
    Etudiant() {
        matricule = 0;
        this->nom = "";
        nbrNots = 0;
        tabNots = new float[nbrNots];
    }

   
    Etudiant(string nomE, int nb) {
        n++;
        matricule = n;
        this->nom = nomE;
        nbrNots = nb;
        tabNots = new float[nbrNots];

      
        for (int i = 0; i < nbrNots; i++) {
            tabNots[i] = 0.0;
        }
    }

    void saisirNotes() {
        cout << "Saisir les " << nbrNots << " notes de l'etudiant " << nom << ":" << endl;
        for (int i = 0; i < nbrNots; i++) {
            cout << "Note " << i + 1 << ": ";
            cin >> tabNots[i];
        }
    }

    float calculerMoyenne() const {
        if (nbrNots == 0) return 0; 
        float somme = 0;
        for (int i = 0; i < nbrNots; i++) {
            somme += tabNots[i];
        }
        return somme / nbrNots;
    }

    bool admis() const {
        return calculerMoyenne() >= 10;
    }

    float getMaxNote() const {
        float maxNote = tabNots[0];
        for (int i = 1; i < nbrNots; i++) {
            if (tabNots[i] > maxNote) {
                maxNote = tabNots[i];
            }
        }
        return maxNote;
    }

    float getMinNote() const {
        float minNote = tabNots[0];
        for (int i = 1; i < nbrNots; i++) {
            if (tabNots[i] < minNote) {
                minNote = tabNots[i];
            }
        }
        return minNote;
    }

    float getQuota() const {
        int count = 0;
        for (int i = 0; i < nbrNots; i++) {
            if (tabNots[i] >= 10) {
                count++;
            }
        }
        return (nbrNots == 0) ? 0 : (count * 100.0 / nbrNots);
    }

    void affiche() const {
        cout << "\nMatricule: " << matricule << endl;
        cout << "Nom: " << nom << endl;
        cout << "Nombre de notes: " << nbrNots << endl;
        cout << "Notes: ";
        for (int i = 0; i < nbrNots; i++) {
            cout << tabNots[i] << " ";
        }
        cout << endl;
        cout << "Moyenne: " << calculerMoyenne() << endl;
        cout << "Note maximale: " << getMaxNote() << endl;
        cout << "Note minimale: " << getMinNote() << endl;
        cout << "Quota (notes >= 10): " << getQuota() << "%" << endl;
        cout << "Resultat: " << (admis() ? "Admis" : "Non admis") << endl;
    }
};

int Etudiant::n = 0;

int main() {
    string nom;
    int nbNotes;

    cout << "Entrez le nom de l'etudiant: ";
    getline(cin, nom);
    cout << "Entrez le nombre de notes: ";
    cin >> nbNotes;
  
    Etudiant etu1(nom, nbNotes);

    etu1.saisirNotes();

    etu1.affiche();

    return 0;
}

