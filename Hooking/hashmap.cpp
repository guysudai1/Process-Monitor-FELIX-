#include "hashmap.h"

unsigned int hash(const wchar_t* str, unsigned int max_elements) {
	// djb2 hash
	unsigned int hash = 5381;
	int c;
	while ((c = *(str++)))
		hash = ((hash << 5) + hash) + c; // hash * 33 + c 
	return hash % max_elements;
}

// Max 1000 files
hash_map::hash_map(int map_size) {
	this->internal_map = new std::tuple<const wchar_t*, const wchar_t*>[map_size];
	for (int i = 0; i < sizeof(this->internal_map); i++)
		this->internal_map[i] = std::make_tuple(L"", L"");
}

hash_map::~hash_map() {
	delete this->internal_map;
}

// Extract value from hashmap
const wchar_t* hash_map::get_value(const wchar_t* key) {
	unsigned int index = this->calculate_hash(key);
	const wchar_t* key_in_arr = L"";
	do {
		key_in_arr = std::get<0>(this->internal_map[index++]);
	} while (key_in_arr != key);

	return std::get<1>(this->internal_map[--index]);
}

/*
template <class T, class R>
R hash_map<T, R>::get_value(T key) {
	return NULL;
}
*/

bool check_null(std::tuple<const wchar_t*, const wchar_t*> tuple) {
	return std::get<0>(tuple) == L"" && std::get<1>(tuple) == L"";
}

bool hash_map::put(const wchar_t* key, const wchar_t* value) {
	// Find space to put in
	unsigned int index = this->calculate_hash(key);
	while (!check_null(this->internal_map[index]) && index < sizeof(this->internal_map)) {
		index++;
	}
	if (index == sizeof(this->internal_map))
		return false;
	// Set element
	this->internal_map[index] = std::make_tuple(key, value);
	return true;
}

/*
template <class T, class R>
bool hash_map<T, R>::put(T key, R value) {
	return false;
}*/

int hash_map::calculate_hash(const wchar_t* key) {
	return hash(key, sizeof(this->internal_map));
}