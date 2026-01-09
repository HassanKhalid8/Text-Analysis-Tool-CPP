///////////////////////////////////
//This program that perform series of task analysis
///////////////////////////////////

//This include all header files which are needed for this program 
#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

//This function is used to merge both paragraph
string mergedpara(string para1, string para2){
    return para1 + " " + para2;
    }

//This function is used to count vowels
int countVowels(string str) {
    string vowels = "aeiouAEIOU";
    int count = 0;

    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }

    cout<<"vowels in this paragraph are "<<count<<endl;

    return count;
}

//This function is use to make whole paragraph lowercase
string to_lowercase(const string &str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

//This function is use to find location of first occurance
int firstoccurance(string word, string para){
    int location;
    location = para.find(word);
    cout<<"The first occurance of '"<<word<<"' is "<<location<<endl;
    return location;
}

//This function is use to find location of all occurances of a word
vector<int> AllOccurrences(const std::string& paragraph, const std::string& word) {
    vector<int> indices;
    stringstream ss(paragraph);
    string temp;

    int position = 0;
    while (ss >> temp) {
        if (temp == word) {
            indices.push_back(position);
        }
        position += temp.length() + 1;
    }
   
    return indices;
}

//This function is used to print histogram
void histogram_of_words(const string &paragraph) {
    map<string, int> word_count;
    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        word = to_lowercase(word);
        word_count[word]++;
    }

    cout << "Word Count Histogram in increasing order of words: " << endl;

    map<string, int> sorted_word_count(word_count.begin(), word_count.end());

    for (auto const &pair: sorted_word_count) {
        cout << pair.first << ": " << string(pair.second, '*') << endl;
    }
}

// Helper struct to represent word-frequency pairs
struct WordFrequency {
    string word;
    int frequency;
};

bool compareWordFrequency(const WordFrequency& a, const WordFrequency& b) {
    return a.frequency < b.frequency;
}

//This function is use to print histogram in increasing order
void histogram_in_increasing_order(const string& paragraph) {
    map<string, int> wordCount;

    // Use a string stream to extract words from the paragraph
    istringstream iss(paragraph);
    string word;

    while (iss >> word) {
        // Convert the word to lowercase to make the histogram case-insensitive
        for (char& ch : word) {
            ch = tolower(ch);
        }
        wordCount[word]++;
    }

    // Store word-frequency pairs in a vector
    vector<WordFrequency> wordFrequencies;
    for (const auto& pair : wordCount) {
        wordFrequencies.push_back({pair.first, pair.second});
    }

    // Sort the vector in increasing order based on word frequencies
    sort(wordFrequencies.begin(), wordFrequencies.end(), compareWordFrequency);

    // Print the histogram in increasing order
    cout << "Word Histogram (Increasing Order):" << endl;
    for (const auto& entry : wordFrequencies) {
        cout << entry.word << ": ";
        for (int i = 0; i < entry.frequency; ++i) {
            cout << '*';
        }
        cout << endl;
    }
}

//This function is use to reverse the paragraph
string reversedpara(string &paragraph) {
    stringstream ss(paragraph);
    string word, reversed_paragraph;

    while (ss >> word) {
        reverse(word.begin(), word.end());
        reversed_paragraph += word + " ";
    }

    return reversed_paragraph;
}

int main(){
    string Para1;
    string Para2;
    string MergedPara;                                                      //Variables needed 
    string word; 
    string ReversedParagraph;
    vector<int> indices;
    int choice;
  
    cout<<"Enter 1st Paragraph: "<<endl;
    getline(cin, Para1);
    cout<<"Enter 2nd Paragraph: "<<endl;
    getline(cin, Para2);                                                    //Input Paragraph
    cout<<"Enter word you need to find location of: ";
    getline(cin, word);
    
    while(true){
    cout<<"\n~~~~~~~~~~Text Analysis~~~~~~~~~~"<<endl;
    cout<<"1)Merge both Paragraph"<<endl;
    cout<<"2)Count the vowels"<<endl;
    cout<<"3)Find Location of first Occurrence of word"<<endl;
    cout<<"4)Find Location of all Occurrence of word"<<endl;                //Menu Interfernece
    cout<<"5)Create Histogram"<<endl;
    cout<<"6)Create Histogram in Increasing order"<<endl;
    cout<<"7)Reverse the paragraph"<<endl;
    cout<<"8)Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    
    switch(choice){
    case 1:
        MergedPara = mergedpara(Para1, Para2);
        cout<<"Merged para is: \n"<<MergedPara<<endl;                          //Merge Paragraph
        break;

    case 2:
        int B;
        cout<<"From which para you need to find vowels: ";
        cout<<"\n1)Paragraph 1";
        cout<<"\n2)Paragraph 2";
        cout<<"\n3)Merged Paragraph";
        cout<<"\nEnter your choice: ";
        cin>>B;
        if(B == 1){                                                             //Count vowels
        countVowels(Para1);}
        else if(B == 2){
        countVowels(Para2);}
        else if(B == 3){
        countVowels(MergedPara);}
        break;

    case 3:
        int D;
        cout<<"Which Paragraph you need to find first occurance: ";
        cout<<"\n1)Paragraph 1";
        cout<<"\n2)Paragraph 2";
        cout<<"\n3)Merged Paragraph";
        cout<<"\nEnter your choice: ";
        cin>>D;
        if(D == 1){                                                             //Find location of first occurace
        firstoccurance(word, Para1);}
        else if(D == 2){
        firstoccurance(word, Para2);}
        else if(D == 3){
        firstoccurance(word, MergedPara);}
        break;   

    case 4:
        indices = AllOccurrences(MergedPara, word);

    if (indices.empty()) {
        cout << "The word \"" << word << "\" was not found in the paragraph." << endl;      //location of all occurance
    } else {
        cout << "The word \"" << word << "\" was found at the following positions: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }
        break;
     
    case 5:
        histogram_of_words(MergedPara);                                         //histogram of words
        break;

    case 6:
        int c;
        cout<<"From which para you need to find vowels: ";
        cout<<"\n1)Paragraph 1";
        cout<<"\n2)Paragraph 2";
        cout<<"\n3)Merged Paragraph";
        cout<<"\nEnter your choice: ";
        cin>>c;
        if(c == 1){                                                             //Histogram in increasing order
        histogram_in_increasing_order(Para1);}
        else if(c == 2){
        histogram_in_increasing_order(Para2);}
        else if(c == 3){
        histogram_in_increasing_order(MergedPara);}
        break;
    
    case 7:
        int C;
        cout<<"Which Paragraph  you need to reverse: ";
        cout<<"\n1)Paragraph 1";
        cout<<"\n2)Paragraph 2";
        cout<<"\n3)Merged Paragraph";
        cout<<"\nEnter your choice: ";
        cin>>C;
        if(C == 1){
        ReversedParagraph = reversedpara(Para1);
        cout << "Reversed paragraph: " << ReversedParagraph << endl;}
        else if(C == 2){                                                          //Reverse the paragraph
        ReversedParagraph = reversedpara(Para2);
        cout << "Reversed paragraph: " << ReversedParagraph << endl;}
        else if(C == 3){
        ReversedParagraph = reversedpara(MergedPara);
        cout << "Reversed paragraph: " << ReversedParagraph << endl;}
        break;

    case 8:
       return 0;                                                                   //Exit the program
    
    default:
        break;
        }
    }
    return 0;

}
