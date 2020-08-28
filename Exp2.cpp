#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <assert.h>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

#define MSG 180
const char heart[] = "\xe2\x99\xa5";
const char arrow[] = "\xe2\x86\x94";

struct post
{
  std::string message; //must not exceed 180 characters
  bool like;
  int num_likes = 0;
  bool reChirp;
  post *previous;
  post *next;
};
typedef post* postPtr;

class Chirp; //define chirp, as chirp contains an instance of itself
class Chirp
{
  private:
  string user;
  string display_name;
  postPtr head = nullptr; //head

  bool isEmpty();
  postPtr previous_chirp();
  postPtr next_chirp();
  void display_chirp(postPtr it, int i);
  void add_like();
  void add_chirp_post(string input);
  void delete_chirp(int);

  char* scroll_thru_posts();
  bool add_like(int msg);
  string scroll_my_posts();
  void scroll_my_posts(post* n, int placement_given);
  void add_friends();
  void reChirp();
  void change_dn();

public:
  Chirp(); //constructor
  Chirp(const Chirp &o);//copy constructor
  Chirp *friends; //one friend
  ~Chirp(); //destructor
  void setup_account();
  void menu();

  void setUser(string entered);
  string getUser();
  void setDN(string entered);
  string getDN();
};

void Chirp::add_friends()
{
  ifstream file("friends_list.dat");
  string word;

  if(!file)
  {
    cout << "Can not find the specified file\n";
    exit(1); //terminate with an error
  } //else opened just fine

  //Chirp f; //make a new member "friends" of the class
  file >> word;

  friends = new Chirp;

  friends -> setUser(word);
  file >> word;
  friends -> setDN(word);
  cin.ignore();
    for(std::string line; getline(file, line); )
    {
      if(line == "") continue;
      line.resize(MSG); //as a precaution
      friends->add_chirp_post(line);
  }
}


void Chirp::display_chirp(postPtr it, int i)
{
  int count = 0;
  cout <<" _______________________________________________________" << endl; //55x
  cout << "|"<< setw(25) << right << ">>>>> Post #" << i << " <<<<"<< setw(24) << "|" << endl;
  cout << "| ";
  for(int j = 0; j < it->message.length(); j++)
  {
     cout << it->message[j];
     count++;
     if((count > 45 && it->message[j] == ' ') || it->message[j+1] == '\0')
     {
       for(int k = 0; k < 53-count; k++)
       {
         cout << " ";
       }
       cout << "|" << endl;
       count = 0;
       if(it->message[j+1] == '\0') break;
      cout << "| ";
   }
  }

  cout << "\tLikes: ";
  if(it->like) cout << heart;
  if(it->like) cout << it->num_likes << "\t";
  else cout << "\t";
  cout << "\tReChirps: ";
  if(it->reChirp) cout << arrow << endl;
  else cout << endl;
  cout <<" _______________________________________________________\n\n"; //55x

  cout << "(p)revious, (n)ext" << endl << "(L)ike, (r)etweet, (d)elete, or E(x)it: ";
}

void Chirp::scroll_my_posts(post* n, int placement_given)
{
  int placement = placement_given;
  post* current = n;

  if (current == NULL)
  {
    cout << "There are no posts" << endl;
  }

  else
  {
    display_chirp(current, placement);
    string given;
    getline(cin, given);
    char response = given[0];




    if (response == 'p' || response == 'n')
    {
        if (response == 'p')
        {
          if (current -> previous == nullptr)
          {
            cout << "This is the oldest chirp. " << endl;
            scroll_my_posts(current, placement);
          }
          else
          {
            current = current -> previous;
            placement--;
            scroll_my_posts(current, placement);
          }
        }

        else if (response == 'n')
        {
          if (current -> next == nullptr)
          {
            cout << "This is the newest chirp. " << endl;
            scroll_my_posts(current, placement);
          }
          else
          {
            current = current -> next;
            placement++;
            scroll_my_posts(current, placement);
          }
        }
    }
    else if (response == 'L')
    {
      current -> like = true;
      current -> num_likes++;
      scroll_my_posts(current, placement);
    }

    else if (response == 'd')
    {
      cout << "Deleting post. " << endl;
      /*
      This section will be worked on for the next submission
      */
    }

    else
    {
      cout << "Entry not understood, returning to menu." << endl;
    }
  }
}


bool Chirp::isEmpty()
{
  //return (this -> head == NULL);
  post* ptr = head;

  if (ptr)
  {
    return false;
  }

  else
  {
    return true;
  }

}

void Chirp::add_chirp_post(string input)
{

  // if there is a head node, append post there
  if (isEmpty())
  {
    //cout << "The LL is empty." << endl;
    post* n = new post;
    head = n;
    n -> message = input;
    n -> next = nullptr;
    n -> previous = nullptr;
    //cout << (n -> message) << endl;
  }

  else
  {
    //cout << "The LL is not Empty." << endl;
    post* n = new post;
    n -> message = input;
    n -> next = nullptr;
    post* hopper = head;
    while (hopper -> next != nullptr)
    {
      hopper = hopper -> next;
    }
    hopper -> next = n;
    n -> previous = hopper;
    //cout << (n -> message) << endl;

  }
  /*
  post* n = new post;
  n -> message = input;
  n -> next = nullptr;
  */
}

void Chirp::setUser(string entered)
{
  string tester = entered;
  while((tester.find (' ') != string::npos))
  {
    cout << "Illegal entry. No spaces are allowed in your display name." << endl;
    cout << "Display Name: ";
    getline(cin, tester);
  }

  user = tester;
}

void Chirp::menu()
{
  bool base = true;
  cout << ">>> Ok, you're ready to start chirping. " << endl;

  while (base == true)
  {
    int option;
    cout << "~~~~~~~~ Select an option:" << endl;
    cout << "         1. Chirp" << endl;
    cout << "         2. Scroll through your chirps" << endl;
    cout << "         3. Scroll through a friend's feed" << endl;
    cout << "         4. Change your display name" << endl;
    cout << "         5. Exit" << endl;

    cout << "Your selection: ";
    cin >> option;
    while(cin.fail())
    {
        cout << "You're entry wasnt understood, Please enter one of the following 5 options." << endl;
        cout << "~~~~~~~~ Select an option:" << endl;
        cout << "         1. Chirp" << endl;
        cout << "         2. Scroll through your chirps" << endl;
        cout << "         3. Scroll through a friend's feed" << endl;
        cout << "         4. Change your display name" << endl;
        cout << "         5. Exit" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> option;
    }

    if (option == 5)
    {
      base = false;
      //cout << "You're entry wasnt understood, let's try that again. " << endl;
    }

    if (option == 1)
    {
      cin.ignore();
      cout << "Write your post here: " << endl;
      string entered;

      bool less_than_180 = false;
      int length;
      while (less_than_180 == false)
      {
        //cin.ignore();
        getline(cin, entered);
        length = entered.length();
        if(length  > 180)
        {
          cout << "Error: Your input should be less than 180 characters! Try again. " << endl << endl;
        }
        else
        {
          less_than_180 = true;
        }
      }
      //cout << entered <<endl;
      add_chirp_post(entered);
    }

    else if (option == 2)
    {
      cin.ignore();
      int placement = 1;
      cout << display_name << "'s posts: " << endl;
      scroll_my_posts(head, placement);
      //display_chirp(head, 1);
      //display_chirp(,)
    }

    else if (option == 3)
    {
      cin.ignore();
      //scroll_thru_friend_posts();
      //display_chirp(head, 1);
      //display_chirp(,)
    }

    else if (option == 4)
    {
      cout << "Please enter your new display name: ";
      string temp;
      cin >> temp;
      setDN(temp);
      cout << "Your display name is now: " << display_name << endl;
    }
  }
}

void Chirp::setup_account()
{
  cout << "Let's set up your chirper account..." << endl;
  cout << "User Name: ";
  //cin >> user;
  string temp1;
  getline(cin, temp1);
  setUser(temp1);
  cout << endl;
  /*
  cout << "Let's set up your chirper account..." << endl;
  cout << "User Name: ";
  string temp;
  getline(cin, temp);
  temp = user;
  //cin >> user;
  cout << endl;
*/
  //cout << "Enter your display name below. Please note that any characters entered after a space will be ignored." << endl;
  cout << "Display Name: ";
  cin >> display_name;
  //string temp;
  //cin >> temp;
  //setDN(temp);
  /*

  cout << "Let's set up your chirper account..." << endl;
  cout << "User Name: ";
  string temp;
  getline(cin, temp);
  while((temp.find (' ') != string::npos))
  {
    cout << "Illegal entry. No spaces are allowed in your username." << endl;
    cout << "User Name: ";
    getline(cin, temp);
  }
  user = temp;
*/
/*
  cout << endl;

  cout << "Display Name: ";
  string temp2;
  getline(cin, temp2);
  while((temp2.find (' ') != string::npos))
  {
    cout << "Illegal entry. No spaces are allowed in your display name." << endl;
    cout << "Display Name: ";
    getline(cin, temp2);
  }


  display_name = temp2;
  */
  //cin.ignore();
  cout << endl;

  cout << "Adding your friends..." << endl;
  add_friends();
}

void Chirp::setDN(string entered)
{
  display_name = entered;
}

Chirp:: ~Chirp()
{

}
Chirp::Chirp()
{}


int main()
{
  Chirp ch;
  ch.setup_account();
  ch.menu();
  cout << "See you next time\n";
  return 0;
}
