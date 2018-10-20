#include "StrBlob.h"
#include "StrBlobPtr.h"
using namespace std;

StrBlob::StrBlob()
    : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::pop_back() {
	data->pop_back();
}

void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}