#include <iostream>
#include <ctime>
#include <random>

using namespace std;



int main()
{
    srand(time(0));
    const int size = 10;
    int arr[size];
	int shift = 0;

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
    
	cout<<"\nshift=";
	cin>>shift;
	
	/*КОД НА Ассемблере*/
	
	
	for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
   
   return 0;
}
