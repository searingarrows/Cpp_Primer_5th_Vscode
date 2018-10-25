#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;

public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();

	std::string& front();
	std::string& back();

	const std::string& front() const;
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr {
public:
	StrBlobPtr()
	    : curr(0){};
	StrBlobPtr(StrBlob& a, size_t sz = 0)
	    : wptr(a.data)
	    , curr(sz){};
	std::string& deref() const;
	std::string& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	std::string* operator->() const { return &this->operator*(); }
	
	StrBlobPtr& incr();
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

	bool operator!=(const StrBlobPtr& rhs) const {
		return wptr.lock() != rhs.wptr.lock() || curr != rhs.curr;
	}

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string& msg) const {
	if (auto p = wptr.lock()) {
		if (i < p->size()) {
			return p;
		}
		else {
			throw std::out_of_range("msg");
		}
	}
	else {
		throw std::runtime_error("unbound StrBlobPtr");
	}
}

StrBlob::StrBlob()
    : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::pop_back() {
	data->pop_back();
}

void StrBlob::check(size_type i, const std::string& msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
	auto ret = *this;
	++*this;
	return ret;
}

StrBlobPtr& StrBlobPtr::operator--() {
	--curr;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator--(int) {
	auto ret = *this;
	--*this;
	return ret;
}

#endif