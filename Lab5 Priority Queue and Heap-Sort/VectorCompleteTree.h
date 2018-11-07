/* VectorCompleteTree.h
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: from Code Fragments 8.12 and 8.13
 */

#ifndef VECTOR_COMPLETE_TREE_H           // avoid repeated expansion
#define VECTOR_COMPLETE_TREE_H           // avoid repeated expansion

#include <vector>

template <typename E>
  class VectorCompleteTree {

  private:					// member data
	std::vector<E> V;		// tree contents
  public:					// publicly accessible types
    typedef typename std::vector<E>::iterator Position; // a position in the tree
  protected:				// protected utility functions
    Position pos(int i)					// map an index to a position
      { return V.begin() + i; }
    int idx(const Position& p) const	// map a position to an index
      { return p - V.begin(); }

  public:
    VectorCompleteTree() : V(1) {}			// constructor
    int size() const						{ return V.size() - 1; }
    Position left(const Position& p)		{ return pos(2*idx(p)); }
    Position right(const Position& p)		{ return pos(2*idx(p) + 1); }
    Position parent(const Position& p)		{ return pos(idx(p)/2); }
    bool hasLeft(const Position& p) const	{ return 2*idx(p) <= size(); }
    bool hasRight(const Position& p) const 	{ return 2*idx(p) + 1 <= size(); }
    bool isRoot(const Position& p) const	{ return idx(p) == 1; }
    Position root()							{ return pos(1); }
    Position last()							{ return pos(size()); }
    void addLast(const E& e)				{ V.push_back(e); }
    void removeLast()						{ V.pop_back(); }
    void swap(const Position& p, const Position& q)
  											{ E e = *q; *q = *p; *p = e; }
	void printTree();
  };

// BK: diagnostic function to show how elements are stored in the vector
template <typename Object>
void VectorCompleteTree<Object>::printTree() {
  Position iter = V.begin(); 		// create vector iterator
  int rank = 0;
  while (iter != V.end()) {			// while more remain
    cout << '[' << rank << "]: "; 			// print rank and element
	cout << *iter << endl;
    ++iter;						            // advance
	++rank;
  }
}

#endif  // VECTOR_COMPLETE_TREE_H
