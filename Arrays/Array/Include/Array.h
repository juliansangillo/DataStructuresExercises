#ifndef ARRAY_H
#define ARRAY_H

#include "ArrayExceptions.h"

/**
 * @brief A static Array implementation. Can hold an ordered list of values of any
 * data type. The size of the Array must be declared upon construction and 
 * can not be changed during its lifecycle.
 * 
 * @tparam T the type of data the Array will hold
 **/
template<class T>
class Array {
    protected:
        T* arr = NULL;
        int _length;

    public:
        /**
         * @brief Constructor uses the length of the Array to initialize the
         * memory space.
         * 
         * @param length the number of elements to be reserved for the Array
         **/
        Array(int length) {

            if(length > 0)
                this->arr = new T[length];
            this->_length = length;

        }

        ~Array() {

            delete[] this->arr;
            this->arr = NULL;

        }

        /**
         * @brief The length of the array.
         * 
         * @returns the number of elements reserved in the array
         **/
        int length() {
            
            return this->_length;
        }

        /**
         * @brief Gets the value in the Array at the given index.
         * 
         * @param index the position in the array whose value is to be returned
         * @returns the element at the given index
         * @throws ArrayIndexOutOfBounds
         **/
        T get(int index) {

            if(index < 0 || index >= this->_length)
                throw ArrayIndexOutOfBounds(index);

            return arr[index];
        }

        /**
         * @brief Assigns a new value in the Array at the given index.
         * 
         * @param index the position in the array whose value is to be changed
         * @param element the new value to be assigned at the given index
         * @throws ArrayIndexOutOfBounds
         **/
        void set(int index, T element) {

            if(index < 0 || index >= this->_length)
                throw ArrayIndexOutOfBounds(index);

            arr[index] = element;

        }

        /**
         * @brief Overloaded '[]' that performs a get operation and ensures that
         * the result is constant. This is the read-only version that is called
         * when just the value is needed.
         * 
         * @param index the position in the array whose value is to be returned
         * @returns the element at the given index
         **/
        const T operator[] (int index) const {

            return get(index);
        }

        /**
         * @brief Overloaded '[]' that gets the value in the Array at the given index 
         * but returns a reference to that result. This version allows for performing 
         * set operations with other operators.
         * 
         * @param index the position in the array whose value is to be returned or changed
         * @returns reference to the element at the index
         * @throws ArrayIndexOutOfBounds
         **/
        T& operator[] (int index) {

            if(index < 0 || index >= this->_length)
                throw ArrayIndexOutOfBounds(index);
            
            return this->arr[index];
        }
};

/**
 * @brief A dynamic Array implementation. Can hold an ordered list of values of any
 * data type. The size is flexible and will change during the Array's lifecycle.
 * Extends the static Array's functionalities and now includes the ability to push,
 * pop, insert, and delete.
 * 
 * @tparam T the type of data the dynamic Array will hold
 **/
template<class T>
class DynamicArray : public Array<T> {
    private:
        int _bufferSize;

        void expandArray() {

            T* temp = NULL;
            if(this->arr != NULL)
                temp = &this->arr[0];
            this->arr = new T[this->_length * 2];

            for(int i = 0; i < this->_length; i++)
                this->arr[i] = temp[i];

            delete[] temp;
            temp = NULL;

            this->_bufferSize *= 2;

        }

        void shiftRight(int index) {

            if(this->_length == this->_bufferSize)
                expandArray();
            
            this->_length++;
            for(int i = this->_length - 2; i >= index; i--)
                this->arr[i + 1] = this->arr[i];

        }

        void shiftLeft(int index) {

            for(int i = index + 1; i < this->length(); i++)
                this->arr[i - 1] = this->arr[i];
            this->_length--;

        }

    public:
        /**
         * @brief Constructor sets the default buffer size of the Array and initializes its length.
         **/
        DynamicArray() : Array<T>(2) {

            this->_bufferSize = this->_length;
            this->_length = 0;

        }

        /**
         * @brief The current size of the Array's buffer. Each dynamic Array is given some memory as a buffer
         * in order to increase the performance of push operations. If there is space in the buffer, then 
         * push will simply use the memory that is already there. If the data exceeds the buffer size, then
         * the buffer size is doubled and the Array is reallocated.
         * 
         * @returns the current buffer size
         **/
        int bufferSize() {

            return this->_bufferSize;
        }

        /**
         * @brief Pushes data onto the end of the Array. Reallocates memory if buffer is exceeded.
         * 
         * @param element the data to add to the end of the current array
         **/
        void push(T element) {

            if(this->_length >= this->_bufferSize)
                expandArray();
            this->arr[this->_length++] = element;

        }

        /**
         * @brief Pops data off of the end of the Array. This deletes the data and returns what was
         * deleted.
         * 
         * @returns element that was just popped
         * @throws ArrayUnderflow
         **/
        T pop() {

            if(this->_length == 0)
                throw ArrayUnderflow();

            T element = this->arr[--this->_length];

            return element;
        }

        /**
         * @brief Adds new data to the Array at the given index. Unlike push, insert can add elements to
         * the middle of the Array, but may be less performant. Insert operations may require shifting
         * elements to the right.
         * 
         * @param index array position to insert the new data at
         * @param element the data to insert at the given index
         * @throws ArrayIndexOutOfBounds
         **/
        void insert(int index, T element) {

            if(index < 0 || index > this->_length)
                throw ArrayIndexOutOfBounds(index);

            shiftRight(index);
            this->arr[index] = element;

        }

        /**
         * @brief Deletes data from the Array at the given index. Unlike pop, drop can remove elements from the
         * middle of the Array, but may be less performant. Drop operations may require shifting elements
         * to the left.
         * 
         * @param index the position of the data to drop
         * @returns the deleted element
         * @throws ArrayIndexOutOfBounds
         **/
        T drop(int index) {

            if(index < 0 || index >= this->_length)
                throw ArrayIndexOutOfBounds(index);

            T deleted = this->arr[index];
            shiftLeft(index);

            return deleted;
        }

        /**
         * @brief Overloaded '<<' that performs a push operation on the element given.
         * 
         * @param element the new data to push
         **/
        void operator<< (T element) {

            push(element);

        }

        /**
         * @brief Overloaded '>>' that performs a pop operation and stores the popped data in the
         * given variable.
         * 
         * @param var a reference to the variable to put the popped data
         **/
        void operator>> (T& var) {

            var = pop();

        }
};

#endif