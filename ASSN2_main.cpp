#include <iostream>
#include <fstream> 
#include "ASSN2_linkedlist.h"
#include "ASSN2_queue.h"
#include "ASSN2_stack.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void welcome();
void exit ();
void menu();
void menu1();
void swap( string &, int, int);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList <string> name;
	DynamicQueue<string> queue;
	stack<string> st;
	ifstream inputFile; 
	
	string word, word1, word2;
	int choice, choice1, n, s, b;
	
	welcome();
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	//open the files
	inputFile.open("ASSN2_TXT.txt");
	
	while (!inputFile.eof()) //read data from file
	{
		if (inputFile.eof()==true)
			break;
		
		else
		{
			// read textfile
			inputFile >> word;
			
			// put the word in the linked list
			name.appendNode(word);
		}		
	}
	// close the files
	inputFile.close();
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	do
	{
		menu();
		cout << "\n\n\t\tEnter your choice  :  ";
		cin >> choice;
		
		while(cin.fail()) // input must same data type as what we had declared //VALIDATE choice
		{ 
    		cout<<"\n\n\n\n\t\tInvalid input!!!\n\n\t\t";
    		cin.clear();
     		cin.ignore(256,'\n');
     		system("pause");
     		system("cls");
			menu();
			cout<<"\n\n\t\tEnter choice : ";
        	cin>>choice;
  		}
  		
		switch (choice)
		{
			case 1 : //add new word in the linked list
					system("cls");
					cout << "\n\n\t\t\t\t====================\n";
					cout << "                                    ADD NEW WORD";
					cout << "\n\t\t\t\t====================";
					cout << "\n\n\n\t\tTo add, please use UPPERCASE LETTER ONLY...\n";
					cout << "\t\tTo return, press 0 (zero)...\n\n\n";
					cout << "\t\tEnter your choice  :  ";
					cin >> word;
					
					// if user press 0 (zero)
					if (word == "0")
					{
						system("cls");
						break;
					}
					
					else
					{
						b = 0;
						name.searchData(word, b);
						
						if (b == 1)
						{
							cout << "\n\n\n\n\t\t" << word << " already available in this program...";
						}
						
						else
						{	
							cout << "\t\tThis word was added in data...";
							name.appendNode(word);
						}
					}
		
					cout<<"\n\n\t\t";
					system("pause");
     				system("cls");
					break;
			case 2 : //all word
     				system("cls");
					cout << "\n\n\t\t\t\t=====================\n";
					cout << "                                  DISPLAY ALL WORDS";
					cout << "\n\t\t\t\t=====================";
					
					cout << "\n\n\n\n\t\tWords available are  :\n\n";
					name.displayList();
					cout<<"\n\n\t\t";
					system("pause");
     				system("cls");
					break;
			case 3 : //search
					system("cls");
					cout << "\n\n\t\t\t\t====================\n";
					cout << "                                       SEARCH";
					cout << "\n\t\t\t\t====================";
					cout << "\n\n\n\t\tTo search, please use UPPERCASE LETTER ONLY...\n";
					cout << "\t\tTo return, press 0 (zero)...\n\n\n";
					cout << "\t\tEnter your choice  :  ";
					cin >> word;
					
					if (word == "0")
					{
						system("cls");
						break;
					}
					
					b = 0;
					name.searchData(word, b);
					
					
					if (b==1)
					{
					do
					{
						word2 = word;
						cout << "\n\n\n\n\t\tWord searched = " << word << "\n\n"; 
						menu1();
						cout << "\n\n\t\tEnter your choice  :  ";
						cin >> choice1;
				
						while(cin.fail()) // input must same data type as what we had declared //VALIDATE choice
						{ 
    						cout<<"\n\n\n\n\t\tInvalid input!!!\n\n\t\t";
    						cin.clear();
     						cin.ignore(256,'\n');
     						system("pause");
     						system("cls");
							menu();
							cout<<"\n\n\t\tEnter choice : ";
        					cin>>choice1;
  						}
  						
  						s=1;
  						
  						//n = total character in string
						int n = word2.size();
						
						int p[n] = {0};

						// i, j represents the index for swapping
						int i = 1, j = 0;

						// display the string
						queue.enqueue(word2);

						while (i < n)
						{
							if (p[i] < i)
							{
								// if i is odd then j = p[i], otherwise j = 0
								j = (i % 2) * p[i];

								swap(word2, j, i);

								// Print current permutation
								queue.enqueue(word2);
								s++; //counter to count total anagram

								p[i]++; // increase index "weight" for i by one
								i = 1;  // reset index i to 1
							}
									
							// otherwise p[i] == i
							else
							{
								// reset p[i] to zero
								p[i] = 0;

								// set new index value for i (increase by one)
								i++;
							}
										
						}
						
						for ( int e = 0; e < s; e++)
						{
							queue.dequeue(word1);
							st.Push(word1);
						}
						
		
						switch (choice1)
						{
							case 1 ://disp all anagram
									{
									int i = 5;
									cout << "\n\n\n\n\t\tTotal permutation for " << word << " is " << s << " :\n\n\n";
									for (int w = 0; w < s; w++)
									{
										st.Pop(word1);
										cout << "\t\t\t" << w+1 << ". " << word1 << endl;
										
										if (w+1== i*10)
										{
											cout << "\n\n\n\n\t\tTo be continued...";
											cout<<"\n\n\t\t";
											system("pause");
     										system("cls");
     										cout << "\n\n\n\n\t\tTotal permutation for " << word << " is " << s << " :\n\n\n";
     										cout << "\n\n\n\n\t\tContinuation....\n\n\n";
     										i+=5;
										}
									}
									
									cout<<"\n\n\t\t";
									system("pause");
     								system("cls");
									break;
								}
							case 2 ://disp anagram start with...
									{
									int i = 5;
									char letter;
									int a = 0;
									cout << "\n\n\n\n\t\tTotal permutation for " << word << " is " << s << " :";
									cout << "\n\n\n\n\t\tEnter a letter to start generating the anagram  :  ";
									cin >> letter;
									
									int l = 0;
									
									for(int o = 0; o < n; o++)
									{
										if (letter == word[o])
										l++;
									}
									
									if (l == 0)
									cout << "\n\n\n\n\t\tWord " << word << " do not have the letter you entered!";
									
									cout << "\n\n\n\n";
									for (int w = 0; w < s; w++)
									{
										st.Pop(word1);
										
										if (word1[0] == letter)
										{
											a++;
											cout << "\t\t\t" << a << ". " << word1 << endl;
											
											if (a== i*10)
											{
												cout << "\n\n\n\n\t\tTo be continued...";
												cout<<"\n\n\t\t";
												system("pause");
     											system("cls");
     											cout << "\n\n\n\n\t\tTotal permutation for " << word << " is " << s << " :\n\n\n";
     											cout << "\n\n\n\n\t\tContinuation....\n\n\n";
     											i+=5;
											}
										}
									}
									cout<<"\n\n\t\t";
									system("pause");
     								system("cls");
									break;
									}
									
							case 3 ://update
									cout << "\n\n\n\n\t\tEnter your new word to update  :  ";
									cin >> word2;
									name.insertNode(word2, word);
									name.deleteNode(word);
									for (int w = 0; w < s; w++)
										st.Pop(word1);
									word = word2;
									cout<<"\n\n\t\t";
									system("pause");
     								system("cls");
									break;
									
							case 4 ://add after
									for (int w = 0; w < s; w++)
										st.Pop(word1);
									cout << "\n\n\n\n\t\tEnter new word you want to put after this word  :  ";
									cin >> word1;
									name.insertNode(word1, word);
									cout<<"\n\n\t\t";
									system("pause");
     								system("cls");
									break;
									
							case 5 ://delete
									for (int w = 0; w < s; w++)
										st.Pop(word1);
									name.deleteNode(word);
									cout << "\n\n\n\n\t\tWord " << word << " was deleted...";
									cout<<"\n\n\t\t";
									system("pause");
     								system("cls");
									break;
									
							case 6 ://exit
									for (int w = 0; w < s; w++)
										st.Pop(word1);
									break;
									
							default://re-enter
									for (int w = 0; w < s; w++)
										st.Pop(word1);
									cout<<"\n\n\n\n\t\tInvalid input!!!\n\n\t\t";
									system("pause");
     								system("cls");
									break;
						}
					} while(choice1 != 6 && choice1 != 5 && choice1 != 4);
					}				
					cout<<"\n\n\t\t";
					system("pause");
     				system("cls");
					break;
			case 4 : //exit
					exit();
					break;
			default ://re=enter
					cout<<"\n\n\n\n\t\tInvalid input!!!\n\n\t\t";
					system("pause");
     				system("cls");
					break;
					
	}
	}while ( choice != 4);
	

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void swap( string & name, int j, int i) // normal function definition : swap the letter
{
	char temp = name[i];
	name[i] = name[j];
	name[j] = temp;
}

void welcome() // normal function definition : to display welcome note
{
	cout <<"\n\n\n\t";	
	cout << "\n\n\n\n\t\t  **   **   **   *******   **         *******    *******    ***      ***   *******\n";
	cout << "\t\t  **  ****  **   **        **        **         **     **   ****    ****   **\n";
	cout << "\t\t  ** **  ** **   *******   **        **         **     **   ** **  ** **   *******\n";
	cout << "\t\t  ****    ****   **        **        **         **     **   **  ****  **   **\n";
	cout << "\t\t  ***      ***   *******   *******    *******    *******    **   **   **   *******\n\n\n";
//	Sleep (500);
	cout<< "\t\t\t\t\t       ********    *******\n";
	cout<< "\t\t\t\t\t          **      **     **\n";
	cout<< "\t\t\t\t\t          **      **     **\n";
	cout<< "\t\t\t\t\t          **      **     **\n";
	cout<< "\t\t\t\t\t          **       *******\n\n";
//	Sleep (500);	
	cout<< "\t____________________________________________________________________________________________________\n\n\n";		
	cout<< "\t\t\t\t\t      - 'ANAGRAM GENERATOR' -\n\n";
	cout<< "\t\t\t\t\tThank you for choosing this program...\n\n";
	cout<< "\t____________________________________________________________________________________________________\n\n";
	cout<< "\t\t";
//	Sleep (500);
	cout << "\n\n\t\t\t";
	system("pause");
	system("cls");
}

void exit () // normal function definition : to display exit note
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t********  **     **    *******    ***   **   **   **       **    **   *******    **     **\n";
	cout << "\t\t   **     **     **   **     **   ****  **   **  **         **  **   **     **   **     **\n";
	cout << "\t\t   **     *********   *********   ** ** **   ****             **     **     **   **     **\n";
	cout << "\t\t   **     **     **   **     **   **  ****   **  **           **     **     **   **     **\n";
	cout << "\t\t   **     **     **   **     **   **   ***   **   **          **      *******     *******\n";
//	Sleep (50);
	cout<< "\n\n\t______________________________________________________________________________________________________\n\n\n";
	cout<< "\t\t\t\t\t\t  for using this program\n\n";
	cout << "\t\t\t\t\t       AND PLEASE COME AGAIN...  :)";
	cout<< "\n\n\t______________________________________________________________________________________________________\n\n\n";
}

void menu() // normal function definition : display menu
{
	cout << "\n\n\t\t\t\t====================\n";
	cout << "                                        MENU";
	cout << "\n\t\t\t\t====================\n\n";
	cout << "                        | 1 | Add new word                |\n";
	cout << "                        | 2 | Display all words           |\n";
	cout << "                        | 3 | Search                      |\n";
	cout << "                        | 4 | Exit                        |\n";
}

void menu1() // normal function definition : display menu
{
	cout << "\n\n\t\t\t\t====================\n";
	cout << "                                        MENU";
	cout << "\n\t\t\t\t====================\n\n";
	cout << "                       | 1 | Display all anagram           |\n";
	cout << "                       | 2 | Display anagram start with..  |\n";
	cout << "                       | 3 | Update word                   |\n";
	cout << "                       | 4 | Add new word after this word  |\n";
	cout << "                       | 5 | Delete this word              |\n";
	cout << "                       | 6 | Return                        |\n";
}
