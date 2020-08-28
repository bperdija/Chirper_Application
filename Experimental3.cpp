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
  void delete_chirp(post* to_delete, post* to_attach);
  void delete_chirp(post* to_delete);

  //char* scroll_thru_posts();
  bool add_like(int msg);
  //string scroll_my_posts();
  void scroll_my_posts(post* n, int placement_given);
  void scroll_thru_friend_posts(post* n, int placement_given);
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
  void hang_man();
  void Clear();

  void setUser(string entered);
  string getUser();
  void setDN(string entered);
  string getDN();
};

void Chirp::hang_man()
{
  //std::cout << "Hello World!\n";
  //ClearScreen();
  int tries = 0;
  int result;
  //cout << result;
  string options[4] = { "espionage" };

  cout << "Alright! Lets play some hangman. Rules are simple, i'll give you a word and you have to guess each letter one at a time. If you guess wrong, well, the hangman gon' get hung. You have 5 tries to guess the sentence. Lets get started!" << endl << endl << "Disclaimer: This is an incredibly early version and was made in literally 3 hours. "<< endl << endl;
  cout << endl;


  cout << "_____________" << endl;
  cout << "|           |" << endl;
  cout << "|           |" << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "|            " << endl;
  cout << "-----------------" << endl;
  cout << "Tries: " << tries << endl;
  cout << "Guess the following: " << endl;
  string temp = options[0];
  int length = temp.length();
  string to_uncover(length, '_');
  cout << to_uncover;

  cout << endl << endl;
  char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  bool alive = true;
  while (alive)
  {
    bool in_word = false;
    char guess;
     cout << "Letters available: " << endl;
    for (int j = 0; j < 25; j++)
    {
      cout << letters[j]<< ", ";
    }
    cout << endl << endl;
    cout << "My guess: ";
    cin >> guess;

    {
      for (int o = 0; o < length; o++ )
      {
        if (temp[o] == guess)
        {
          to_uncover[o] = guess;
          for (int r = 0; r < 25; r++)
          {
            if (letters[r] == guess)
            {
              letters[r] = '.';
            }
          }
          in_word = true;
        }
        else
        {
          for (int r = 0; r < 25; r++)
          {
            if (letters[r] == guess)
            {
              letters[r] = '.';
            }
          }
        }
      }
    }
    cout << to_uncover << endl;

    if (to_uncover == temp)
    {
      cout << "You got it!!" << endl << endl;
      break;
    }

    if (in_word == false)
    {
      if (tries == 0)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
      }

      else if (tries == 1)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|           |" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
      }

      else if (tries == 2)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|          /|" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
      }
      else if (tries == 3)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|          /|\\" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
      }
      else if (tries == 4)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|          /|\\" << endl;
        cout << "|          / " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
      }
      else if (tries == 5)
      {
        tries++;
        cout << "_____________" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           O" << endl;
        cout << "|          /|\\" << endl;
        cout << "|          / \\" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "-----------------" << endl;
        cout << "Tries: " << tries << endl;
        cout << "No more moves. The hangman is hung. How do you feel?" << endl;
        alive = false;
      }
    }
    continue;
  }

  if (!alive)
  {
    cout << "Would you like to share on chirper?";
    char input;
    string output = "I JUST MURDERED A GUY ON HANGMAN and it was WILD!!!!!";
    cin >> input;
    if (input == 'y')
    {
      add_chirp_post(output);
      cout << "Returning to menu." << endl;
    }
    else
    {
      cout << "Fair enough. Returning to menu." << endl;
    }
  }

  if (alive)
  {
    cout << "Congratulations, the hangman is in your debt. Would you like to share your win on chirper? Type 'y' for yes and type 'n' for no" << endl << "response: ";
    char input;
    string output = "WOW! Check out this AWESOME game I played on chirper!";
    cin >> input;
    if (input == 'y')
    {
      add_chirp_post(output);
      cout << "Returning to menu." << endl;
    }
    else
    {
      cout << "Fair enough. Returning to menu." << endl;
    }
  }
}
void Chirp::Clear()
{
  for (int n = 0; n < 10; n++)
  {
    printf( "\n\n\n\n\n" );
  }
}

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
  //the following is ignore when using getline() prior. Not sure why.
  //cin.ignore();
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
  if(it->like) cout << heart << " ";
  if(it->like) cout << (it -> num_likes) << "\t";
  else cout << "\t";
  cout << "\tReChirps: ";
  if(it->reChirp) cout << arrow << endl;
  else cout << endl;
  cout <<" _______________________________________________________\n\n"; //55x

  cout << "(p)revious, (n)ext" << endl << "(L)ike, (r)etweet, (d)elete, or E(x)it: ";
}

// The scroll_my_posts() function is used to scrill through the users posts. Precondition: user has passed a pointer to a node and given an inteteger value. Postcondition: Displays the users post and the order of the post (ie, first, second, third)
void Chirp::scroll_my_posts(post* n, int placement_given)
{
  // Initialize a int variable called placement that is used to determine what numbered post the user will be looking at. It is taken from the placement_given perameter
  int placement = placement_given;
  // Initialize a pointer variable named current that points to the pointer n from the parameters.
  post* current = n;

  // If the pointer variable current is equal to NULL, no node exists and therefore there are no nodes. Output that to the user.
  if (current == NULL)
  {
    cout << "There are no posts" << endl;
  }

  // If a pointer variable current exists, do the following:
  else
  {
    // Display the chirp using the display_chirp() function. Input the pointer variable "current" with the int variable placement as parameters.
    display_chirp(current, placement);
    // Create a tempory string called "given" that is used to store user input.
    string given;
    // Write the string input to given.
    getline(cin, given);
    // Create a new character type variable named "response", and have it equal only the first letter of the string "given".
    char response = given[0];

    // If the response variable is equal to p(revious) or n(ext). Move the pointer variable "current" the previous or next node, and call the function again recursively.
    if (response == 'p' || response == 'n')
    {
      // If the response is p(revious), check if the previous node to the pointer variable "current" exists. If the previous node is NULL, then the user is viewing the oldest chirp and will call the function recursively. If the previous node is not NULL, make the pointer variable "current" equal to the pointer variable of the previous node. Decrease the placement variable as we are going down the linked list (leftwards). Call the function recursively.
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

      // If the response is n(ext), check if the next node to the pointer variable "current" exists. If the next node is NULL, then the user is viewing the newest chirp and will call the function recursively. If the next node is not NULL, make the pointer variable "current" equal to the pointer variable of the next node. Increase the placement variable as we are going up the linked list (rightwards). Call the function recursively.
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

    // If the response is L(ike), make the member variable of like equal to true at that node.
    else if (response == 'L' || response == 'l')
    {
      current -> like = true;
      // If the current node already has a like, you've already liked the node before and cannot like it again. Call the function scroll_my_posts() recursively to display the chirp again.
      if (current -> num_likes == 1)
      {
        cout << endl << "You've already liked this post!" << endl;
        scroll_my_posts(current, placement);
      }
      // If the current node doesnt already have a like, increase the number tally of num_likes at that node by one. Call the function recursively to update the chirp.
      else
      {
        current -> num_likes++;
        scroll_my_posts(current, placement);
      }
    }

    // If the response is d(elete), delete the node at current.
    else if (response == 'd')
    {
      cout << "Deleting post. " << endl;
      if (current -> next == nullptr && current -> previous == nullptr)
      {
        cout << "All posts deleted. Returning to menu."<< endl;
        delete_chirp(current);
        return;
      }
      if (current->next == nullptr)
      {
        delete_chirp(current, current->previous);
        placement--;
        scroll_my_posts(current -> previous, placement);
      }

      else if (current -> previous == nullptr)
      {
        delete_chirp(current, current->next);
        scroll_my_posts(current -> next, placement);
      }

      else
      {
        delete_chirp(current, current -> previous);
        placement--;
        scroll_my_posts(current -> previous, placement);
      }
    }



    else if (response == 'r')
    {
      cout << "You can't retweet your own posts! " << endl;
      scroll_my_posts(current, placement);
    }

    else if (response == 'x')
    {
      cout << endl << "Returning to main menu." << endl;
    }

    // If the response is none of these, return to the menu.
    else
    {
      cout << endl << "Entry not understood, returning to menu." << endl;
    }
  }
}

// The scroll_thru_friend_posts() function is used to scrill through the friends posts. Precondition: add_friends() has passed a pointer to a node and user has given an inteteger value. Postcondition: Displays the friends post and the order of the post (ie, first, second, third)
void Chirp::scroll_thru_friend_posts(post* n, int placement_given)
{
  // Initialize a int variable called placement that is used to determine what numbered post the user will be looking at. It is taken from the placement_given perameter
  int placement = placement_given;
  // Initialize a pointer variable named current that points to the pointer n from the parameters.
  post* current = n;

  // If the pointer variable current is equal to NULL, no node exists and therefore there are no nodes. Output that to the user.
  if (current == NULL)
  {
    cout << "There are no posts" << endl;
  }

  // If a pointer variable current exists, do the following:
  else
  {
    // Display the chirp using the display_chirp() function. Input the pointer variable "current" with the int variable placement as parameters.
    display_chirp(current, placement);
    // Create a tempory string called "given" that is used to store user input.
    string given;
    // Write the string input to given.
    getline(cin, given);
    // Create a new character type variable named "response", and have it equal only the first letter of the string "given".
    char response = given[0];

    // If the response variable is equal to p(revious) or n(ext). Move the pointer variable "current" the previous or next node, and call the function again recursively.
    if (response == 'p' || response == 'n')
    {
      // If the response is p(revious), check if the previous node to the pointer variable "current" exists. If the previous node is NULL, then the user is viewing the oldest chirp and will call the function recursively. If the previous node is not NULL, make the pointer variable "current" equal to the pointer variable of the previous node. Decrease the placement variable as we are going down the linked list (leftwards). Call the function recursively.
      if (response == 'p')
      {
        if (current -> previous == nullptr)
        {
          cout << "This is the oldest chirp. " << endl;
          scroll_thru_friend_posts(current, placement);
        }
        else
        {
          current = current -> previous;
          placement--;
          scroll_thru_friend_posts(current, placement);
        }
      }

      // If the response is n(ext), check if the next node to the pointer variable "current" exists. If the next node is NULL, then the user is viewing the newest chirp and will call the function recursively. If the next node is not NULL, make the pointer variable "current" equal to the pointer variable of the next node. Increase the placement variable as we are going up the linked list (rightwards). Call the function recursively.
      else if (response == 'n')
      {
        if (current -> next == nullptr)
        {
          cout << "This is the newest chirp. " << endl;
          scroll_thru_friend_posts(current, placement);
        }
        else
        {
          current = current -> next;
          placement++;
          scroll_thru_friend_posts(current, placement);
        }
      }
    }

    // If the response is L(ike), make the member variable of like equal to true at that node.
    else if (response == 'L' || response == 'l')
    {
      current -> like = true;
      // If the current node already has a like, you've already liked the node before and cannot like it again. Call the function scroll_my_posts() recursively to display the chirp again.
      if (current -> num_likes == 1)
      {
        cout << endl << "You've already liked this post!" << endl;
        scroll_thru_friend_posts(current, placement);
      }
      // If the current node doesnt already have a like, increase the number tally of num_likes at that node by one. Call the function recursively to update the chirp.
      else
      {
        current -> num_likes++;
        scroll_thru_friend_posts(current, placement);
      }
    }

    // If the response is d(elete), delete the node at current.
    else if (response == 'd')
    {
      cout << "You can't delete another users posts. " << endl;
      scroll_thru_friend_posts(current, placement);
    }

    else if (response == 'r')
    {
      if (current -> reChirp == true)
      {
        cout << "You can't rechirp a post twice SILLY GOOSE. " << endl;
        scroll_thru_friend_posts(current, placement);
      }
      else
      {
        cout << "Post rechirped! " << endl;
        current -> reChirp = true;
        add_chirp_post(current -> message);
        scroll_thru_friend_posts(current, placement);
      }
    }

    else if (response == 'x')
    {
      cout << endl << "Returning to main menu." << endl;
    }

    // If the response is none of these, return to the menu.
    else
    {
      cout << endl << "Entry not understood, returning to menu." << endl;
    }
  }
}



// The isEmpty() function is used to check if the head of a linked list is NULL. Precondition: None. Postcondition: return false if head is not NULL, return true if head is NULL.
bool Chirp::isEmpty()
{
  // create a temporary pointer variable named ptr that is equal to head.
  post* ptr = head;

  // If the ptr variable exists (head was not null), return false. Otherwise, if the ptr variable does not exist (head was null), return false
  if (ptr)
  {
    return false;
  }

  else
  {
    return true;
  }

}

// The add_chirp_post() function is used to append nodes to the linked list (of chirps). Precondition: function takes in a string. Postcondition: If a linked list does not exist (ie, head == NULL), then this function will create a head node, and place the passed string parameter into "message" of the node. If a linked list already exists, then this function will simply append a new node to the end of the linked list.
void Chirp::add_chirp_post(string input)
{

  // First check if there is a head node using isEmpty. If there isn't, make the head pointer point to your node.
  if (isEmpty())
  {
    //cout << "The LL is empty." << endl;
    // Make a new pointer variable n that points to a new node.
    post* n = new post;
    // Make the pointer variable head equal the pointer variable n.
    head = n;
    // Fill in the node data given the parameter input, and make the next and previous pointers NULL
    n -> message = input;
    n -> next = nullptr;
    n -> previous = nullptr;
    //cout << (n -> message) << endl;
  }

  // If there is a head node, make a new node and append it to the last node in the linked list.
  else
  {
    //cout << "The LL is not Empty." << endl;
    // Make a new pointer variable n that points to a new node.
    post* n = new post;
    // Fill in the node data given the parameter input, and make the next pointer NULL. Do not make the previous pointer NULL because there is a node before it.
    n -> message = input;
    n -> next = nullptr;
    // Traverse the original linked list and append n to the end of the list.
    // Create a temporary pointer that points to the head of the linked list.
    post* hopper = head;
    // If the next node is not NULL, move over to the next node. Continue until the next node is NULL
    while (hopper -> next != nullptr)
    {
      hopper = hopper -> next;
    }
    // At the last node, make the non-existent next node equal to the new node we have created earlier (from the pointer variable n)
    hopper -> next = n;
    // Make the newly appended node have the previous pointer point to the node before it.
    n -> previous = hopper;
    //cout << (n -> message) << endl;
  }
}


void Chirp::delete_chirp(post* to_delete, post* to_attach)
{
  if (to_delete->next == nullptr)
  {
    //post* first_temp = to_delete -> previous;
    to_attach -> next = nullptr;
    delete to_delete;
    //first_temp -> next = nullptr;
    //return first_temp;
  }

  else if (to_delete -> previous == nullptr)
  {
    to_attach -> previous = nullptr;
    delete to_delete;
    head = to_attach;
    //return second_temp;
  }

  else
  {
    post* temp = to_attach -> next -> next;
    to_attach -> next = to_attach-> next->next;
    temp -> previous = to_attach;
    delete to_delete;
  }
}

void Chirp::delete_chirp(post* to_delete)
{
  head = NULL;
  delete to_delete;
}


// The menu() function is used to setup the main menu of our Chirper program. Precondition: None. Postcondition: Takes in user input that must be either 1,2,3,4, or 5. If user input is neither of these options, repeat the main menu. Otherwise, call the associated function to the user input. When the user enters 5, exit the menu() function.
void Chirp::menu()
{
  // The boolean variable "base" is used to repeat the main menu. When "base" becomes false, this function will end.
  bool base = true;
  cout << ">>> Ok, you're ready to start chirping. " << endl;

  while (base == true)
  {
    // Declare int variable "option" that is used to store the users input (for their selection).
    int option;
    // Print out the menu options for the user.
    cout << "~~~~~~~~ Select an option:" << endl;
    cout << "         1. Chirp" << endl;
    cout << "         2. Scroll through your chirps" << endl;
    cout << "         3. Scroll through a friend's feed" << endl;
    cout << "         4. Change your display name" << endl;
    cout << "         5. Hangman" << endl;
    cout << "         6. Exit" << endl;

    cout << "Your selection: ";

    // Take user input and store it into the "option" variable declared earlier.
    cin >> option;
    // If the user input failed to store an integer input, repeat the menu and notify the user of their mistake.
    while(cin.fail())
    {
        cout << endl << "You're entry wasnt understood, Please enter one of the following 5 options." << endl;
        cout << "~~~~~~~~ Select an option:" << endl;
        cout << "         1. Chirp" << endl;
        cout << "         2. Scroll through your chirps" << endl;
        cout << "         3. Scroll through a friend's feed" << endl;
        cout << "         4. Change your display name" << endl;
        cout << "         5. Hangman" << endl;
        cout << "         6. Exit" << endl;
        // Erase the contents of the string, as a precaution.
        cin.clear();
        // Discard the first 256 characters or until the user enters a character constant '\n'
        cin.ignore(256,'\n');
        // Take user input again, and store it into the option variable.
        cin >> option;
    }

    // If the user entered 5, turn the boolean "base" false which will end the end the menu() function
    if (option == 6)
    {
      base = false;
    }

    // If the user entered 1, the process of creating a new chirp will commence.
    else if (option == 1)
    {
      // Discard the characters that have previously been entered in cin.
      cin.ignore();
      cout << "Write your post here: " << endl;
      // Create a temporary string variable named "entered" that will be used to store the user's string input
      string entered;
      // Create a boolean named less_than_180 that is initialized as false. It will be used to determine whether the user entered more than or less than 180 characters in the string.
      bool less_than_180 = false;
      // Create a temporary integer variable named "length" that will be used to determine the length of the users inputted string.
      int length;

      // less_than_180 will remain false until the user enters a string that is less than 180 characters. While less_than_180 remains false, continue repeating the while loop taking in user input.
      while (less_than_180 == false)
      {
        // Extract the characters from user input and store them in the string "entered" variable.
        getline(cin, entered);
        // Determine the length of the inputted string using the length() function.
        length = entered.length();
        // If the length is greater than 180 characters, let the user know and keep the less_than_180 boolean equal to false, the while loop will repeat.
        if(length  > 180)
        {
          cout << "Error: Your input should be less than 180 characters! Try again. " << endl << endl;
        }
        // If the length is less than 180 characters, less_than_180 will equal to true, and the program will exit this while loop.
        else
        {
          less_than_180 = true;
        }
      }

      //cout << entered <<endl;
      // Pass the "entered" string variable into the add_chirp_post() function to create a new node (chirp) in the linked list.
      add_chirp_post(entered);
    }

    // If the user entered 2, the process of scrolling through your chirps will commence.
    else if (option == 2)
    {
      // Discard the characters that have previously been entered in cin.
      cin.ignore();
      // Initialize an integer variable named placement and set it equal to 1. This variable will be used to pass into the scroll_my_posts() function to list the currently shown tweet (ie, first tweet, second tweet, third... etc)
      int placement = 1;
      // Display the display_name of the user
      cout << display_name << "'s posts: " << endl;
      // Pass the head of the linked list and the "placement" integer variable into the scroll_my_posts() function. This function will traverse the linked list (chirps).
      scroll_my_posts(head, placement);
    }

    // If the user entered 3, the process of scrolling through your friends chirps will commence.
    else if (option == 3)
    {
      // Discard the characters that have previously been entered in cin.
      cin.ignore();
      //scroll_thru_friend_posts();
      int placement = 1;
      cout << (friends -> display_name) <<"'s posts: " << endl;
      //display_chirp(head, 1);
      scroll_thru_friend_posts((friends -> head), placement);
      //display_chirp(,)
    }

    // If the user entered 4, the process of changing your display name will commence.
    else if (option == 4)
    {
      // Discard the characters that have previously been entered in cin.
      cin.ignore();
      cout << "Please enter your new display name: ";
      // Make a temporary string named temp that will be used to store user input.
      string temp;
      // Store user input into the temp variable
      getline(cin,temp);
      // Check the temp string to see if there are any spaces entered until the end of the string. If there are, get user input again.
      while((temp.find (' ') != string::npos))
      {
        cout << "Illegal entry. No spaces are allowed in your username." << endl;
        cout << "User Name: ";
        getline(cin, temp);
      }
      // Pass the temp variable into the setDN() function to set the display name to the given variable.
      setDN(temp);
      cout << "Your display name is now: " << display_name << endl;
    }

    else if (option == 5)
    {
      hang_man();
    }

    // If the user entered anything not 1,2,3,4, or 5, display a warning and repeat the menu options.
    else
    {
      cout << "Your entry wasn't understood, try again. " << endl;
    }

  }

}

// The setup_account() function is used to setup the display name and user name of the user in our Chirper program. Precondition: None. Postcondition: writes to the "user" and "display_name" member variables in the class Chirp.
void Chirp::setup_account()
{
  user = "tim";
  display_name = "OOF";
  /*
  // Ask the user to input a user name.
  cout << "Let's set up your chirper account..." << endl;
  cout << "User Name: ";
  //cin >> user;
  // NOTE: using getline() below requires you to omit cin.ignore() in add_friends() function. I've commented it out for now. Using cin does not require ommiting that.
  // Using getline(), get user input into the "user" member variable.
  getline(cin,user);
  // Check the "user" member variable to see if there are any spaces entered until the end of the string. If there are, get user input again.
  while((user.find (' ') != string::npos))
  {
    cout << "Illegal entry. No spaces are allowed in your username." << endl;
    cout << "User Name: ";
    getline(cin, user);
  }
  cout << endl;

  // Ask the user to input a display name.
  cout << "Display Name: ";
  // Using getline(), get user input into the "display_name" member variable.
  getline(cin, display_name);
  // Check the "display_name" member variable to see if there are any spaces entered until the end of the string. If there are, get user input again.
  while((display_name.find (' ') != string::npos))
  {
    cout << "Illegal entry. No spaces are allowed in your username." << endl;
    cout << "User Name: ";
    getline(cin, display_name);
  }
  //cin >> display_name;

  cout << endl;

  cout << "Adding your friends..." << endl;
  // Call the add_friends() function to set up friends account.
  //add_friends();
  */
}

// The setDN() function is used to change the "display_name" member variable of the class. Precondition: Given a string. Postcondition: Member variable "display_name" is now set to the given string.
void Chirp::setDN(string entered)
{
  display_name = entered;
}

// The setUser() function is used to change the "user" member variable of the class. Precondition: Given a string. Postcondition: Member variable "user" is now set to the given string.
void Chirp::setUser(string entered)
{
  user = entered;
}

Chirp::~Chirp()
{
  post* current_look = head;
  post* next_node;

  while (current_look != NULL)
  {
    next_node = current_look -> next;
    delete current_look;
    current_look = next_node;
  }
}

// Default instructor used for compilation. No precondition.
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
