#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Car
{
    int year;
    char* brand;
    char* model;
};

void startCar(const struct Car *car) {
    printf("Starts the %s's engine...", car->brand);
}

struct Car createCar(int year, const char* brand, const char* model) {
    struct Car car;
    car.year = year;

    car.brand = malloc(strlen(brand) + 1);
    car.model = malloc(strlen(model) + 1);

    if (car.brand != NULL && car.model != NULL) {
        strcpy(car.brand, brand);
        strcpy(car.model, model);
    }

    return car;
}

int main(int argc, char const *argv[])
{
    struct Car car = createCar(2003, "Dodge", "Ram 1500");
    startCar(&car);
  
    free(car.brand);
    free(car.model);

    return 0;
}
