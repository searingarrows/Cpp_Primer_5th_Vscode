#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>


class StrVec {
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){};
	StrVec(const StrVec& rhs);
	StrVec& operator=(const StrVec&);
	~StrVec();
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&& rhs) noexcept;
	void push_back(const std::string&);
	void push_back(std::string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc(){
        if(first_free==cap){
			reallocate();
		}
    }
	std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
	void free();
	void reallocate();
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& str) {
	chk_n_alloc();
	alloc.construct(first_free++, str);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e){
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free(){
    if(elements){
		for (auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap-elements);
	}
}

StrVec::StrVec(const StrVec& rhs){
	auto pair = alloc_n_copy(rhs.begin(), rhs.end());
	elements = pair.first;
	first_free = cap = pair.second;
}

StrVec::~StrVec(){
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = std::uninitialized_copy(
	    std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

StrVec::StrVec(StrVec&& s) noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap){
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept{
    if(this!=&rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::push_back(std::string&& s){
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
#endif