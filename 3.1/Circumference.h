#ifndef INC_3_1_CIRCUMFERENCE_H
#define INC_3_1_CIRCUMFERENCE_H

class Circumference{
    double radius;

public:
    Circumference();
    double areaOfCirc() const;
    double circumferenceOfCirc() const;
    void interface();
    void setRadius();
    double getRadius() const;
    static void displayData(double radius);
    static void displayData(double radius, double area, double circumference);
    Circumference operator+ (double value) const;
    double* operator&();

};
#endif
