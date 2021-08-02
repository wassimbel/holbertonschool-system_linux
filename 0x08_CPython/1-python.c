#include <Python.h>

/**
 * print_python_list - prints info about python list object
 * @p: pointer to PyObject
 */

void print_python_list(PyObject *p)
{
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", PyList_Size(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)(p))->allocated);
	for (Py_ssize_t i = 0; i < PyList_Size(p); i++)
		printf("Element %lu: %s\n", i,
		       Py_TYPE(PyList_GET_ITEM(p, i))->tp_name);
}
