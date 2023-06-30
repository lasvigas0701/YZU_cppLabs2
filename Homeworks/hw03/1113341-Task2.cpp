#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void ascending(T arr[], int n)
{
	sort(arr, arr + n);
}

template <typename T>
void descending(T* arr, int n)
{
	T* buf = new T[n]();
	T* sorted = new T[n]();
	for (int i = 0; i < n; i++)
		buf[i] = arr[i] < 0 ? -arr[i] : arr[i];

	for (int pass = n - 1; pass > 0; pass--)
	{
		for (int i = 0; i < pass; i++)
		{
			if (buf[i] < buf[i + 1])
			{
				T temp = buf[i];
				buf[i] = buf[i + 1];
				buf[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (buf[i] + arr[j] == 0 || buf[i] + arr[j] == (2 * arr[j]))
			{
				sorted[i] = arr[j];
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		arr[i] = sorted[i];
	cout << endl;

	delete[] buf;
	delete[] sorted;
	//return arr;
}

template <typename T>
void evenAsOddDes(T arr[], int n)
{
	vector<T> evenBuf;
	vector<T> oddBuf;

	for (int i = 0; i < n; i++)
		arr[i] % 2 == 0 ? evenBuf.push_back(arr[i]) : oddBuf.push_back(arr[i]);

	T* even = new T[evenBuf.size()];
	T* odd = new T[oddBuf.size()];
	
	for (int i = 0; i < evenBuf.size(); i++)
		even[i] = evenBuf[i];

	for (int i = 0; i < oddBuf.size(); i++)
		odd[i] = oddBuf[i];

	ascending(even, evenBuf.size());
	/*bubble sort for descending, also can use sort(array, array + array.size, greater<T>())
	  with including <functional>*/
	for (int pass = oddBuf.size() - 1; pass > 0; pass--)
	{
		for (int i = 0; i < pass; i++)
		{
			if (odd[i] < odd[i + 1])
			{
				T temp = odd[i];
				odd[i] = odd[i + 1];
				odd[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < evenBuf.size(); i++)
		arr[i] = even[i];

	for (int i = evenBuf.size(), j = 0; j < oddBuf.size(); i++, j++)
		arr[i] = odd[j];
}

template <typename T>
void negDesPosAs(T arr[], int n)
{
	vector<T> negativeBuf;
	vector<T> positiveBuf;

	for (int i = 0; i < n; i++)
		arr[i] < 0 ? negativeBuf.push_back(arr[i]) : positiveBuf.push_back(arr[i]);

	T* negative = new T[negativeBuf.size()];
	T* positive = new T[positiveBuf.size()];

	for (int i = 0; i < negativeBuf.size(); i++)
		negative[i] = negativeBuf[i];

	for (int i = 0; i < positiveBuf.size(); i++)
		positive[i] = positiveBuf[i];

	ascending(positive, positiveBuf.size());
	sort(negative, negative + negativeBuf.size(), greater<T>());

	for (int i = 0; i < negativeBuf.size(); i++)
		arr[i] = negative[i];

	for (int i = negativeBuf.size(), j = 0; j < positiveBuf.size(); i++, j++)
		arr[i] = positive[j];
}

/* self-testing code
int main() {
	int arr[] = { -1, 7, -3, 2, 4, 20, -49};
	evenAsOddDes(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
}*/