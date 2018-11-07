/* HeapSort.cpp
 * Description: Implement the Heap-Sort algorithm 
 * Author: Dante Cherubini
 * Date: 7 November 2018
 */

#include "pch.h"
#include <iostream>
using namespace std;

// #pragma warning( disable : 4290 ) // BK: disable warnings for unimplemented exceptions

#include "Point2D.h"  // BK: includes Point2D and comparator classes
#include "HeapPriorityQueue.h"

int main() {
	HeapPriorityQueue<Point2D, DistCompare> pq;
	double p1, p2 = 0;
	while (true) {
		cout << "Enter a pair of doubles, separated by whitespace: ";
		cin >> p1 >> p2;
		if (p1 == 0 && p2 == 0) {
			break;
		}
		Point2D *pp;
		pp = new Point2D(p1, p2);
		pq.insert(*pp);
	}
	pq.printHeap();
	while (!pq.empty()) {
		Point2D first = pq.min();
		cout << "\nThe current minimum point is: " << first << endl;
		pq.removeMin();
	}
	system("PAUSE");
}