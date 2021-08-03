#include <Python.h>

/**
 * print_python_float -  prints some basic info about Python float objects.
 * @p: pointer to PyObject
 **/

void print_python_float(PyObject *p)
{
	char *str;

	printf("[.] float object info\n");
	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object");
		fflush(stdout);
		return;
	}
	str = PyOS_double_to_string(((PyFloatObject *)(p))->ob_fval, 'r', 0,
			Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", str);
	fflush(stdout);
}


/**
 * print_python_bytes - prints some basic info about Python bytes objects.
 * @p: pointer to PyObject
 **/

void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size;
	char *str;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
		return;
	}
	size = PyBytes_Size(p);
	str = ((PyBytesObject *)p)->ob_sval;
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);
	printf("  first %ld bytes:", size < 10 ? size + 1 : 10);
	for (i = 0; i < 10 && i <= size; i++)
		printf(" %02hhx", str[i]);
	printf("\n");
	fflush(stdout);
}



/**
 * print_python_list - prints info about python list object
 * @p: pointer to PyObject
 */

void print_python_list(PyObject *p)
{
	Py_ssize_t i, size;
	PyObject *ob;

	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object");
		fflush(stdout);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)(p))->allocated);
	for (i = 0; i < size; i++)
	{
		ob = PyList_GET_ITEM(p, i);
		printf("Element %ld: %s\n", i,
		       ob->ob_type->tp_name);
		if (PyBytes_Check(ob))
			print_python_bytes(ob);
		else if (PyFloat_Check(ob))
			print_python_float(ob);
	}
	fflush(stdout);
}
