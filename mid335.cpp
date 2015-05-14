//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	Z,
	END = Z,
	HALF_STEPS_PER_OCTAVE = B 
} note_t;

double freq(note_t note, int octave_delta);
void test(double data[][8],double tol);


int main(int argc, char *argv[])
{
    
	note_t note;
	int octave_delta;
	double data[7][8];
	double tol;
	
        data[1][0]=27.50;
        data[1][1]=55.00;
        data[1][2]=110.00;
        data[1][3]=220.00;
        data[1][4]=440.00;
        data[1][5]=880.00;
        data[1][6]=1760.00;
        data[1][7]=3520.00;
        data[1][8]=7040.00;
        data[2][0]=30.87;
        data[2][1]=61.74;
        data[2][2]=123.47;
        data[2][3]=246.94;
        data[2][4]=493.88;
        data[2][5]=987.77;
        data[2][6]=1975.53;
        data[2][7]=3951.07;
        data[2][8]=7902.13;
        data[3][0]=16.35;
        data[3][1]=32.70;
        data[3][2]=65.41;
        data[3][3]=130.81;
        data[3][4]=261.63;
        data[3][5]=523.25;
        data[3][6]=1046.50;
        data[3][7]=2093.00;
        data[3][8]=4186.01;
        data[4][0]=18.35;
        data[4][1]=36.71;
        data[4][2]=73.42;
        data[4][3]=146.83;
        data[4][4]=293.66;
        data[4][5]=587.33;
        data[4][6]=1174.66;
        data[4][7]=2349.32;
        data[4][8]=4698.63;

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA> " << endl;
		return 0;
	}
	//
	note = (note_t)(toupper(argv[1][0]) - 64);
	switch(toupper(argv[1][0])) {
		case 'A': note = A; break;
		case 'B': note = B; break;
		case 'C': note = C; break;
		case 'D': note = D; break;
		case 'E': note = E; break;
		case 'F': note = F; break;
		case 'Z': note = Z; break;	  
	}
	//You may call your unit test here...
	tol = atoi(argv[2]);
        //if(note=='Z'){	    
		test(data,tol);
	//}	

	if (note > END) {
		cout << "Invalid note!" << endl;
		return 1;
	}
	//octave_delta = atoi(argv[2]);
	
	//cout << HALF_STEPS_PER_OCTAVE << endl;
	//cout << freq(note, octave_delta) << endl;
	return 0;
}
/*
	data[1][0]=27.50;
	data[1][1]=55.00;
	data[1][2]=110.00;
	data[1][3]=220.00;
	data[1][4]=440.00;
	data[1][5]=880.00;
	data[1][6]=1760.00;
	data[1][7]=3520.00;
	data[1][8]=7040.00;
	data[2][0]=30.87;
	data[2][1]=61.74;
	data[2][2]=123.47;
	data[2][3]=246.94;
	data[2][4]=493.88;
	data[2][5]=987.77;
	data[2][6]=1975.53;
	data[2][7]=3951.07;
	data[2][8]=7902.13;
	data[3][0]=16.35;
	data[3][1]=32.70;
	data[3][2]=65.41;
	data[3][3]=130.81;
	data[3][4]=261.63;
	data[3][5]=523.25;
	data[3][6]=1046.50;
	data[3][7]=2093.00;
	data[3][8]=4186.01;
	data[4][0]=18.35;
	data[4][1]=36.71;
	data[4][2]=73.42;
	data[4][3]=146.83;
	data[4][4]=293.66;
	data[4][5]=587.33;
	data[4][6]=1174.66;
	data[4][7]=2349.32;
	data[4][8]=4698.63;
*/



void test(double data[][8],double tol)
{
	double diff;
	int count=0;

	for(int o=0;o<8;o++){
		diff= data[1][o]-freq(A,o);
		
		if(diff<0){
			diff=diff*-1.00;
		}
		cout<<"note = A  "<<"  octave="<<o<<"  value = "<<freq(A,o)<<"  diff= "<<diff;
		if(diff>tol){
			cout<<"  bad \n";
			count++;
		}else{
			cout<<"  good \n";
		}
	}

	cout<<"number of bad elements="<<count<<endl;
}
//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
	double freq;
	double factor;
	double a;
	int n;
	int octave = octave_delta - F0_octave;

	a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
	n = note - F0_note;
	freq = F0 * pow(a, (double)n);
	factor = pow(2.0, (double)octave);
	freq = freq * factor;
	return freq;
}

