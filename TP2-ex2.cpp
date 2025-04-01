#include <iostream>
#include <cmath>

using namespace std;

class Point {
    float x;
    float y;

public:
    
    Point(float a = 0.0, float b = 0.0) {
        x = a;
        y = b;
    }

    
    void saisie(float a, float b) {
        x = a;
        y = b;
    }

    
    void afficher() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

  
    void deplacer(float a, float b) {
        x += a;
        y += b;
    }

    
    float getX() {
        return x;
    }

    
    float getY() {
        return y;
    }

    
    bool comparer(Point p) {
        return (x == p.getX() && y == p.getY());
    }

    
    float distance(Point p) {
        return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
    }

    
    float distanceOrigine() {
        return sqrt(x * x + y * y);
    }
};

int main() {
   
    Point p1(2.0, 3.0);
    Point p2(2.0, 3.0);
    Point p3(1.0, 3.0);

    
    cout << "Coordonnées initiales des points : " << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    
    cout << "p1 et p2 sont identiques ? " << (p1.comparer(p2) ? "Oui" : "Non") << endl;
    cout << "p1 et p3 sont identiques ? " << (p1.comparer(p3) ? "Oui" : "Non") << endl;

    
    cout << "Distance de p1 à l'origine : " << p1.distanceOrigine() << endl;
    cout << "Distance entre p1 et p2 : " << p1.distance(p2) << endl;
    cout << "Distance entre p1 et p3 : " << p1.distance(p3) << endl;

  
    p2.deplacer(20, 13);
    cout << "Nouveau p2 après déplacement : ";
    p2.afficher();

   
    float d12 = p1.distance(p2);
    float d13 = p1.distance(p3);
    float d23 = p2.distance(p3);

    cout << "Les deux points les plus proches sont : ";
    if (d12 <= d13 && d12 <= d23) {
        cout << "p1 et p2" << endl;
    } else if (d13 <= d12 && d13 <= d23) {
        cout << "p1 et p3" << endl;
    } else {
        cout << "p2 et p3" << endl;
    }

    return 0;
}

