#include <iostream>
#include <fstream>
#include <string>

#define character_size 26

using namespace std;

void search_string(struct node* temp,string name,int index);
void insert_string(struct node* temp,string name,int index);
void readFile();

struct node{
    char end_str;
    struct node* pointers[character_size];

};

struct node* root=new(node);

int main()
{
    for(int i=0;i<character_size;i++)
        root->pointers[i]=NULL;

    readFile();

    string query1="a";
    cout <<"Enter the string to be searched (press 1 to exit) :";

    while(1){

        cin >> query1;
        if(query1=="1"){
            break;
        }
        search_string(root,query1,0);
        cout <<"\n";
    }
    return 0;
}

void readFile()
{
     string line;
  ifstream myfile ("dictionary.txt");
  if (myfile.is_open()){
    while ( getline (myfile,line) ){
      insert_string(root,line,0);
    }
    myfile.close();
  }
  else cout << "Unable to open file";
}

void insert_string(struct node* temp,string name,int index){

    int string_index=((int)name[index])-97;

    if(root==NULL){
        struct node* temp1=new(node);

        for(int i=0;i<character_size;i++){
            temp1->pointers[i]=NULL;
        }

        root->pointers[string_index]=temp1;
        if(name.length()==1){
            temp1->end_str='$';
        }
        else{
            temp1->end_str='a';
        }
        insert_string(temp1,name,index+1);

    }

    if(temp->pointers[string_index]!=NULL){

         if(index==name.length()-1){
            (temp->pointers[string_index])->end_str='$';
            return;
        }
        insert_string(temp->pointers[string_index],name,index+1);

    }
    else{
        struct node* temp1=new(node);
        for(int i=0;i<character_size;i++){
            temp1->pointers[i]=NULL;
        }
        temp->pointers[string_index]=temp1;
        if(index==name.length()-1){
            temp1->end_str='$';
            return;
        }
        else{
            temp1->end_str='a';
            insert_string(temp->pointers[string_index],name,index+1);
        }
    }
}

void search_string(struct node* temp,string name,int index){
    if(temp==NULL){
        cout << "Not found";
        insert_string(root,name,0);
        return;
    }
    if(index==name.length() && temp->end_str=='$'){
        cout <<"search successful";
        return;
    }

    int string_index=((int)name[index])-97;
    if(temp->pointers[string_index]!=NULL)
        search_string(temp->pointers[string_index],name,index+1);
    else{
        cout << "Not found";
        insert_string(root,name,0);
        return;
    }
}
