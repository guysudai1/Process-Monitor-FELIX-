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
#include <variant>

unsigned int hash(char*, unsigned int);

template <class T, class R>
class hash_map {
public:
	hash_map(int);
	~hash_map();
	R get_value(T);
	bool put(T, R);
private:
	R* internal_map;
	int calculate_hash(T);
};

// Max 1000 files
template <class T, class R>
hash_map<T, R>::hash_map(int map_size) {
	this->internal_map = new std::tuple<T,R>[map_size];
	for (int i = 0; i < sizeof(this->internal_map); i++)
		this->internal_map[i] = NULL;
}

template <class T, class R>
hash_map<T, R>::~hash_map() {
	delete this->internal_map;
}

// Extract value from hashmap
template <class T, class R>
R hash_map<T, R>::get_value(T key) {
	unsigned int index = this->calculate_hash(key);
	do {
		T key_in_arr = std::get<0>(this->internal_map[index]);
		index++;
	} while (key_in_arr != key);

	return std::get<1>(this->internal_map[index]);
}

template <class T, class R>
bool hash_map<T, R>::put(T key, R value) {
	if (std::is_same(key, char*)) {
		 // Find space to put in
		 unsigned int index = hash(key, sizeof(this->internal_map));
		 while (this->internal_map[index] != NULL && index < sizeof(this->internal_map)) {
			 index++;
		 }
		 if (index == sizeof(this->internal_map))
			 return false;
		 // Set element
		 this->internal_map[index] = std::make_tuple(key, value);
		 return true;
	}
	return false;
}

template <class T, class R>
int hash_map<T, R>::calculate_hash(T key) {
	if (std::is_same(key, char*)) {
		return hash(key, sizeof(this->internal_map));
	}
	return 0;
}


// TODO: add headers that you want to pre-compile here

#endif //HASHMAP_H
