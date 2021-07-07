#include "laps.h"

/**
 * race_state -  keeps track of the number of laps
 * made by several cars in a race.
 * @id: array of int representing the “identifier” of each car.
 * @size: size of this array
 **/

void race_state(int *id, size_t size)
{
	static car_t *cars;
	car_t *tmp, *next;
	size_t i;

	if (size == 0)
	{
		while (cars)
		{
			next = cars->next;
			free(cars);
			cars = next;
		}
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (check_new_car(cars, id[i]))
			cars = add_new_car(cars, id[i]);
		else
			add_lap(cars, id[i]);
	}
	printf("Race state:\n");
	for (tmp = cars; tmp; tmp = tmp->next)
		printf("Car %d [%d laps]\n", tmp->id, tmp->laps);
}

/**
 * add_new_car - adds a new car
 * @cars: pointer to list of cars
 * @id: id of the car
 * Return: pointer to cars
 **/

car_t *add_new_car(car_t *cars, int id)
{
	car_t *prev, *tmp, *new_car;

	prev = NULL;
	tmp = cars;

	new_car = (car_t *)malloc(sizeof(car_t));

		if (!new_car)
			return (NULL);
	new_car->id = id;
	new_car->laps = 0;
	new_car->next = NULL;

	printf("Car %d joined the race\n", new_car->id);
	while (tmp)
	{
		if (new_car->id < tmp->id)
		{
			if (prev)
				prev->next = new_car;
			else
				cars = new_car;
			new_car->next = tmp;
			return (cars);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (cars)
	{
		prev->next = new_car;
		return (cars);
	}
	return (new_car);
}

/**
 * check_new_car - checks if new car is added
 * @cars: pointer to cars
 * @id: id of the car to check
 * Return: returns 1 if new car otherwise 0
 */

int check_new_car(car_t *cars, int id)
{
	car_t *new_car = cars;

	while (new_car)
	{
		if (new_car->id == id)
			return (0);
		new_car = new_car->next;
	}
	return (1);
}

/**
 * add_lap - adds a lap to a given car
 * @cars: pointer to cars list
 * @id: id of the car
 **/
void add_lap(car_t *cars, int id)
{
	car_t *tmp;

	for (tmp = cars; tmp; tmp = tmp->next)
	{
		if (tmp->id == id)
			tmp->laps++;
	}
}
