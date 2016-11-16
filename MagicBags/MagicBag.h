#pragma once

#include <iostream>
#include <time.h>
#include <random>

using namespace std;

template<class T> class MagicBag
{
public:


	// Constructs a new, empty magic bag
	MagicBag() {
		head = NULL;
		count = 0;
		generator.seed((unsigned int)time(NULL));
	}

	// Copies a magic bag from an older magic bag
	MagicBag(const MagicBag& other) {

	}

	// Copies the supplied magic bag
	MagicBag& operator=(const MagicBag& other) {
		MagicBag fresh();
		node *temp = head;
		while (temp->next != NULL) {
			fresh.insert(T(&(temp->x)));
			temp = temp->next;
		}
	}

	// Cleanly deallocates a magic bag
	~MagicBag() {
		
	}

	// inserts an item into the magic bag
	void insert(T item) {
		count++;
		node temp();
		temp.x = item; temp.next = head;
		head = &temp;
	}

	// takes a random item from the bag
	T draw() {
		if (count == 0) {
			throw(1);
		}
		unsigned int distance = uint_dist(generator) % count;
		node *temp = head;
		if (distance == 0) {
			T tvalue = head->x;
			head = head->next;
			return tvalue;
		}
		for (size_t i = 0; i < distance - 1; i++)
		{
			temp = temp->next;
		}
		T tvalue = temp->next->x;
		temp->next = temp->next->next;
		return tvalue;
	}

	// returns a random item from the bag
	int peek(T item) {

	}

private:

	struct node {
		T x;
		node *next = NULL;
	};

	node *head;
	unsigned int count;
	mt19937 generator;
	uniform_int_distribution<uint32_t> uint_dist;

	friend ostream& operator<<(ostream& os, const MagicBag& mb) {
		os << "Magic bag: ";
		node *temp = mb.head;
		for (size_t i = 0; i < mb.count; i++)
		{
			os << temp->x << " ";
			temp = temp->next;
		}
	}
};


