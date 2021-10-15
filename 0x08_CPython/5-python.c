#include <Python.h>

/**
 * print_python_int - prints Python integers.
 * @p: pointer to PyObject
 * Return: void
 */

void print_python_int(PyObject *p)
{

	Py_ssize_t size, i;
	uint32_t *array;
	unsigned long x;

	if (PyLong_Check(p))
	{
		size = ((PyVarObject *) p)->ob_size;
		array = ((PyLongObject *) p)->ob_digit;
		if (size > 3 || (size == 3 && array[2] > 15))
		{
			printf("C unsigned long int overflow\n");
			return;
		}
		x = 0;
		for (i = 0; i < (size < 0 ? size * -1 : size); ++i)
			x += array[i] * (1L << (PyLong_SHIFT * i));
		if (size < 0)
			putchar('-');
		printf("%lu\n", x);
	}
	else
		printf("Invalid Int Object");
}
