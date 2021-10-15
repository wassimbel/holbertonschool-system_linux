#include <Python.h>

/**
 * print_python_int - prints Python integers
 * @p: PyObject int
 */

void print_python_int(PyObject *p)
{
	Py_ssize_t i, j, k;
	PyLongObject *a, *b;
	digit *x, y, *z;
	twodigits v;
	int c;

	if (!p || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	b = (PyLongObject *)p;
	c = (33 * _PyLong_DECIMAL_SHIFT) /
		(10 * PyLong_SHIFT - 33 * _PyLong_DECIMAL_SHIFT);
	i = 1 + abs(Py_SIZE(b)) + abs(Py_SIZE(b)) / c;
	a = _PyLong_New(i);
	if (a == NULL)
		return;
	x = b->ob_digit;
	z  = a->ob_digit;
	i = 0;
	for (j = abs(Py_SIZE(b)); --j >= 0;)
	{
		y = x[j];
		for (k = 0; k < i; k++)
		{
			v = (twodigits)z[k] << PyLong_SHIFT | y;
			y = (digit)(v / _PyLong_DECIMAL_BASE);
			z[k] = (digit)(v - (twodigits)y * _PyLong_DECIMAL_BASE);
		}
		while (y)
			z[i++] = y % _PyLong_DECIMAL_BASE, y /= _PyLong_DECIMAL_BASE;
	}
	if (i == 0)
		z[i++] = 0;

	if (Py_SIZE(b) < 0)
		putchar('-');
	for (k = i; --k >= 0;)
	{
		if (k == i - 1)
			printf("%u", z[k]);
		else
			printf("%09u", z[k]);
	}
	printf("\n");
}
