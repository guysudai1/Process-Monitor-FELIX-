// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef HASHMAP_H
#define HASHMAP_H
#include <tuple>
#include <typeinfo>

unsigned int hash(const wchar_t*, unsigned int);

class hash_map {
public:
	hash_map(int);
	~hash_map();
	const wchar_t* get_value(const wchar_t* key);
	//R get_value(T);
	bool put(const wchar_t* key, const wchar_t* value);
	//bool put(T, R);
private:
	std::tuple<const wchar_t*, const wchar_t*>* internal_map;
	// int calculate_hash(T);
	int calculate_hash(const wchar_t* key);
};




// TODO: add headers that you want to pre-compile here

#endif //HASHMAP_H
