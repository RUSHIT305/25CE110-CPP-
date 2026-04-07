#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    // move function with chaining
    Point& move(int dx, int dy)
    {
        x += dx;
        y += dy;
        return *this;   // return current object
    }

    void display()
    {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

// pass-by-reference using pointer
void updatePoint(Point *p)
{
    p->move(5, 5);   // modifies original object
}

int main()
{
    Point p(2, 3);

    cout << "Original: ";
    p.display();

    // chaining using this pointer
    p.move(2, 3).move(-1, 4);

    cout << "After chaining moves: ";
    p.display();

    // pass-by-reference using pointer
    updatePoint(&p);

    cout << "After pointer update: ";
    p.display();

    return 0;
}
