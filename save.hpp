#ifdef SAVE_HPP
#else
#define SAVE_HPP

using namespace std;

void save(const Data &data) {
    remove("./data");

    fstream datafile("data", ios::binary|ios::app);

    if (!datafile.is_open()) cout << "Error in Writing Data into file, Please Check Writing Permissions for the Program. \n"; exit(0);

    datafile.write(reinterpret_cast<const char*> (&data), sizeof(Data));
}

#endif