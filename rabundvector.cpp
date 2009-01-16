/*
 *  rabundvector.cpp
 *  
 *
 *  Created by Pat Schloss on 8/8/08.
 *  Copyright 2008 Patrick D. Schloss. All rights reserved.
 *
 */
using namespace std;
 
#include "datavector.hpp"
#include "utilities.hpp"
#include <exception>
#include "rabundvector.hpp"
#include "sabundvector.hpp"
#include "ordervector.hpp"


/***********************************************************************/

RAbundVector::RAbundVector() : DataVector(), maxRank(0), numBins(0), numSeqs(0) {};

/***********************************************************************/

RAbundVector::RAbundVector(int n) : DataVector(), data(n,0) , maxRank(0), numBins(0), numSeqs(0) {};

/***********************************************************************/

//RAbundVector::RAbundVector(const RAbundVector& rav) : DataVector(rav), data(rav.data), (rav.label),  (rav.maxRank), (rav.numBins), (rav.numSeqs){};


/***********************************************************************/

RAbundVector::RAbundVector(string id, vector<int> rav) : DataVector(id), data(rav) {
	try {
		numBins = 0;
		maxRank = 0;
		numSeqs = 0;
		
		for(int i=0;i<data.size();i++){
			if(data[i] != 0)		{	numBins = i+1;		}
			if(data[i] > maxRank)	{	maxRank = data[i];	}
			numSeqs += data[i];
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function RAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function RAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}


/***********************************************************************/


RAbundVector::RAbundVector(ifstream& f) : DataVector(), maxRank(0), numBins(0), numSeqs(0) {
	try {
		int hold;
		f >> label >> hold;
	
		data.assign(hold, 0);
		int inputData;
	
		for(int i=0;i<hold;i++){
			f >> inputData;
			set(i, inputData);
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function RAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function RAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/

RAbundVector::~RAbundVector() {

}

/***********************************************************************/

void RAbundVector::set(int binNumber, int newBinSize){
	try {
		int oldBinSize = data[binNumber];
		data[binNumber] = newBinSize;
	
		if(oldBinSize == 0)			{	numBins++;				}
		if(newBinSize == 0)			{	numBins--;				}
		if(newBinSize > maxRank)	{	maxRank = newBinSize;	}
	
		numSeqs += (newBinSize - oldBinSize);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function set. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function set. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/

int RAbundVector::get(int index){
	return data[index];
	
}

/***********************************************************************/

void RAbundVector::push_back(int binSize){
	try {
		data.push_back(binSize);
		numBins++;
	
		if(binSize > maxRank){
			maxRank = binSize;
		}
	
		numSeqs += binSize;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function push_back. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function push_back. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/

void RAbundVector::pop_back(){

	return data.pop_back();
}

/***********************************************************************/

void RAbundVector::resize(int size){
	
	data.resize(size);
}

/***********************************************************************/

int RAbundVector::size(){
	return data.size();
}

/***********************************************************************/

vector<int>::reverse_iterator RAbundVector::rbegin(){
	return data.rbegin();				
}

/***********************************************************************/

vector<int>::reverse_iterator RAbundVector::rend(){
	return data.rend();					
}

/***********************************************************************/
void RAbundVector::print(string prefix, ostream& output){
	try {	
		output << prefix << '\t' << numBins << '\t';
	
		vector<int> hold = data;
		sort(hold.rbegin(), hold.rend());
	
		for(int i=0;i<numBins;i++){		output << hold[i] << '\t';		}
		output << endl;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function print. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function print. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/
void RAbundVector::print(ostream& output){
	try {
		output << label << '\t' << numBins << '\t';
	
		vector<int> hold = data;
		sort(hold.rbegin(), hold.rend());
		
		for(int i=0;i<numBins;i++){		output << hold[i] << '\t';		}
		output << endl;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function print. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function print. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/
int RAbundVector::getNumBins(){
	return numBins;
}

/***********************************************************************/

int RAbundVector::getNumSeqs(){
	return numSeqs;
}

/***********************************************************************/

int RAbundVector::getMaxRank(){
	return maxRank;
}

/***********************************************************************/

RAbundVector RAbundVector::getRAbundVector(){
	return *this;			
}

/***********************************************************************/

SAbundVector RAbundVector::getSAbundVector() {
	try {
		SAbundVector sav(maxRank+1);
		
		for(int i=0;i<data.size();i++){
			int abund = data[i];
			sav.set(abund, sav.get(abund) + 1);
		}
		sav.set(0, 0);
		sav.setLabel(label);
		return sav;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function getSAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function getSAbundVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/

OrderVector RAbundVector::getOrderVector(map<string,int>* nameMap = NULL) {
	try {
		OrderVector ov;
	
		for(int i=0;i<data.size();i++){
			for(int j=0;j<data[i];j++){
				ov.push_back(i);
			}
		}
		random_shuffle(ov.begin(), ov.end());

		ov.setLabel(label);	
		return ov;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RAbundVector class Function getOrderVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RAbundVector class function getOrderVector. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/
