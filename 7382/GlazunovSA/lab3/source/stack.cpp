#include <algorithm>// for exit
#include <iostream>
#include <cstring>//for memset
#define START_SIZE_OF_STACK 10
template <typename T>
class Mystack
{
public:
	Mystack( int = START_SIZE_OF_STACK );
	~Mystack();
	bool empty();
	int size();
	T top();
	T pop();
	void push(T);

private:
	T *array;
	int size_of_array,
		length;
	void resize();
};

template <typename T>
void Mystack<T>::resize(){
	/*int cur_size = size_of_array + START_SIZE_OF_STACK ;
	T* cur_array = new T[cur_size];
	memset(cur_array , 0 , sizeof(T)*cur_size);
	std::cerr<<cur_array<<std::endl;
	std::copy(array , array + size_of_array + 1 , cur_array);
	delete [] array;
	array = cur_array;
	size_of_array += START_SIZE_OF_STACK;
*/
	array=(T*)realloc(array,size_of_array+START_SIZE_OF_STACK);
	size_of_array += START_SIZE_OF_STACK;
}

template <typename T>
Mystack<T>::~Mystack()
{
    delete [] array;    
}
template <typename T>
Mystack<T>::Mystack(int size)
{
    size_of_array = size > 0 ? size : 10;   
    array = new T[size_of_array]; 
    length = -1; 
}
template <typename T>
void Mystack<T>::push(T value)
{
	if(length==size_of_array-1)
	{
		resize();
	}
	array[++length]=value;
}
template <typename T>
bool Mystack<T>::empty()
{
	if(length<=-1)
		return true;
	return false;
}
template <typename T>
int Mystack<T>::size()
{
	return length;
}
template <typename T>
T Mystack<T>::top()
{
	if(!empty())
		return array[length];
	std::cout<<std::endl<<"ERROR!!!"<<std::endl;
	exit(0);
}
template <typename T>
T Mystack<T>::pop()
{
	int total=top();
	length--;
	return total;
}