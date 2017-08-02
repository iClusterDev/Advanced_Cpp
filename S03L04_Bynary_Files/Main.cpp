#include <iostream>
#include <fstream>



//To pack a class is to place its members directly after each other in memory,
//which can mean that some or all members can be aligned on a boundary smaller 
//than the default alignment the target architecture.

// https://msdn.microsoft.com/en-us/library/2e70t5y1.aspx

//push, 1 = align the data on single byte boundaries
#pragma pack(push, 1)

struct Person {
	char Name[50];
	int Age;
	double Height;
};

#pragma pack(pop)



//exceptions
class Bad_File_Exception : std::exception {
public:
	const char* what() const noexcept {
		return "Bad File Exception";
	}
};



//writing a binary file ----------------------------------------
void WriteBinary(std::string fileName, const Person &person) {
	std::ofstream OutputStream(fileName, std::ofstream::binary);

	if (!OutputStream) {
		throw Bad_File_Exception();
	}
	else {
		OutputStream.write(reinterpret_cast<const char*>(&person), sizeof(Person));
		OutputStream.close();
	}
}



//reading a binary file ----------------------------------------
void ReadBinary(std::string fileName, Person &person) {
	std::ifstream InputStream(fileName, std::ofstream::binary);

	if (!InputStream) {
		throw Bad_File_Exception();
	}
	else {
		InputStream.read(reinterpret_cast<char*>(&person), sizeof(Person));
		InputStream.close();
	}
}



int main() {

	std::string FileName = "test.bin";
	Person someone = { "Fabio", 38, 1.62 };

	try	{
		WriteBinary(FileName, someone);
	}
	catch (const std::exception& e)	{
		std::cout << e.what() << std::endl;
	}	

	Person someoneElse = {};

	try	{
		ReadBinary(FileName, someoneElse);
	}
	catch (const std::exception& e)	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << someoneElse.Name << " - " << someoneElse.Age << " - " << someoneElse.Height << std::endl;

	std::cin.get();

}