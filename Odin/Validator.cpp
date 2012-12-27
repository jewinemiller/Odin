#include "Validator.h"
/*
*The Validator Class
*This class is used to validate things such as Entity position and collision
*in order to facilitate proper entity placement. 
*/

//Validate Position
//Ensures that anything placed is at the top left of the box it was placed in. 
int Validator::validatePosition(int position, int dimension){
	return (position - (position % dimension)); 
}

Validator::Validator(){}