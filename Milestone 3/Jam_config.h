//$Id: Jam_config.h,v 1.5 2012/05/10 20:38:00 p334-70d Exp p334-70d $
//$Log: Jam_config.h,v $
//Revision 1.5  2012/05/10 20:38:00  p334-70d
//Final checks
//
//Revision 1.4  2012/05/10 20:29:39  p334-70d
//Added documentation
//
//Revision 1.3  2012/05/09 23:32:29  p334-70d
//Added const notations
//
//Revision 1.2  2012/05/09 23:28:39  p334-70d
//Added new data members
//
//Revision 1.1  2012/05/09 23:27:46  p334-70d
//Initial revision
//
//Author: Ramnath Ananthraman
//Author: Aditya Jagtiani
//This class defines the data members and methods needed to solve the 
//parking lot puzzle

#ifndef JAM_CONFIG
#define JAM_CONFIG
#include<fstream>
#include<vector>
#include<map>
#include<iostream>

class Jam_config {

private: //Access

int columns; //number of columns in the parking lot grid
int rows; //number of rows in the parking lot grid
std::vector<std::vector<int> >initial_config; //2D int vector containing
											//initial car configs	
std::vector<int>final_config;//int vector containing final car configs
int vect_size;//size of the vector
std::ostream *o; //ostream object for file output

public: //Access

	///Constructor
	///
	///@param c		number of columns
	///@param r		number of rows
	///@param initial	2D vector holding initial configuration 
	///@param final		int vector holding final configuration
	///@param _size		size of the vector, integer
	///@param out		output object for files
	Jam_config(int, int , std::vector<std::vector<int> > initial,
			std::vector<int>, int, std::ostream *out);
	///Destructor
	~Jam_config();
	
	///This function generates the possible moves from current state
	///
	///@param lpc		number of professors on lhs
	///@param lsc		number of students on lhs
	///@param rpc		number of professors on rhs
	///@param rsc		number of students on rhs
	///@param final		vector containing final configuration
	///@return		a 3 dimensional vector containing possible configs
	std::vector<std::vector<std::vector<int> > >get_moves(std::vector
						<std::vector<int> > ) const;
	
	///This function checks whether the current config is a solution or not
	///
	///@param config	a 2D vector of ints containing current configuration	
	///@return		true if the current config is the solution, else false
	bool isGoal_config(std::vector<std::vector<int> >)const;
	
	///This accessor function fetches the initial configuration
	///
	///@param	none
	///@return	a 2D integer vector containing current configuration
	std::vector<std::vector<int> > getinitial_config()const;
	
	///This accessor function fetches the final configuration
	///
	///@param	none
	///@return	a 2D integer vector containing current configuration
	std::vector<std::vector<int> >getfinal_config()const;
	
	///This function displays the shortest path taken from start to finish
	///
	///@param cfg		2D int vector containing goal config
	///@param initial   2D int vector containing initial config
	///@param trackpath a map with 2D integer vectors as keys and 
	///				values to display the path traversed from start to finish
	///
	///@return			void
	void display(std::vector<std::vector<int> >,std::vector<std::vector<int>
						>, std::map<std::vector<std::vector<int> >,
						std::vector<std::vector<int> > >);
	
	///This function checks whether a car is horizontal or not
	///
	///@param	coord	an integer vector containing current car coordinates
	///@return true when car is horizontal, false otherwise
	bool isHorizontalCar(std::vector<int>)const;
	
	///This function checks whether a car moves towards the right
	///
	///@param prev	int vector containing coordinates of the last accessed car
	///@param curr	int vector containing coordinates on current car
	///
	///@return true when car moves to the right, false if it doesn't
	bool isMotionToRight(std::vector<int> ,std::vector<int> )const;
	
	///This function checks whether a car moves towards the left
	///
	///@param prev	int vector containing coordinates of the last accessed car
	///@param curr	int vector containing coordinates on current car
	///
	///@return true when car moves to the left, false if it doesn't
	bool isMotionToLeft(std::vector<int> ,std::vector<int> )const;
	
	///This function checks whether a car moves upwards
	///
	///@param prev	int vector containing coordinates of the last accessed car
	///@param curr	int vector containing coordinates on current car
	///
	///@return true when car moves upwards, false if it doesn't
	bool isMotionToTop(std::vector<int> ,std::vector<int> )const;
	
	///This function checks whether a car moves downwards
	///
	///@param prev	int vector containing coordinates of the last accessed car
	///@param curr	int vector containing coordinates on current car
	///
	///@return true when car moves downwards, false if it doesn't
	bool isMotionToBottom(std::vector<int> ,std::vector<int> )const;

};
#endif

