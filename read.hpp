#ifdef READ_HPP
#else
#define READ_HPP

using namespace std;

void load(Data &data) {
    if (!::datafile.is_open()) open;

    if (!::datafile.is_open()) cout << "Error in Read Data from the file, Please Check Reading Permissions for the Program. \n"; exit(0);

    ::datafile.read((char*) (&data), sizeof(Data));
}

#endif