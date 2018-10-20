#include "StrBlobPtr.h"

std::string& StrBlobPtr::deref() const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const {
	if (auto p = wptr.lock()) {
		if (i<p->size()){
			return p;
		}else{
			throw std::out_of_range("msg");
		}
	}
	else {
		throw std::runtime_error("unbound StrBlobPtr");
	}
}