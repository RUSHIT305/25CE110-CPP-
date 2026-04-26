#include <iostream>
#include <vector>
using namespace std;

// 🔷 Base Class
class Shape {
private:
    double radius;  // encapsulated

public:
    // Setter
    void setRadius(double r) {
        if (r > 0)
            radius = r;
        else
            radius = 0;
    }

    // Getter
    double getRadius() const {
        return radius;
    }
};

// 🔷 Derived Class
class Circle : public Shape {
public:
    double calculateArea() const {
        const double PI = 3.14159;
        return PI * getRadius() * getRadius();
    }
};

int main() {
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    // =========================
    // 🔹 STATIC METHOD
    // =========================
    cout << "\n--- Static Array Method ---\n";

    Circle staticCircles[100]; // fixed size (limit = 100)

    for (int i = 0; i < n; i++) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static Array):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1
             << " Area = " << staticCircles[i].calculateArea()
             << endl;
    }

    // =========================
    // 🔹 DYNAMIC METHOD (vector)
    // =========================
    cout << "\n--- Dynamic Vector Method ---\n";

    vector<Circle> dynamicCircles;

    for (int i = 0; i < n; i++) {
        Circle c;
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        c.setRadius(r);
        dynamicCircles.push_back(c);
    }

    cout << "\nAreas (Dynamic Vector):\n";
    for (int i = 0; i < dynamicCircles.size(); i++) {
        cout << "Circle " << i + 1
             << " Area = " << dynamicCircles[i].calculateArea()
             << endl;
    }

    return 0;
}
