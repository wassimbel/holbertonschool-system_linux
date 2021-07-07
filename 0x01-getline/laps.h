#ifndef _LAPS_H_
#define _LAPS_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct cars - list of racecars
 * @laps: number of laps of the car
 * @id: id of the car
 * @next: pointer to next car
 **/

typedef struct cars
{
	int id;
	int laps;
	struct cars *next;
} car_t;

void race_state(int *id, size_t size);
int check_new_car(car_t *cars, int id);
car_t *add_new_car(car_t **cars, int id);
void add_lap(car_t *cars, int id);
#endif /* _LAPS_H_  */
