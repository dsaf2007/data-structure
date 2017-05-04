//--------------------------------------------------------------------
//
//  Laboratory 12                                         bstree.cpp
//  Author: James Roberge lab manual prelab solution
//
//  SOLUTION: Linked implementation of the Binary Search Tree ADT
//
//--------------------------------------------------------------------

#include <assert.h>

#include "bstree.h"

//--------------------------------------------------------------------

template < class TE, class KF >
BSTreeNode<TE,KF>:: BSTreeNode ( const TE &elem,
				 BSTreeNode<TE,KF> *leftPtr,
				 BSTreeNode<TE,KF> *rightPtr )

// Creates a binary search tree node containing element elem, left
// child pointer leftPtr, and right child pointer rightPtr.

  : element(elem),
    left(leftPtr),
    right(rightPtr)

{}

//--------------------------------------------------------------------

template < class TE, class KF >
BSTree<TE,KF>:: BSTree ()

// Creates an empty tree.

  : root(0)

{}

//--------------------------------------------------------------------

template < class TE, class KF >
BSTree<TE,KF>:: ~BSTree ()

// Frees the memory used by a tree.

{
    clear();
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF>:: insert ( const TE &newElement )

// Inserts newElement into a tree. If an element with the same key
// as newElement already exists in the tree, then updates that
// element's data with newElement's data.

{
    insertSub(root,newElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: insertSub ( BSTreeNode<TE,KF> *&p,
                                 const TE &newElement   )

// Recursive partner of the insert() function. Inserts newElement in
// the subtree pointed to by p.

{
    if ( p == 0 )
    {                                                  // Insert
       p = new BSTreeNode<TE,KF>(newElement,0,0);
       assert ( p != 0 );
    }
    else if ( newElement.key() < p->element.key() )
       insertSub(p->left,newElement);                  // Search left
    else if ( newElement.key() > p->element.key() )
       insertSub(p->right,newElement);                 // Search right
    else
       p->element = newElement;                        // Update
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF>:: retrieve ( KF searchKey, TE &searchElement ) const

// Searches a tree for the element with key searchKey. If the element
// is found, then copies the element to searchElement and returns 1.
// Otherwise, returns 0 with searchElement undefined.

{
    return retrieveSub(root,searchKey,searchElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
int BSTree<TE,KF>:: retrieveSub ( BSTreeNode<TE,KF> *p,
                                  KF searchKey,
                                  TE &searchElement     ) const

// Recursive partner of the retrieve() function. Searches the subtree
// pointed to by p.

{
    int result;   // Result returned

    if ( p == 0 )
       result = 0;
    else if ( searchKey < p->element.key() )
       result = retrieveSub(p->left,searchKey,searchElement);
    else if ( searchKey > p->element.key() )
       result = retrieveSub(p->right,searchKey,searchElement);
    else
    {
       searchElement = p->element;
       result = 1;
    }

    return result;
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF>:: remove ( KF deleteKey )

// Removes the element with key deleteKey from a tree. If the
// element is found, then deletes it from the tree and returns 1.
// Otherwise, returns 0.

{
    return removeSub(root,deleteKey);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
int BSTree<TE,KF>:: removeSub ( BSTreeNode<TE,KF> *&p,
                                KF deleteKey           )

// Recursive partner of the remove() function. Searches the subtree
// pointed to by p for the node with key deleteKey. If this node is
// found, then does one of the following:
//
//    - If the node is missing one or more children, then links
//      around it and deletes it.
//
//    - Otherwise, uses cutRightmost to replace the data in the
//      node with the data in the rightmost descendant of the node's
//      left child and deletes that node.

{
    BSTreeNode<TE,KF> *delPtr;  // Pointer to node to delete
    int result;                 // Result returned

    if ( p == 0 )
       result = 0;                               // Search failed
    else if ( deleteKey < p->element.key() )
       result = removeSub(p->left,deleteKey);    // Search left
    else if ( deleteKey > p->element.key() )
       result = removeSub(p->right,deleteKey);   // Search right
    else
    {                                            // Found
       delPtr = p;
       if ( p->left == 0 )
          p = p->right;                    // No left child
       else if ( p->right == 0 )
          p = p->left;                     // No right child
       else
          cutRightmost(p->left,delPtr);    // Has both children
       delete delPtr;
       result = 1;
    }

    return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: cutRightmost ( BSTreeNode<TE,KF> *&r,
                                    BSTreeNode<TE,KF> *&delPtr )

// Recursive partner of the removeSub() function. Traces down a
// sequence of right children. Copies the data from the last node in
// the sequence into the node pointed to delPtr, sets delPtr to point
// to the last node in the sequence, and links around this node.

{
    if ( r->right != 0 )
       cutRightmost(r->right,delPtr);   // Continue down to the right
    else
    {
       delPtr->element = r->element;
       delPtr = r;
       r = r->left;
    }
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF>:: writeKeys () const

// Outputs the keys in a tree in ascending order.

{
    writeKeysSub(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: writeKeysSub ( BSTreeNode<TE,KF> *p ) const

// Recursive partner of the writeKeys() function. Outputs the keys in
// the subtree pointed to by p.

{
    if ( p != 0 )
    {
       writeKeysSub(p->left);
       cout << p->element.key() << endl;
       writeKeysSub(p->right);
    }
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF>:: clear ()

// Removes all the nodes from a tree.

{
    clearSub(root);
    root = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: clearSub ( BSTreeNode<TE,KF> *p )

// Recursive partner of the clear() function. Clears the subtree
// pointed to by p.

{
    if ( p != 0 )
    {
       clearSub(p->left);
       clearSub(p->right);
       delete p;
    }
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF>:: empty () const

// Returns 1 if a tree is empty. Otherwise returns 0.

{
    return ( root == 0 );
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF>:: full () const

// Returns 1 if a tree is full. Otherwise returns 0. Cannot be done
// cleanly in generic C++.

{
    return (  sizeof(TE) );
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF>:: showStructure () const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
    if ( root == 0 )
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showSub(root,1);
       cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: showSub ( BSTreeNode<TE,KF> *p,
                               int level             ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the tree.

{
     int j;   // Loop counter

     if ( p != 0 )
     {
        showSub(p->right,level+1);         // Output right subtree
        for ( j = 0 ; j < level ; j++ )    // Tab over to level
            cout << "\t";
        cout << " " << p->element.key();   // Output key
        if ( ( p->left != 0 ) &&           // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showSub(p->left,level+1);          // Output left subtree
    }
}

template < class TE, class KF >
int BSTree<TE, KF>::height() const

{
	
	return heightSub(root);

}

template < class TE, class KF >
int BSTree<TE, KF>::heightSub(BSTreeNode<TE, KF> *p) const

{


	int l = 0;
	int r = 0;

	if (p == NULL)
	{
		return 0;
	}
	{
		l = heightSub(p->left);
		r = heightSub(p->right);
		if (l >= r)
		{
			return (++l);
		}
		else
		{
			return (++r);
		}
	}


}


