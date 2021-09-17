#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

class Empty_Collection{};

template<typename Obj, typename F1, typename F2>
class Collection{
    int size;
    int capacity;
    Obj* array;
    void resize() {
        int newCapacity;

        if (capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity = capacity * 2;
        }

        // create a new array with double capacity
        Obj *newArray = new Obj[newCapacity];

        // copy old elements over to new array
        for (int i = 0; i < capacity; i++) {
            newArray[i] = array[i];
        }

        // update capacity
        capacity = newCapacity;

        // delete old array
        delete [] array;

        // update array
        array = newArray;
    }

public:
    Collection() : size(0), capacity(0), array(nullptr) {}
    Collection(int cap) : size(0), capacity(cap), array(nullptr) {
        // create the array with the specified capacity to hold sb
        Obj *newArray = new Obj[cap];

        // update array
        array = newArray;
    }
    Collection(const Collection& c) : size(c.size), capacity(c.capacity), array(nullptr){
        // create an array for the new collection
        Obj *newArray = new Obj[capacity];

        // copy arrary
        for (int i = 0; i < size; i++) {
            newArray[i] = c.array[i];
        }

        // update collection's array
        array = newArray;
    }
    Collection& operator=(const Collection& c) {
        // check for self assignment
        if (this == &c) {
            return *this;
        }

        size = c.size;
        capacity = c.capacity;

        // delete the original array
        // delete [] array;

        // create a new array
        Obj *newArray = new Obj[capacity];

        // copy array
        for (int i = 0; i < size; i++) {
            newArray[i] = c.array[i];
        }

        // update collections's array
        array = newArray;

        return *this;
    }
    ~Collection()  {
        size = 0;
        capacity = 0;

        delete [] array;
    }
    Collection(Collection&& c) : size(c.size), capacity(c.capacity), array(c.array){
        // update other to no longer exist
        c.size = 0;
        c.capacity = 0;
        c.array = nullptr;
    }
    Collection& operator=(Collection&& c)  {
        // check for self assignment
        if (this == &c) {
            return *this;
        }

        // clear the existing array to avoid memory leak
        // delete [] array;

        // move over the size and capacity variables
        size = c.size;
        capacity = c.capacity;

        // have this array point to the same array as other
        array = c.array;

        // update other to no longer exist
        c.size = 0;
        c.capacity = 0;
        c.array = nullptr;

        return *this;
    }
    void insert_item(const Obj& sb)  {
        // if collection full
        if (size == capacity) {
            // resize the array
            resize();
        }

        // add the stress ball into the array
        array[size] = sb;

        // update size
        size++;
    }
    bool contains(const Obj& sb) const  {
        // get given color and size
        F1 givenSbColor = sb.get_color();
        F2 givenSbSize = sb.get_size();

        // iterate though collection array to see if a ball with specifications match
        for (int i = 0; i < size; i++) {
            if ((array[i].get_color() == givenSbColor) && (array[i].get_size() == givenSbSize)) {
                // if a match is found
                return true;
            }
        }

        // match was never found
        return false;
    }
    Obj remove_any_item()  {
        // if the collection is empty throw an exception
        if (size == 0) {
            throw std::invalid_argument("Collection is empty.");
        }

        // generate a random index between 0 and (size - 1)
        int randIndex = rand() % (size - 1);

        // get the item
        Obj item = array[randIndex];

        // just overwrite the array to simulate "delete"
        // iterate though from randIndex -> (size - 2)
        for (int i = randIndex; i < (size - 1); i++) {
            // copy down elements
            array[i] = array[i+1];
        }

        // update size -> this essentially gets rid of the last element
        size = size - 1;

        // return the stress ball
        return item;
    }
    void remove_this_item(const Obj& sb) {
        bool ballFound = false;

        // if collection is empty
        if (size == 0) {
            throw std::invalid_argument("Collection is empty.");
        }

        int itemIndex = 0;
        // iterate though collection array to see if a ball with specifications match
        for (itemIndex = 0; itemIndex < size; itemIndex++) {
            if (array[itemIndex] == sb) {
                // if the ball was found
                ballFound = true;
                break;
            }
        }

        // just overwrite the array to simulate "delete"
        // iterate though from itemIndex -> (size - 2)
        for (int i = itemIndex; i < (size - 1); i++) {
            // copy down elements
            array[i] = array[i+1];
        }

        // update size -> this essentially gets rid of the extra element
        if (ballFound) {
            size = size - 1;
        }
    }
    void make_empty()  {
        // update size&capacity
        size = 0;
        capacity = 0;

        // deallocate memory
        delete [] array;
    }
    bool is_empty() const {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
    int total_items() const { return size;
    }
    int total_items(F2 s) const {
        int sizeCounter = 0;

        // iterate through array
        for (int i = 0; i < size; i++) {
            // if size matches
            if (array[i].get_size() == s){
                // increment size counter
                sizeCounter ++;
            }
        }

        return sizeCounter;
    }
    int total_items(F1 c) const  {
        int colorCounter = 0;

        // iterate through array
        for (int i = 0; i < size; i++) {
            // if color matches
            if (array[i].get_color() == c){
                // increment color counter
                colorCounter ++;
            }
        }

        return colorCounter;
    }
    void print_items() const {
        // iterate through the array
        for (int i = 0; i < size; i ++) {
            cout << array[i] << endl;
        }
    }
    Obj& operator[](int i) {
        // return the element
        return array[i];
    }
    const Obj& operator[](int i) const  {
        // return the element
        return array[i];
    }
};
template<typename Obj, typename F1, typename F2>
ostream& operator<<(ostream& os, const Collection<Obj,F1,F2>& c) {
    // iterate through the array
    for (int i = 0; i < c.total_items(); i ++) {
        os << c[i] << endl;
    }
    return os;
}
template<typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj,F1,F2>& c1, const Collection<Obj,F1,F2>& c2) {
    int newCapacity = c1.total_items() + c2.total_items();

    // create a new collection with combined capacity
    Collection<Obj,F1,F2> c3 = Collection<Obj,F1,F2>(newCapacity);

    // iterate though all the elements in c1
    for (int i = 0; i < c1.total_items(); i++) {
        // add the element to c3
        c3.insert_item(c1[i]);
    }

    // iterate though all the elements in c2
    for (int i = 0; i < c2.total_items(); i++) {
        // add the element to c3
        c3.insert_item(c2[i]);
    }

    return c3;
}
template<typename Obj, typename F1, typename F2>
void swap(Collection<Obj,F1,F2>& c1, Collection<Obj,F1,F2>& c2) {

    // move c1 to a temp
    Collection<Obj,F1,F2> temp = Collection<Obj,F1,F2>(c1);

    // move assign c1 to c2
    c1 = c2;

    // move assign c2 
    c2 = temp;
}
template<typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj,F1,F2>& c, Sort_choice sort) {

    switch(sort) {
        case Sort_choice::bubble_sort:
        {
            int i = 0;
            int j = 0;
            bool cont = false;

            // iterate though the Collection<Obj,F1,F2> for each element in the Collection<Obj,F1,F2>
            // the (-1) will prevent over indexing
            for (i = 0; i < c.total_items(); i++) {

                // iterate one less each time a run is completed 
                for (j = 0; j < (c.total_items() - i); j++) {

                    // if the next element is bigger in size
                    if (c[j+1].get_size() < c[j].get_size()) {
                        // swap
                        swap(c[j], c[j+1]);
                        cont = true;
                    }
                }

                // if a swap did not take place, break the loop, the function is sorted
                if (cont == false) {
                    break;
                }
            }

            break;
        }

        case Sort_choice::insertion_sort:
        {
            for (int k = 1; k < c.total_items(); k++) {
                F2 tmp = c[k].get_size();
                int j = k;
                for ( ; (j > 0) && (tmp < c[j-1].get_size()); j--) {
                    c[j] = c[j-1];
                }
                c[j] = c[k];

            }

            break;
        }

        case Sort_choice::selection_sort:
        {
            for (int k = 0; k < (c.total_items() - 1); k ++) {
                int index = k;
                for (int i = k+1; i < c.total_items(); i ++) {
                    if (c[i].get_size() < c[index].get_size()) {
                        index = i;
                    }
                    swap(c[k], c[index]);
                }
            }

            break;
        }
    }
}

#endif
