#ifndef INC_3_1_CIRCUMFERENCE_H
#define INC_3_1_CIRCUMFERENCE_H

class Circumference{
    double radius;

public:
    double areaOfCirc();
    double circumferenceOfCirc();
    void interface();
    void setRadius();
    double getRadius();
    Circumference(){
        radius = 0;
    }
};
#endif
