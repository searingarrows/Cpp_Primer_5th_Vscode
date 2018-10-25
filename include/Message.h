#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>
class Message;
class Folder {
	friend void swap(Folder&, Folder&);
	friend class Message;

public:
	Folder() {}
	~Folder();
	Folder(const Folder&);
	Folder& operator=(const Folder&);

private:
	std::set<Message*> messages;
	void addMsg(Message* message) { messages.insert(message); }
	void remMsg(Message* message) { messages.erase(message); }
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
};
class Message {
	friend class Folder;
	friend void swap(Message&, Message&);

public:
    explicit Message(const std::string& s=std::string()):contents(s){}
	~Message();
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message* m);
	void addFolder(Folder* folder) { folders.insert(folder); }
	void remFolder(Folder* folder) { folders.erase(folder); }
};

//==============folder===================
void Folder::add_to_Messages(const Folder& folder){
	for(auto msg:messages){
		msg->addFolder(this);
	}
}

Folder::~Folder() {
	remove_from_Messages();
}

void Folder::remove_from_Messages(){
	for (auto msg : messages) {
		msg->remFolder(this);
	}
}

Folder::Folder(const Folder& rhs) {
	add_to_Messages(rhs);
}

Folder& Folder::operator=(const Folder& rhs){
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

//==============message===================

void Message::save(Folder& folder){
	folders.insert(&folder);
	folder.addMsg(this);
}

void Message::remove(Folder& folder){
	folders.erase(&folder);
	folder.remMsg(this);
}

void Message::add_to_Folders(const Message& message){
    for(auto folder:message.folders){
		folder->addMsg(this);
	}
}

void Message::remove_from_Folders(){
    for(auto folder:folders){
		folder->remMsg(this);
	}
}

Message::Message(const Message& rhs){
	contents = rhs.contents;
	add_to_Folders(rhs);
}

Message::~Message(){
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs){
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void swap(Message& lhs, Message& rhs){
	using std::swap;
	
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

void Message::move_Folders(Message* m){
	folders = std::move(m->folders);
	for(auto f:folders){
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(Message&& m):contents(std::move(m.contents)){
	move_Folders(&m);
}

Message& Message::operator=(Message &&rhs){
	if(this!=&rhs){
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}
#endif