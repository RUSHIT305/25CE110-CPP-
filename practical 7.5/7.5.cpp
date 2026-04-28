#include <iostream>
#include <vector>
#include <string>
#include <memory>

// 1. Abstract Base Class
class GradingFramework {
protected:
    double marks;
    std::string studentName;

public:
    GradingFramework(std::string name, double m) : studentName(name), marks(m) {}
    virtual ~GradingFramework() {}

    // Pure virtual function - makes this class abstract
    virtual void computeGrade() = 0;

    std::string getName() const { return studentName; }
};

// 2. Undergraduate Class (Derived)
class Undergraduate : public GradingFramework {
public:
    Undergraduate(std::string name, double m) : GradingFramework(name, m) {}

    void computeGrade() override {
        std::string grade;
        if (marks >= 40) grade = "Pass";
        else grade = "Fail";
        std::cout << "UG Student: " << studentName << " | Marks: " << marks
                  << " | Grade: " << grade << std::endl;
    }
};

// 3. Postgraduate Class (Derived)
class Postgraduate : public GradingFramework {
public:
    Postgraduate(std::string name, double m) : GradingFramework(name, m) {}

    void computeGrade() override {
        std::string grade;
        // More rigorous standards
        if (marks >= 70) grade = "Distinction";
        else if (marks >= 50) grade = "Pass";
        else grade = "Fail";
        std::cout << "PG Student: " << studentName << " | Marks: " << marks
                  << " | Grade: " << grade << std::endl;
    }
};

int main() {
    // Collection of student records using polymorphism
    std::vector<std::unique_ptr<GradingFramework>> records;

    records.push_back(std::make_unique<Undergraduate>("Alice", 35));
    records.push_back(std::make_unique<Postgraduate>("Bob", 65));
    records.push_back(std::make_unique<Undergraduate>("Charlie", 80));

    // Polymorphic behavior
    for (const auto& student : records) {
        student->computeGrade();
    }

    return 0;
}
