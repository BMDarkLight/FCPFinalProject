#ifdef READ_HPP
#else
#define READ_HPP

using namespace std;


Data load() {
    fstream datafile("data", ios::binary|ios::app);

    Data data;

    if (!datafile.is_open()) cout << "Error in Read Data from the file, Please Check Reading Permissions for the Program. \n"; exit(0);

    datafile.read(reinterpret_cast<char*> (&data), sizeof(Data));

    return data;
}

#endif