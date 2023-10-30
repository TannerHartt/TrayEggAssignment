#include<iostream>
#include <vector>
using namespace std;

void part_one()
{
  string docstr="The_Declaration_of_Independence_";

  //1. Write a line of code to print out the length of docstr
  cout << docstr.size() <<endl;

 // 2. Use a loop (or loops) to print out every 4 characters of docstr on a different line:
    // The_
    // Decl
    // arat
    // ion_
    // of_I
    // ndep
    // ende
    // nce_

  for (int i = 0;i<docstr.size(); i+=4) {
    cout << docstr.substr(i, 4) << endl;
  }

  // 3. Write code to replace each underscore in the string with a newline character '\n'
  //   Print out the string to show that the replacement worked
  //   The
  //   Declaration
  //   of
  //   Independence
  

  for(int i = 0; i<docstr.size(); i++) {
    if (docstr.at(i) == '_') {
      docstr.at(i)='\n';
    }
  }
  cout << docstr << endl;
}

// void part_two()
// {
//   //5. comment out part_one() in main() and uncomment the call to this function

  vector<string> lines;
  lines.push_back("Groo The Wanderer");
  lines.push_back("by");
  lines.push_back("Sergio Aragones");

  //prints out the vector
  for(int i=0; i<lines.size(); ++i)
    cout << lines[i] << endl;


  //6. Determine the length of the longest string in the vector.
  int max = 0;
  for (string line : lines) {
    if (line.size() > max) {
      max = line.size();
      continue;
    }
  }

 for (size_t i = 0; i < max; ++i) {
        // Inner loop for each string (column)
        for (const string& s : lines) {
            // Print the character if it exists, otherwise print a space
            if (i < s.length()) {
                cout << s[i];
            } else {
                cout << ' ';
            }
            cout << "   ";  // 3 spaces between columns
        }
        cout << endl;  // Move to the next line after printing all columns
    }

  //7. Use nested loops to print out the strings in the array vertically,
  //   with a column of spaces between each column of text (5 total columns):
  //  12345  <--5 total columns
  //  G b S
  //  r y e
  //  o   r
  //  o   g
  //      i
  //  T   o
  //  h 
  //  e   A
  //      r
  //  W   a
  //  a   g
  //  n   o
  //  d   n
  //  e   e
  //  r   s
  //  e
  //  r

}

void part_three()
{
  //8. comment out part_two() in main() and uncomment the call to this function

  std::vector<std::string> lines;
  lines.push_back("abc\ndef\nghi\njkl\n");
  lines.push_back("123\n456\n789\n");
  lines.push_back("PQR\nSTU\nVWX\nYZA\nBCD\n");

  // //prints out the vector
  for(int i=0; i<lines.size(); ++i)
    cout << lines.at(i) << endl;


  
int max = 0;
for (string line : lines) {
  if (line.size() > 0) {
    max = line.size();
  }
}

cout << "============== Break ================\n";

 for(int i = 0; i < max; i+=4) {
        // Inner loop for each string (column)
        for (const string s : lines) {
            // Print the character if it exists, otherwise print a space
            if (i < s.length()) {
                cout << s.at(i) << s.at(i+1) << s.at(i+2) << ' ';   
            } else {
              cout << "    ";
            }
        }
        cout << endl;  // Move to the next line after printing all columns
    }




 for (int i = 0; i < max; i+=4) {
        for (int j = 0; j < lines.size(); j++) {
          if (i < lines.at(j).length()) {
            cout << lines.at(j).substr(i, 3) << ' ';
          } else {
            cout << "    ";
          }
        }  
        cout << endl;
    }


  //9. Determine the longest string, 
  //   then Use a loop (or loops) to print out the strings 
  //   in the vector like this:
  //
  //  abc 123 PQR
  //  def 456 STU
  //  ghi 789 VWX
  //  jkl     YZA
  //          BCD

}

int main()
{
  // part_one();
  // part_two();
  part_three();
  return 0;
}
