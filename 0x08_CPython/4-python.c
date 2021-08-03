#include <Python.h>

/**
 * print_python_string - print basic information about Python string objects
 * @p: Python object
 */
void print_python_string(PyObject *p)
{
	char *type;
	wchar_t *buff;

	printf("[.] string object info\n");
	if (!PyUnicode_Check(p))
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	if (PyUnicode_IS_COMPACT_ASCII(p))
		type = "compact ascii";
	else if (PyUnicode_IS_COMPACT(p) && !PyUnicode_IS_ASCII(p))
		type = "compact unicode object";
	buff = PyUnicode_AsWideCharString(p, NULL);
	printf("  type: %s\n"
			"  length: %ld\n"
			"  value: %ls\n", type, PyUnicode_GET_LENGTH(p), buff);
	fflush(stdout);
}
