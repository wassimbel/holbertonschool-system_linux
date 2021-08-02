#include <Python.h>



/**
 * print_python_bytes - prints some basic info about Python bytes objects.
 * @p: pointer to PyObject
 **/

void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
	size = PyBytes_Size(p);
	printf("size: %ld\n", size);
	printf("trying string %s\n", PyBytes_AsString(p));
	printf("first %ld bytes", size < 10 ? size + 1 : 10);
	for (i = 0; i < 10 && i < size; i++)
		printf(" %2hhx", PyBytes_AS_STRING(p)[i]);
	printf("\n");
}



/**
 * print_python_list - prints info about python list object
 * @p: pointer to PyObject
 */

void print_python_list(PyObject *p)
{
	if (!PyList_Check(p))
		return;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
	printf("[*] Allocated = %ld\n", ((PyListObject *)(p))->allocated);
	for (Py_ssize_t i = 0; i < PyList_Size(p); i++)
	{
		printf("Element %ld: %s\n", i,
		       (PyList_GET_ITEM(p, i))->ob_type->tp_name);
		if (PyBytes_Check(PyList_GET_ITEM(p, i)))
			print_python_bytes(PyList_GET_ITEM(p, i));
	}
}
