#include <exception>

using namespace std;

struct FileException : public exception
{
	const char * detail () const throw ()
    {
    	return "File reading error";
    }
};

struct DecimalConvException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error during decimal to binary conversion";
    }
};

struct BinaryConvException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error during binary conversion";
    }
};

struct StoreAccessException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured while attempting to access Store";
    }
};

struct AccumulatorAccessException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured while attempting to access Accumulator";
    }
};

struct ControlAccessException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured while attempting to access Control";
    }
};

struct FetchException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured during fetch";
    }
};

struct DecodeException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured during decode";
    }
};

struct ExecutionException : public exception
{
	const char * detail () const throw ()
    {
    	return "Error occured during execution";
    }
};