class Fuel {
protected:
    string fuelType;
public:
    Fuel(string f) : fuelType(f) {}
};

class Brand {
protected:
    string brandName;
public:
    Brand(string b) : brandName(b) {}
};

class Car : public Fuel, public Brand {
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}
    void display() {
        cout << "Brand: " << brandName << " | Fuel: " << fuelType << endl;
    }
};
