#include <Python.h>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    setenv("PYTHONPATH", ".", 1);

    if (argc < 3) {
        fprintf(stderr, "Usage: %s pythonfile funcname [args]\n", __func__);
        return 1;
    }

    Py_Initialize();
    pName = PyString_FromString(argv[1]);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    if (pModule == NULL) {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[2]);
        goto err;
    }

    pFunc = PyObject_GetAttrString(pModule, argv[2]);
    if ((pFunc == NULL) || !PyCallable_Check(pFunc)) {
        if (PyErr_Occurred())
            PyErr_Print();
        fprintf(stderr, "Call failed\n");
        goto err;
    }

    pArgs = PyTuple_New(argc - 3);
    for (i = 0; i < argc - 3; ++i) {
        pValue = PyInt_FromLong(atoi(argv[i + 3]));
        if(pValue == NULL) {
            fprintf(stderr, "Cannot convert argument\n");
            goto err;
        }
        /* pValue reference stolen here */
        PyTuple_SetItem(pArgs, i, pValue);
    }

    pValue = PyObject_CallObject(pFunc, pArgs);
    if (pValue == NULL) {
        PyErr_Print();
        fprintf(stderr, "Call failed\n");
        goto err;
    }

    printf("Result of call: %ld\n", PyInt_AsLong(pValue));

    Py_DECREF(pName);
    Py_DECREF(pArgs);
    Py_DECREF(pModule);
    Py_DECREF(pFunc);
    Py_DECREF(pValue);

    Py_Finalize();
    return 0;

err:

    if (pName)
        Py_DECREF(pName);
    if (pModule)
        Py_DECREF(pModule);
    if (pFunc)
        Py_DECREF(pFunc);
    if (pArgs)
        Py_DECREF(pArgs);
    if (pValue)
        Py_DECREF(pValue);

    return 1;
}
