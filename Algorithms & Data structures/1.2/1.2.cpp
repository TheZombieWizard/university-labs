#include <iostream> 
#include <stack> 
#include <cstdlib>

using namespace std; 

int main()
{
    unsigned int MAX = 13;
    cout << "Array size: " << endl;
    cin >> MAX;
    if (!MAX || MAX < 0) 
        return 1;
    
    int* array = new int[MAX]{0}; 
    cout << "Array numbers: " << endl;
    for (unsigned int i = 0; i < MAX; i++)
        cin >> array[i];
    
    int* answer_right = new int[MAX]{0};
    int* answer_left = new int[MAX]{0};

    stack<int> stack;
    
	for (int i = MAX-1; i >= 0; i--)
	{
		if (stack.empty())
			answer_right[i] = -1;
		else
        {
			if (array[i] > array[stack.top()])
				answer_right[i] = stack.top();
			else
			{
				while (!stack.empty() && array[i] < array[stack.top()])
					stack.pop();

				if (stack.empty())
					answer_right[i] = -1;
				else
					answer_right[i] = stack.top();
			}
        }
		stack.push(i);
	}

	while (!stack.empty())
		stack.pop();

	for (int i = 0; i < MAX; i++)
	{
		if (stack.empty())
			answer_left[i] = -1;
		else
			if (array[i] > array[stack.top()])
				answer_left[i] = stack.top();
			else
			{
				while (!stack.empty() && array[i] < array[stack.top()])
					stack.pop();

				if (stack.empty())
					answer_left[i] = -1;
				else
					answer_left[i] = stack.top();
			}
		stack.push(i);
	}

	int n;
	cout << "Number of comparing element: ";
	cin >> n;

	if (answer_right[n-1] == -1)
		cout << "There is no element lower than it on the right side" << endl;
	else
		cout << "Right: " << array[answer_right[n-1]] << endl;

	if (answer_left[n-1] == -1)
		cout << "There is no element lower than it on the left side" << endl;
	else
		cout << "Left: " << array[answer_left[n-1]] << endl;
   
    return 0;
}