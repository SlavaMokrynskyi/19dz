#include <iostream>
#include <string>

using namespace std;

enum Type { BEAST, BIRD, HUMAN};

union Number
{
	int number_int;
	char number_str[9];
};

union Characteristic
{
	float flying_speed;
	bool isEvenToad;
	int IQ;
};

struct Book
{
	string name;
	string author;
	string publishing_house;
	string genre;
};

struct Machine
{
	string color;
	string model;
	Number number;
};

struct LivingEntity
{
	float speed;
	int Type;
	string color;
	Characteristic characteristic;
	
};

Book EditBook(int index, Book books_arr[], int size)
{
	if (index > size || index < size)
	{
		return books_arr[size];
	}
	string new_name,new_author,new_publishing_house,new_genre;
	cout << "Enter new name of book (Enter 0 if you dont wanna change name) : ";
	getline(cin, new_name);
	if (new_name == "0")
	{
		new_name = books_arr[index].name;
	}
	cout << "Enter new author of book (Enter 0 if you dont wanna change author) : ";
	getline(cin, new_author);
	if (new_author == "0")
	{
		new_author = books_arr[index].author;
	}
	cout << "Enter new publighing_house of book (Enter 0 if you dont wanna change publighing_house) : ";
	getline(cin, new_publishing_house);
	if (new_publishing_house == "0")
	{
		new_publishing_house = books_arr[index].publishing_house;
	}
	cout << "Enter new genre of book (Enter 0 if you dont wanna change genre) : ";
	getline(cin, new_genre);
	if (new_genre == "0")
	{
		new_genre = books_arr[index].genre;
	}

	books_arr[index].name = new_name;
	books_arr[index].author = new_author;
	books_arr[index].publishing_house = new_publishing_house;
	books_arr[index].genre = new_genre;
	return books_arr[size];

}

void ShowBooks(Book books[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " book: " << endl;
		cout << "Name: " << books[i].name << endl;
		cout << "Author: " << books[i].author << endl;
		cout << "Publishing_house: " << books[i].publishing_house << endl;
		cout << "Genre: " << books[i].genre << endl;
		cout << endl;
	}
}

void FindBookByAuthor(Book books[], int size, string author)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i].author == author)
		{
			cout << "Book by this author is by " << i << " index" << endl;
		}
	}
}

void FindBookByName(Book books[], int size, string name)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i].name == name)
		{
			cout << "Book by this name is by " << i << " index" << endl;
		}
	}
}

Book SortArrByAuthor(Book books[], int size)
{
	Book temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (books[i].author > books[j].author)
			{
				temp = books[j];
				books[j] = books[i];
				books[i] = temp;
			}
		}
	}

	return books[size];
}

Book SortArrByName(Book books[], int size)
{
	Book temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (books[i].name > books[j].name)
			{
				temp = books[j];
				books[j] = books[i];
				books[i] = temp;
			}
		}
	}

	return books[size];
}

Book SortArrByPublighingHouse(Book books[], int size)
{
	Book temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (books[i].publishing_house > books[j].publishing_house)
			{
				temp = books[j];
				books[j] = books[i];
				books[i] = temp;
			}
		}
	}

	return books[size];
}

Machine Initialize(Machine machine)
{
	int type = 0;
	cout << "Enter color of machine: " << endl;
	getline(cin, machine.color);
	cout << "Enter machine`s model: " << endl;
	getline(cin, machine.model);
	cout << "What type of number u use?\n1)Five-digit num\n2)Eight symbols" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
		cout << "Enter five-digit num for machine`s number: ";
		cin >> machine.number.number_int;
		break;
	case 2:
		cout << "Enter 8 symbols for machine`s number: ";
		cin >> machine.number.number_str;
		break;
	default:
		break;
	}
	return machine;
}

void ShowMachine(Machine machine)
{
	cout << "Color: " << machine.color << endl;
	cout << "Model: " << machine.model << endl;
	if (machine.number.number_str == false)
	{
		cout << "Number: " << machine.number.number_int << endl;
	}
	else
	{
		cout << "Number: " << machine.number.number_str << endl;
	}
	
}

Machine EditMachine(Machine machine)
{
	string new_color, new_model;
	char new_number[9];
	int number;
	cout << "Enter new color of machine (or 0 if u dont wanna change this) : ";
	getline(cin, new_color);
	if (new_color != "0")
	{
		machine.color = new_color;
	}
	cout << "Enter new model of machine (or 0 if u dont wanna change this) : ";
	getline(cin, new_model);
	if (new_model != "0")
	{
		machine.model = new_model;
	}
	if (machine.number.number_str == false)
	{
		cout << "Enter new number of machine (or 0 if u dont wanna change this) : ";
		cin >> number;
		if (number != 0)
		{
			 machine.number.number_int = number;
		}
	}
	else {
		cout << "Enter new number of machine (or 0 if u dont wanna change this) : ";
		cin >> new_number;
		if (new_number != "0")
		{
			for (int i = 0; i < 9; i++)
			{
				machine.number.number_str[i] = new_number[i];
			}
		}
	}
	return machine;
}

void ShowAllMachines(int size, Machine machine_arr[])
{
	for (int i = 0; i < size; i++)
	{
		ShowMachine(machine_arr[i]);
	}
}

void FindMachineByNumber(Number number, Machine machine_arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (machine_arr[i].number.number_int == number.number_int || machine_arr[i].number.number_str == number.number_str)
		{
			cout << "index of machine: " << i << endl;
		}
	}
}

LivingEntity IntializeLivingEntity(LivingEntity entity)
{
	int choice;
	cout << "Enter speed of your entity -> ";
	cin >> entity.speed;
	cout << "Enter type of your entity:\n1)Bird\n2)Beast\n3)Human\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		entity.Type = BIRD;
		cout << "Enter flying speed of your bird: ";
		cin >> entity.characteristic.flying_speed;
		break;
	case 2:
		entity.Type = BEAST;
		cout << "Enter is your beast even-toated:\n1)Yes\n2)No";
		cin >> choice;
		if (choice == 1)
		{
			entity.characteristic.isEvenToad = true;
		}
		else if (choice == 2)
		{
			entity.characteristic.isEvenToad = false;
		}
		break;
	case 3:
		entity.Type = HUMAN;
		cout << "Enter how much IQ have your human: ";
		cin >> entity.characteristic.IQ;
		break;
	default:
		break;
	}
	cout << "Enter color of your entity: ";
	getline(cin, entity.color);
	return entity;
}

void ShowInfoOfEntity(LivingEntity entity)
{
	cout << "Speed: " << entity.speed << endl;
	switch (entity.Type)
	{
	case 0:
		cout << "Type: Bird" << endl;
		cout << "Flying Speed: " << entity.characteristic.flying_speed << endl;
		break;
	case 1:
		cout << "Type: Beast" << endl;
		cout << "Is Even Toated: " << entity.characteristic.isEvenToad << endl;
		break;
	case 2:
		cout << "Type: Human" << endl;
		cout << "IQ: " << entity.characteristic.IQ << endl;
		break;
	default:
		break;
	}
	cout << "Color: " << entity.color << endl;
}

LivingEntity EditEntity(LivingEntity entity)
{
	string new_color;
	int new_speed, choice;
	cout << "Enter new speed of entity (or 0 if u dont wanna change this) : ";
	cin >> new_speed;
	if (new_speed != 0)
	{
		entity.speed = new_speed;
	}
	cout << "Enter new Type of entity (or 0 if u dont wanna change this) : \n1)Bird \n2)Beast\n3)Human\n";
	cin >> choice;
	if (choice != 0)
	{
		switch (choice)
		{
		case 1:
			entity.Type = BIRD;
			cout << "Enter flying speed of your bird: ";
			cin >> entity.characteristic.flying_speed;
			break;
		case 2:
			entity.Type = BEAST;
			cout << "Enter is your beast even-toated:\n1)Yes\n2)No";
			cin >> choice;
			if (choice == 1)
			{
				entity.characteristic.isEvenToad = true;
			}
			else if (choice == 2)
			{
				entity.characteristic.isEvenToad = false;
			}
			break;
		case 3:
			entity.Type = HUMAN;
			cout << "Enter how much IQ have your human: ";
			cin >> entity.characteristic.IQ;
			break;
		default:
			break;
		}
	}
	cout << "Enter new color of entity (Enter 0 if u dont wanna change this) : ";
	getline(cin, new_color);
	if (new_color != "0")
	{
		entity.color = new_color;
	}
	return entity;
}

void ShowEntityArr(LivingEntity entity_arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ShowInfoOfEntity(entity_arr[i]);
	}
}

void FindEntityByCharacteristics(string Type, LivingEntity entity_arr[], int size)
{

	if (Type == "Bird")
	{
		float flying_speed = 0;
		cout << "Enter flying speed: ";
		cin >> flying_speed;
		for (int i = 0; i < size; i++)
		{
			if (entity_arr[i].characteristic.flying_speed == flying_speed)
			{
				cout << "Index of your entity: " << i << endl;
			}
		}
	}
	else if (Type == "Beast")
	{
		int choice;
		bool isEvenToated = false;
		cout << "Enter is your beast even-toated:\n1)Yes\n2)No\n ";
		cin >> choice;
		if (choice == 1)
		{
			isEvenToated = true;
		}
		else
		{
			isEvenToated = false;
		}
		for (int i = 0; i < size; i++)
		{
			if ((entity_arr[i].characteristic.isEvenToad == true && isEvenToated == true)||(entity_arr[i].characteristic.isEvenToad != true && isEvenToated != true))
			{
				cout << "Index of your entity: " << i << endl;
			}
		}
	}
	else if (Type == "Human")
	{
		int IQ = 0;
		cout << "Enter IQ: ";
		cin >> IQ;
		for (int i = 0; i < size; i++)
		{
			if (entity_arr[i].characteristic.IQ == IQ)
			{
				cout << "Index of your entity: " << i << endl;
			}
		}
	}
}

int main()
{
	
}


