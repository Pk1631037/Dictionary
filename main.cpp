#include <iostream>
#include "Dictionary.hpp"
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
using namespace std;


int Search();
int HelpManual();


Dictionary a;



int HelpManual()
{

    cout << endl;

    cout << "---------------" << endl;

    cout << endl;
    cout << "Instructions:" << endl;
    cout << "\n1) From Main Menu Press 3" << endl;
    cout << "2) Then Type the word to search" << endl;
    cout << "3) The search result will be given below." << endl << endl;

   return 0;
}


int Search()
{

    cout << "\nType a word to search for it's meaning." << endl << endl;

    string s;
    while(cin >> s)
    {
        string ss = "";
        for(int i = 0; s[i]; ++i)
            ss += tolower(s[i]);

        Pair WordInfo = a.SearchItem(ss);
        cout << endl;

        cout << "Search Result:" << endl;
        cout << "---------------" << endl << endl;

        if(WordInfo.wordId < 1)
        {
            cout << "No meanings were found for " << "'" << s << "'" << "." << endl;
            cout << endl;
        }
        else
        {
            cout << "Word: " << s << endl;
            cout << "Word ID: " << WordInfo.wordId << endl;
            cout << "Meaning: " << WordInfo.meaning << endl;
            cout << endl;
            break;

        }

        cout << "-------x-------" << endl;
        cout << endl;


    }
    return 0;
}



void BuildTrie()
{
    ifstream fin;
    fin.open("data.txt");


    while(!fin.eof())
    {
        string word,meaning;
        fin >> word;
        fin.ignore();
        getline(fin, meaning);

        a.InsertItem(word, meaning);
    }

    fin.close();
}




int main()
{
	system("color 0C");
    BuildTrie();

 int n=1;
    while (n!=0)
    {
        system("cls");
        system("more ASCII.txt");
        cout << endl;
        cout << "You Can Search Any Word and It will Show The Corresponding Meaning\n" << endl;
        cout << "Press Any Of The Key To Go For: " << endl;
        cout << " 1 >> Search For Word." << endl;
        cout << " 2 >> Help Manual." << endl;
        cout << " 3 >> Spell Checker" << endl;
        cout << " 4 >> Word of the Day" << endl;
        cout << " 0 >> Quit." << endl;
        cout << "\nYour Choice : ";
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 :
            Search();
            system("pause");
            break;
        case 2:
            HelpManual();
            system("pause");
            break;
        case 3:
        	system("spell_checker_TRIE.exe");
        	system("pause");
        	break;
        case 4:
        	system("finalwaste.exe");
        	system("pause");
        	break;
        case 0:
            n=0;
            break;
        default:
            cout<<endl<<"Wrong Choice Try Again"<<endl;
            system("pause");
        }



}
}



Dictionary::Dictionary() {
	root = new node();
	wordCounter = 0;
}


string Dictionary::Word(int ID) {
	return word[ID];
}

void Dictionary::WordSetter(int ID, string w) {
	word[ID] = w;
}



void Insert(node *root, string item, string meaning, int cnt)
{
	node *curr = root;
	int id, len = (int)item.size();

	for (int i = 0; i < len; i++)
	{
		char ch = item[i];
		if (isupper(ch)) id = (ch - 'A') + 26;
		else id = (ch - 'a');

		if (curr->next[id] == NULL)
			curr->next[id] = new node();

		curr = curr->next[id];
	}
	curr->endmark = true;
	curr->wordMeaning = meaning;
	curr->wordID = cnt;

}


void Dictionary::InsertItem(string item, string meaning)
{
	Insert(root, item, meaning, ++wordCounter);

	WordSetter(wordCounter, item);
}



Pair isFound(node *root, string item)
{
	node *curr = root;
	int id, len = (int)item.size(), wID = -1; string wM = "Not Found";
	if (!isalpha(item[0])) return { wM,wID };
	for (int i = 0; i<len; i++)
	{
		char ch = item[i];
		if (isupper(ch)) id = (ch - 'A') + 26;
		else id = (ch - 'a');

		if (curr->next[id] == NULL) 
		return { wM,wID };
		curr = curr->next[id];
	}

	wM = curr->wordMeaning;
	wID = curr->wordID;

int visited[100000];
	return { wM,wID };
}


Pair Dictionary::SearchItem(string item)
{
	Pair res = isFound(root, item);
	return res;
}

void Dictionary::addSynonym(string w1, string w2) {
	int id1 = isFound(root, w1).wordId;
	int id2 = isFound(root, w2).wordId;

	Synonym[id1].push_back(id2);
	Synonym[id2].push_back(id1);
}



