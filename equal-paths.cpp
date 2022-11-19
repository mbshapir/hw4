#include "equal-paths.h"
#include <iostream>
using namespace std;


// You may add any prototypes of helper functions here
int evenChecker(int counter, Node* root){

	int left = 0;
	int right = 0;

  if(root->left == NULL && root->right == NULL){ //check if left leaf and right leaf empty
          return counter; //return depth level
	}

	if(root->left == NULL) //there is nothing on the left
	{
		right = evenChecker(counter +1, root->right); //move down right leaf add one to depth level
		return right; //last recursive iteration - walking back up the tree
  }
	
	if(root->right != NULL && root->left != NULL) //there is something on the right, and there is something on the left
	{
		right = evenChecker(counter + 1, root ->right);
		left = evenChecker(counter + 1, root ->left);
	}
	else{
		left = evenChecker(counter + 1, root->left);
		return left;
	}

	if(right != left) //if depth of left side and right side !=, return false
	{
		return -1;
	}
	else{ //otherwise depths are equal, so true
		return right;
	}
    
}

bool equalPaths(Node * root)
{
    if(root == NULL){ //base case empty tree
        return true;
    }

		if(root->left == NULL && root->right == NULL)
		{
			return true;
		}

		int counter = 0;
    if(evenChecker(counter, root) == -1){
        return false;
    }else{
        return true;
    }
}

