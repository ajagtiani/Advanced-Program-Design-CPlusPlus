//$Id: jam.cpp,v 1.6 2012/05/10 20:17:15 p334-70d Exp p334-70d $
//$Log: jam.cpp,v $
//Revision 1.6  2012/05/10 20:17:15  p334-70d
//Added a few more error conditions
//
//Revision 1.5  2012/05/09 20:33:28  p334-70d
//Fixed errors
//
//Revision 1.4  2012/05/09 20:33:02  p334-70d
//Added file reading error conditions
//
//Revision 1.3  2012/05/09 20:31:40  p334-70d
//Added a few basic error conditions
//
//Revision 1.2  2012/05/09 20:30:57  p334-70d
//Declared required variables
//
//Revision 1.1  2012/05/09 20:30:22  p334-70d
//Initial revision
//
//This file contains the main() function, calls the
//solver and implements error checking mechanisms. 

//Author: Ramnath Ananthraman
//Author: Aditya Jagtiani

#include"Solver.h"
#include"Jam_config.h"

using namespace std;

int main(int argc, char *argv[]){
	
	const int INPUT_INDEX =1;
	const int OUTPUT_INDEX =2;
	const int TOTAL_ARGS = 3;
	const char DASH = '-';
	
	int columns; //number of columns in the grid
	int rows;//number of rows in the grid
	int num_cars;//number of cars in the grid
	istream *in;//istream object to read from file
	ostream *out;//ostream file to write to file
	bool delin =false;
	bool delout=false;
	
	if (argc != TOTAL_ARGS) {
		cerr<<"Invalid number of arguments."<<endl;
		exit(1);
	}
	
	if(*argv[INPUT_INDEX]==DASH)
	{
		in = &cin;
	}  
	
    else
	{
		delin=true;
		in = new ifstream(argv[INPUT_INDEX], ifstream::in);
		if((*in).fail()){
			cerr<<"Could not locate entered file."<<endl;
        }
		
    } 
		
	if(*argv[OUTPUT_INDEX]==DASH) 
	{
		out=&cout;
    }
	
    else
	{
		delout=true;
		out=new ofstream(argv[OUTPUT_INDEX], ofstream::out);
    }
	
	(*in) >> columns;
	(*in) >> rows;
	(*in) >> num_cars;
	if((*in).fail()){
		cerr<<"Invalid input. Enter integers only."<<endl;
		exit(1);
	}
	
	if(num_cars>=(rows*columns)/2){
		cerr<<"Invalid Configuration"<<endl;
		exit(1);
      }
	
	if(columns <= 1) {
		cerr<<"Invalid number of columns"<<endl;
		exit(1);
	}
	
	if(rows <= 0) {
		cerr<<"Invalid number of rows."<<endl;
		exit(1);
	}
		vector<vector<int> > initial;
	vector<int> cars(4);
	int c;
	
	// inserting initial configuration

	for(int i=0;i<num_cars;i++){
		for(int j=0;j<4;j++){
			(*in) >> ws >> c;
				
			 if(c < 0) {
				cerr<<"Please enter positive integers only."<<endl;
				exit(1);
			}
			 if((*in).fail()){
				cerr<<"Invalid input."<<endl;
				exit(1);
			}
			cars[j]=c;
		}
		initial.push_back(cars);
	}

for(unsigned int i=0; i<initial.size();i++) {
	if(initial[i].at(0) == initial[i].at(2) 
	&& initial[i].at(1) == initial[i].at(3)) {
		cerr<<"Cars cannot be of one block."<<endl;
		exit(1);
	}

	if(initial[i].at(0) == initial[i].at(2) 
	&& initial[i].at(1) == initial[i].at(3)) {
		cerr<<"Cars cannot be of one block."<<endl;
		exit(1);
	}
}

for(unsigned int i=0; i<initial.size();i++) {
	for(unsigned int j=1; j<num_cars-1; j++) {
			if(i!=j){
				if(((initial[i].at(0)==initial[j].at(0)) 
					&& (initial[i].at(1)==initial[j].at(1))) 
				   || ((initial[i].at(0)==initial[j].at(2)) 
					   &&(initial[i].at(1)==initial[j].at(3))) 
				   || ((initial[i].at(2)==initial[j].at(0)) 
					   && (initial[i].at(3)==initial[j].at(1)))
	              ||((initial[i].at(2)==initial[j].at(2)) 
					 && (initial[i].at(3)==initial[j].at(3)))) 

		 {
				cerr<<"Co-ordinates of 2 or more cars clash."<<endl;
				exit(1);
			}
		}
	}
}

	/*if(!(*in).good()){
		cerr<<"Invalid car configurations provided."<<endl;
		exit(1);
	}*/
	
for(unsigned int i =0;i<initial.size();i++){
	 if(((initial[i].at(0)>=columns) || (initial[i].at(2)>=columns )) ||((initial[i].at(1)>=rows)
	|| (initial[i].at(3)>=rows))){
		cerr<<"Car coordinates out of scope"<<endl;
		exit(1);
	  }
    }


	if(initial[initial.size()-1].at(0)==initial[initial.size()-1].at(2)){
	cerr<<" It is an unsolvable puzzle"<<endl;
    		exit(1);
     }
	if(initial[initial.size()-1].at(2)==(columns-1)){
	cerr<<"Car already at the exit"<<endl;
	exit(1);
       }
	int _size = initial.size();
	vector<int> final;
	final.push_back(initial[_size-1].at(0));
	final.push_back(initial[_size-1].at(1));
	final.push_back(initial[_size-1].at(2));
	final.push_back(initial[_size-1].at(3));

	Solver<vector<vector<int> > , Jam_config > jam_solver;
	Jam_config jam_object(columns,rows,initial,final,_size,out);
	jam_solver.solve(jam_object);
	
	if(delin == true)
	{
		delete in;
		in=0;
	}
	
	if(delout == true)
	{
		delete out;
		out=0;
	}
	return 0;
}
