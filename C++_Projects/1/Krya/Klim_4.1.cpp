#include <iostream>

using namespace std;

int main()
{
  const int MAX = 1000;
  char in_text[MAX];
  char out_text[MAX];

  cin.getline(in_text, MAX, ';');  
  
  for (int i = 0, f = 0; i < MAX; i++)
  {
    if (in_text[i] == 42)
    { 
        f++;
        continue;
    }
    if (f == 1) 
        cout << in_text[i] << " ";
  }
  cout << endl;

  int n = 0;  
  for (int i = 0, f = 0, n = 0; i < n; i++, f = 0)
  {
    for (int q = i + 1; q < MAX; q++)
        if (in_text[i] = in_text[q]) 
            f++;
    if (!f)
        out_text[n++] = in_text[i];
  }

    /**for (int i = 1; i < MAX; i++)
    for (int j = MAX - 1; j >= i; j--)
        if (out_text[j - 1] > out_text[j])
        {
            int x = out_text[j - 1];
            out_text[j - 1] = out_text[j];
            out_text[j] = x;
        }
    /**/
  cout << out_text << endl;
  return 0;

}