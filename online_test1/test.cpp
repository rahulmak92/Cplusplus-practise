#include <iostream>
#include <string>
#include <map>

class NamesCount
{
public:
	NamesCount()
	{
		count = 0;
	}

	/**
	*   \brief Adds the name.
	*
	*   \param name Name.
	*
	**/
	void check()
	{
		for(int i=0;i<=counts.size();i++)
		{
			std::cout<<
		}
	}
	void addName(std::string name)
	{
		int nameCount = 0;
		std::map<std::string, int>::iterator search = counts.find(name);
		if (search == counts.end())
		{

			counts[name] = nameCount;
		}
		else
		{
			nameCount = counts[name];
		}
		nameCount++;
		count++;
		std::cout<<std::endl<<"Name count="<<nameCount<<" Count = "<<count<<std::endl;
	}

	/**
	*   \brief Returns proportion of parameter name in all calls to addName.
	*
	*   \param name Name.
	*   \return double in interval [0, 1]. Returns 0 if addName has not been called.
	*
	**/
	double nameProportion(std::string name)
	{

		std::cout<<"HERE : "<<counts[name]<<" kaik";
		return static_cast<double>(counts[name] / count);
	}

private:
	int count;
	std::map<std::string, int> counts;
};

int main(int argc, const char* argv[])
{
	NamesCount namesCount;

	namesCount.addName("James");
	namesCount.addName("John");
	namesCount.addName("Mary");
	namesCount.addName("Mary");
	namesCount.check();
	std::cout << "Fraction of Johns: " << namesCount.nameProportion("John") << '\n';
	std::cout << "Fraction of Marys: " << namesCount.nameProportion("Mary") << '\n';

	return 0;
}
