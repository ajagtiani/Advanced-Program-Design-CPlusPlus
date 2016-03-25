//$Id: Clock_config.h,v 1.3 2012/04/25 01:03:13 p334-70d Exp p334-70d $
//
//$Log: Clock_config.h,v $
//Revision 1.3  2012/04/25 01:03:13  p334-70d
//Added const notations
//
//Revision 1.2  2012/04/25 00:50:48  p334-70d
//Added comments
//
//Revision 1.1  2012/04/25 00:07:12  p334-70d
//Initial revision
//
//Revision 1.1  2012/04/13 01:35:18  rxa2695
//Initial revision
//
//
//Revisions:
//@author: Ramnath Anantharaman
//@contributor: Aditya Jagtiani

#ifndef CLOCK_CONFIG
#define CLOCK_CONFIG
#include<iostream>
#include<vector>
#include<deque>
#include<map>

class Clock_config{
	
public: //Access
	
	///Constructor
	///
	///@param start		the current time
	///@param end		the correct time
	///@param hours		the number of hours the clock is set to
	Clock_config(int,int,int);
	
	///This method generates the possible moves from starting configuration to goal
	///
	///@param 	cfg		current configuration
	///@return	a vector containing the next possible moves from current state
 	std::vector<int> get_moves(int) ;
	
	///This function displays the path taken from initial state to final state
	///
	///@param	cfg			current configuration
	///@param	initial_config		initial configuration
	///@param	trackpath		an integer map containing value as current state (parent) and index as 			///				neighbors (children)
	///@return	void
  	void display(int,int,std::map<int,int>) ;
	
	///This function checks whether the current configuration is a solution or not
	///
	///@param	config		integer representing current configuration
	///@return	true or false
	bool isGoal_config(int) const;
	
	///Destructor
	///
	/// Frees memory once the concerned object is out of scope		
	~Clock_config();
	
	///This accessor method returns the initial configuration
	///
	///@param	none
	///@return	integer representing initial configuration
  	int getinitial_config() const;
	
	///This accessor method returns the final configuration
	///
	///@param	none
	///@return	integer representing final configuration
	int getfinal_config() const;
	
private: //Data Members
	
	///Holds the total number of hours on clock		
	int total_hours;
	
	///Holds the initial configuration of clock
	int initial_config;
	
	///Holds the final configuration of clock
	int final_config;
};
#endif

