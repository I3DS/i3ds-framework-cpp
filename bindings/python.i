// -*- Mode: Python -*-

%module i3ds

%include <typemaps.i>
%include <std_string.i>
%include <std_shared_ptr.i>

%naturalvar;

%exception {
   try {
      $action
   } catch (std::runtime_error &e) {
      PyErr_SetString(PyExc_RuntimeError, const_cast<char*>(e.what()));
      return NULL;
   }
}

%typemap(in) bool = bool;
%typemap(out) bool = bool;

%typemap(in) NodeID = int;
%typemap(out) NodeID = int;

%typemap(in) SampleRate = int;
%typemap(out) SampleRate = int;

%typemap(in) ExposureTime = int;
%typemap(out) ExposureTime = int;

%typemap(in) FlashStrength = int;
%typemap(out) FlashStrength = int;

%typemap(in) PatternSequence = int;
%typemap(out) PatternSequence = int;

%typemap(in) SensorGain = double;
%typemap(out) SensorGain = double;

%typemap(in) PlanarRegion {
    $1.size_x   = PyLong_AsLong(PyTuple_GetItem($input, 0));
    $1.size_y   = PyLong_AsLong(PyTuple_GetItem($input, 1));
    $1.offset_x = PyLong_AsLong(PyTuple_GetItem($input, 2));
    $1.offset_y = PyLong_AsLong(PyTuple_GetItem($input, 3));
}

%typemap(out) PlanarRegion {
    $result = PyTuple_New(4);
    PyTuple_SetItem($result, 0, PyLong_FromLong($1.size_x));
    PyTuple_SetItem($result, 1, PyLong_FromLong($1.size_y));
    PyTuple_SetItem($result, 2, PyLong_FromLong($1.offset_x));
    PyTuple_SetItem($result, 3, PyLong_FromLong($1.offset_y));
}

%include "i3ds.i"

%pythoncode %{

%}