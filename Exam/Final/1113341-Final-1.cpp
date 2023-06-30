#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
class List
{
private:
	T** data;
	int n;
public:
	List()
	{
		data = new T * [0]();
	}
	List(int n)
	{
		this->n = n;
		data = new T * [n]();
		for (int i = 0; i < n; i++)
			data[i] = new T();
	}
	~List()
	{
		
		for (int i = 0; i < n; i++)
		{
			if (data[i] != nullptr)
			{
				delete[] data[i];
			}
		}
		delete[] data;
	}
	int getDatas()
	{
		return n;
	}
	void insertAt(int x, T value)
	{
		List buffer(n);
		for (int i = 0; i < n; i++)
		{
			*buffer.data[i] = *data[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (data[i] != nullptr)
			{
				delete[] data[i];
			}
		}
		delete[] data;

		data = new T * [n + 1]();
		for (int i = 0; i < n + 1; i++)
			data[i] = new T();

		for (int i = 0; i < x; i++)
			*data[i] = *buffer.data[i];
		*data[x] = value;
		for (int i = x + 1; i < n + 1; i++)
			*data[i] = *buffer.data[i - 1];
		
		n++;
	}
	T getAt(int x)
	{
		return *data[x];
	}
	void sort()
	{
		T* buffer = new int[n];
		for (int i = 0; i < n; i++)
		{
			buffer[i] = *data[i];
		}

		for (int i = 0; i < n - 1; i++) /*for (int i = 0; i < n; i++)*/
		{
			for (int j = i + 1; j < n; j++) /*for (int j = i; j < n - 1; j++)*/
			{
				if (buffer[i] > buffer[j])
				{
					T temp = buffer[j];
					buffer[j] = buffer[i];
					buffer[i] = temp;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			*data[i] = buffer[i];
		}
	}
	void unique()
	{
		vector<T> buf;
		for (int i = 0; i < n; i++)
		{
			buf.push_back(*data[i]);
			for (int j = 0; j < buf.size() - 1; j++)
			{
				if (buf[j] == *data[i])
				{
					buf.pop_back();
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (data[i] != nullptr)
			{
				delete[] data[i];
			}
		}
		delete[] data;
		n = buf.size(); /*change the value of n, or the program will crash when output 
							because getAt(i) function can not access value which is
							  deleted due to repeat*/
		data = new T * [buf.size()]();
		for (int i = 0; i < buf.size(); i++)
			data[i] = new T(buf[i]);
	}
	List operator + (const List& list)
	{
		List afterAdd(n + list.n);
		for (int i = 0; i < n; i++)
		{
			*afterAdd.data[i] = *data[i];
		}
		for (int i = n, j = 0; i < n + list.n; i++, j++)
		{
			*afterAdd.data[i] = *list.data[j];
		}

		return afterAdd;
	}
	friend istream& operator >> (istream& is, List& list)
	{
		/*T input;
		int num = list.getDatas();
		for (int i = 0; i < n; i++)
		{
			is << input;
		}*/

		for (int i = 0; i < list.getDatas(); i++)
		{
			is >> *list.data[i];
		}

		return is;
	}
	friend ostream& operator << (ostream& os, List& list)
	{
		for (int i = 0; i < list.getDatas(); i++)
		{
			os << list.getAt(i) << " ";
		}
		cout << endl;

		return os;
	}
};

int main() {
	int n1, n2;
	cout << "Input number of element of list A: ";
	cin >> n1;
	List<int> A(n1);
	cin >> A;
	cout << "Input number of element of list B: ";
	cin >> n2;
	List<int> B(n2);
	cin >> B;

	List<int> C = A + B;
	cout << "List C = A + B: " << C << endl;
	C.insertAt(8, 6);
	cout << "List C after insert 6: " << C << endl;
	C.sort();
	cout << "List C after sorting: " << C << endl;
	C.unique();
	cout << "List C after unique: " << C << endl;

}