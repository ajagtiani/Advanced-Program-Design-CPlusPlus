//$Id: River_config.h,v 1.1 2012/05/07 17:57:04 p334-70d Exp p334-70d $
//$Log: River_config.h,v $
//Revision 1.1  2012/05/07 17:57:04  p334-70d
//Initial revision
//
//Revision 1.6  2012/04/24 23:36:20  p334-70d
//Final changes
//
//Revision 1.5  2012/04/24 23:26:24  p334-70d
//Added comments
//
//Revision 1.4  2012/04/24 23:18:43  p334-70d
//Removed the standard namespace declaration
//
//Revision 1.3  2012/04/24 23:17:26  p334-70d
//Declared required methods
//
//Revision 1.2  2012/04/24 23:17:26  p334-70d
//Declared some more variables
//
//Revision 1.1  2012/04/23 18:15:27  p334-70d
//Initial revision
//
//Author: Ramnath Ananthraman
//Author: Aditya Jagtiani

#ifndef RIVER_CONFIG
#define RIVER_CONFIG
#include<vector>
#include<map>

class River_config{
	
private: //Access
	//Variable declaration
	int lprof_count;
	int lst_count;
	int rprof_count;
	int rst_count;
	std::vector<int> initial;
	std::vector<int> final_config;
		
public:
	///Constructor
	///
	///@param lpc		number of professors on lhs
	///@param lsc		number of students on lhs
	///@param rpc		number of professors on rhs
	///@param rsc		number of students on rhs
	///@param final		vecotr containing final configuration
	River_config(int, int, int, int,std::vector<int> );
	
	///Destructor
	///
	/// Frees memory once the concerned object is out of scope	
	~River_config();
	
	///This method generates the possible moves from starting 
	///	configuration to goal
	///
	///@param 	v	vector containing current configuration
	///@return	a vector containing the next possible moves from current 
	///				state
	std::vector<std::vector<int> >get_moves(std::vector<int>);
	
	///This function checks whether the current configuration is a 
	///		solution or not
	///
	///@param	config		vector representing current configuration
	///
	///@return	true or false
	bool isGoal_config(std::vector<int>) const;
	
	///This accessor method returns the initial configuration
	///
	///@param	none
	///
	///@return	vector representing initial configuration
	std::vector<int> getinitial_config() const;
	
	///This accessor method returns the final configuration
	///
	///@param	none
	///
	///@return	vector representing final configuration
	std::vector<int> getfinal_config() const;
	
	///This function displays the path taken from initial state to final state
	///
	///@param	cfg		vector containing current configuration
	///@param	initial		vector containing initial configuration
	///@param	trackpath	a map of vectors containing value as 
	///			current state (parent) and index as neighbors (children)
	///
	///@return	void
	void display(std::vector<int>,std::vector<int>,
				std::map<std::vector<int>,std::vector<int> >) const;	
};

#endif
