# include <iostream>
#include <fstream> // Бибилиотека, описывающая классы для работы с файловой системой устройства
#include<string>

const char stat_path[] = "stats.txt";

bool statistic(const std::string str);
void print_file();
bool clear();

int main() {
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251>null"); // Вместо setlocate запись в файл на русском языке
	int n;
	std::string path = "file.txt"; // Относительный путь

	// класс ofstream
	/*std::ofstream out;//(path) // Создание объекта для записи данных в файл
	//out.open(path); // Открытие файла с режимом по умолчанию std::ios::out
	out.open(path, std::ios::app); // Открытие файла для добаления записей в конец файла
	if (out.is_open()) {
		std::cout << "Файл открыт для записи\n";
		std::string msg;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, msg);
		out << msg <<'\n'; // добавление строки в файл
	}
	else
		std::cout << "Ошибка открытия файла";

	out.close();*/

	// Класс ifstream
	/*std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "Содердимое файла:\n";
		std::string file;
		// 1-ый способ считывания файла: посимвольное считывание
		//char sym;
		//while (in.get(sym))
		//	file += sym;
		//std::cout << file << std::endl;
		// 2-ой способ: пословное
		//while (!in.eof()) {
			//std::string str;
			//in >> str;
			//file += str + '\n';
		//}
		//std::cout << file << std::endl;
		// 3-ий способ: построчное
		std::string str;
		while (std::getline(in, str))
			file += str + '\n';
		std::cout << file;
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	in.close();*/

	// Удаление файла
	//remove(path.c_str()); // Простой вариант использования
	/*if (remove(path.c_str()) == 0)
		std::cout << "Файл удалён\n";
	else
		std::cout << "Ошибка удаления файла\n";*/

	// Задача 1. Статистика
	std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	if (statistic(str1))
		std::cout << "Запись добавлена в файл.\n\n";
	else
		std::cout << "Ошибка!\n\n";

	// Задача 2. Дополнения к задаче 1


	return 0;
}

bool statistic(const std::string str) {
	static std::ofstream out;
	out.open(stat_path, std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	return false;
}

void print_file() {
	static std::ifstream in;
	in.open(stat_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
	}
}

bool clear() {	
	static std::ofstream out;
	out.open(stat_path);
	if (out.is_open()) {
		out.close();
		return true;
	}
	return false;
}