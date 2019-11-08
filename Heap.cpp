#include "Heap.h"
#include <iostream>

Heap::Heap() {
	numItems = 0;
}

void Heap::enqueue ( PrintJob* curr) {
	if(numItems >= 10) {
		return;
	}
	
	++numItems;
	int nodeIndex = numItems -1 ;
	arr[nodeIndex] = curr;
	MaxPercolateUp(nodeIndex);
	
}

void Heap::MaxPercolateUp(int nodeIndex) {
	while(nodeIndex > 0) {
		int parentIndex = (nodeIndex - 1) / 2;
		
		if(arr[parentIndex] -> getPriority() >=  arr[nodeIndex] -> getPriority()) { 
			return;
		}
		else {
			arr[nodeIndex] ->swap (arr[parentIndex]);
			nodeIndex = parentIndex;
		}
	}
	return;
}

void Heap::print() {
	if(numItems == 0) {
		return;
	}
std::cout << "Priority: " << arr[0] ->getPriority();
	std::cout << ", Job Number: " << arr[0] ->getJobNumber();
	std::cout <<", Number of Pages: " << arr[0] -> getPages() << std::endl;
}

 PrintJob* Heap::highest ( ) {
	 return arr[0];
 }

void Heap::dequeue ( ){

	if(numItems ==0) {
		return;
	}
	if(numItems == 1) {
		arr[0] = NULL;
		--numItems;
		return;
	}

	arr[0] -> swap(arr[numItems -1]);
	arr[numItems - 1] = NULL;
	--numItems;
	trickleDown(0);

}

void Heap::trickleDown(int nodeIndex) {
	int childIndex = nodeIndex * 2 + 1;
	
	
	while(childIndex < numItems) {
		int currentPr = arr[nodeIndex] -> getPriority();
		
		int maxPr = currentPr;
		int maxIndex = -1;
		
		if(arr[childIndex] -> getPriority() > maxPr) {
			maxPr = arr[childIndex] -> getPriority();
			maxIndex = childIndex;
		}
		
		if(childIndex + 1 < numItems) {
			if(arr[childIndex + 1] -> getPriority() > maxPr) {
				maxPr = arr[childIndex + 1] -> getPriority();
				maxIndex = childIndex + 1;
			}
		} 
		
		if(maxPr == currentPr) {
			return;
		}
		
		else {
			arr[nodeIndex] -> swap (arr[maxIndex]);
			nodeIndex = maxIndex;
			childIndex = 2 * nodeIndex +1;
		}
	}
}
