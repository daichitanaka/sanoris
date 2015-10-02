#include <iostream>

#define MALE	1
#define	FEMALE	2

class fux{
	public:
		fux();
		~fux();
		void fuck() {std::cout << "Are you homo?" << std::endl;};
		void sex() {std::cout << "Let's sex" << std::endl;};
	private:
		int your_sex;
};

fux::fux()
{
	fux::your_sex = 0;
	std::cout << "which your sex, male = 1 or female = 2" << std::endl;
	std::cin >> fux::your_sex;
	if(fux::your_sex == MALE){
		fuck();
	}else if(fux::your_sex == FEMALE){
		sex();
	}
}

fux::~fux()
{
	std::cout << "finish" << std::endl;
}

int main(void)
{
	fux *pfux = new fux;
	delete pfux;
	return 0;
}
