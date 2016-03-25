//$Id: Jam_config.cpp,v 1.7 2012/05/09 20:28:45 p334-70d Exp p334-70d $
//$Log: Jam_config.cpp,v $
//Revision 1.7  2012/05/09 20:28:45  p334-70d
//Fixed warnings
//
//Revision 1.6  2012/05/09 20:28:07  p334-70d
//Fixed logical errors
//
//Revision 1.5  2012/05/09 20:26:49  p334-70d
//Fixed syntax errors
//
//Revision 1.4  2012/05/09 20:21:28  p334-70d
//Developed display logic
//
//Revision 1.3  2012/05/09 20:20:07  p334-70d
//wrote getmoves()
//
//Revision 1.2  2012/05/09 20:19:05  p334-70d
//Implemented the initial methods
//
//Revision 1.1  2012/05/09 20:15:52  p334-70d
//Initial revision
//
//Author: Aditya Jagtiani
//Author: Ramnath Ananthraman

//This file implements the methods needed to solve the 'parking lot' puzzle

#include"Jam_config.h"
#include"Solver.h"

using namespace std;


Jam_config::Jam_config(int c, int r, vector<vector<int> >initial,
					vector<int> final,int _size,ostream *out)
					:columns(c),rows(r),initial_config(initial),
						final_config(final),vect_size(_size),o(out)
{ }

vector<vector<int> >Jam_config::getinitial_config() const{
	return initial_config;
} 

vector<vector<vector<int> > >Jam_config::get_moves(vector<vector<int> >v) const {
	vector<vector<vector<int> > > config;
	
	for(unsigned int i=0;i<v.size();i++){
		
		if(v[i].at(1)==v[i].at(3)){
			bool flag = true;
			for(unsigned int j=0;j<v.size();j++){
				
				if(i!=j){
					if(((((v[i].at(2))+1) >= (v[j].at(0))) && 
					(((v[i].at(2))+1) <=(v[j].at(2)))) && 
					(((v[i].at(3)) >= (v[j].at(1))) && 
					((v[i].at(3)) <= (v[j].at(3))))){
						flag= false;
					}
					else if(v[i].at(2)==(columns-1)){
						flag =false;					
					}
				}
			}
			if(flag==true){	
				vector<vector<int> > temp1(vect_size,vector<int>(4));
				for(unsigned int a=0;a<v.size();a++){
					for(unsigned int b=0;b<v[a].size();b++){
						temp1[a].at(b)= v[a].at(b);
					}
				}
				// check for boolean to make moves
				
				temp1[i].at(0)= (temp1[i].at(0))+1;
				
				temp1[i].at(2)= (temp1[i].at(2))+1;
				config.push_back(temp1);
				
			}			
			
			flag=true;			//moves to go left
			for(unsigned int j=0;j<v.size();j++){
				if(i!=j){
					if(((((v[i].at(0)-1)) >= (v[j].at(0))) 
					&& (((v[i].at(0))-1) <= (v[j].at(2)))) 
					&& (((v[i].at(1)) >= (v[j].at(1))) 
					&& ((v[i].at(1)) <= (v[j].at(3)))))   	{
						
						flag= false;
					}
					// wall condition	
					else if(v[i].at(0)==0){
						flag = false;
					}		
				}
			}
						
			if(flag==true){	
				
				vector<vector<int> > temp2(vect_size,vector<int>(4));
				for(unsigned int a=0;a<v.size();a++){
					
					for(unsigned int b=0;b<v[a].size();b++){
						temp2[a].at(b)= v[a].at(b);
					}
				}
				
				//(*o)<<"moves to go left"<<endl;
				temp2[i].at(0)= (temp2[i].at(0))-1;
				temp2[i].at(2)= (temp2[i].at(2))-1;
				config.push_back(temp2);			
			}
					
		}				
		
		//moves for vertical cars
		
		else {	
			
			bool flag=true;
			for(unsigned int j=0;j<v.size();j++){
				
				if(i!=j){
					// check for moves to go down	
					
				    if(((v[i].at(2)>=v[j].at(0)) 
				    && (v[i].at(2)<=v[j].at(2))) 
				    && ((v[i].at(3)+1) >=(v[j].at(1))) 
				    && ((v[i].at(3)+1)<=(v[j].at(3)))){
						
						flag=false;
					}
					
					//wall condition
					else if(v[i].at(3)==(rows-1)){
						flag=false;	
						
					}
				}
				
			} //end j for loop	
			
			
			if(flag==true){
				vector<vector<int> > temp3(vect_size,vector<int>(4));
				
				for(unsigned int a=0;a<v.size();a++){
					
				    for(unsigned int b=0;b<v[a].size();b++){
						
						temp3[a].at(b)=v[a].at(b);
						
					}
				}
				
				//moves to go down
				temp3[i].at(1)=(temp3[i].at(1))+1;
				temp3[i].at(3)=(temp3[i].at(3))+1;
				config.push_back(temp3);
			}
			
			flag=true;
			
			for(unsigned int j=0;j<v.size();j++){
				
				if(i!=j){
					//check for moves to go up
					if((v[i].at(0)>=v[j].at(0)) 
					&& (v[i].at(0)<=v[j].at(2)) 
					&& ((v[i].at(1)-1)>=(v[j].at(1))) 
					&& ((v[i].at(1)-1)>= (v[j].at(3)))){
						flag=false;
					}
					
					//wall condition	
					else if(v[i].at(1)==0){
						flag=false;	
						
					}
				}
				
			}
			if(flag==true){
				vector<vector<int> > temp4(vect_size,vector<int>(4));
				for(unsigned int a=0;a<v.size();a++){
				    for(unsigned int b=0;b<v[a].size();b++){
						temp4[a].at(b)=v[a].at(b);
					}	
				}
				
				//moves to go up
				temp4[i].at(1)=(temp4[i].at(1))-1;
				temp4[i].at(3)=(temp4[i].at(3))-1;
				config.push_back(temp4);
				
			}
		}  // end of else	
		
	}    //end of for
	return config;
}//end function		

bool Jam_config:: isGoal_config(vector<vector<int> > config)const{
	
	
	if(config[vect_size-1][2]==(columns-1)) {
		return true;
	}
	return false;
}

void Jam_config::display(vector<vector<int> >cfg, 
				vector<vector<int> >initial,map<vector<vector<int> >,
				vector<vector<int> > > trackpath){
	
	deque<vector<vector<int> > > path;
	path.push_back(cfg);
	
	map<vector<vector<int> > ,vector<vector<int> > >
							::iterator it = trackpath.find(cfg);
	while(it->second!=initial){
		it=trackpath.find(cfg);
		path.push_front(it->second);
		cfg=it->second;
	}	
	
	
	(*o)<<"\nInitial Status:\n";
	for(unsigned int i=0;i<path.size();++i){ 
		vector<vector<int> > prev;
		if(i != 0) {
			prev = path[i-1];
		}
		
		for(unsigned int j =0 ;j<path[i].size();++j){
			
			(*o)<<"Car "<<j<<":";
			(*o)<<"Position: "<<"("<<path[i][j].at(0)<<","
								<<path[i][j].at(1)<<")";
			(*o)<<"("<<path[i][j].at(2)<<","<<path[i][j].at(3)<<")\n";
			if (i != 0) {
				
				if(isHorizontalCar(path[i][j])) {
					if (isMotionToRight(prev[j], path[i][j])) {
						(*o) << "Moved to right";	
					} else if(isMotionToLeft(prev[j], path[i][j])) {
						(*o) << "Moved to left";
					} else {
						(*o) << "No movement";
					}
				} else {
					if (isMotionToTop(prev[j], path[i][j])) {
						(*o) << "Moved up";	
					} else if(isMotionToBottom(prev[j], path[i][j])) {
						(*o) << "Moved down";
					} else {
						(*o) << "No movement";
					}
				}
				(*o) << "\n";
			}
			(*o) << "\n";
				
		}
		(*o)<<"--------------------------------------"<<"\n";	
	}
}

bool Jam_config::isHorizontalCar(vector<int> coord) const{
	return (coord[0] != coord[2])?true:false;
}

bool Jam_config::isMotionToRight(vector<int> prev,vector<int>curr)const{
	return (prev[0] < curr[0])?true:false;
}
bool Jam_config::isMotionToTop(vector<int> prev,vector<int>curr)const{
	return (prev[1] > curr[1])?true:false;
}
bool Jam_config::isMotionToLeft(vector<int> prev,vector<int>curr)const{
	return (prev[0] > curr[0])?true:false;
}
bool Jam_config::isMotionToBottom(vector<int>prev,vector<int>curr)const{
	return (prev[1] < curr[1])?true:false;
}

Jam_config::~Jam_config()
{}


