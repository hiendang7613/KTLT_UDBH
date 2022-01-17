#pragma once
#include <stdlib.h>
#include <vector>

using namespace std;

template<class T>
using CompareFunc = bool (*) (T& t, T& t2);

template<class T>
class MyList
{
	T* arr;
	int n;
	int max;

private:
	void ReAlloc() {
		max *= 1.5;
		realloc(arr, max * sizeof(T));
	}

public:
	T* Arr() {
		return arr;
	}

	int N() {
		return n;
	}

	void Add(T t) {
		if (n == max) {
			ReAlloc();
		}
		arr[n] = t;
		n++;
	}

	void Delete(int pos) {
		for (size_t i = pos; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		n--;
	}

	vector<int> Find(T& t, CompareFunc<T> func) {
		vector<int> pos;
		for (size_t i = 0; i < n; i++)
		{
			if (func(arr[i], t)) {
				pos.push_back(i);
			}
		}
		return pos;
	}

	void Update(T& t, int pos) {
		arr[pos] = t;
	}


	void NewAlloc(int n)
	{
		arr = new T[n];
		this->n = n;
		max = n;
	}


public:
	MyList() {
		n = 0;
		max = 20;
		arr = new T[max];
	}

	void Close() {
		delete[] arr;
	}

};

//=== template define====

