#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Purpose: 
Given a sentence, arrange the words in reverse order. 
*/

bool isAlphabet(char c)
{
	if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
		return true;
	}

	return false;
}

void getWordStartStopPosition(vector<pair<int, int> >* pt_word_start_stop_position, 
	const string& s)
{
	int left = -1;
	int right = -1;
	for(int i = 0; i < s.size(); ++i)
	{
		if(left == -1 && isAlphabet(s[i])){
			// Beginning of the word
			left = i;
			right = i;
		}
		else if(left >= 0 && isAlphabet(s[i])){
			// In the middle of the word
			++right;
		}
		else if(left >=0 && !isAlphabet(s[i])){
			// End of the word
			pt_word_start_stop_position->emplace_back(left, right);
			cout << "left = " << left << " right = " << right << endl;
			left = -1;
			right = -1;
		}
		else if(left == -1 && !isAlphabet(s[i])){
			// Continuation of not a word
			continue;
		}

		if( left >=0 && i == s.size() - 1 ){
			// Last word
			pt_word_start_stop_position->emplace_back(left, right);
		}
	}
}

void reverseEachWord(string* pt_s, const pair<int, int>& wordStartEnd)
{
	int begin = wordStartEnd.first;
	int end = wordStartEnd.second;

	for(int i = begin, j = end; i < j; ++i, --j)
	{
		swap(pt_s->at(i), pt_s->at(j));
	}
}

void reverseAllWordsInPlace(string* pt_s, const vector<pair<int, int> >& word_start_end_positions)
{
	for(int wordIdx = 0; wordIdx < word_start_end_positions.size(); ++wordIdx)
	{
		reverseEachWord(pt_s, word_start_end_positions[wordIdx]);
	}

	cout << *pt_s << endl;
}

void reverseString(string* pt_s)
{
	for(int i = 0, j = pt_s->size() - 1; i < j; ++i, --j)
	{
		swap(pt_s->at(i), pt_s->at(j));
	}
}

void reverseWordsInSentence(string* pt_s)
{
	string& s = *pt_s;

	vector<pair<int, int> > word_start_end_positions;
	getWordStartStopPosition(&word_start_end_positions, s);
	reverseAllWordsInPlace(&s, word_start_end_positions);
	reverseString(&s);
}

int main()
{
	string s = "This is a beautiful day";
	reverseWordsInSentence(&s);

	cout << s << endl;
}