#include"Header.h"
#include<iostream>
/*Online Book Reader System:
basic system components:
Library; userManager; Display; 

Only one active user at a time;
Only one active book by this user;

Each of the main system component translates roughly to an object, and each action translates to a method.

*/

class onlineReaderSystem{
private:
	Library* library;
	userManager* manager;
	Display* display;
	Book* activeBook;
	User* activeUser;
public:
	onlineReaderSystem(){
		manager = new userManager();
		library = new Library();
		display = new Display();
	}
	Library* getLibrary(){
		return library;
	}
	userManager* getManager(){
		return manager;
	}
	Display* getDisplay(){
		return display;
	}
	Book* getActiveBook(){
		return activeBook;
	}
	void setActiveBook(Book* book){
		activeBook = book;
		display->displayBook(book);
	}
	User* getActiveUser(){
		return activeUser;
	}
	void setActiveBook(User* user){
		activeUser = user;
		display->displayUser(user);
	}
};

class Library{
private:
	unordered_map<int, Book*> hash;
public:
	Book* addBook(int id, string details){
		if (hash.find(id) != hash.end()){
			return nullptr;
		}
		Book* book = new Book(id, details);
		hash[id] = book;
		return book;
	}

	bool removeBook(int id){
		if (hash.find(id) == hash.end()){
			return false;
		}
		hash.erase(id);
		return true;
	}
	bool removeBook(Book* book){
		return removeBook(book->getId());
	}

	Book* find(int id){
		if (hash.find(id) == hash.end()){
			return nullptr;
		}
		return hash[id];
	}
};

class userManager{
private:
	unordered_map<int, User*> users;
public:
	User* addUser(int id, string details, int accountType){
		if (users.find(id) != users.end()){
			return nullptr;
		}
		User* user = new User(id, details, accountType);
		users[id] = user;
		return user;
	}

	bool removeUser(int id){
		if (users.find(id) == users.end()){
			return false;
		}
		users.erase(id);
		return true;
	}
	bool removeUser(User* user){
		return removeUser(user->getId());
	}

	User* find(int id){
		if (users.find(id) == users.end()){
			return nullptr;
		}
		return users[id];
	}
};

class Display{
private:
	Book* activeBook;
	User* activeUser;
	int pageName;
public:
	void displayUser(User* user){
		activeUser = user;
		refreshUserName();
	}
	void refreshUserName(){}

	void displayBook(Book* book){
		activeBook = book;
		refreshBookName();
	}
	void refreshBookName(){}
	void turnPageForward(){
		pageName++;
		refreshPage();
	}
	void refreshBookName(){
		pageName--;
	}
	void refreshPage(){}

};

class Book{
private:
	int bookId;
	string details;
public:
	Book(int id, string s) :bookId(id), details(s){}

	int getId(){
		return bookId;
	}
	void setId(int id){
		bookId = id;
	}

	string getDetails(){
		return details;
	}
	void setDetails(string s){
		details = s;
	}
};

class User{
private:
	int userId;
	string details;
	int accountType;
public:
	User(int id, string s, int type) :userId(id), details(s), accountType(type){}

	void renewMembership(){}

	int getId(){
		return userId;
	}
	void setId(int id){
		userId = id;
	}

	string getDetails(){
		return details;
	}
	void setDetails(string s){
		details = s;
	}

	int getAccountType(){
		return accountType;
	}
	void setAccountType(int t){
		accountType = t;
	}
};