#include "split.h"

int split(string toBeSplit, char delimiter, string words[], int length) //defines integer function split, with four input arguments
{
    if (toBeSplit.length() == 0) { //if the string length is 0, or nonexistent
        return 0; //returns 0
    }
    string str = ""; //defines string str, equal to empty
    int j = 0; //defines j as integer equal to 0
    toBeSplit = toBeSplit + delimiter; //sets string toBeSplit equal to itself plus delimiter
    for (int i = 0; i < toBeSplit.length(); i++) //for loop, starts integer i at 0, conditional i is less toBeSplit length, increases i by 1
    {
        if (toBeSplit[i] == delimiter) //if ith value is equal to delimiter
        {
        	if (str.length() == 0) continue; //if string length is 0, executes next iteration of loop 
            words[j] = str; //inputs string as jth value of array
            j++; //increases j by 1
            str = ""; //resets str to empty
        }
        else //else
        {
            str = str + toBeSplit[i]; //sets str equal to itself plus toBeSplit ith value
        }
    }
    return j; //returns value of j
}
