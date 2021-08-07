#include <iostream>
using namespace std;

struct plane
{
	struct plane* left;
	int flight_number;
	int landing_time;
	struct plane* right;
};

struct plane* timeInterval(struct plane* i, int requestTime, int flightNumber, int K)
{
	int temp;
	if(i != NULL)
	{
		if((i)->landing_time>requestTime)
		{
			temp = (i)->landing_time - requestTime;
		}
		else
		{
			temp = requestTime - (i)->landing_time;
		}
		
		if(temp - K >= 1)
		{
			timeInterval(i->left, requestTime, flightNumber, K);
			timeInterval(i->right, requestTime, flightNumber, K);
		}
		else
		{
			return i;
		}
	}
	return NULL;
}

void addPlane(struct plane **i, int requestTime, int flightNumber)
{
	if(*i == NULL)
	{
		*i = new struct plane;
		(*i)->left = NULL;
		(*i)->landing_time = requestTime;
		(*i)->flight_number = flightNumber;
		(*i)->right = NULL;
	}
	else
	{
		if((*i)->landing_time > requestTime)
		{
			addPlane(&((*i)->left), requestTime, flightNumber);
		}
		else
		{
			addPlane(&((*i)->right), requestTime, flightNumber);
		}
	}
	return;
}

struct plane* findMin(struct plane* i)
{
	while(i->left != NULL)
	i = i->left;
	return i;
}

struct plane* cancelPlane(struct plane *i, int requestTime)
{
	struct plane *temp;
	if(i == NULL)
	{
		return i;
	}
	else if(requestTime < i->landing_time)
	{
		i->left = cancelPlane(i->left, requestTime);
	}
	else if(requestTime > i->landing_time)
	{
		i->right = cancelPlane(i->right, requestTime);
	}
	else
	{
		if(i->left == NULL && i->right == NULL)
		{
			delete i;
			i = NULL;
		}
		else if(i->left == NULL)
		{
			temp = i;
			i = i->right;
			delete temp;
		}
		else if(i->right == NULL)
		{
			temp = i;
			i = i->left;
			delete temp;
		}
		else
		{
			temp = findMin(i->right);
			i->landing_time = temp->landing_time;
			i->right = cancelPlane(i->right, temp->landing_time);
		}
	}
	return i;
}

//define a function to display all the elements in the tree
void list(struct plane *i)
{
	if(i != NULL)
	{	
		list((i)->left);
		cout << "===================================================================" << endl;
		cout << "Flight number: "<<i->flight_number<<"  Landing time: "<<i->landing_time<<endl;
		cout << "===================================================================" << endl;		
		list((i)->right); 
	}
	else
	{
		return;
	}
}

int main()
{
	struct plane* i,j;
	int K;
	int n;
	int flightNumber;
	int requestTime;
	i = NULL;
	
	cout<<"Enter a value for K (plane timeInterval): "<<endl;
	cin>>K;
	
	while(1)
	{
		//display the option menu
		cout << "1. Request landing" <<endl;
		cout << "2. delete landing" <<endl;
		cout << "3. List landing times and the flight number" <<endl;
		cout << "4. Exit" <<endl;
		cout << "Please enter the option:  "<<endl;
		cin>>n;
		
		switch(n)
		{   
			//when the input n is 1, perform the first option 
			case 1:cout << "Enter the flight number " <<endl;
				cin>>flightNumber;
				cout << "Enter the request landing time " <<endl;
				cin>>requestTime;
				if(i == NULL)
				{
					addPlane(&i, requestTime, flightNumber);
					cout << "===============================" << endl;
					cout << "Landing request succeed" << endl;
					cout << "===============================" << endl;
				}
				else if(timeInterval(i, requestTime, flightNumber, K) == NULL)
				{
					addPlane(&i, requestTime, flightNumber);
					cout << "===============================" << endl;
					cout << "Landing request succeed" << endl;
					cout << "===============================" << endl;
				}
				else 
				{
					cout << "================================================================================" << endl;
					cout << "Landing request did not succeed, the Request time with other plane larger than K" << endl;
					cout << "================================================================================" << endl;
				}
				break;


			case 2:cout << "Enter the landing time you want to cancel " <<endl;
				cin>>requestTime;
				i = cancelPlane(i, requestTime);

				cout << "===============================" << endl;
				cout << "Cancel Landing successful!" << endl;
				cout << "===============================" << endl;

				break;


			case 3:
				list(i);
				break;

			case 4:
				exit(1);
			default:
				cout << "Invalid choice";
		}
	}
}
