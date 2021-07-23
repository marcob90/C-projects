#include <stdio.h>
#define IBM(m,h) ( (m) / ( (h) * (h) ) )

int main() {
    double mass;
    double height;
    
    printf("Enter body mass in kg: ");
    scanf("%lf", &mass);
    printf("Enter height in m: ");
    scanf("%lf", &height);
    
    printf("The IBM is %.2lf\n\n", IBM(mass,height));
    printf("BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater");

	return 0;
}
