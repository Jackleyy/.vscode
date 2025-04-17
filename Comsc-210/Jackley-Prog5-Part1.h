#ifndef MY_HEAP_
#define MY_HEAP_
#include <algorithm>

//
// COMSC-210
// Array-based heap template.
//
// This is a starter file with a framework C++ template you can use as the
// basis for writing your heap.  In the 'private' section there are various
// utility functions that you can use to navigate around the tree.  The
// 'public' section contains the functions that your code in main() will use
// as an interface into the heap.
//

template<class ItemType>
class myHeap {
private:
   // Start with a small default size
   static const int DEFAULT_CAPACITY = 24;
   ItemType *items;

   int itemCount; // Current count of heap items
   int maxItems;  // Maximum capacity of the heap

   // Returns the array index of the left child (if exists).
   int getLeftChildIndex(const int nodeIndex) const;
   
   // Returns the array index of the right child (if exists).
   int getRightChildIndex(int nodeIndex) const;
   
   // Returns the array index of the parent node.
   int getParentIndex(int nodeIndex) const;
   
   // Converts a semiheap to a heap.
   void heapRebuild(int nodeIndex);
   
   // Creates a heap from an unordered array.
   void heapCreate();

   
   
public:
   myHeap();
   myHeap(const ItemType someArray[], const int arraySize);
   ~myHeap();
   
   // HeapInterface Public Methods:
   bool isEmpty() const;
   int getNumberOfNodes() const;
   
   ItemType peekTop() const;
   bool add(const ItemType& newData);
   bool remove();
   void clear();
   bool inBounds(int index);
};



//NEED TO DO

//DO
// Given a subheap rooted at index subTreeNodeIndex, rebuild the nodes
// so a heap is formed.
template<class ItemType>
void myHeap<ItemType>::heapRebuild(const int subTreeNodeIndex) {
   int daddy_index = subTreeNodeIndex;

   
   while(true){
      int largest = daddy_index;
      int LC_index = getLeftChildIndex(daddy_index);
      int RC_index = getRightChildIndex(daddy_index);
      

      if(inBounds(LC_index) && items[LC_index] > items[largest]){
         largest = LC_index;
      }

      if(inBounds(RC_index) && items[RC_index] > items[largest]){
         largest = RC_index;
      }

      if(largest != daddy_index){
         std::swap(items[daddy_index], items[largest]);
         daddy_index = largest;
      }
      else{
         break;
      }

   }
}

//making my own functions in order to check if something is out of bounds
template<class ItemType>
bool myHeap<ItemType>::inBounds(int index){
   if(index < 0 || index >= itemCount){
      return false;//out of bounds
   }
   return true; // valid
}

//DO
// Remove the root of the heap and rebuild it
template<class ItemType>
bool myHeap<ItemType>::remove() {

   if(isEmpty()){
      return false;
   }

   std::swap(items[0], items[itemCount-1]);
   itemCount--; // 1 less item so counter follows suit
   
   heapRebuild(0);

   return true;




}

//DO
// Add a new item to the heap
template<class ItemType>
bool myHeap<ItemType>::add(const ItemType& newData) {

   if (itemCount >= maxItems) {
      return false;  // Optional: handle capacity overflow
   }

   int index = itemCount;
   items[itemCount] = newData;
   itemCount++;

   while(index > 0 && items[index] > items[getParentIndex(index)]){
      std::swap(items[index], items[getParentIndex(index)]);
      index = getParentIndex(index);
   }

   return true;

}


// Constructor that accepts an existing array
template<class ItemType>
myHeap<ItemType>::
myHeap(const ItemType someArray[], const int arraySize):
             itemCount(arraySize), maxItems(2 * arraySize) {
      
   items = new ItemType[DEFAULT_CAPACITY];
   // Copy elements from the input array into the heap
   for (int i = 0; i <= arraySize; i++) {
      items[i] = someArray[i];
   }

   // Build the heap from the copied array
   heapCreate();
}



//CO0MPLETED PRIOR



// Given a nodeIndex, return its LEFT child index.  If the return
// value of this function is greater than or equal to itemCount, there is
// no left child (the node is a leaf).
template<class ItemType>
int myHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
   return (2 * nodeIndex) + 1;
}

// Given a nodeIndex, return its RIGHT child index.  Our array-based
// format implies that if a node has a right child, it must already have
// a left child.
template<class ItemType>
int myHeap<ItemType>::getRightChildIndex(const int nodeIndex) const {
   return (2 * nodeIndex) + 2;
}

// Given a nodeIndex, return its PARENT index.
template<class ItemType>
int myHeap<ItemType>::getParentIndex(const int nodeIndex) const {
   return (nodeIndex - 1) / 2;
}



// Rebuild the entire heap.  This is the 'bottom up' algorithm.
template<class ItemType>
void myHeap<ItemType>::heapCreate() {
   for (int index = itemCount / 2; index >= 0; index--) {
      heapRebuild(index);  
   }
}


// Default constructor
template<class ItemType>
myHeap<ItemType>::myHeap(): itemCount(0),
        maxItems(DEFAULT_CAPACITY) {
        items = new ItemType[DEFAULT_CAPACITY];
}

// Default destructor
template<class ItemType>
myHeap<ItemType>::~myHeap() {
        delete [] items; 
}

// Return whether the heap is empty
template<class ItemType>
bool myHeap<ItemType>::isEmpty() const {
   return itemCount == 0;
}

// Return the total number of nodes
template<class ItemType>
int myHeap<ItemType>::getNumberOfNodes() const {
   return itemCount;
}


// Clear all items (note we do not resize the array here).
template<class ItemType>
void myHeap<ItemType>::clear() {
   itemCount = 0;
}

// Return the value at the root of the heap
template<class ItemType>
ItemType myHeap<ItemType>::peekTop() const {
   return items[0];
}






#endif /* !MY_HEAP_ */


