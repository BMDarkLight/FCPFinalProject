#ifdef SAVE_HPP
#else
#define SAVE_HPP

using namespace std;

#define open ::datafile.open("data", ios::binary|ios::app)

void save(const Data &data) {
    remove("./data");

    open;

    if (!::datafile.is_open()) cout << "Error in Writing Data into file, Please Check Writing Permissions for the Program. \n"; exit(0);

    ::datafile.write((const char*) (&data), sizeof(Data));
}

#endif