//
//  Driver file
//  main.cpp
//  Data Structures
//
//  Created by Omar Nouh on 9/27/25.
//

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string deletor(string word);
vector<int> windowMax (int k, const int size, int* array);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    string word;
    cout << "please enter your string" << endl;
    getline(cin, word);
    string output = deletor(word);
    cout << "the edited string is \"" << output << "\"" << endl;

    int k, size;
    cout << "please provide the size of your integer array" << endl;
    cin >> size;
    cout << "please enter the window size" << endl;
    cin >> k;
    int* arr = new int[size];
    cout << "please enter the array (separated by whitespaces)" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    vector<int> maximums = windowMax(k, size, arr);
    cout << "the sliding window max is: [ ";
    for (int i = 0; i < maximums.size(); i++) {
        cout << maximums[i] << " ";
    }
    cout << "]\n";
    
    
    return EXIT_SUCCESS;
}

string deletor(string word) {
        // solution to question 1
        
        // using the stack from <stack> who's main functions are push, pop, top, empty and size
    string output;
    if (word.size()) {
//        int i = 0;                                      // counter to find index of char
        
            //    cout << "please enter the string" << endl;      // debugging purposes
            //    cout << "thank you" << endl;                    // debugging purposes
        
        stack<char> St_temp, St;
        
            // Phase one: skip every two char --> the char follwed by * and the * itself
        
        for (char c : word) {
            if (c == '*') {
                if (!St_temp.empty()) {
                    St_temp.pop();
                }
            }
            else {
                St_temp.push(c);
            }
        }
         
        /*
        while (i < word.size()) {
  //        cout << i ;                               // debugging purposes
            St_temp.push(word[i]);
            if (word[i] == '*') {
                St_temp.pop();
                St_temp.pop();
            }
            **
            if (word[i+1] == '*' || word[i] == '*') {
                    //word.erase(i+1, 1);       // to erase the char altogether
                i++;                                    // to avoid infinite loop
                continue;
            }
            else St_temp.push(word[i]);                 // if neither condition is fulfilled then we can push into the Stack
             **
            i++;
        }
        */
            // Phase two: empty the reverse ordered chars into a new stack to read in the correct sequence
        
        while (!(St_temp.empty())) {
                //        cout << endl << St_temp.top(); // debugging purposes
            St.push(St_temp.top());
            St_temp.pop();
        }
        
            // Phase three: fill the String
        
        while (!(St.empty())) {
            output.push_back(St.top());
            St.pop();
        }
    }
    return output;
}

vector<int> windowMax (int k, const int size, int* array) {
    vector<int> maximums;                   // create the returning vector
    if (k < 0 || size <= 0 || k > size) {   // avoiding errors
        return maximums;
    }
    int temp, counter = 0;                  // create helper variables that store the value that will be compared and the counter to shift the window
    queue<int> Q;                           // create the queue that will store the variables inside
    while ((counter + k) <= size) {         // shift the window until the end of the window coincides with the end of the array
        for (int i = 0; i < k; i++) {       // fill the window
            Q.push(array[(counter + i)]);
//            cout << array[(counter + i)]; // debugging code
        }
        int /*j = 0, */max = Q.front();         // setup the window max calculator
        
        do {
            temp = Q.front();
            Q.pop();
//            max = std::max(Q.front(), temp);
            if (max < temp) {
                max = temp;
            }
//            if (j == k-1) {                 // special case to compare the last variable to avoid accessing empty queue
//                if (max < temp) {
//                    max = temp;
//                }
//            } else {                        // compare every element with next and store larger in max
//                if (Q.front() < temp) {
//                    if (max < temp) {
//                        max = temp;
//                    }
//                }
//            }
//            j++;
        } while (!Q.empty()/*j < k*/);                    // loop until counter reaches end of window
        maximums.push_back(max);            // concatinate the max to the string
        counter++;
    }
    return maximums;
}
