#ifndef HASH_ENTITY_HPP
#define HASH_ENTITY_HPP

#include <string>

using namespace std;

class HashEntity {
private:
	int key;
	string value;
public:
	HashEntity(int _k, string _v) {
		this->key = _k;
		this->value = _v;
	}

	int getKey() {
		return key;
	}

	string getValue() {
		return value;
	}
};

#endif //! HASH_ENTITY_HPP