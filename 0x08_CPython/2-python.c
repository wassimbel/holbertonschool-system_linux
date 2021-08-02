#include <Python.h>



/**
 * print_python_bytes - prints some basic info about Python bytes objects.
 * @p: pointer to PyObject
 **/

void print_python_bytes(PyObject *p)
{

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
	printf("size: %ld\n", PyBytes_Size(p));
	printf("trying string %s\n", PyBytes_AsString(p));
	printf("first %ld bytes", PyBytes_Size(p));
	for (Py_ssize_t i = 0; i < 10; i++)
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
		printf("Element %ld: %s\n", i,
		       (PyList_GET_ITEM(p, i))->ob_type->tp_name);
}
