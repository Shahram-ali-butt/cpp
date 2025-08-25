#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
using std::cout, std::cin, std::string, std::getline, std::endl, std::vector, std::unique_ptr, std::make_unique;

class FileSystemEntity{
    public:
    string name;
    string owner = "administrator";
    FileSystemEntity(string n) : name(n) {}
    
    string const display(){
        string properties = "Folder Name: " + name + ", Owner: " + owner;
        return properties;
    }

    void getCreationTime() {
        time_t timestamp = time(nullptr);  // Get current time
        char* createdTime = ctime(&timestamp);  // Convert to readable string
        cout << "Creation Time: " << createdTime << endl;
    }
    virtual int getSize() const {return 0; /*dummy logic*/}
};

class File : public FileSystemEntity{
    protected:
    string data;
    public:
    File(string n, string d) : FileSystemEntity(n) {writeData(d);}
    void writeData(string d) {data = d;}
    void readData() {cout << data << endl;}
    int getSize() const override {return data.size();}
};

class Folder : public FileSystemEntity{
    public:
    vector<unique_ptr<FileSystemEntity>> files;

    Folder(string n) : FileSystemEntity(n) {}

    int getSize() const override {return files.size();}
    void showContent(){
        for(const auto& entity : files){
            if(Folder* folder = dynamic_cast<Folder*>(entity.get())){
                cout << "- " << folder->name << endl;
            }else if(File* file = dynamic_cast<File*>(entity.get())){
                cout << file->name << endl;
            }
        }
        cout << endl;
    }
    void add(unique_ptr<FileSystemEntity> entity) {
        files.push_back(std::move(entity));
    }

    void remove(string entityName){
        for(int i = 0; i < files.size(); i++){
            if(files[i]->name == entityName){
                files.erase(files.begin() + i);
            }
        }
        cout << "Updated folder Content:" << endl;
        showContent();
    }
    void open(string filename) {
        for (const auto& entity : files) {
            if (entity->name == filename) {
                if (Folder* folder = dynamic_cast<Folder*>(entity.get())) {
                    cout << "\nOpening Folder: " << entity->name << " ......" << endl;
                    folder->showContent();  // Or folder->open(some_subfile) if needed
                    cout << "End of Folder......" << endl;
                } else if (File* file = dynamic_cast<File*>(entity.get())) {
                    cout << "Opening File: " << entity->name << " ......\n" << endl;
                    file->readData();
                    cout << "\nEnd of File......" << endl;
                }
                return;  // Stop after finding the match
            }
        }
        cout << "File or folder not found: " << filename << endl;
    }
};

int main(){
    cout << "**  Welcome to your very own file handling system!  **" << endl;
    Folder root("root");
    root.add(make_unique<File>("notes.txt", "C++ is powerful!"));
    root.add(make_unique<Folder>("projects"));
    cout << root.display() << endl;
    root.showContent(); 
    cout << "Total size: " << root.getSize() << " bytes\n";
    cout << "********** File methods **********" << endl;
    root.open("notes.txt");
    root.open("projects");
    cout << "Deleting notes.txt" << endl;
    root.remove("notes.txt");
    return 0;
}
