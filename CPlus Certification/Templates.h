#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <exception>

using std::cout;
template<typename T>
T maxof(T a, T b);



namespace bw {
// Exception class
	class S_err : public std::exception {
		const char* msg;
	public: 
		S_err() = delete;
		explicit S_err(const char* s)noexcept : msg(s) {}
		const char* what() const noexcept { return msg; }
	};

	// Simple fixed-size LIFO Stack template
	template <typename T>
	class Stack {
		static const int default_size{ 10 }; //only one copy
		static const int max_size{ 1000 };
		int S_size{};
		int S_top{};
		std::unique_ptr<T[]> S_ptr{}; // Managed pointer, allows only one copy of the pointer to exist at one time
	public:
		explicit Stack(int s = default_size); // Constructor
		~Stack() { if (S_ptr) S_ptr.release(); }
		T& push(const T&); // 
		T& pop();
		bool isEmpty() const { return S_top < 0; }
		bool isFull() const {return S_top >= S_size - 1;}
		int Top() const { return S_top; }
		int Size() const { return S_size; }
	};
}