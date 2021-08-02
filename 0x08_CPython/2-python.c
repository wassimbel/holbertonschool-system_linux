#include <Python.h>



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
		return;
	}
	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);
	printf("  first %ld bytes:", size < 10 ? size + 1 : 10);
	for (i = 0; i < 10 && i < size; i++)
		printf(" %2hhx", str[i]);
	printf("\n");
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
		return;

	size = PyList_Size(p);
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
	}
}
