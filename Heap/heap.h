/**
 * @file heap.h - Blueprint for a heap class
 * 
 * @date (created) 31 July 2018
 */

#ifndef HEAP_H
#define HEAP_H

#include <cstddef>      // size_t
#include <vector>

using std::vector;

/**
 * Heap: a min-heap that can implement a priority queue
 */
class Heap {
    public:
        /**
         * Construct an empty heap
         */
        Heap();
        
        /**
         * Returns the heap's smallest value, without changing the heap 
         * structure in any way.
         * This is a O(1) operation.
         *
         * @return The minimum heap value.
         */
        int getMin() const;

        /**
         * Inserts a value into the heap while restoring the heap's property. 
         * This is a worst case O(logN) operation.
         *
         * @param value The data to insert into the heap
         */
        void insert(const int& value);

        /**
         * Returns the size of the heap.
         *
         * @return The number of elements in the heap.
         */
        size_t size() const;

    private:
        /**
         * Container for this min-heap. Note, the heap starts at index(0) 
         */
        vector<int> elements;

        /**
         * The current size of our heap.
         */
        size_t length;
    
        /**
         * Helper function that returns the index of the current node's
         * parent.
         *
         * @param currentIndex The index of the current node.
         * @return The index of the current node's parent
         */
        size_t parent(size_t currentIndex) const;
         
        /**
         * Helper function that returns the index of the current node's
         * left child.
         *
         * @param currentIndex The index of the current node.
         * @return The index of the current node's left child
         */
        size_t leftChild(size_t currentIndex) const;
    
        /**
         * Helper function that returns the index of the current node's
         * right child.
         *
         * @param currentIndex The index of the current node.
         * @return The index of the current node's right child
         */
        size_t rightChild(size_t currentIndex) const;
    
        /**
         * Helper function that returns the smaller of two children. For
         * example, if a node's left child is 2, and the right is 7, this
         * returns the index of the left child.
         *
         * This function assumes the parent has children.
         * 
         * @param currentIndex The index of the current node.
         * @return The index of the smaller child node
         */
        size_t minChild(size_t currentIndex) const;
    
        /**
         * Helper function to restore heap property by bubbling up the
         * smaller node to the top as necessary.
         *
         * @param currentIndex The index of the node that is rising up
         * the tree.
         */
        void heapifyUp(size_t currentIndex);

        /**
         * Helper function that restores the heap property by sinking a
         * node down the tree as necessary.
         *
         * @param currentIndex The index of the current node that is sinking 
         * down the tree.
         */
        void heapifyDown(size_t currentIndex);
    
        /**
         * Swaps the data of two variables.
         *
         * @param x The value to store in y
         * @param y The value to store in x
         */
        void swap(int &x, int &y);

        
};

#endif
