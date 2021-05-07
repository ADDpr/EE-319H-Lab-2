// ****************** Lab2.c ***************
// Program written by: Anthony Do
// Date Created: 1/18/2017 
// Last Modified: 1/17/2021 
// Put your name and EID in the next two line
char Name[] = "Anthony Do";
char EID[] = "add3254";
// Brief description of the Lab: 
// An embedded system is capturing temperature data from a
// sensor and performing analysis on the captured data.
// The controller part of the system is periodically capturing size
// readings of the temperature sensor. Your task is to write three
// analysis routines to help the controller perform its function
//   The three analysis subroutines are:
//    1. Calculate the mean of the temperature readings 
//       rounded down to the nearest integer
//    2. Convert from Centigrate to Farenheit using integer math 
//    3. Check if the captured readings are a non-increasing monotonic series
//       This simply means that the readings are sorted in non-increasing order.
//       We do not say "decreasing" because it is possible for consecutive values
//       to be the same, hence the term "non-increasing". The controller performs 
//       some remedial operation and the desired effect of the operation is to 
//       raise the the temperature of the sensed system. This routine helps 
//       verify whether this has indeed happened
#include <stdint.h>
#define True 1
#define False 0

// Return the computed Mean
// Inputs: Data is an array of 16-bit unsigned distance measurements
//         N is the number of elements in the array
// Output: Average of the data
// Notes: you do not need to implement rounding
uint16_t Average(const uint16_t Data[],const uint32_t N){
		
		uint16_t avg = 0;
		uint16_t sum = 0;
		
		for(int i = 0; i < N; i++){
			sum += Data[i];
		}
		avg = (sum/N);
	
    return avg;
}

// Convert temperature in Farenheit to temperature in Centigrade
// Inputs: temperature in Farenheit 
// Output: temperature in Centigrade
// Notes: you do not need to implement rounding
int16_t FtoC(int16_t const TinF){
	
	int16_t TinC = ((TinF - 32)*5)/9; //formula from F -> C
  
  return TinC;
}

// Return True of False based on whether the readings
// are an increasing monotonic series
// Inputs: Readings is an array of 16-bit distance measurements
//         N is the number of elements in the array
// Output: true if monotonic increasing, false if nonmonotonic
int IsMonotonic(uint16_t const Data[], int32_t const N){
	
	int32_t count = 0; //counts the number of elements that are >= to prev.
	
	if(N == 1){
		return True; //series is inc. mono. if size 1; no elements to compare to
	}
	
	for(int i = 1; i < N; i++){
		if(Data[i] >= Data[i-1]){
			count++;  //element is increasing/equal
		}
	}
  if(count == (N-1)){
		return True; //all elements are increasing/equal
	}
	return False;
}


