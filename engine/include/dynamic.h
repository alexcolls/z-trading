// Dynamic Array Header /////////////////////////////////
// 
// Based on the MT4R dll by Bernd Kreuss, distributed under GNU license
// in the Source folder. See RTest.c for example usage.

#ifndef dynamic_h
#define dynamic_h

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32

#ifdef DYNAMICARRAY_EXPORTS 
#define DA_FUNC __declspec(dllexport)
#else  
#define DA_FUNC __declspec(dllimport)
#endif  
#define API(x,y)		// ignore
#define DynamicArray	// ignore

#else // if Zorro Trading Automation
#include <windows.h>	// Zorro windows API header
#define DA_FUNC			// ignore
#endif

// ** CREATION, EXISTENCE, AND DELETION **

// Creates a new dynamic array. Each element of the array has size of sizeof_type.
// Returns a handle to the array.
DA_FUNC int da_new(int sizeof_type);
API(da_new, DynamicArray)

// Confirms the existence of a dynamic array.
DA_FUNC bool da_exists(int handle);
API(da_exists, DynamicArray)

// De-allocates the dynamic vector from memory
// After this function, the handle will no longer be recognized.
// Returns true if completed, false if handle not recognized.
DA_FUNC bool da_delete(int handle);
API(da_delete, DynamicArray)

// De-allocates **all** dynamic vectors from memory.
// After this function, **all handles** will no longer be recognized.
DA_FUNC void da_delete_all();
API(da_delete_all, DynamicArray)

// ** SIZING **

// Returns the size of the dynamic array, in number of elements,
// or zero if the handle does not exist.
DA_FUNC int da_size(int handle);
API(da_size, DynamicArray)

// Returns the capacity of the dynamic array, in number of elements,
// or zero if the handle does not exist.
DA_FUNC int da_capacity(int handle);
API(da_capacity, DynamicArray)

// Returns the max number of elements the dynamic array is capable of holding,
// or zero if the handle does not exist.
DA_FUNC int da_max_size(int handle);
API(da_max_size, DynamicArray)

// Returns true if an existing array is empty
// or false if either the array has elements or does not exist.
DA_FUNC bool da_is_empty(int handle);
API(da_is_empty, DynamicArray)

// Returns the size of each individual element,
// or zero if the handle does not exist.
DA_FUNC int da_typesize(int handle);
API(da_typesize, DynamicArray)

// Resizes the array in terms of number of elements.  
// Behavior is similar to that of std::vector.
// Returns true if completed, false if handle not recognized.
DA_FUNC bool da_resize(int handle, int nSize);
API(da_resize, DynamicArray)

// Pre-allocates contiguous memory without changing the size of the dynamic array.
// Behavior is similar to that of std::vector.
// Returns true if completed, false if handle not recognized.
DA_FUNC bool da_reserve(int handle, int nSize);
API(da_reserve, DynamicArray)

// At the STL implementation's discretion, the capacity will be reduced to the size.
// Behavior is similar to that of std::vector.
// handle: Dynamic array handle.
DA_FUNC bool da_shrink_to_fit(int handle);
API(da_shrink_to_fit, DynamicArray)

// ** DATA ACCESS **

// Returns a (temporary) pointer to element number nElement of the array,
// or NULL if the handle does not exist,
// or NULL if the element number does not exist.
// Note: if size==0, no pointer can be returned.
// handle: Dynamic array handle.
// The pointer should be assumed invalid once the array is resized or reserved.
DA_FUNC void* da_data(int handle, int nElement);
API(da_data, DynamicArray)

// ** ADD ELEMENTS **

// Pushes the input element to the back of the dynamic array.
// handle: Dynamic array handle.
// Returns the new size of the dynamic array, in number of elements,
// or zero if the handle does not exist.
//DA_FUNC int da_push_back(int handle, void* pElement);
DA_FUNC int da_push_back(int handle, void* pElement);
API(da_push_back, DynamicArray)

// Inserts elements to a given position in the dynamic array.
// Behavior is similar to that of std::vector.
// handle: Dynameic array handle.
// pElement: Pointer to element or array of elements to be inserted.
// nPosition: Position where the new element(s) are to be placed,
//	          where 0 = front and size = back.
// numElements: Number of fixed-size elements to be inserted. Must be 1 or greater.
// Returns the new size if completed or zero if unsuccessful.
//DA_FUNC int da_insert(int handle, void* pElement, int nPosition, int numElements);
DA_FUNC int da_insert(int handle, void* pElement, int nPosition, int numElements);
API(da_insert, DynamicArray)

// ** REMOVE ELEMENTS **

// Erases elements at a given position in the dynamic array.
// Behavior is similar to that of std::vector.
// handle: Dynamic array handle.
// nPosition: Position where the first element is to be erased,
//			  where 0 = front and size = back.
// numElements: Number of fixed-size elements to be deleted. Must be 1 or greater.
//				For example, nPosition = 2, numElements = 3 :: 2 thru 5 get deleted.
DA_FUNC int da_erase(int handle, int nPosition, int numElements);
API(da_erase, DynamicArray)

// Removes the last element of the dynamic array.
// handle: Dynamic array handle.
// Returns the new size if completed or zero if unsuccessful.
DA_FUNC int da_pop_back(int handle);
API(da_pop_back, DynamicArray)

// Clears the contents of the dynamic array.
// (The size become zero but not the capacity per se.)
// handle: Dynamic array handle.
// Returns true if successful or false if handle not recognized.
DA_FUNC bool da_clear(int handle);
API(da_clear, DynamicArray)

#ifdef __cplusplus
}
#endif

#endif // dynamic_h